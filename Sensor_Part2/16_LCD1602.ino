#include <Wire.h>                     
#include <LiquidCrystal_I2C.h>        

LiquidCrystal_I2C lcd(0x3F,16,2);     

void setup()
{
  lcd.init();                      // LCD 초기화
  // Print a message to the LCD.
  lcd.backlight();                // 백라이트 켜기
  lcd.setCursor(0,0);             // 1번째, 1라인
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);             // 1번째, 2라인
  lcd.print("Bye!");
  //lcd.noBacklight();            // 백라이트 끄기
}

void loop()
{

}

 
