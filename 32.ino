#define R0 10000.00
#define R1 10000.00
#define T0 298.15
#define B 3435.00

#define PinTemp A0
void setup() {
  Serial.begin(115200);
}
float Temperature_get() {
  float sample = analogRead(PinTemp);
  float R = R1 * (sample / (1023.0 - sample));
  // Serial.print("R: ");
  // Serial.print(R);
  
  float T = 1.0 / ((1.0 / T0) + (1.0 / B) * (log(R / R0)));
  // Serial.print("          Temp: ");
  // Serial.println(T-273.15);
  return T-273.15;
}
void loop() {
  int i ,time = millis();
  float avg=0 ;
  for(i=0;millis()-time<500;i++){
    avg += Temperature_get();
  }
   Serial.println(avg/i);
}
