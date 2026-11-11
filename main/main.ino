#include <Stepper.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int stepsPerRevolution = 2048;
const int botaoPorta = 53;
const int sensor = 11;

Stepper meuMotor(stepsPerRevolution, 7, 9, 8, 10);
Stepper meuMotor2(stepsPerRevolution, 2, 4, 3, 5);

int valorBotaoAnterior = 0;

void setup() {
  Serial.begin(9600);
  meuMotor.setSpeed(15);
  meuMotor2.setSpeed(15);
  pinMode(botaoPorta, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  displayMSG("Hello", 0, 0);
  pinMode(sensor, INPUT);
}

void loop() {
  /*meuMotor.step(stepsPerRevolution);
  delay(1000);

  meuMotor.step(-stepsPerRevolution);
  delay(1000);*/

  /*meuMotor.step(40);
  delay(100);*/
  displayMSG(String (valorBotaoAnterior), 0, 0);
  int valorBotao = digitalRead(botaoPorta);
  if (!valorBotao and !valorBotaoAnterior) {
    Serial.print(1); valorBotaoAnterior = 1;
    displayMSG(String (valorBotao), 0, 1);
    meuMotor.step(60);
    }
  if (valorBotao) {valorBotaoAnterior = 0;}
  delay(1);

  /*for (int i = 5; i >= 0; i--) {
    displayMSG(String(i), 0, 0);
  } 
  displayMSG("Sensor output:", 0, 0);
  displayMSG(String(leituraSensor(sensor)), 0, 1);
  */
}