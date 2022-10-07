const int red = 4 ;
const int yellow = 3 ;
const int green = 2 ;
const int sw1 = 5 ;
const int sw2 = 6 ;
const int sw3 = 7 ;
byte counter = 0 ;
byte counter1 = 0;
byte counter2 = 0;

void setup()
{
  for (byte i = 0; i <= 3; i++) {
    pinMode(i, OUTPUT);
  }

  for (byte i = 4; i <= 6; i++) {
    pinMode(i, INPUT);
  }

}

void loop()
{
  if ( digitalRead(sw1) == HIGH) {
    counter++;
    if (counter >= 3)counter = 0;
    delay(250);
  }


  switch (counter) {

    case 0 :
      if (digitalRead(sw2) == HIGH) {
        for (byte i = 2; i < 5; i++) {
          digitalWrite(i, HIGH);
          delay(250);
        }
      }
      else if (digitalRead(sw3) == HIGH) {
        for (byte i = 4; i > 1; i--) {
          digitalWrite(i, LOW);
          delay(250);
        }
      }
      break;


    case 1 :

      if (digitalRead(sw2) == HIGH) {
        counter1++;
        //if(counter1>=3)counter=0;
        switch (counter1) {

          case 1 :  digitalWrite(green, HIGH); break;

          case 2 :  digitalWrite(yellow, HIGH); break;

          case 3 :  digitalWrite(red, HIGH); counter1 = 0; counter2 = 0;
            break;
          default : counter1 = 0; counter2 = 0;

        }
        delay(250);

      }

      if (digitalRead(sw3) == HIGH) {
        counter2++;
        switch (counter2) {

          case 1 :    digitalWrite(red, LOW); break;

          case 2 :  digitalWrite(yellow, LOW); break;

          case 3 :   digitalWrite(green, LOW); counter1 = 0; counter2 = 0;  break;

          default : counter1 = 0; counter2 = 0;
        }

        delay(250);
      }
      break;

    case 2 :
      if (digitalRead(sw2) == HIGH) {
        counter1++;

        switch (counter1) {

          case 1 :  digitalWrite(green, HIGH); break;

          case 2 :  digitalWrite(yellow, HIGH); break;

          case 3 :  digitalWrite(red, HIGH); counter1 = 0; counter2 = 0;
            break;

          default : counter1 = 0; counter2 = 0;
        }
        while (digitalRead(sw2) == HIGH);

      }


      if (digitalRead(sw3) == HIGH) {
        counter2++;

        switch (counter2) {

          case 1 :    digitalWrite(red, LOW); break;

          case 2 :  digitalWrite(yellow, LOW); break;

          case 3 :   digitalWrite(green, LOW); counter1 = 0; counter2 = 0;  break;

          default : counter1 = 0; counter2 = 0;
        }
        while (digitalRead(sw3) == HIGH);
      }

      break;
  }
}
