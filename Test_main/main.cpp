#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define LED1_PIN 2
#define BUTTON_PIN 23

// Flags 
volatile bool Button_Flag = false;
volatile bool IR_Flag = false;
volatile bool Blink_Flag = false;
// Task handle
TaskHandle_t BlinkTaskHandle = NULL;
TaskHandle_t PowerTaskHandle = NULL;
TaskHandle_t SerialTaskHandle = NULL;

// Creating the queue
QueueHandle_t isrQueue;
// int value = 1;
// xQueueSendFromISR(isrQueue, &value, NULL);
// xQueueReceive(isrQueue, &value, portMAX_DELAY)

// Volatile variables for ISR
volatile bool taskSuspended = false;
volatile uint32_t lastInterruptTime = 0;
const uint32_t debounceDelay = 100; // debounce period

void SerialTask(void *parameter) {
  if (Blink_Flag) {
    Serial.println("SerialTask: Blinking is ON");
  } else {
    Serial.println("SerialTask: Blinking is OFF");
  }

  if (Button_Flag) {
    Serial.println("SerialTask: Button was pressed");
    Button_Flag = false;
  }
}

// Fast ISR to toggle task state
void IRAM_ATTR buttonISRfast(){
  BaseType_t higherPriorityTaskWoken = pdFALSE;
  // Toggle task state
  taskSuspended = !taskSuspended;
  if (taskSuspended) {
    vTaskSuspend(BlinkTaskHandle);
    Blink_Flag = false;
  } else {
    vTaskResume(BlinkTaskHandle);
    Blink_Flag = true;
  }
  // notify SerialTask
  vTaskNotifyGiveFromISR(SerialTaskHandle, &higherPriorityTaskWoken);
  if (higherPriorityTaskWoken) {
    portYIELD_FROM_ISR();
  }
}

// ISR for button press
void IRAM_ATTR buttonISRHandler() {
  // Debounce the button press
  uint32_t currentTime = millis();
  if (currentTime - lastInterruptTime < debounceDelay) {
    return;
  }
  lastInterruptTime = currentTime;
  buttonISRfast();
}

void BlinkTask(void *parameter) {
  for (;;) { // Infinite loop
    digitalWrite(LED1_PIN, HIGH);
    Serial.println("BlinkTask: LED ON");
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1000ms
    digitalWrite(LED1_PIN, LOW);
    Serial.println("BlinkTask: LED OFF");
    Serial.print("BlinkTask running on core ");
    Serial.println(xPortGetCoreID());
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    Serial.printf("Task1 Stack Free: %u bytes\n", uxTaskGetStackHighWaterMark(NULL));

  }
}

void Powerfunction(void *parameter){
  // Power ON/OFF
}

void setup() {
  Serial.begin(115200);

  Serial.printf("Starting FreeRTOS: Memory Usage\nInitial Free Heap: %u bytes\n", xPortGetFreeHeapSize());

  // Initialize pins
  pinMode(LED1_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Internal pull-up resistor

  // Create task for blinking LED
  xTaskCreatePinnedToCore(
    BlinkTask,         // Task function
    "BlinkTask",       // Task name
    10000,             // Stack size (bytes)
    NULL,              // Parameters
    4,                 // Priority
    &BlinkTaskHandle,  // Task handle
    1                  // Core 1
  );

  // Create task for using the IR sensor to power ON/OFF televisions
  xTaskCreatePinnedToCore(
    Powerfunction,         // Task function
    "PowerTask",       // Task name
    10000,             // Stack size (bytes)
    NULL,              // Parameters
    5,                 // Priority
    &PowerTaskHandle,  // Task handle
    1                  // Core 1
  );

  xTaskCreatePinnedToCore(
    SerialTask,
    "SerialTask",
    4096,
    NULL,
    5,
    &SerialTaskHandle,
    1
  );

  // Attach interrupt to button
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonISRHandler, FALLING);
}

void loop() {
  // Empty because FreeRTOS scheduler runs the task
}