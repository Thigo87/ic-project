#include <Stepper.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// =========================================================================
// COMPONENTES E PINOS
// =========================================================================
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int PASSOS_VOLTA = 2048;

// Pinos dos motores (IN1, IN3, IN2, IN4)
const int M1_P1 = 8, M1_P2 = 10, M1_P3 = 9, M1_P4 = 11;
const int M2_P1 = 2, M2_P2 = 4,  M2_P3 = 3, M2_P4 = 5;

Stepper motor1(PASSOS_VOLTA, M1_P1, M1_P2, M1_P3, M1_P4);
Stepper motor2(PASSOS_VOLTA, M2_P1, M2_P2, M2_P3, M2_P4);

// Pinos dos botões
const int PIN_BOTAO_1 = 18;
const int PIN_BOTAO_2 = 19;

// Pinos dos sensores
const int PIN_IR_LARGADA_1 = 22;
const int PIN_IR_LARGADA_2 = 24;
const int PIN_IR_CHEGADA_1 = 23;
const int PIN_IR_CHEGADA_2 = 25;

// Pinos dos LEDs
const int PIN_LED_LARGADA_1 = 30;
const int PIN_LED_LARGADA_2 = 31;
const int PIN_LED_LARGADA_3 = 32;
const int PIN_LED_VITORIA_1 = 34;
const int PIN_LED_VITORIA_2 = 35;

// =========================================================================
// CALIBRAÇÃO
// =========================================================================
const int  DIR_FRENTE_1      = 1;    // -1 para inverter
const int  DIR_FRENTE_2      = 1;    // -1 para inverter
const int  BOTAO_ATIVO       = LOW;
const int  SENSOR_ATIVO      = LOW; 
const int  VELOCIDADE_RPM    = 12;
const long PASSOS_MAX_RODADA = 600;
const long PASSOS_MIN_RODADA = 100;

// =========================================================================
// VARIÁVEIS GLOBAIS
// =========================================================================
int  estadoAtual   = 0;
int  vencedor      = 0; // 0->ninguém; 1->P1; 2->P2; 3->empate
long passosRodada1 = 0;
long passosRodada2 = 0;

// =========================================================================
// SETUP e LOOP
// =========================================================================
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));

  motor1.setSpeed(VELOCIDADE_RPM);
  motor2.setSpeed(VELOCIDADE_RPM);

  pinMode(PIN_BOTAO_1, INPUT_PULLUP);
  pinMode(PIN_BOTAO_2, INPUT_PULLUP);

  pinMode(PIN_IR_LARGADA_1, INPUT);
  pinMode(PIN_IR_LARGADA_2, INPUT);
  pinMode(PIN_IR_CHEGADA_1, INPUT);
  pinMode(PIN_IR_CHEGADA_2, INPUT);

  pinMode(PIN_LED_LARGADA_1, OUTPUT);
  pinMode(PIN_LED_LARGADA_2, OUTPUT);
  pinMode(PIN_LED_LARGADA_3, OUTPUT);
  pinMode(PIN_LED_VITORIA_1, OUTPUT);
  pinMode(PIN_LED_VITORIA_2, OUTPUT);

  lcd.init();
  lcd.backlight();
  displayLinha("   JoqueIno!    ", 0);
  displayLinha("  iniciando...  ", 1);
  delay(500);
}

void loop() {
  switch (estadoAtual) {
    case 0: // Retorno
      voltarParaLargada();
      estadoAtual = 1;
      break;

    case 1: // Esperando P1 e P2 confirmarem
      esperarJogadores();
      estadoAtual = 2;
      break;

    case 2: // Semáforo
      semaforoLargada();
      estadoAtual = 3;
      break;

    case 3: // Rodada
      rodadaContagem();
      estadoAtual = 4;
      break;

    case 4: // Movimentanção + checagem de chegada
      vencedor = moverCavalos();
      if (vencedor == 0) {
        estadoAtual = 3; // Ninguém venceu ainda: nova rodada
      } else {
        estadoAtual = 5; // Alguém venceu: vai para a comemoração
      }
      break;

    case 5: // Comemoração + reinicío
      comemorarVitoria(vencedor);
      vencedor = 0;
      estadoAtual = 0;
      break;
  }
}