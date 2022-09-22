#define trig 8
#define echo 9
#define forward 0
#define left 1
#define right 2
#define stp 3
#define backward 4
byte IN[] = {4, 5, 6, 7};
byte moving[5][4] =
{ {1, 0, 1, 0}, //forward
  {0, 0, 1, 0}, //left
  {1, 0, 0, 0}, //right
  {0, 0, 0, 0}, //stp
  {0, 1, 0, 1}  //backward
};

void setup() {
  Serial.begin(9600);
  for (int i = 4; i <= 9; i++)
    pinMode(i, OUTPUT);


}
void loop() {
  if (Serial.available()) {
    switch (Serial.read()) {
      case 'f': for (int i = 0; i <= 3; i++)digitalWrite(IN[i], moving[forward][i]);
      case 'l': for (int i = 0; i <= 3; i++)digitalWrite(IN[i], moving[left][i]);
      case 'r': for (int i = 0; i <= 3; i++)digitalWrite(IN[i], moving[right][i]);
      case 's': for (int i = 0; i <= 3; i++)digitalWrite(IN[i], moving[stp][i]);
      case 'b': for (int i = 0; i <= 3; i++)digitalWrite(IN[i], moving[backward][i]);
    }
  }
}
