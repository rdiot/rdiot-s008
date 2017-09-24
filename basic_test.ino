/* Temperature and humidity DHT11 sensor module (KY-015) [S008] : http://rdiot.tistory.com/50 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT11.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
 
int pin=4; // D4
DHT11 dht11(pin); 
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
  
  pinMode(pin,INPUT);
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{ 
  lcd.setCursor(0,0);
  lcd.print("S008:DHT11");
 
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
 
    lcd.setCursor(0,1);
    lcd.print("temperature=" + (String)temp + "'C");
 
    lcd.setCursor(0,2);
    lcd.print("humidity=" + (String)humi + "'F");
  }
  else
  {
    lcd.setCursor(0,3);
    lcd.print("err=" + (String)err); 
  } 
  delay(DHT11_RETRY_DELAY); //delay for reread
}
