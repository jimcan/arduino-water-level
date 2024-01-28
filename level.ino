/// Height of the container in cm
const int CONTAINER_HEIGHT = 25;

/// Define the pins for the HC-SR04 ultrasonic sensor
const int TRIG_PIN = 3;
const int ECHO_PIN = 4;

/// Setup the Level indicator (Ultrasonic Sensor)
void setupLevel() {
  // Initialize the HC-SR04 ultrasonic sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

/// Read the water level
float readLevel() {  
  // Read the distance value from the HC-SR04 sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  float duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;
  float level = CONTAINER_HEIGHT - distance;

  return level > 0 ? level : 0;
}