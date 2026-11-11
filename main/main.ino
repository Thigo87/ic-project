#include <Stepper.h>

const int stepsPerRevolution = 2048;
const int botaoPorta = 53;

Stepper meuMotor(stepsPerRevolution, 8, 10, 9, 11);
Stepper meuMotor2(stepsPerRevolution, 2, 4, 3, 5);

int valorBotaoAnterior = 0;

void setup() {
  Serial.begin(9600);
  meuMotor.setSpeed(15);
  meuMotor2.setSpeed(15);
  pinMode(botaoPorta, INPUT_PULLUP); 
  displayMSG("Hello", 0, 0);
}

void loop() {
  /*meuMotor.step(stepsPerRevolution);
  delay(1000);

  meuMotor.step(-stepsPerRevolution);
  delay(1000);*/

  /*meuMotor.step(40);
  delay(100);*/

  /*int valorBotao = digitalRead(botaoPorta);
  if (!valorBotao and !valorBotaoAnterior) {
    Serial.print(1); valorBotaoAnterior = 1; 
    meuMotor.step(60); meuMotor2.step(60);
    }
  if (valorBotao) {valorBotaoAnterior = 0;}
  delay(1);*/

  /*for (int i = 5; i >= 0; i--) {
    displayMSG(String(i), 0, 0);
  } */

}