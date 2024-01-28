#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/// Define the I2C address of the LCD
const int LCD_ADDR = 0x27;

/// Initialize the LCD with I2C interface
LiquidCrystal_I2C lcd(LCD_ADDR, 20, 4);

/// Prints a text in the first line of the LCD
void printA(const char *text) {
  lcd.setCursor(0, 0);
  lcd.print(text);
}

/// Prints a text in the first line of the LCD in a given position
void printA(const char *text, uint8_t pos) {
  lcd.setCursor(pos, 0);
  lcd.print(text);
}

/// Prints a text in the second line of the LCD
void printB(const char *text) {
  lcd.setCursor(0, 1);
  lcd.print(text);
}

/// Prints a text in the second line of the LCD in a given position
void printB(const char *text, uint8_t pos) {
  lcd.setCursor(pos, 1);
  lcd.print(text);
}

/// Prints a text in the third line of the LCD
void printC(const char *text) {
  lcd.setCursor(0, 2);
  lcd.print(text);
}

/// Prints a text in the third line of the LCD in a given position
void printC(const char *text, uint8_t pos) {
  lcd.setCursor(pos, 2);
  lcd.print(text);
}

/// Prints a text in the fourth line of the LCD
void printD(const char *text) {
  lcd.setCursor(0, 3);
  lcd.print(text);
}

/// Prints a text in the fourth line of the LCD in a given position
void printD(const char *text, uint8_t pos) {
  lcd.setCursor(pos, 3);
  lcd.print(text);
}

/// Prints the values after reading from the sensors
void print(float level, float temp, float pH) {
  char lbuf[10];
  char tbuf[10];
  char pbuf[10];

  char *l = dtostrf(level, 4, 2, lbuf);
  strcat(lbuf, "cm");

  char *t = dtostrf(temp, 4, 2, tbuf);
  strcat(tbuf, "C");

  char *p = dtostrf(pH, 4, 2, pbuf);

  printA("       ", 13);
  printA(l, 13);
  printB("           ", 6);
  printB(t, 6);
  printC("          ", 10);
  printC(p, 10);
}

/// Setup the LCD display
void setupDisplay() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();

  printA(" Arduino Uno Water");
  printB(" Quality Monitoring");
  printC("System Temperature &");
  printD("    pH Detector     ");
  delay(5000);
  lcd.clear();

  printA("Water level: ");
  printB("Temp: ");
  printC("pH value: ");
}