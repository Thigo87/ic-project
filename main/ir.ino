int leitura;

int leituraSensor(int pino){
  leitura = digitalRead(pino);

  return leitura;
}