// ESTADO 1: Espera P1 e P2 apertarem o botão para confirmar "Pronto"
void esperarJogadores() {
  bool pronto1 = false;
  bool pronto2 = false;

  displayLinha("Pressione botao", 0);
  mostrarStatusJogadores(pronto1, pronto2);

  while (!pronto1 || !pronto2) {
    if (!pronto1 && botaoPressionado(PIN_BOTAO_1)) {
      pronto1 = true;
      LigarLED(PIN_LED_VITORIA_1);
      mostrarStatusJogadores(pronto1, pronto2);
    }

    if (!pronto2 && botaoPressionado(PIN_BOTAO_2)) {
      pronto2 = true;
      LigarLED(PIN_LED_VITORIA_2);
      mostrarStatusJogadores(pronto1, pronto2);
    }

    delay(20);
  }

  delay(400);
  apagarTodosLEDs();
}