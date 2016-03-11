void Print_values() {

//--- SENSOR HUMIDADE
  lcd.clear();                           //Situamos o cursor no caracter 0, linha 0
  Serial.print(F("HUMIDADE (%):"));
  lcd.print(F("HUMIDADE (%):"));
  lcd.setCursor(0, 1);
  Serial.print(HM_value);
  lcd.print(HM_value);
  Serial.print(F("\n"));
  Serial.print(F("  \n"));
  delay(3500);
  
   lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print(F("LAST EVENT:HUMD. "));
  lcd.setCursor(0, 2);
  lcd.print (EEPROM.read(10));
  lcd.setCursor(3, 2);
  lcd.print(F("/"));
  lcd.setCursor(4, 2);
  lcd.print (EEPROM.read(20));
  lcd.print(F(" "));
  lcd.setCursor(10, 2);
  lcd.print (EEPROM.read(30));
  lcd.setCursor(12, 2);
  lcd.print(F(":"));
  lcd.setCursor(13, 2);
  lcd.print (EEPROM.read(40));
  delay(3500); 
  
  lcd.clear();                           //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("SENSOR HUMIDADE:"));
  lcd.setCursor(0, 1);
  lcd.print(stateHM);
  delay(2500);
  
//--- SENSOR REGA
  lcd.clear();    
  Serial.print(F("AGUA NO SOLO(%):"));
  lcd.print(F("AGUA NO SOLO(%):"));
  lcd.setCursor(0, 1); 
  Serial.print(SM_val);
  lcd.print(SM_val);
  Serial.print(F("\n"));
  Serial.print(F("  \n"));
  Serial.print(F("   \n"));
  Serial.print(F("    \n"));
  Serial.print(F("************************************************************************************** fim do loop *******************************************************************************************************"));
  Serial.print(F("\n")); 
  delay(3500);
  
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print(F("LAST EVENT:REGA "));
  lcd.setCursor(0, 2);
  lcd.print (EEPROM.read(90));
  lcd.setCursor(3, 2);
  lcd.print(F("/"));
  lcd.setCursor(4, 2);
  lcd.print (EEPROM.read(100));
  lcd.print(F(" "));
  lcd.setCursor(10, 2);
  lcd.print (EEPROM.read(110));
  lcd.setCursor(12, 2);
  lcd.print(F(":"));
  lcd.setCursor(13, 2);
  lcd.print (EEPROM.read(120));
  delay(3500); 

  lcd.clear();                           //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("SENSOR REGA P/TEMPO:"));
  lcd.setCursor(0, 1);
  lcd.print(stateRG);
  delay(2500); 
  
  lcd.clear();                           //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("TEMPO REGA(m):"));
  lcd.setCursor(0, 1);
  tempo = 180000;
  tempo1 = (1000*60);
  tempof = (tempo / tempo1);
  lcd.print(tempof);
  delay(2500);
  
  lcd.clear();                           //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("SENS. RG.EXTERIOR:"));
  lcd.setCursor(0, 1);
  lcd.print(stateRE);
  delay(2500);
  
  lcd.clear();                           //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("TEMPO.RG.EXT.(m):"));
  lcd.setCursor(0, 1);
  te = 600000;
  te1 = (1000*60);
  tef = te/te1;
  lcd.print(tef);
  delay(2500);

  lcd.clear();                           //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("SENSOR HM.SOLO:"));
  lcd.setCursor(0, 1);
  lcd.print(stateSM);
  delay(2500);

//---SENSOR TEMPERATURA ESTUFA
  lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
  Serial.print(F("TEMPERATURA (C):"));
  lcd.print(F("TEMPERATURA (C):"));
  lcd.setCursor(0, 1);
  Serial.print(TPA_value);
  lcd.print(TPA_value);
  Serial.print(F("\n"));
  Serial.print(F("  \n"));
  delay(3500);
  
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print(F("LAST EVENT:TEMP. "));
  lcd.setCursor(0, 2);
  lcd.print (EEPROM.read(130));
  lcd.setCursor(3, 2);
  lcd.print(F("/"));
  lcd.setCursor(4, 2);
  lcd.print (EEPROM.read(140));
  lcd.print(F(" "));
  lcd.setCursor(10, 2);
  lcd.print (EEPROM.read(150));
  lcd.setCursor(12, 2);
  lcd.print(F(":"));
  lcd.setCursor(13, 2);
  lcd.print (EEPROM.read(160));
  delay(3500);
  
  lcd.clear();                           //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("SENS. TEMPERATURA:"));
  lcd.setCursor(0, 1);
  lcd.print(stateTP);
  delay(2500);
  
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print(F("LAST EVENT:ILUM. "));
  lcd.setCursor(0, 2);
  lcd.print (EEPROM.read(50));
  lcd.setCursor(3, 2);
  lcd.print(F("/"));
  lcd.setCursor(4, 2);
  lcd.print (EEPROM.read(60));
  lcd.print(F(" "));
  lcd.setCursor(10, 2);
  lcd.print (EEPROM.read(70));
  lcd.setCursor(12, 2);
  lcd.print(F(":"));
  lcd.setCursor(13, 2);
  lcd.print (EEPROM.read(80));
  delay(3500); 

  lcd.clear();                           //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("SENS. ILUMINACAO:"));
  lcd.setCursor(0, 1);
  lcd.print(stateIL);
  delay(2500);
  
  //---SENSOR TEMPERATURA QUADRO
  lcd.clear();   
  Serial.print(F("TEMP.QUADRO (C):"));
  lcd.print(F("TEMP.QUADRO (C):"));
  lcd.setCursor(0, 1);
  Serial.print(temp);
  lcd.print(temp);
  Serial.print(F("\n"));
  Serial.print(F("  \n"));
  delay(3500);

  lcd.clear();
  Serial.print(F("TEMP.MAX.DIA: "));
  lcd.print(F("TEMP.MAX.DIA: "));
  lcd.setCursor(0, 1);
  Serial.print(maxi);
  lcd.print(maxi);
  Serial.print(F("\n"));
  Serial.print(F("  \n"));
  delay(3500);

  lcd.clear();
  Serial.print(F("TEMP.MIN.NOITE: "));
  lcd.print(F("TEMP.MIN.NOITE: "));
  lcd.setCursor(0, 1);
  Serial.print(mini);
  lcd.print(mini);
  Serial.print(F("\n"));
  Serial.print(F("  \n"));
  delay(3500); 
    
  }
