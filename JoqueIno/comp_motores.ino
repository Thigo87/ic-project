// Desliga as bobinas dos motores para evitar aquecimento
void desligarMotor1() {
  digitalWrite(M1_P1, LOW);
  digitalWrite(M1_P2, LOW);
  digitalWrite(M1_P3, LOW);
  digitalWrite(M1_P4, LOW);
}

void desligarMotor2() {
  digitalWrite(M2_P1, LOW);
  digitalWrite(M2_P2, LOW);
  digitalWrite(M2_P3, LOW);
  digitalWrite(M2_P4, LOW);
}


// Converte a precisão temporal em número de passos (curva quadrática)
long calcularPassos(bool clicou, unsigned long tempoClique, unsigned long alvoZero, unsigned long duracao) {
  if (!clicou) return 0;

  long erro = (long)(alvoZero - tempoClique);
  if (erro < 0) return 0; // Apertou depois do zero ("queimou")

  float precisao = 1.0 - ((float)erro / duracao);
  precisao = constrain(precisao, 0.0, 1.0);
  return PASSOS_MIN_RODADA + (long)((PASSOS_MAX_RODADA - PASSOS_MIN_RODADA) * precisao * precisao);
}
