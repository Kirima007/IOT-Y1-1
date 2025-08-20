//declare variables for the motor pins
int motorPin1 = 11;  // Blue
int motorPin2 = 10;  // Pink
int motorPin3 = 9;   // Yellow
int motorPin4 = 8;   // Orange
// Red
int motorSpeed = 1275;  //variable to set stepper speed
int stepCount = 0;   // number of steps the motor has taken
void setup() {
  pinMode(motorPin1, OUTPUT);  //declare the motor pins as outputs
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(13, INPUT_PULLUP);
  Serial.begin(115200);  // initialize the serial port:
}
void loop() {
  // wavedrive();  // จ่ายไฟให้ทำงานครั้งละ 1 ขด
  // fullstep();   // จ่ายไฟให้ทำงานครั้งละ 2 ขด
  if (digitalRead(13)) {
    fullstep1();  // ใช้ทั้งสองแบบรวมกันทำให้หมุนได้ครั้งละครึ่งเสตป
  } else {
    fullstep2();
  }
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  //delayMicroseconds(500);
}

void fullstep1() {
  // 1
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delayMicroseconds(motorSpeed);
  // 2
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, LOW);
  delayMicroseconds(motorSpeed);
  // 3
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, HIGH);
  delayMicroseconds(motorSpeed);
  // 4
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, HIGH);
  delayMicroseconds(motorSpeed);
}

void fullstep2() {
  // 4
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, HIGH);
  delayMicroseconds(motorSpeed);
  // 3
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, HIGH);
  delayMicroseconds(motorSpeed);
  // 2
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, LOW);
  delayMicroseconds(motorSpeed);
  // 1
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delayMicroseconds(motorSpeed);
}