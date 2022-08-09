#define sensorR 3
#define sensorL 4
#define speedR 10
#define speedL 11
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9

void setup() {
  for (int i=6;i<=11;i++){
    pinMode(i,OUTPUT);}
    pinMode(sensorR,INPUT);
    pinMode(sensorL,INPUT);
}

void loop() {
digitalWrite(IN1, digitalRead(sensorL)); digitalWrite(IN3, digitalRead(sensorR));
digitalWrite(IN2, 0); digitalWrite(IN4, 0);
analogWrite(speedL,120* digitalRead(sensorR)); analogWrite(speedR,120*digitalRead(sensorL));
}
