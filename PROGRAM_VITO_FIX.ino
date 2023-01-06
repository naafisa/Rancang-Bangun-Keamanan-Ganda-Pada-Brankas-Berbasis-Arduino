
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define BUZZER 2
#define RST_PIN   8
#define SS_PIN    10
#define RELAY 9

const byte ROWS = 4; //keypad 4 baris
const byte COLS = 4; //4 kolom
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {0,1,A5,A4}; //koneksi baris keypad
byte colPins[COLS] = {A3,A2,A1,A0}; //koneksi kolom keypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

byte i,j,k,f_cek;
String ID_TAG;
String ID[2];
int jmlkartu;
String Password="000000";
String pw;
byte f_kpd;
//==============================
void setup() { 
  lcd.init();
  lcd.backlight();  
  SPI.begin();
  mfrc522.PCD_Init();
  jmlkartu=2;
  ID[0]="251da7ac";
  ID[1]="803ee1b";
  lcd.clear();
  lcd.print("Halo Bos!"); 
  lcd.setCursor(0,1);
  lcd.print("Mau Setoran?");
  pinMode(BUZZER,OUTPUT);
  pinMode(RELAY,OUTPUT);
  digitalWrite(RELAY,HIGH);
  delay(2000);
  lcd.clear();
  lcd.print("Tempelkan Kartu");
}
//============
void readRFID(byte *buffer, byte bufferSize)
{
  ID_TAG="";
  for(byte i = 0;i<bufferSize; i++)
  {
    ID_TAG=ID_TAG+String(buffer[i], HEX);
  }
}
//=============

void loop() {     
  if(!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()){
    return;
  } 
  readRFID(mfrc522.uid.uidByte, mfrc522.uid.size); 
  f_cek=0;
  for(k=0;k<jmlkartu;k++){
  if(ID_TAG==ID[k]){        
    f_cek=1;
    lcd.clear();
    lcd.print("Kartu Benar");
    delay(2000);
    lcd.clear();
    lcd.print("Masukkan Password");
    lcd.setCursor(0,1);
    lcd.print("PW:");
    f_kpd=1;
    pw="";
    while(f_kpd){
      char customKey = customKeypad.getKey();
      if (customKey){        
        lcd.print("*");
        pw=pw+customKey;
        j++;
        if(j==6){
          j=0;
          if(pw==Password){
            f_kpd=0;
            lcd.clear();
            lcd.print("Password Benar");
            lcd.setCursor(0,1);
            lcd.print("Selamat Setoran!");
            digitalWrite(RELAY,LOW); 
            while(1);
          }
          else{
            lcd.clear();
            lcd.print("Password Salah");
            delay(2000);
            k++;
            if(k<3){
              pw="";
              lcd.clear();
              lcd.print("Masukkan Password");
              lcd.setCursor(0,1);
              lcd.print("PW:");
            }
            else{
              lcd.clear();
              lcd.print("Maaf Anda");
              lcd.setCursor(0,1);
              lcd.print("Terblokir...");
              while(1);
            }
            delay(3000);
          }
        }
      } 
    }    
  }
  }
  if(f_cek==0){
    lcd.clear();
    lcd.print("Kartu Salah");     
    delay(1000);    
    for(j=0;j<3;j++){
    digitalWrite (BUZZER,HIGH);
    delay(500);
    digitalWrite (BUZZER,LOW);
    delay(500);
    }
  }  
    
    lcd.clear();
    lcd.print("Tempelkan Kartu"); 
}
