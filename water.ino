#define printInterval 800

float pHValue;

void setup() {
  setupDisplay();
  setupTemp();
  setupLevel();
}

void loop() {
  float level = readLevel();
  float temp = readTemp();
  readPH();

  static unsigned long printTimepoint = millis();
  if (millis() - printTimepoint > printInterval) {
    printTimepoint = millis();

    print(level, temp, pHValue);
  }
}
