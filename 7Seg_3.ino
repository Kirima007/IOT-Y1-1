// 4 digit 7 segment display
int segmentA = A0;
int segmentB = A1;
int segmentC = A2;
int segmentD = 2;
int segmentE = 4;
int segmentF = 7;
int segmentG = 8;
int segmentDP = 13;
int Min = 0 , Max = 9 , number=0;
bool ledst = 0;
int time;
void setup() {
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentDP, OUTPUT);
  pinMode(12, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {f
  displayNumber();
  Serial.println(number);
}

void displayNumber() {
  if (!digitalRead(12))number--;
  else number++;
  
  if(number<Min)number=Max;
  if(number>Max)number=Min;
  displaySegment(number);
  delay(500);
}

void displaySegment(int numberToDisplay) {
  switch (numberToDisplay) {
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
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 2:  // แสดงผลเลข 2
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;
    case 3:  // แสดงผลเลข 3
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
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