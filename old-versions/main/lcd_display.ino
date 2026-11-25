void displayMSG(String msg, int x, int y) { //função que mostra uma mensagem msg no display na posição (x, y)
  Serial.begin(9600);
  lcd.setCursor(x, y);
  lcd.print(msg);
}