#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp> // Include the library
uint16_t sAddress = 0x0514;
uint16_t sCommand = 0xFFFF;
uint8_t sRepeats = 0;
void setup()
{
pinMode(8, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);
pinMode(10, INPUT_PULLUP);
pinMode(11, INPUT_PULLUP);
pinMode(LED_BUILTIN, OUTPUT); // LED pin
Serial.begin(9600);
IrSender.begin(); // Start with IR_SEND_PIN
disableLEDFeedback(); // Disable feedback LED at default feedback LED pin
}

void loop() {
if (digitalRead(8) == 0){
  sCommand = 0xAAAA ;
  Send();
  }
else if (digitalRead(9) == 0){
  sCommand = 0xBBBB ;
  Send();
  }
else if (digitalRead(10) == 0){
  sCommand = 0xCCCC ;
  Send();
  }
else if (digitalRead(11) == 0){
  sCommand = 0xDDDD ;
  Send();
  }
}
void Send(){
  Serial.println();
  Serial.print("Send IR signals at pin ");
  Serial.println(IR_SEND_PIN);
  Serial.print("Send Protocol=NEC : address=");
  Serial.print(sAddress, HEX);
  Serial.print(", command=");
  Serial.print(sCommand, HEX);
  Serial.print(", repeats=");
  Serial.println(sRepeats);
  IrSender.sendNEC(sAddress, sCommand, sRepeats);
  delay(100);
}