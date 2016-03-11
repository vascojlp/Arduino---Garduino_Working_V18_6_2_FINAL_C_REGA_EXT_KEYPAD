void KeyPad(){
    
PROGstateHM=0;
PROGstateIL=0;
PROGstateTP=0;
PROGstateRG=0;
PROGstateSM=0;
count=0;
state = 0;
waitingInput = false;
i = 0;
num = 0;
num1 = 0;
key1 = 0;
key = 0;
  
   lcd.clear();
   lcd.print(F("PRIMA TECLA ...!"));
   delay(500);
   lcd.setCursor(0,1);
   lcd.print(F("TO CONFIG SENSORS"));
   delay(1000); 
   
   char key = keypad.getKey(); 
  
  
  }


 
