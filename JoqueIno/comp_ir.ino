bool sensorAtivado(int pino) {
  return (digitalRead(pino) == SENSOR_ATIVO);
}