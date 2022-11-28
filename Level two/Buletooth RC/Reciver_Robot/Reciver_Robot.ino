#include <SoftwareSerial.h>
SoftwareSerial x(2,3);
bool in[3]={0};//{in1,in2,in3}
char u;
void setup() {
Serial.begin(9600);
x.begin(9600);  
for(int i=4;i<8;i++)pinMode(i,OUTPUT);
}
void loop() {
  if (x.available()){
    u=x.read();
    switch(u){
    case 'F' :in[0]=1;in[1]=0;in[2]=1;break;
    case 'B' :in[0]=0;in[1]=1;in[2]=0;break;
    case 'R' :in[0]=0;in[1]=0;in[2]=1;break;
    case 'L' :in[0]=1;in[1]=0;in[2]=0;break;
    case 'S' :in[0]=0;in[1]=0;in[2]=0;break;    
    }
    digitalWrite(4,in[0]);
    digitalWrite(5,in[1]);
    digitalWrite(6,in[2]);
    digitalWrite(7,in[1]);    
    }
    }
