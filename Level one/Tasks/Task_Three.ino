#define oled 7
#define bled 6
#define wled 5
#define ppb  4
#define npb  3
#define mpb  2

byte c1 = 0, c2 = 0;

void setup()
{
  pinMode(oled, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(wled, OUTPUT);
  pinMode(ppb, INPUT);
  pinMode(npb, INPUT);
  pinMode(mpb, INPUT);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(mpb)) {
    c1++; c2 = 0;
    if (c1 >= 2)c1 = 0;
    delay(250);
    digitalWrite(oled, 1);
    digitalWrite(wled, 1);
    digitalWrite(bled, 1);
  }
  if (c1 == 1) {
    if (digitalRead(ppb)) {
      c2++;
      switch (c2) {
        case 1 : digitalWrite(wled, 0); break;
        case 2 : digitalWrite(wled, 1);
          digitalWrite(bled, 0); break;
        case 3 : digitalWrite(bled, 1);
          digitalWrite(oled, 0); break;
        default : for (int i = 5; i < 8; i++)
            digitalWrite(i, 1); c2 = 0;
      }
      delay(250);
    }
    else if (digitalRead(npb)) {
      c2 = 0;
      for (int i = 5; i < 8; i++)
        digitalWrite(i, 1);
    }
  }
  else {
    digitalWrite(oled, 0);
    digitalWrite(wled, 0);
    digitalWrite(bled, 0);
  }
}
