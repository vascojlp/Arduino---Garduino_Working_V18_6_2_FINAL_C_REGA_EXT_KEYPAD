void Sensor_Humidade(){
 
if (stateHM == 1){  
  if (DHT.humidity < HM_min) {
      lcd.clear(); 
      Serial.print(F("HUMIDADE UP!"));
      lcd.print(F("HUMIDADE UP!"));
      delay(1500);
      Serial.print(F("\n"));
      Serial.print(F("  \n"));                                   
      digitalWrite(LEDNBATpowerPin, HIGH);        //  LED nebulizadores em automatico ON
      digitalWrite(RL2WSHTPApowerPin, LOW);
      delay(10000);                                // delay de 1/2 para subir a humd.
     }
    digitalWrite(RL2WSHTPApowerPin, HIGH);
    digitalWrite(LEDNBATpowerPin, LOW); 
     
      DateTime now = RTC.now(); 
      EEPROM.write(10, now.day()); 
      EEPROM.write(20, now.month()); 
      EEPROM.write(30, now.hour());
      EEPROM.write(40, now.minute());   
  
  } else {
      digitalWrite(RL2WSHTPApowerPin, HIGH);
      digitalWrite(LEDNBATpowerPin, LOW); 
      }
}


