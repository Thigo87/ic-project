// ESTADO 2: Semafóro de transição
void semaforoLargada() {
  displayLinha("   PREPARAR!    ", 0);

  LigarLED(PIN_LED_LARGADA_1);
  displayLinha("       3        ", 1);
  delay(800);

  LigarLED(PIN_LED_LARGADA_2);
  displayLinha("       2        ", 1);
  delay(800);

  LigarLED(PIN_LED_LARGADA_3);
  displayLinha("       1        ", 1);
  delay(800);

  displayLinha("    LARGADA!    ", 0);
  displayLinha("    VALENDO!    ", 1);
  delay(500);
  apagarTodosLEDs();
}