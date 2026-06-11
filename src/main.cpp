#include <Arduino.h>

// GPIO 2 is the onboard LED for most ESP32 DevModules
#define LED_PIN 2

void setup() {
    // Set the pin mode to output
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(500); // 500ms for a faster blink
    digitalWrite(LED_PIN, LOW);
    delay(500);
}