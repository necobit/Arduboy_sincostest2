//Arduboyで三角関数のお勉強です。
//奇数のサイン波を足し算していく変化が見られます。

#include "Arduboy.h"
Arduboy arduboy;

int mx = 0;
int my = 20;
int oy = 32;
int i;
int lp = 1;

void setup() {
//  Serial.begin(115200);
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.clear();
  arduboy.setCursor(0, 0);
  arduboy.print("1");
}

void loop() {
  i = i + 5;
  if (i >= 359) i = 0;
  my = 0;
  float rad = PI * i / 180.000 ;
  for (int N = lp; N >= 1; N --) {
    my = my + (sin(((2 * N) - 1) * rad) / (float)((2 * N) - 1)) * 20;
  }
  mx ++;
  if (mx <= 0) mx = 0;
  if (mx >= 128) {
    mx = 0;
    arduboy.clear();
    lp ++;
    if (lp > 20) lp = 1;
    arduboy.setCursor(0, 0);
    arduboy.print(lp);
  }
  arduboy.fillCircle(mx, my + oy , 1, WHITE);
  arduboy.display();
  //  delay(10);
}