// ESTADO 3: Rodada - conta de "duracao" até 0, registra cliques e calcula os passos dos cavalos
void rodadaContagem() {
  long duracao    = random(1000, 1500); // Entre 1.0s e 1.5s
  long tempoTapar = random(500, 800);   // Tapa quando faltar entre 0.50s e 0.80s
  long alvoZero   = millis() + duracao;
  long ultimoLCD  = 0;

  bool clicou1 = false;
  bool clicou2 = false;
  bool tapado  = false;
  long tempoClique1 = 0;
  long tempoClique2 = 0;

  iniciarTempoLCD();

  // Roda até os dois clicarem OU passar 250ms do zero
  while (!(clicou1 && clicou2) && (long)(alvoZero - millis()) > -250) {
    long agora = millis();

    if (!clicou1 && botaoPressionado(PIN_BOTAO_1)) {
      tempoClique1 = agora;
      clicou1 = true;
    }

    if (!clicou2 && botaoPressionado(PIN_BOTAO_2)) {
      tempoClique2 = agora;
      clicou2 = true;
    }

    if (!tapado && (agora - ultimoLCD >= 10)) {
      ultimoLCD = agora;
      tapado = atualizarTempoLCD(alvoZero - agora, tempoTapar);
    }
  }

  passosRodada1 = calcularPassos(clicou1, tempoClique1, alvoZero, duracao);
  passosRodada2 = calcularPassos(clicou2, tempoClique2, alvoZero, duracao);

  String resumo1 = textoResultado(clicou1, passosRodada1);
  String resumo2 = textoResultado(clicou2, passosRodada2);

  displayLinha("P1:" + resumo1 + " P2:" + resumo2, 0);
  displayLinha("Avancando...    ", 1);
}