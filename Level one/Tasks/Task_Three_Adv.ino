#define oled 7
#define bled 6
#define wled 5
#define ppb  4
#define npb  3
#define mpb  2

byte c1=0,c2=0,i=0;

void setup()
{
  pinMode(oled, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(wled, OUTPUT);
  pinMode(ppb, INPUT);
  pinMode(npb, INPUT);
  pinMode(mpb, INPUT);
}

void loop()
{
  if(digitalRead(mpb)){
  c1++;c2=0;
    if(c1>=2)c1=0;
  while(digitalRead(mpb));
//  delay(250);
  digitalWrite(oled,0);
  digitalWrite(wled,0);
  digitalWrite(bled,0);
  }
  if(c1==1){
    if(digitalRead(ppb)){
    c2++;
      if(c2>=4)c2=0;
      
      delay(250);
    }
    else if(digitalRead(npb)){
    c2=0;
      delay(250);
    }
    digitalWrite(wled,c2-1);   
    digitalWrite(bled,c2-2); 
    digitalWrite(oled,c2-3);     
  }
}
