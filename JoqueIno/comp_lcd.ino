// Função rápida para escrever uma linha no LCD
void displayLinha(String msg, int y) {
  while (msg.length() < 16) {
    msg += " ";
  }
  lcd.setCursor(0, y);
  lcd.print(msg.substring(0, 16));
}


// Mostra o texto de status dos cliques durante Esperando e Rodada
void mostrarStatusJogadores(bool ok1, bool ok2) {
  String s1 = ok1 ? "OK  " : "... ";
  String s2 = ok2 ? "OK  " : "... ";
  displayLinha("P1: " + s1 + "P2: " + s2, 1);
}


// Mostra o texto de resultado dos cliques durante Rodada
String textoResultado(bool clicou, long passos) {
  if (!clicou)     return "N/A";
  if (passos == 0) return "FORA";
  return "+" + String(passos);
}


// Função inteligente/econômica para mostrar relógio no LCD
int ultSeg  = -1;
int ultDec  = -1;
int ultCent = -1;

void iniciarTempoLCD() {
  ultSeg  = -1;
  ultDec  = -1;
  ultCent = -1;
  displayLinha("CONTEM E APERTEM", 0);
  displayLinha("Tempo:    ,     ", 1);
}

// Sobrescreve apenas caracteres sob demanda + retorna true quando o relógio é tapado
bool atualizarTempoLCD(long restante, long tempoTapar) {
  if (restante <= tempoTapar) {
    lcd.setCursor(9, 1);
    lcd.print("?,??");
    return true;
  }

  int r    = restante;
  int seg  = r / 1000;
  int dec  = (r / 100) % 10;
  int cent = (r / 10) % 10;

  if (seg != ultSeg) {
    lcd.setCursor(9, 1);
    lcd.print(seg);
    ultSeg = seg;
  }
  if (dec != ultDec) {
    lcd.setCursor(11, 1);
    lcd.print(dec);
    ultDec = dec;
  }
  if (cent != ultCent) {
    lcd.setCursor(12, 1);
    lcd.print(cent);
    ultCent = cent;
  }

  return false;
}