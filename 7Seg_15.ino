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

#define R_var A0
#define R0 10000.00
#define R1 10000.00
#define T0 298.15
#define B 3435.00

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
  Serial.begin(115200);
}
float avg=0 , avg_temp=0;
int i=0 ,time = millis();
void loop() {
  float sample = analogRead(R_var);
  float R = R1 * (sample / (1023.0 - sample));
  float T = 1.0 / ((1.0 / T0) + (1.0 / B) * (log(R / R0)));
  T = T-273.15;
  if(millis()-time>=250){
    avg_temp = avg/i;
    i=0;
    avg = 0;
    time = millis();
  }
  i++;
  avg += T;
  int displayValue = (int)(avg_temp*100.0);
  digitalWrite(segmentDP, 0);
  displayNumber(1,displayValue /1000);
  digitalWrite(segmentDP, 1);
  displayNumber(2,(displayValue/100) %10);
  digitalWrite(segmentDP, 0);
  displayNumber(3,(displayValue/10) %10);
  digitalWrite(segmentDP, 0);
  displayNumber(4,displayValue %10);
  Serial.println(avg_temp);
}

// void displayAll(int i, int j, int k, int l) {
//   //int time = millis();
//   //while (millis() - time <= Delay || Delay == 0) {
//     displayNumber(1, i);
//     displayNumber(2, j);
//     displayNumber(3, k);
//     displayNumber(4, l);
//   //}
// }

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
      digitalWrite(segmentA, 0);
      digitalWrite(segmentB, 0);
      digitalWrite(segmentC, 0);
      digitalWrite(segmentD, 0);
      digitalWrite(segmentE, 0);
      digitalWrite(segmentF, 0);
      digitalWrite(segmentG, 0);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      digitalWrite(A3, 0);
      digitalWrite(A4, 0);
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
  }
}