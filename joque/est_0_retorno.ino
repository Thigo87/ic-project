// ESTADO 0: Volta os 2 cavalos até o ponto de largada
void voltarParaLargada() {
  apagarTodosLEDs();
  displayLinha("Retornando...", 0);
  displayLinha("Aguarde largada", 1);

  bool chegou1 = false;
  bool chegou2 = false;

  while (!chegou1 || !chegou2) {
    // Cavalo 1
    if (!chegou1) {
      if (sensorAtivado(PIN_IR_LARGADA_1)) {
        chegou1 = true;
        desligarMotor1();
      } else {
        motor1.step(-DIR_FRENTE_1);
      }
    }

    // Cavalo 2
    if (!chegou2) {
      if (sensorAtivado(PIN_IR_LARGADA_2)) {
        chegou2 = true;
        desligarMotor2();
      } else {
        motor2.step(-DIR_FRENTE_2);
      }
    }
  }

  desligarMotor1();
  desligarMotor2();
}