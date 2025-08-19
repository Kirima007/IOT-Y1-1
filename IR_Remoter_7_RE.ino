#include <IRremote.hpp>    // Include the library
#define IR_RECEIVE_PIN 11  // IR receiver pin 11

int A;
int segmentA = 1;
int segmentB = 2;
int segmentC = 7;
int segmentD = 4;
int segmentE = 5;
int segmentF = 6;
int segmentG = 8;
int segmentDP = 3;

int digit1 = A1;
int digit2 = A2;
int digit3 = A3;
int digit4 = A4;

void setup() {
  Serial.begin(9600);                                     // Message will be sent to PC
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the receiver
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
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}
void loop() {
  if (IrReceiver.decode())  // Received IR signal
  {
    switch (IrReceiver.decodedIRData.protocol) {
      case NEC: Serial.print("NEC: "); break;
      case SONY: Serial.print("SONY: "); break;
      case SHARP: Serial.print("SHARP: "); break;
      case PANASONIC: Serial.print("PANASONIC: "); break;
      case JVC: Serial.print("JVC: "); break;
      case RC5: Serial.print("Philips RC5: "); break;
      case RC6: Serial.print("Philips RC6: "); break;
      case DENON: Serial.print("DENON: "); break;
      case SAMSUNG: Serial.print("SAMSUNG: "); break;
      case LG: Serial.print("LG: "); break;
      case UNKNOWN: Serial.print("UNKNOWN: "); break;
    }
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print raw data
    IrReceiver.resume();                                           // Enable receiving of the next value
  }
    displayNumber(1, (IrReceiver.decodedIRData.decodedRawData / 0x0FFFFFFF) % 16);
    displayNumber(2, (IrReceiver.decodedIRData.decodedRawData / 0x00FFFFFF) % 16);
    displayNumber(3, (IrReceiver.decodedIRData.decodedRawData / 0x000FFFFF) % 16);
    displayNumber(4, (IrReceiver.decodedIRData.decodedRawData / 0x0000FFFF) % 16);
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