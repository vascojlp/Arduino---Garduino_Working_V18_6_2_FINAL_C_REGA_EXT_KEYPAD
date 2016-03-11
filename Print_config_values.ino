void Print_config_values() {

 /*
 lcd.clear(); 
 lcd.print(F("-= MODO VERAO =-"));
 delay(500);
 lcd.setCursor(0,1);
 lcd.print(F("___ COM REGA ___"));
 delay(4000);
 */
  
 if( stateHM == 1){
 lcd.clear(); 
 lcd.print(F("HUMIDADE :"));
 delay(500);
 lcd.setCursor(0,1);
 lcd.print(F("Running!"));
 delay(2000); 
 } else { 
   lcd.clear(); 
   lcd.print(F("HUMIDADE :"));
   delay(500);
   lcd.setCursor(0,1);
   lcd.print(F("NOT Running!"));
   delay(2000); 
   }

 if (stateIL == 1){
 lcd.clear(); 
 lcd.print(F("ILUMINACAO :"));
 delay(500);
 lcd.setCursor(0,1);
 lcd.print(F("Running!"));
 delay(2000);
 } else {
    lcd.clear(); 
   lcd.print(F("ILUMINACAO :"));
   delay(500);
   lcd.setCursor(0,1);
   lcd.print(F("NOT Running!"));
   delay(2000);
   }
 
 if (stateRG == 1){
 lcd.clear(); 
 lcd.print(F("REGA :"));
 delay(500);
 lcd.setCursor(0,1);
 lcd.print(F("Running !"));
 delay(2000);
 } else {
     lcd.clear(); 
     lcd.print(F("REGA :"));
     delay(500);
     lcd.setCursor(0,1);
     lcd.print(F("NOT Running !"));
     delay(2000);   
       }
 
 if( stateTP == 1) {
 lcd.clear(); 
 lcd.print(F("TEMPERATURA :"));
 delay(500);
 lcd.setCursor(0,1);
 lcd.print(F("Running!"));
 delay(2000);
 } else {
   lcd.clear(); 
   lcd.print(F("TEMPERATURA :"));
   delay(500);
   lcd.setCursor(0,1);
   lcd.print(F("NOT Running!"));
   delay(2000);
   }

 /*
 lcd.clear(); 
 Serial.print(F("Val.Ilum.Minima:"));
 lcd.print(F("Val.Ilum.Minima:"));
 lcd.setCursor(0,1);
 Serial.print(LI_min);
 lcd.print(LI_min);
 delay(4000);
 
 lcd.clear(); 
 Serial.print(F("Val.Humd.Minima:"));
 lcd.print(F("Val.Humd.Minima:"));
 lcd.setCursor(0,1);
 Serial.print(HM_min);
 lcd.print(HM_min);
 delay(4000);
 
 lcd.clear(); 
 Serial.print(F("Val.Temp.Maxima:"));
 lcd.print(F("Val.Temp.Maxima:"));
 lcd.setCursor(0,1);
 Serial.print(TPA_max);
 lcd.print(TPA_max);
 delay(4000);
 
 lcd.clear(); 
 Serial.print(F("Val.Hm.Sol.Min:"));
 lcd.print(F("Val.Hm.Sol.Min:"));
 lcd.setCursor(0,1);
 Serial.print(SM_min);
 lcd.print(SM_min);
 delay(4000);  
  */ 
  
  
  }





