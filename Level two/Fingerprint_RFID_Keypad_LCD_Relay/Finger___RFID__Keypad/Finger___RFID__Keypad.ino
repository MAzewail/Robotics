#include <Adafruit_Fingerprint.h>
#include<SoftwareSerial.h>
#include <SPI.h>
#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <RFID.h>
#define SS_PIN 10
#define RST_PIN 9
LiquidCrystal_I2C lcd(0x27,16,2);
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
RFID rfid(SS_PIN, RST_PIN); 


char k[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};

const byte rpins[4]={A0,A1,A2,A3};
const byte cpins[4]={4,5,6,7};
char myk;
Keypad mypad (makeKeymap(k),rpins,cpins,4,4);
char pass[]={'1','3','4','5'};
char upass[sizeof(pass)]={0};
byte counter=0,i=0;

void reslcd(){
 lcd.home();
 lcd.clear();
 lcd.print("Enter password");
 lcd.setCursor(0,1);
}
// Setup variables:Dec: 180, 43, 99, 40, 212
    int serNum0=180;
    int serNum1=43;
    int serNum2=99;
    int serNum3=40;
    int serNum4=212;
byte state=0,pstate=0,x=0;
void setup()
{
   lcd.init();
 lcd.backlight();
 reslcd();
  Serial.begin(9600);
  SPI.begin(); 
  rfid.init();
  pinMode(8, OUTPUT);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");

  // set the data rate for the sensor serial port
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);

  finger.getTemplateCount();
finger.security_level=5;
  if (finger.templateCount == 0) {
    Serial.print("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
  }
  else {
    Serial.println("Waiting for valid finger...");
      Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  }
}

void loop()                     // run over and over again
{
  x=0;state=0;
  getFingerprintID();
  delay(50);            //don't ned to run this at full speed.
  Serial.println(finger.fingerID);
  if(finger.fingerID==1&&x==1){
                digitalWrite(8,1);
                delay(1000);
                digitalWrite(8,0);
                reslcd();
                lcd.print("finger found");
            
  }
  else if(state==1){
               Serial.println("Enter the right Card");
               reslcd();
               lcd.print("wrong finger");
               digitalWrite(8,0);
  }
      if (rfid.isCard()) {
        if (rfid.readCardSerial()) {
            if (rfid.serNum[0] == serNum0
                && rfid.serNum[1] == serNum1
                && rfid.serNum[2] == serNum2
                && rfid.serNum[3] == serNum3
                && rfid.serNum[4] == serNum4
            ) {
                /* With a new cardnumber, show it. */
                Serial.println(" ");
                Serial.println("Card found");
                lcd.print("finger found");
                reslcd();
                lcd.print("Card found");
                digitalWrite(8,1);
                delay(1000);
                digitalWrite(8,0);

             } else {
               /* If we have the same ID, just write a dot. */
               Serial.println("Enter the right Card");
               reslcd();
               lcd.print("try again");
               digitalWrite(8,0);
             }
          }
    }
rfid.halt();
    
  myk=mypad.getKey();
  if(myk){
    if(counter<=0)reslcd();
  lcd.print("*");
  upass[counter]=myk;
  if(myk=='D'){
    lcd.clear();  
    lcd.home();
    for(i=0;i<sizeof(upass);i++){
    if(upass[i]!=pass[i])break;
  }
  if(i==sizeof(upass)){
  counter=-1;
  lcd.clear();
  lcd.home();
  lcd.print("User authorized");
  digitalWrite(8,1);
  delay(3000);
  digitalWrite(8,0);
  reslcd();
  }
  else {
  counter=-1;
  lcd.clear();
  lcd.home();
  lcd.print("Wrong password");
  delay(2000);
  reslcd();
  }
  }
 counter++; }
    
    pstate=state;
    
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    state=1;
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }
  x=1;
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}
