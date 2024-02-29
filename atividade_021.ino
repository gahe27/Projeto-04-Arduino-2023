#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

#define AnalogLDR A0
int Leitura = 0;
float VoltagemLDR;
float distancia, tempo;

void setup()
{
 	lcd.begin(16, 2);
  	pinMode(11, INPUT); //Echo	
  	pinMode(10, OUTPUT);//Trig
  	pinMode(9, OUTPUT); //Buzzer
  	pinMode(8, OUTPUT); //Verde
  	pinMode(7, OUTPUT); //Amarelo
  	pinMode(6, OUTPUT); //Vermelho
  	Serial.begin(9600);
}

void loop()
{
  digitalWrite(10, HIGH);
  delay(500);
  digitalWrite(10, LOW);
  tempo = pulseIn(11, HIGH);
  distancia = tempo * 0.01715;
  Serial.println(distancia);
  
  if(distancia < 10.0){
  	digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    tone(9, 261.63, 100);
	lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DISTANCIA: ");
    lcd.setCursor(11, 0);
    lcd.print(distancia);
    lcd.setCursor(0,1);
    lcd.print("PARE");
  }
  if((distancia >= 10) && (distancia < 30)){
  	digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DISTANCIA: ");
    lcd.setCursor(11, 0);
    lcd.print(distancia);
    lcd.setCursor(0,1);
    lcd.print("ATENCAO");
  }
  if(distancia >= 30){
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
  	digitalWrite(6, LOW);
    tone(9, 261.63, 100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DISTANCIA: ");
    lcd.setCursor(11, 0);
    lcd.print(distancia);
    lcd.setCursor(0,1);
    lcd.print("SIGA");
  }
}