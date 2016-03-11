void Read_sensors() {
 
  DateTime myRTC = RTC.now();
  
 //--- SENSOR HUMIDADE
  DHT.read11(DHT11sensorPin);             //Le as informacoes do sensor
  HM_value = DHT.humidity;

//--- SENSOR ILUMINACAO
  Hr = (myRTC.hour());
  
  LI_val = analogRead(LIsensorPin);                //DESMARCAR PARA CORRER A VERSAO FINAL
  LI_val = 1000 - LI_val;
 
 //--- SENSOR SENSOR HUMIDADE SOLO 
  Hr = (myRTC.hour());
  
  SM_val = analogRead(2);                    
  SM_val = (1405 - SM_val)*0.100;   //escala de --- 395(100%) - 1022(0%)
  
 //--- SENSOR TEMP ESTUFA
  DHT.read11(DHT11sensorPin);     
  TPA_value = DHT.temperature;
  
  if(TPA_value > 25) {
    TPA_value = TPA_value - 4; 
    } else{ TPA_value = TPA_value; }
   
//--- SENSOR TEMP QUADRO
Temperatura_Quadro();

  
  
  }





