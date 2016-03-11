void Sensor_Luz() {
  
if( stateIL == 1) {
  if ( 5 < Hr && Hr < 24) {
   
   if(LI_val <= LI_min && currentMillis < 10000) {
     
    lcd.clear();                                 
    lcd.print(F("ILUMINACAO EM..."));
    Serial.print(F("ILUMINACAO EM..."));
    lcd.setCursor(0, 1);                         
    lcd.print(F("...MODO AUTO!"));
    delay(1000);
    Serial.print(F("...MODO AUTO!"));
    Serial.print(F(" \n"));
    Serial.print(F("  \n"));
    digitalWrite(LEDLIATpowerPin, HIGH);          // LED da iluminaÃ§Ã£o em automatico ON  
    digitalWrite(RL4LIpowerPin, LOW);
    delay (10800000);                            // 3 horas*60minutos*60segundos = 10800000 milisegundos
    digitalWrite(RL4LIpowerPin, HIGH);
    digitalWrite(LEDLIATpowerPin, LOW); 
   
   currentMillis = millis();
   
      DateTime now = RTC.now(); 
      EEPROM.write(50, now.day()); 
      EEPROM.write(60, now.month()); 
      EEPROM.write(70, now.hour());
      EEPROM.write(80, now.minute());
   }   
   
   if (LI_val <= LI_min && currentMillis + 54000000 <= millis()){          //54000000
    
    lcd.clear();                                 
    lcd.print(F("ILUMINACAO EM..."));
    Serial.print(F("ILUMINACAO EM..."));
    lcd.setCursor(0, 1);                         
    lcd.print(F("...MODO AUTO!"));
    delay(1000);
    Serial.print(F("...MODO AUTO!"));
    Serial.print(F(" \n"));
    Serial.print(F("  \n"));
    digitalWrite(LEDLIATpowerPin, HIGH);          // LED da iluminaÃ§Ã£o em automatico ON  
    digitalWrite(RL4LIpowerPin, LOW);
    delay (10800000);                            // 3 horas*60minutos*60segundos = 10800000 milisegundos
    digitalWrite(RL4LIpowerPin, HIGH);
    digitalWrite(LEDLIATpowerPin, LOW); 
   
   currentMillis = millis();
   
      DateTime now = RTC.now(); 
      EEPROM.write(50, now.day()); 
      EEPROM.write(60, now.month()); 
      EEPROM.write(70, now.hour());
      EEPROM.write(80, now.minute());
   }
   
  else { 
    digitalWrite(RL4LIpowerPin, HIGH);
    digitalWrite(LEDLIATpowerPin, LOW);
  }

} else {
    digitalWrite(RL4LIpowerPin, HIGH);
    digitalWrite(LEDLIATpowerPin, LOW);
    }
    
  } else {
    digitalWrite(RL4LIpowerPin, HIGH);
    digitalWrite(LEDLIATpowerPin, LOW);
    }
}
