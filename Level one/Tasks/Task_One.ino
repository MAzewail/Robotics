#define green 2
#define yellow 3
#define red 4
void setup()
{
  for(byte i=2;i<5;i++)
  pinMode(i, OUTPUT);
  /*
   * pinMode(green, OUTPUT);
   * pinMode(yellow, OUTPUT);
   * pinMode(red, OUTPUT);
   */
}

void loop()
{
  digitalWrite(green, HIGH);
  delay(400); 
  digitalWrite(yellow, HIGH);
  delay(400);
  digitalWrite(yellow, LOW);
  delay(400);
  digitalWrite(yellow, HIGH);
  delay(400);
  digitalWrite(yellow, LOW);
  delay(400);
  digitalWrite(yellow, HIGH);
  delay(400);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  delay(400); 
  digitalWrite(red, LOW);
}
