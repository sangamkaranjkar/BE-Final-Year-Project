#include <LiquidCrystal.h>   //Library file for LCD display
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);   

int relay=11;
int IR_IN=9;
int IR_OUT=10;
int M1=3;
int M2=4;
int R_led=5;
int G_led=2;


void setup() 
{
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(R_led,OUTPUT);
  pinMode(G_led,OUTPUT);
  pinMode(relay,OUTPUT);
  pinMode(IR_IN,INPUT_PULLUP);
  pinMode(IR_OUT,INPUT_PULLUP);
  lcd.begin(16,2);       // Start LCD in 16 coloum 2 rows format
  lcd.print("   L SEALER   ");    // write string on LCD
  lcd.setCursor(0,1);              // shift lcd cursor in second line 
  lcd.print("    SYSTEM    ");    // write string on LCD
}

void loop() 
{
    
  lcd.clear();
  lcd.print("Checking IR");
  delay(500);
  if(digitalRead(IR_IN)==LOW)
  {
    lcd.clear();
    lcd.print("In-Object");
    lcd.setCursor(0,1);
    lcd.print("Detected");
    delay(500);
     digitalWrite(M1,HIGH);
    digitalWrite(M2,LOW);
    digitalWrite(R_led,LOW);
    digitalWrite(G_led,HIGH);
  }
  while(digitalRead(IR_OUT)==HIGH)
  {
    
  }
    digitalWrite(R_led,HIGH);
    lcd.clear();
    lcd.print("Sealing");
    lcd.setCursor(0,1);
    lcd.print("-------");
     digitalWrite(M1,LOW);
    digitalWrite(M2,LOW);
     delay(500);
    digitalWrite(relay,HIGH);
    delay(2000);
    digitalWrite(relay,LOW);
    digitalWrite(M1,HIGH);
    digitalWrite(M2,LOW);

   
 }
