#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void displayMSG(String msg, int x, int y) { //função que mostra uma mensagem msg no display na posição (x, y)
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(x, y);
  lcd.print(msg);
}