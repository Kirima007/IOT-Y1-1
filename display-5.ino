#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
void setup() {
  matrix.begin();
}
const uint32_t HI[] = {
  0xCD8CD8CD,
  0x8FD8FD8C,
  0xD8CD8CD8
};
const uint32_t IH[] = {
  0xCD8CD8CD,
  0x8CF8CF8C,
  0xD8CD8CD8
};
void loop() {
  matrix.loadFrame(HI);
  delay(500);
  matrix.loadFrame(IH);
  delay(500);
}