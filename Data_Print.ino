void Data_Print()
{
   DateTime now = RTC.now();
    
    lcd.clear(); 
    Serial.print(now.day(), DEC);
    lcd.print(now.day(), DEC);
    Serial.print('/');
    lcd.print('/');
    Serial.print(now.month(), DEC);
    lcd.print(now.month(), DEC);
    Serial.print('/');
    lcd.print('/');
    Serial.print(now.year(), DEC);
    lcd.print(now.year(),DEC);
   
    lcd.setCursor(0,1);
    Serial.print("\n");
    Serial.print(now.hour(), DEC);
    lcd.print(now.hour(), DEC);
    Serial.print(':');
    lcd.print(':');
    Serial.print(now.minute(), DEC);
    lcd.print(now.minute(), DEC);
    Serial.println();
    Serial.print("\n");
    delay(3500);
  
  
  
  
  }





