#include <Arduino.h>
#include <IRremote.hpp>

// Define the LED pin
const int ledPin = 13; // Most Arduino boards have an onboard LED on pin 13
const int IR_Transmitter = 10; // Pin for the IR transmitter
const int IR_Receiver = 9; // Pin for the IR receiver

void blink(){
  Serial.println("IR signal received! Blinking LED...");
  // Turn the LED on
  digitalWrite(ledPin, HIGH);
  delay(1000); // Wait for 1 second

  // Turn the LED off
  digitalWrite(ledPin, LOW);
  delay(1000); // Wait for 1 second
}
// Allow a menu of devices to control 
void DeviceMenu(){
}

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud rate

  // Delay 10 seconds to give time to open the Serial Monitor
  delay(10000);

  Serial.println("Starting IR Receiver...");

  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Start the IR transmitter on Sensor Pin
  IrReceiver.begin(IR_Receiver, ENABLE_LED_FEEDBACK);  
}

void loop() {
  if (IrReceiver.decode()) {
    blink(); // Blink the LED when a signal is received
    
    Serial.print("Protocol: ");
    Serial.println(IrReceiver.decodedIRData.protocol);

    Serial.print("Address: ");
    Serial.println(IrReceiver.decodedIRData.address, HEX);

    Serial.print("Command: ");
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    Serial.println("----------------");

    IrReceiver.resume(); // Ready for next signal
  }
}