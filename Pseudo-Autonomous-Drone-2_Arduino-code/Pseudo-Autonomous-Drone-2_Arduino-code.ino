#include "Wire.h"
#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#define S0 5
#define S1 4
#define S2 3
#define S3 2
#define playBtn 6
#define omniBtn 7
#define entropyBtn 8
#define screenBtn 9
#define SIG A0
#define I2C_ADDR 0x3F  // Add your address here.
#define BACKLIGHT_PIN 3
//Analog pin4  TO SDA
//Analog pin5 TO SCL
LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7);

//void serialPotValues() {
//  for (int i = 0; i < potCount; i ++) {
//    Serial.print(i);
//    Serial.print(":");
//    Serial.print(potValue[i]);
//    Serial.print("/ ");
//  }
//  Serial.println();
//}
