#define trig 8
#define echo 9
#define forward 0
#define left 1
#define right 2
#define stp 3
long duration = 0, distance = 0;
byte IN[] = {4, 5, 6, 7};
byte moving[4][4] =
{ {1, 0, 1, 0}, //forward
  {0, 0, 1, 0}, //left
  {1, 0, 0, 0}, //right
  {0, 0, 0, 0}  //stp
};
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
  for (int i = 4; i <= 9; i++)
    pinMode(i, OUTPUT);
  pinMode(echo, INPUT);

}
void loop() {
  if (ultrasonic(trig, echo) > 25) {
    for (int i = 0; i <= 3; i++)
      digitalWrite(IN[i], moving[forward][i]);
  }
  else {
    for (int i = 0; i <= 3; i++)
      digitalWrite(IN[i], moving[stp][i]);
    delay(250);
    for (int i = 0; i <= 3; i++)
      digitalWrite(IN[i], moving[right][i]);
    delay(500);
  }
}
