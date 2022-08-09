#define sensorR 3
#define sensorL 4
#define speedR 10
#define speedL 11
byte IN[]={6,7,8,9};
byte moving[4]={1,0,1,0}; 
void setup() {
  for (int i=6;i<=11;i++)
    pinMode(i,OUTPUT);
    pinMode(sensorR,INPUT);
    pinMode(sensorL,INPUT);
    }
void loop() {
digitalWrite(IN[0], moving[0]&digitalRead(sensorL));
digitalWrite(IN[2], moving[2]& digitalRead(sensorR));
digitalWrite(IN[1],0);
digitalWrite(IN[3],0);
analogWrite(speedL,80* digitalRead(sensorR));
analogWrite(speedR,80*digitalRead(sensorL));
}
