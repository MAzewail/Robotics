#define O OUTPUT
#define H HIGH
#define L LOW
int led[5] = {9, 10, 11, 12, 13};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(*(led + i), OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(*(led + i), H);
  }
  delay(250);
  for (int i = 4; i >= 0; i--) {
    digitalWrite(*(led + i), L);
  }
  delay(250);
}
