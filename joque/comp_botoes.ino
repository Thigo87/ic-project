bool botaoPressionado(int pino) {
  return (digitalRead(pino) == BOTAO_ATIVO);
}