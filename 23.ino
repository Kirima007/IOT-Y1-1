void setup() {
  Serial.begin(115200);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  int Temp = analogRead(A0);
  Serial.println(Temp);
  if (Temp > 800){
    digitalWrite(9,0);
    digitalWrite(10,0);
    digitalWrite(11,0);
  }
  else if (Temp > 700){
    digitalWrite(9,0);
    digitalWrite(10,0);
    digitalWrite(11,1);
  }
  else if (Temp > 600){
    digitalWrite(9,0);
    digitalWrite(10,1);
    digitalWrite(11,0);
  }
  else if (Temp > 500){
    digitalWrite(9,1);
    digitalWrite(10,0);
    digitalWrite(11,0);
  }
}
