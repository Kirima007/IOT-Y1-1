#include <WiFi.h>
#include <WiFiClient.h>
// ตั้งค่า WiFi SSID PASSWORD
const char* ssid = "NG-00"; // ใส่ชื่อ WiFi
const char* password = "00000000"; // ใส่รหัสผ่าน WiFi
// ตั้งค่า URL ที่ต้องการเรียกข้อมูล
const char* host = "192.168.137.1"; // ใส่ชื่อโดเมนหรือ IP ของเซิร์ฟเวอร์
const int httpPort = 1880; // พอร์ต HTTP (ส่วนใหญ่จะใช้ 1880)
// ตั้งค่าเส้นทาง URL
String urlPath = "/analog"; // เส้นทางของข้อมูลที่ต้องการดึงจากเซิร์ฟเวอร์
WiFiClient client;
void setup() {
 Serial.begin(115200);
 WiFi.begin(ssid, password);
 Serial.print("Connecting to WiFi");
 while (WiFi.status() != WL_CONNECTED) {
 delay(1000);
 Serial.print(".");
 }
 Serial.println(" Connected!");
 pinMode(8,OUTPUT);
}
void loop() {
 // วนลูปซ้ำถ้าต้องการอัปเดตข้อมูล
 if (WiFi.status() == WL_CONNECTED) {
 Serial.println("Connecting to server...");

 // เชื่อมต่อไปยังเซิร์ฟเวอร์ที่ระบุ
 if (client.connect(host, httpPort)) {
 Serial.println("Connected to server!");
 // สร้างคำขอ HTTP GET
 client.println("GET " + urlPath + " HTTP/1.1");
 client.println("Host: " + String(host));
 client.println("Connection: close");
 client.println(); // สิ้นสุดส่วน header ของคำขอ HTTP
 // อ่านการตอบกลับจากเซิร์ฟเวอร์
 while (client.connected() || client.available()) {
 if (client.available()) {
 String line = client.readStringUntil('\n');
 Serial.println(line); // แสดงผลการตอบกลับใน Serial Monitor
//  if (line == "ON") digitalWrite(8,1);
 
//  else if (line == "OFF") digitalWrite(8,0);
//  }
 }
 client.stop(); // ปิดการเชื่อมต่อกับเซิร์ฟเวอร์
 } else {
 Serial.println("Connection to server failed");
 }
 } else {
 Serial.println("WiFi not connected");
 }
}
