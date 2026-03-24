#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const int numStars = 50;
float starX[numStars], starY[numStars], starZ[numStars];

void setup() {
  u8g2.begin();
  // Initialize stars at random positions
  for (int i = 0; i < numStars; i++) {
    starX[i] = random(-64, 64);
    starY[i] = random(-32, 32);
    starZ[i] = random(1, 128);
  }
}

void loop() {
  u8g2.clearBuffer();
  
  for (int i = 0; i < numStars; i++) {
    // Move star closer
    starZ[i] -= 2;
    if (starZ[i] <= 0) starZ[i] = 128; // Reset star to back

    // Perspective projection
    int x = 64 + (starX[i] * 128 / starZ[i]);
    int y = 32 + (starY[i] * 128 / starZ[i]);

    // Draw only if on screen
    if (x >= 0 && x < 128 && y >= 0 && y < 64) {
      // Size gets bigger as it gets "closer"
      int size = (starZ[i] < 40) ? 2 : 1;
      u8g2.drawDisc(x, y, size);
    }
  }

  u8g2.setFont(u8g2_font_unifont_t_symbols);
  u8g2.drawGlyph(5, 60, 0x2605); // Draw a little star icon
  u8g2.sendBuffer();
}