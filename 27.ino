void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A0));
  if (analogRead(A0)<220){
    digitalWrite(9,1);
  }
  else{digitalWrite(9,0);}
}
