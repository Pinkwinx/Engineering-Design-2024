#include <SoftwareSerial.h>

// Define the RX and TX pins for the Bluetooth module
#define BT_RX 10
#define BT_TX 11

SoftwareSerial bluetoothSerial(BT_RX, BT_TX); // RX, TX

void setup() {
  // Initialize serial communication with the computer
  Serial.begin(9600);
  Serial.println("Arduino Bluetooth Terminal");

  // Initialize serial communication with the Bluetooth module
  bluetoothSerial.begin(9600);
}

void loop() {
  // Check if data is available from the Bluetooth module
  if (bluetoothSerial.available()) {
    // Read data from Bluetooth and send it to Serial (USB)
    char c = bluetoothSerial.read();
    Serial.write(c);
  }

  // Check if data is available from Serial (USB)
  if (Serial.available()) {
    // Read data from Serial (USB) and send it to Bluetooth
    char c = Serial.read();
    bluetoothSerial.write(c);
  }
}
