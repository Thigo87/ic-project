void LigarLED(int pino) {
  digitalWrite(pino, HIGH);
}


void ApagarLED(int pino) {
  digitalWrite(pino, LOW);
}


void apagarTodosLEDs() {
  digitalWrite(PIN_LED_LARGADA_1, LOW);
  digitalWrite(PIN_LED_LARGADA_2, LOW);
  digitalWrite(PIN_LED_LARGADA_3, LOW);
  digitalWrite(PIN_LED_VITORIA_1, LOW);
  digitalWrite(PIN_LED_VITORIA_2, LOW);
}
