// ESTADO 4: Avança os 2 cavalos juntos e retorna quem venceu (0 enquanto ninguém vencer)
int moverCavalos() {
  int ganhador = 0; // 0->ninguém; 1->P1; 2->P2; 3->empate
  bool cruzou1 = false;
  bool cruzou2 = false;

  while (passosRodada1 > 0 || passosRodada2 > 0) {
    // Cavalo 1
    if (passosRodada1 > 0) {
      if (sensorAtivado(PIN_IR_CHEGADA_1)) {
        cruzou1 = true;
        passosRodada1 = 0;
        desligarMotor1();
      } else {
        motor1.step(DIR_FRENTE_1);
        passosRodada1--;
        if (sensorAtivado(PIN_IR_CHEGADA_1)) {
          cruzou1 = true;
          passosRodada1 = 0;
          desligarMotor1();
        }
      }
    }

    // Cavalo 2
    if (passosRodada2 > 0) {
      if (sensorAtivado(PIN_IR_CHEGADA_2)) {
        cruzou2 = true;
        passosRodada2 = 0;
        desligarMotor2();
      } else {
        motor2.step(DIR_FRENTE_2);
        passosRodada2--;
        if (sensorAtivado(PIN_IR_CHEGADA_2)) {
          cruzou2 = true;
          passosRodada2 = 0;
          desligarMotor2();
        }
      }
    }

    // Registra o primeiro cavalo que cruzar a chegada (MUDAR ESSA LÓGICA DEPOIS, NÃO ESTÁ OTIMIZADA)
    if (ganhador == 0) {
      if (cruzou1 && cruzou2) ganhador = 3;
      else if (cruzou1)       ganhador = 1;
      else if (cruzou2)       ganhador = 2;

      if (ganhador == 1 || ganhador == 3) {LigarLED(PIN_LED_VITORIA_1);}
      if (ganhador == 2 || ganhador == 3) {LigarLED(PIN_LED_VITORIA_2);}
    }
  }

  desligarMotor1();
  desligarMotor2();

  if (ganhador == 0) {delay(1000);} // Pausa rápida antes da próxima rodada
  return ganhador;
}