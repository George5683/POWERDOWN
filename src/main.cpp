#include <Arduino.h>
// DEFINE THE GPIO PIN where the LED is connected
#define LED_PIN 2


void blink(){
  digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

void setup() {
  // Start the serial monitor
  Serial.begin(9600);

  // Initialize LED pin to be an output
  pinMode(LED_PIN, OUTPUT);

  // Print a message to the serial monitor indicating setup has started
  Serial.println("Setup started");
}

void loop() {
  Serial.println("Blinking LED");
  while(true){
    blink();
  }
}
