#include <IRremote.hpp>    // Include the library
#define IR_RECEIVE_PIN 11  // IR receiver pin 11

// 4 digit 7 segment display
#define segmentA 6
#define segmentB 8
#define segmentC 4
#define segmentD 2
#define segmentE 1
#define segmentF 7
#define segmentG 5
#define segmentDP 3

#define digit1 A1
#define digit2 A2
#define digit3 A3
#define digit4 A4

int value[] = { 0, 0, 0, 0 };

void setup() {
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentDP, OUTPUT);
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  //Serial.begin(115200);
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
      case 0xF609FF00: Serial.print("1 ");break;
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

    IrReceiver.resume();  // Enable receiving of the next value
  }
  // displayNumber(2, (IrReceiver.decodedIRData.decodedRawData/0x00FFFFFF)%0xF);
  // displayNumber(3, (IrReceiver.decodedIRData.decodedRawData/0x000FFFFF)%0xF);
  // displayNumber(4, (IrReceiver.decodedIRData.decodedRawData/0x0000FFFF)%0xF);
    displayNumber(1,(IrReceiver.decodedIRData.decodedRawData/0x0FFFFFFF)%16);
    displayNumber(2,(IrReceiver.decodedIRData.decodedRawData/0x00FFFFFF)%16);
    displayNumber(3,(IrReceiver.decodedIRData.decodedRawData/0x000FFFFF)%16);
    displayNumber(4,((IrReceiver.decodedIRData.decodedRawData/0x0000FFFF)%16)-1);
}
void displayNumber(int Digit, int Number) {
  displaySegment(Number);
  switch (Digit) {
    case -1:
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      digitalWrite(A3, 0);
      digitalWrite(A4, 0);
      break;
    case 1:
      digitalWrite(A1, 1);
      digitalWrite(A2, 0);
      digitalWrite(A3, 0);
      digitalWrite(A4, 0);
      break;
    case 2:
      digitalWrite(A1, 0);
      digitalWrite(A2, 1);
      digitalWrite(A3, 0);
      digitalWrite(A4, 0);
      break;
    case 3:
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      digitalWrite(A3, 1);
      digitalWrite(A4, 0);
      break;
    case 4:
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      digitalWrite(A3, 0);
      digitalWrite(A4, 1);
      break;
  }
  delay(5);
}

void displaySegment(int numberToDisplay) {
  switch (numberToDisplay) {
    default:
      digitalWrite(segmentA, 1);
      digitalWrite(segmentB, 1);
      digitalWrite(segmentC, 1);
      digitalWrite(segmentD, 1);
      digitalWrite(segmentE, 1);
      digitalWrite(segmentF, 1);
      digitalWrite(segmentG, 0);
      break;
    case 0:  // แสดงผลเลข 1
      digitalWrite(segmentA, 1);
      digitalWrite(segmentB, 1);
      digitalWrite(segmentC, 1);
      digitalWrite(segmentD, 1);
      digitalWrite(segmentE, 1);
      digitalWrite(segmentF, 1);
      digitalWrite(segmentG, 0);
      break;
    case 1:  // แสดงผลเลข 1
      digitalWrite(segmentA, 0);
      digitalWrite(segmentB, 1);
      digitalWrite(segmentC, 1);
      digitalWrite(segmentD, 0);
      digitalWrite(segmentE, 0);
      digitalWrite(segmentF, 0);
      digitalWrite(segmentG, 0);
      break;
    case 2:  // แสดงผลเลข 2
      digitalWrite(segmentA, 1);
      digitalWrite(segmentB, 1);
      digitalWrite(segmentC, 0);
      digitalWrite(segmentD, 1);
      digitalWrite(segmentE, 1);
      digitalWrite(segmentF, 0);
      digitalWrite(segmentG, 1);
      break;
    case 3:  // แสดงผลเลข 3
      digitalWrite(segmentA, 1);
      digitalWrite(segmentB, 1);
      digitalWrite(segmentC, 1);
      digitalWrite(segmentD, 1);
      digitalWrite(segmentE, 0);
      digitalWrite(segmentF, 0);
      digitalWrite(segmentG, 1);
      break;
    case 4:  // แสดงผลเลข 4
      digitalWrite(segmentA, 0);
      digitalWrite(segmentB, 1);
      digitalWrite(segmentC, 1);
      digitalWrite(segmentD, 0);
      digitalWrite(segmentE, 0);
      digitalWrite(segmentF, 1);
      digitalWrite(segmentG, 1);
      break;
    case 5:  // แสดงผลเลข 5
      digitalWrite(segmentA, 1);
      digitalWrite(segmentB, 0);
      digitalWrite(segmentC, 1);
      digitalWrite(segmentD, 1);
      digitalWrite(segmentE, 0);
      digitalWrite(segmentF, 1);
      digitalWrite(segmentG, 1);
      break;
    case 6:  // แสดงผลเลข 6
      digitalWrite(segmentA, 1);
      digitalWrite(segmentB, 0);
      digitalWrite(segmentC, 1);
      digitalWrite(segmentD, 1);
      digitalWrite(segmentE, 1);
      digitalWrite(segmentF, 1);
      digitalWrite(segmentG, 1);
      break;
    case 7:  // แสดงผลเลข 7
      digitalWrite(segmentA, 1);
      digitalWrite(segmentB, 1);
      digitalWrite(segmentC, 1);
      digitalWrite(segmentD, 0);
      digitalWrite(segmentE, 0);
      digitalWrite(segmentF, 0);
      digitalWrite(segmentG, 0);
      break;
    case 8:  // แสดงผลเลข 8
      digitalWrite(segmentA, 1);
      digitalWrite(segmentB, 1);
      digitalWrite(segmentC, 1);
      digitalWrite(segmentD, 1);
      digitalWrite(segmentE, 1);
      digitalWrite(segmentF, 1);
      digitalWrite(segmentG, 1);
      break;
    case 9:  // แสดงผลเลข 9
      digitalWrite(segmentA, 1);
      digitalWrite(segmentB, 1);
      digitalWrite(segmentC, 1);
      digitalWrite(segmentD, 1);
      digitalWrite(segmentE, 0);
      digitalWrite(segmentF, 1);
      digitalWrite(segmentG, 1);
      break;
    case 10:
      digitalWrite(segmentA, 1);
      digitalWrite(segmentB, 1);
      digitalWrite(segmentC, 1);
      digitalWrite(segmentD, 0);
      digitalWrite(segmentE, 1);
      digitalWrite(segmentF, 1);
      digitalWrite(segmentG, 1); 
      break;
    case 11:
      digitalWrite(segmentA, 0);
      digitalWrite(segmentB, 0);
      digitalWrite(segmentC, 1);
      digitalWrite(segmentD, 1);
      digitalWrite(segmentE, 1);
      digitalWrite(segmentF, 1);
      digitalWrite(segmentG, 1); 
      break;
    case 12:
      digitalWrite(segmentA, 1);
      digitalWrite(segmentB, 0);
      digitalWrite(segmentC, 0);
      digitalWrite(segmentD, 1);
      digitalWrite(segmentE, 1);
      digitalWrite(segmentF, 1);
      digitalWrite(segmentG, 0); 
      break;
    case 13:
      digitalWrite(segmentA, 0);
      digitalWrite(segmentB, 1);
      digitalWrite(segmentC, 1);
      digitalWrite(segmentD, 1);
      digitalWrite(segmentE, 1);
      digitalWrite(segmentF, 0);
      digitalWrite(segmentG, 1); 
      break;
    case 14:
      digitalWrite(segmentA, 1);
      digitalWrite(segmentB, 0);
      digitalWrite(segmentC, 0);
      digitalWrite(segmentD, 1);
      digitalWrite(segmentE, 1);
      digitalWrite(segmentF, 1);
      digitalWrite(segmentG, 1); 
      break;
    case 15:
      digitalWrite(segmentA, 1);
      digitalWrite(segmentB, 0);
      digitalWrite(segmentC, 0);
      digitalWrite(segmentD, 0);
      digitalWrite(segmentE, 1);
      digitalWrite(segmentF, 1);
      digitalWrite(segmentG, 1); 
      break;
  }
}
