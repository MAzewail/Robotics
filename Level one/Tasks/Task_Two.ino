
const int orang=4;
const int blue=3;
const int green=2;
const int button=8;
bool reading=0;
byte count=0;
void setup() {
  for(byte i=2;i<5;i++)
   pinMode(i,OUTPUT);  
  /*
pinMode(orang,OUTPUT);
pinMode(blue,OUTPUT);
pinMode(green,OUTPUT);*/
pinMode(button,INPUT);

}

void loop() {
  reading=digitalRead(button);
  if(reading==HIGH){
    count++;
    if(count==1){
    digitalWrite(orang,HIGH);
    }
   else if(count==2){
    digitalWrite(blue,HIGH);
    }
    else if(count==3){
    digitalWrite(green,HIGH);
   }
    else {
      for(byte i=2;i<5;i++)
       digitalWrite(i,LOW); 
    /*  
    digitalWrite(orang,LOW);
    digitalWrite(blue,LOW);
    digitalWrite(green,LOW);*/
      count=0;}
    
    delay(250);
  }
}
