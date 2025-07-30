#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
uint8_t frame[8][12] = {
  { 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0 },
  { 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0 },
  { 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0 },
  { 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0 },
  { 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0 },
  { 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0 }
};
void setup() {
  matrix.begin();
}
void smile() {
  frame[4][3] = 1;
  frame[4][8] = 1;
}
void face() {
  frame[4][3] = 0;
  frame[4][8] = 0;
}
void loop() {
  // face();
  matrix.renderBitmap(frame, 8, 12);
  // delay(1000);

  // smile();
  matrix.renderBitmap(frame, 8, 12);
  // delay(1000);
}