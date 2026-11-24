// ESTADO 5: Exibe vencedor e pisca LED antes do retorno
void comemorarVitoria(int ganhador) {
  if (ganhador == 1)      {displayLinha("  VENCEDOR: P1  ", 0);
                           displayLinha("   Parabens!!   ", 1);}
  else if (ganhador == 2) {displayLinha("  VENCEDOR: P2  ", 0);
                           displayLinha("   Parabens!!   ", 1);}
  else                    {displayLinha("     EMPATE     ", 0);
                           displayLinha(" evento raro... ", 1);}
  

  // Piscas de comemoração
  for (int c = 0; c < 6; c++) {
    if (ganhador == 1 || ganhador == 3) {LigarLED(PIN_LED_VITORIA_1);}
    if (ganhador == 2 || ganhador == 3) {LigarLED(PIN_LED_VITORIA_2);}
    delay(150);

    ApagarLED(PIN_LED_VITORIA_1);
    ApagarLED(PIN_LED_VITORIA_2);
    delay(150);
  }
}