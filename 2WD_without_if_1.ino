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
moving[0]=digitalRead(sensorR);
moving[2]=digitalRead(sensorL);
for(int i=0;i<=3;i++)digitalWrite(IN[i],moving[i]);
analogWrite(speedL,80* digitalRead(sensorR));
analogWrite(speedR,80*digitalRead(sensorL));
}
