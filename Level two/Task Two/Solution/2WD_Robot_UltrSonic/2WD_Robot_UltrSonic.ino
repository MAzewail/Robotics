#define IN1 6
#define IN3 7
#define trig 8
#define echo 9
long duration = 0, distance = 0;
long ultrasonic(byte trigpin, byte echopin) {
  digitalWrite(trigpin, 0);
  delayMicroseconds(2);
  digitalWrite(trigpin, 1);
  delayMicroseconds(10);
  digitalWrite(trigpin, 0);
  duration = pulseIn(echopin, 1);
  distance = (duration / 2) * 0.0343;
  return distance;
}
void setup() {
  for (int i = 6; i <= 8; i++)
    pinMode(i, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(IN1, 1);
}
void loop() {
  if (ultrasonic(trig, echo) > 25) {
    digitalWrite(IN3, 1);
  }
  else {
    digitalWrite(IN3, 0);
    delay(500);
  }
}
