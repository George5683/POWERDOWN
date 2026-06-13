#include <Arduino.h>
#include <IRremote.hpp>
#include <remote.hpp>

// GPIO 2 is the onboard LED for most ESP32 DevModules
#define IR_R_PIN 18
#define IR_T_PIN 18

bool receiveON = false;
// Create Samsung transmitter instance (make it global so loop() can use it)
Samsung sam(IR_T_PIN);

void setup() {
    // Start Serial for terminal output 
    Serial.begin(115200);

    // Set the pin mode to output
    pinMode(IR_R_PIN, INPUT);
    pinMode(IR_T_PIN, OUTPUT);

    IrReceiver.begin(IR_R_PIN);

}

void loop() {
    if (IrReceiver.decode() &&  receiveON) {
        Serial.print("Protocol: ");
        Serial.println(getProtocolString(IrReceiver.decodedIRData.protocol));

        Serial.print("Address: 0x");
        Serial.println(IrReceiver.decodedIRData.address, HEX);

        Serial.print("Command: 0x");
        Serial.println(IrReceiver.decodedIRData.command, HEX);

        Serial.println();

        IrReceiver.resume(); // Ready for next code
    }
    sam.TV_ON();
    delay(2000);
}