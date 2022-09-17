#define O OUTPUT
#define H HIGH
#define L LOW
int led[5] = {2, 3, 4, 5, 6};

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
