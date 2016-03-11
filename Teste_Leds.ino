void Teste_Leds() {
  
digitalWrite(LEDHMpowerPin,HIGH);            // Vermelho
delay(200);
digitalWrite(LEDRMpowerPin,HIGH);            // Vermelho
delay(200);
digitalWrite(LEDLIpowerPin,HIGH);            // Vermelho
delay(500);

digitalWrite(LEDLIATpowerPin,HIGH);          // Amarelo
delay(200);  
digitalWrite(LEDRATpowerPin,HIGH);           // Amarelo
delay(200);
digitalWrite(LEDNBATpowerPin,HIGH);          // Amarelo
delay(500); 
 
 
digitalWrite(LEDHMpowerPin,LOW); 
digitalWrite(LEDNBATpowerPin,HIGH);
delay(200);
digitalWrite(LEDRMpowerPin,LOW);
digitalWrite(LEDRATpowerPin,HIGH);
delay(200);
digitalWrite(LEDLIATpowerPin,HIGH); 
digitalWrite(LEDLIpowerPin,LOW);
delay(500);

digitalWrite(LEDNBATpowerPin,HIGH);            // Vermelho
delay(200);
digitalWrite(LEDRATpowerPin,HIGH);            // Vermelho
delay(200);
digitalWrite(LEDLIATpowerPin,HIGH);            // Vermelho
delay(500);

digitalWrite(LEDNBATpowerPin,LOW);             
digitalWrite(LEDRATpowerPin,LOW);            
digitalWrite(LEDLIATpowerPin,LOW);
delay(500);

digitalWrite(LEDNBATpowerPin,HIGH);            // Verde
digitalWrite(LEDRATpowerPin,HIGH);             // Verde
digitalWrite(LEDLIATpowerPin,HIGH);
delay(500);

digitalWrite(LEDNBATpowerPin,LOW);              // Verde
digitalWrite(LEDRATpowerPin,LOW);               // Verde
digitalWrite(LEDLIATpowerPin,LOW);
delay(500);

digitalWrite(LEDNBATpowerPin,HIGH);              // Verde
digitalWrite(LEDRATpowerPin,HIGH);               // Verde
digitalWrite(LEDLIATpowerPin,HIGH);
digitalWrite(LEDNBATpowerPin,LOW);              // Verde
digitalWrite(LEDRATpowerPin,LOW);               // Verde
digitalWrite(LEDLIATpowerPin,LOW);

lcd.clear(); 
lcd.print(F("LEDS OK"));
delay(2500);

/************************************************************************************************************************************************/
  digitalWrite(LEDNBATpowerPin, LOW);   
  digitalWrite(LEDRATpowerPin, LOW);     
  digitalWrite(LEDLIATpowerPin, LOW);   
  digitalWrite(LEDRMpowerPin, LOW);
  digitalWrite(LEDHMpowerPin, LOW);
  digitalWrite(LEDLIpowerPin, LOW);
    
  
  }





