void Temperatura_Estufa() {

 /* if (TPA_value >= TPA_valueventax) {
  Ventax.update();    // arranca a ventax
  Templed.update();  // led temp verde
  Templedver.update();   // led temp vermelho 
  
  } else {
    digitalWrite(LEDNBATpowerPin, LOW);
    digitalWrite(LEDHMpowerPin, LOW);
    digitalWrite(RL3MTpowerPin, HIGH); } */

  if (stateTP == 1) {
  if(TPA_value > TPA_max) {
      lcd.clear();
      Serial.print(F("A BAIXAR A TEMPERATURA"));
      lcd.print(F("A BAIXAR A TEMPERATURA"));
      Serial.print(F("\n"));
      Serial.print(F("  \n"));
      digitalWrite(RL2WSHTPApowerPin, LOW);
      digitalWrite(LEDNBATpowerPin, HIGH);                            //  LED nebulizadores em automatico OFF
      delay(30000);                                                   // delay de 1 minuto para a nova leitura
      digitalWrite(LEDNBATpowerPin, LOW);
      digitalWrite(RL2WSHTPApowerPin, HIGH);  
 
      DateTime now = RTC.now(); 
      EEPROM.write(130, now.day()); 
      EEPROM.write(140, now.month()); 
      EEPROM.write(150, now.hour());
      EEPROM.write(160, now.minute());
      
  } else {
   digitalWrite(LEDNBATpowerPin, LOW);
   digitalWrite(RL2WSHTPApowerPin, HIGH); 
  }
 } else {
   digitalWrite(LEDNBATpowerPin, LOW);
   digitalWrite(RL2WSHTPApowerPin, HIGH); 
 }
 }

