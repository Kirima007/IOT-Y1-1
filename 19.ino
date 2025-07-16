void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int Temp = analogRead(A0);
  Serial.println(Temp);
  if (Temp <= 10 ){
    digitalWrite(9,1);
    digitalWrite(10,0);
  }
  else{
    digitalWrite(9,0);
    digitalWrite(10,1);
  }
}
