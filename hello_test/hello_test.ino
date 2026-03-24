#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  u8g2.begin();
}

void loop() {
  u8g2.clearBuffer();

  // Set font
  u8g2.setFont(u8g2_font_ncenB14_tr);

  // Centered text
  u8g2.drawStr(10, 30, "Hello");
  u8g2.drawStr(10, 55, "World");

  u8g2.sendBuffer();

  delay(1000);
}