#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define buz 6

void setup(){
  Serial.begin(9600);
  Serial.println(F("DHT11 test!\n"));
  dht.begin();
  lcd.init(); // initialize the lcd
  lcd.backlight();
}
int time1 = millis();
bool st = 0 ;
float h ,t ;

void loop(){
  if (millis()-time1 >= 1000){
  h = dht.readHumidity();
  t = dht.readTemperature();
  }
  if  (t > 33){
    h = dht.readHumidity();
    t = dht.readTemperature();
    Serial.print("Humidity : ");
    Serial.print(h);
    Serial.print("      Temperature : ");
    Serial.println(t);
    lcd.clear(); // clear display
    lcd.setCursor(4, 0); // move cursor to (0, 0)
    lcd.print("ALERT !!!"); // print message at (0, 0)
    for (int i = 2000 ; i > 1000 ; i--){
      tone(buz,i);
      delay(1);
    }
    noTone(buz); // หยุดเสียง
    delay(1000); // รอ 1วินาที
    }

  else {
    if (millis() - time1 >= 2000) {
    st = !st ; 
    time1 = millis();
    switch (st) {
    case 0 :
      h = dht.readHumidity();
      t = dht.readTemperature();
      Serial.print("Humidity : ");
      Serial.print(h);
      Serial.print("      Temperature : ");
      Serial.println(t);
      lcd.clear(); // clear display
      lcd.setCursor(0, 0); // move cursor to (0, 0)
      lcd.print("Temp :"); // print message at (0, 0)
      lcd.setCursor(6, 0); // move cursor to (2, 1)
      lcd.print(t); // print message at (2, 1)
      lcd.print(" C"); // print message at (0, 0)
      lcd.setCursor(0, 1); // move cursor to (0, 0)
      lcd.print("Humi :"); // print message at (0, 0)
      lcd.setCursor(6, 1); // move cursor to (2, 1)
      lcd.print(h); // print message at (2, 1)
      lcd.print(" %"); // print message at (0, 0)
      break;
    case 1 :
      lcd.clear(); // clear display
      lcd.setCursor(0, 0); // move cursor to (0, 0)
      lcd.print("Weerapat"); // print message at (0, 0)
      lcd.setCursor(0, 1); // move cursor to (0, 0)
      lcd.print("68050514"); // print message at (0, 0)
      break;
    }
    }
  }
  
} 