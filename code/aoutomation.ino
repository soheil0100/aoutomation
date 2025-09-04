#include<LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define tempi A0
#define up A1
#define down A2
#define fan 2
#define ledfan 3
#define heater 4
#define ledheater 5
#define lednormal 6
#define buzzer 7
int x=0, temp=0, upt=30, downt= 10;
float volt;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.noBlink();
  pinMode(tempi, INPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(fan, OUTPUT);
  pinMode(ledfan, OUTPUT);
  pinMode(heater, OUTPUT);
  pinMode(ledheater, OUTPUT);
  pinMode(lednormal, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  upt=analogRead(up);
  upt=upt*0.00489;
  upt=upt*20;
  downt=analogRead(down);
  downt=downt*0.00489;
  downt=downt*20;
  x=analogRead(tempi);
  volt=x*0.00489;
  temp=volt*100;

  Serial.print("UpTemp=");
  Serial.println(upt);
  Serial.print("DownTemp=");
  Serial.println(downt);
  Serial.print("Temp=");
  Serial.println(temp);

  lcd.setCursor(0, 0);
  lcd.print("TEMP=");
  lcd.setCursor(5, 0);
  lcd.print(temp);
  lcd.setCursor(8, 0);
  lcd.print(" 'C     ");
  lcd.setCursor(0, 1);
  lcd.print("DNT=");
  lcd.setCursor(4, 1);
  lcd.print(downt);
  lcd.setCursor(7, 1);
  lcd.print("C");
  lcd.setCursor(8, 1);
  lcd.print("UPT=");
  lcd.setCursor(12, 1);
  lcd.print(upt);
  lcd.setCursor(15, 1);
  lcd.print("C");

  if(temp>=0 and temp<10){
    lcd.setCursor(6, 0);
    lcd.print("  ");
  }
  if(temp>=10 and temp<100){
    lcd.setCursor(7, 0);
    lcd.print(" ");
  }
  if(downt>=0 and downt<10){
    lcd.setCursor(5, 1);
    lcd.print("  ");
  }
  if(downt>=10 and downt<100){
    lcd.setCursor(6, 1);
    lcd.print(" ");
  }
  if(upt>=0 and upt<10){
    lcd.setCursor(13, 1);
    lcd.print("  ");
  }
  if(upt>=10 and upt<100){
    lcd.setCursor(14, 1);
    lcd.print(" ");
  }
  
  if(temp>=upt){
    digitalWrite(lednormal, LOW);
    digitalWrite(ledheater, LOW);
    digitalWrite(heater, LOW);
    digitalWrite(ledfan, HIGH);
    digitalWrite(fan, HIGH);
    tone(buzzer, 10000, 1000);
  }
  if(temp>=(upt-5) and temp<=(upt-3)){
    digitalWrite(lednormal, HIGH);
    digitalWrite(ledheater, LOW);
    digitalWrite(heater, LOW);
    digitalWrite(ledfan, LOW);
    digitalWrite(fan, LOW);
  }
  if(temp<=downt){
    digitalWrite(lednormal, LOW);
    digitalWrite(ledheater, HIGH);
    digitalWrite(heater, HIGH);
    digitalWrite(ledfan, LOW);
    digitalWrite(fan, LOW);
    tone(buzzer, 8000, 1000);
  }
  if(temp>=(downt+3) and temp<=(downt+5)){
    digitalWrite(lednormal, HIGH);
    digitalWrite(ledheater, LOW);
    digitalWrite(heater, LOW);
    digitalWrite(ledfan, LOW);
    digitalWrite(fan, LOW);
  }
  if(temp>downt and temp<upt){
    digitalWrite(lednormal, HIGH);
    digitalWrite(ledheater, LOW);
    digitalWrite(heater, LOW);
    digitalWrite(ledfan, LOW);
    digitalWrite(fan, LOW);
  }
}
