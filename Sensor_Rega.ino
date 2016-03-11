void Sensor_Rega() {
  
  //////////////////////////////////////////// REGA INTERIOR ESTUFA - HUMIDADE NO SOLO  /////////////////////////////////////////////////////////////////////
  if (stateSM == 1){
    if (Hr >= X && Hr <= Y && currentMillisSM == 0) {
        lcd.clear();
        Serial.print(F("A REGAR..."));
        lcd.print(F("A REGAR..."));
        Serial.print(F("\n"));
        Serial.print(F("  \n"));
        digitalWrite(RL1WSRpowerPin, LOW);
        delay(1000);
        digitalWrite(RL3MTpowerPin, LOW);
        digitalWrite(LEDRATpowerPin, HIGH);
        delay(180000);
        digitalWrite(RL3MTpowerPin, HIGH);
        delay(1000);
        digitalWrite(RL1WSRpowerPin,HIGH);    // turn off Rega
        digitalWrite(LEDRATpowerPin, LOW);    // turn off LED
        
        currentMillisSM = millis();
  
        DateTime now = RTC.now(); 
        EEPROM.write(90, now.day()); 
        EEPROM.write(100, now.month()); 
        EEPROM.write(110, now.hour());
        EEPROM.write(120, now.minute());            
        }
        
        if (Hr >= X && Hr <= Y && currentMillisSM + 36000000 <= millis()){
        lcd.clear();
        Serial.print(F("A REGAR..."));
        lcd.print(F("A REGAR..."));
        Serial.print(F("\n"));
        Serial.print(F("  \n"));
        digitalWrite(RL1WSRpowerPin, LOW);
        delay(1000);
        digitalWrite(RL3MTpowerPin, LOW);
        digitalWrite(LEDRATpowerPin, HIGH);
        delay(180000);
        digitalWrite(RL3MTpowerPin, HIGH);
        delay(1000);
        digitalWrite(RL1WSRpowerPin,HIGH);    // turn off Rega
        digitalWrite(LEDRATpowerPin, LOW);    // turn off LED
        
        currentMillisSM = millis();
        
        DateTime now = RTC.now(); 
        EEPROM.write(90, now.day()); 
        EEPROM.write(100, now.month()); 
        EEPROM.write(110, now.hour());
        EEPROM.write(120, now.minute());
          
    }        
      
      if (Hr >= X && Hr <= Y && currentMillisSM + 36000000 <= millis()){
      lcd.clear();
      Serial.print(F("A REGAR..."));
      lcd.print(F("A REGAR..."));
      Serial.print(F("\n"));
      Serial.print(F("  \n"));
      digitalWrite(RL1WSRpowerPin, LOW);
      delay(1000);
      digitalWrite(RL3MTpowerPin, LOW);
      digitalWrite(LEDRATpowerPin, HIGH);
      delay(180000);
      digitalWrite(RL3MTpowerPin, HIGH);
      delay(1000);
      digitalWrite(RL1WSRpowerPin,HIGH);    // turn off Rega
      digitalWrite(LEDRATpowerPin, LOW);    // turn off LED
      
      currentMillisSM = millis();
      
      DateTime now = RTC.now(); 
      EEPROM.write(90, now.day()); 
      EEPROM.write(100, now.month()); 
      EEPROM.write(110, now.hour());
      EEPROM.write(120, now.minute());
        
  }
 } else {
    digitalWrite(RL1WSRpowerPin, HIGH);    // turn off Rega
    digitalWrite(LEDRATpowerPin, LOW);    // turn off LED
    }


//////////////////////////////////////////// REGA INTERIOR ESTUFA - REGA POR TEMPO  /////////////////////////////////////////////////////////////////////
  if (stateRG == 1){
    if (Hr >= X && Hr <= Y && currentMillisRG == 0) {
        lcd.clear();
        Serial.print(F("A REGAR..."));
        lcd.print(F("A REGAR..."));
        Serial.print(F("\n"));
        Serial.print(F("  \n"));
        digitalWrite(RL1WSRpowerPin, LOW);
        delay(1000);
        digitalWrite(RL3MTpowerPin, LOW);
        digitalWrite(LEDRATpowerPin, HIGH);
        delay(180000);
        digitalWrite(RL3MTpowerPin, HIGH);
        delay(1000);
        digitalWrite(RL1WSRpowerPin,HIGH);    // turn off Rega
        digitalWrite(LEDRATpowerPin, LOW);    // turn off LED
        
        currentMillisRG = millis();
  
        DateTime now = RTC.now(); 
        EEPROM.write(90, now.day()); 
        EEPROM.write(100, now.month()); 
        EEPROM.write(110, now.hour());
        EEPROM.write(120, now.minute());            
        }
        
        if (Hr >= X && Hr <= Y && currentMillisRG + 36000000 <= millis()){
        lcd.clear();
        Serial.print(F("A REGAR..."));
        lcd.print(F("A REGAR..."));
        Serial.print(F("\n"));
        Serial.print(F("  \n"));
        digitalWrite(RL1WSRpowerPin, LOW);
        delay(1000);
        digitalWrite(RL3MTpowerPin, LOW);
        digitalWrite(LEDRATpowerPin, HIGH);
        delay(180000);
        digitalWrite(RL3MTpowerPin, HIGH);
        delay(1000);
        digitalWrite(RL1WSRpowerPin,HIGH);    // turn off Rega
        digitalWrite(LEDRATpowerPin, LOW);    // turn off LED
        
        currentMillisRG = millis();
        
        DateTime now = RTC.now(); 
        EEPROM.write(90, now.day()); 
        EEPROM.write(100, now.month()); 
        EEPROM.write(110, now.hour());
        EEPROM.write(120, now.minute());
          
    }

if (Hr >= W && Hr <= Z && currentMillisRG + 54000000 <= millis()){
        lcd.clear();
        Serial.print(F("A REGAR..."));
        lcd.print(F("A REGAR..."));
        Serial.print(F("\n"));
        Serial.print(F("  \n"));
        digitalWrite(RL1WSRpowerPin, LOW);
        delay(1000);
        digitalWrite(RL3MTpowerPin, LOW);
        digitalWrite(LEDRATpowerPin, HIGH);
        delay(180000);
        digitalWrite(RL3MTpowerPin, HIGH);
        delay(1000);
        digitalWrite(RL1WSRpowerPin,HIGH);    // turn off Rega
        digitalWrite(LEDRATpowerPin, LOW);    // turn off LED
        
        currentMillisRG = millis();
        
        DateTime now = RTC.now(); 
        EEPROM.write(90, now.day()); 
        EEPROM.write(100, now.month()); 
        EEPROM.write(110, now.hour());
        EEPROM.write(120, now.minute());
          
    }
   }
/////////////////////////////////////////////////// REGA EXTERIOR DA ESTUFA /////////////////////////////////////////////////////////////

if( stateRE == 1) {
if (Hr >= I && Hr <= F && currentMillisEXT == 0) {
      lcd.clear();
      Serial.print(F("A REGAR Ext..."));
      lcd.print(F("A REGAR Ext..."));
      Serial.print(F("\n"));
      Serial.print(F("  \n"));
      digitalWrite(RL5EXTpowerPin, LOW);
      delay(1000);
      digitalWrite(RL3MTpowerPin, LOW);
      digitalWrite(LEDRATpowerPin, HIGH);
      delay(600000);
      digitalWrite(RL3MTpowerPin, HIGH);
      delay(1000);
      digitalWrite(RL5EXTpowerPin,HIGH);    // turn off Rega
      digitalWrite(LEDRATpowerPin, LOW);    // turn off LED
    
      currentMillisEXT = millis();
           
      }
 
 if (Hr >= L  && Hr <= M && currentMillisEXT + 36000000 <= millis()){
      lcd.clear();
      Serial.print(F("A REGAR Ext..."));
      lcd.print(F("A REGAR Ext..."));
      Serial.print(F("\n"));
      Serial.print(F("  \n"));
      digitalWrite(RL5EXTpowerPin, LOW);
      delay(1000);
      digitalWrite(RL3MTpowerPin, LOW);
      digitalWrite(LEDRATpowerPin, HIGH);
      delay(600000);
      digitalWrite(RL3MTpowerPin, HIGH);
      delay(1000);
      digitalWrite(RL5EXTpowerPin,HIGH);    // turn off Rega
      digitalWrite(LEDRATpowerPin, LOW);
      
      currentMillisEXT = millis();
        
  }
 
      
      if (Hr >= I  && Hr <= F && currentMillisEXT + 54000000 <= millis()){
      lcd.clear();
      Serial.print(F("A REGAR Ext..."));
      lcd.print(F("A REGAR Ext..."));
      Serial.print(F("\n"));
      Serial.print(F("  \n"));
      digitalWrite(RL5EXTpowerPin, LOW);
      delay(1000);
      digitalWrite(RL3MTpowerPin, LOW);
      digitalWrite(LEDRATpowerPin, HIGH);
      delay(600000);
      digitalWrite(RL3MTpowerPin, HIGH);
      delay(1000);
      digitalWrite(RL5EXTpowerPin,HIGH);    // turn off Rega
      digitalWrite(LEDRATpowerPin, LOW);
      
      currentMillisEXT = millis();
        
  }
} else {
    digitalWrite(RL5EXTpowerPin, HIGH);    // turn off Rega
    digitalWrite(RL3MTpowerPin, HIGH);
    digitalWrite(LEDRATpowerPin, LOW);    // turn off LED
    
}
}

  
