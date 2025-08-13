#include <IRremote.hpp>    // Include the library
#define IR_RECEIVE_PIN 11  // IR receiver pin 11
void setup() {
  Serial.begin(9600);                                     // Message will be sent to PC
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the receiver
}
void loop() {
  if (IrReceiver.decode())  // Received IR signal
  {
    switch (IrReceiver.decodedIRData.decodedRawData)  // Remote IR codes
    {
      case 0xF807FF00: Serial.print("OK "); break;
      case 0xB847FF00: Serial.print("LEFT "); break;
      case 0xBF40FF00: Serial.print("RIGHT "); break;
      case 0xF906FF00: Serial.print("FORWARD "); break;
      case 0xBB44FF00: Serial.print("REVERSE "); break;
      case 0xF609FF00: Serial.print("1 "); break;
      case 0xE21DFF00: Serial.print("2 "); break;
      case 0xE01FFF00: Serial.print("3 "); break;
      case 0xA857FF00: Serial.print("4 "); break;
      case 0xF20DFF00: Serial.print("5 "); break;
      case 0xE619FF00: Serial.print("6 "); break;
      case 0xE41BFF00: Serial.print("7 "); break;
      case 0xBE41FF00: Serial.print("8 "); break;
      case 0xEE11FF00: Serial.print("9 "); break;
      case 0xEA15FF00: Serial.print("0 "); break;
      case 0xFF42BD: Serial.print("* "); break;
      case 0xFF52AD: Serial.print("# "); break;
      case 0xB44BFF00: Serial.print("REPEAT "); break;
      default: Serial.print("other button ");
    }
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print raw data
    IrReceiver.resume();                                           // Enable receiving of the next value
  }
}
