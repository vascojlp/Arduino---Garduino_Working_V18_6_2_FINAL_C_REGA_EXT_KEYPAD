
/*********************************************************************************************************************************************
*********************************************************** ABREVIATURAS ********************************************************************/
 /* 
 * SM  = SoilMoisture
 * TPA = Air TemPerature
 * HM  = Air Humidity,
 * WSR = Water Solenoid Rega
 * WSHTPA = Water Solenoid Air Humidity and Temperature
 * MT  = Nebulizer Pressure Motor
 * LI = Light Value Photocell
 * LEDRAT = Led da rega automÃƒÆ’Ã‚Â¡tica
 * LEDTPAAT = Led dos nebulizadores  automaticos - temperatura
 * LEDHMAT = Led dos nebulizadores  automaticos - humidade
 * LEDRM = LED da rega em modo MANUAL
 * LEDHM = LED dos nebulizadores em modo MANUAL
 * 
 * RL1WSR = Relay 1 Water Solenoid Rega Control 
 * RL2WSHTPA = Relay 2 Water Solenoid Air Humidity and Temperature Control
 * RL3MT = Relay 3 Nebulizer Pressure Motor Control
 * RL4LI = Relay 4 Light Control
 
 Pins used by LCD & Keypad Shield:
  
    A0: Buttons, analog input from voltage ladder
    D4: LCD bit 4
    D5: LCD bit 5
    D6: LCD bit 6
    D7: LCD bit 7
    D8: LCD RS
    D9: LCD E
    D3: LCD Backlight (high = on, also has pullup high so default is on)
    
    delay(10 * 60 * 60 * 1000);  10 minutos de delay
      
 */ 
/********************************************************************************************************************************************
******************************************************** BIBLIOTECAS *********************************************************************/
#include <LiquidCrystal.h> 
#include <dht.h>
#include <Timer.h>
#include "Timer.h"
#include <Wire.h>
#include <RTClib.h>  // Credit: Adafruit, library do RTC
#include <SoftwareSerial.h>
#include <EEPROM.h>
#include <Keypad.h>
#include "Config.h"

/*********************************************************************************************************************************************
******************************************************** DEFINICAO DE PINOS *****************************************************************/
// Analog Pins
#define SMsensorPin A2         // Input soil moisture sensor 
#define DHT11sensorPin A1       // Input Humidity sensor and Air temperature 
#define LIsensorPin A3         // Input Light photocell sensor
int tempPin = A4;

// digital pins
#define RL1WSRpowerPin 28       // power Output to eletrovÃƒÆ’Ã‚Â¡lvula da Rega 
#define RL2WSHTPApowerPin 26    // power output to eletrovÃƒÆ’Ã‚Â¡lvula dos Nebuliadores
#define RL3MTpowerPin 27        // power output to relÃƒÆ’Ã‚Â© do motor de pressÃƒÆ’Ã‚Â£o dos nebulizadores  
#define RL4LIpowerPin 29        // power output to relÃƒÆ’Ã‚Â© da iluminaÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o 
#define RL5EXTpowerPin 30        // power output to eletrovalvula da rega no exterior da estufa

#define LEDRMpowerPin 41        // Power output to LED da rega em modo manual
#define LEDHMpowerPin 39        // power output to LED dos nebulizadores em modo manual
#define LEDLIpowerPin 37        // power output to LED da iluminaÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o em modo manual
#define LEDRM_IN 24             // Input signal do LED da rega em modo manual
#define LEDHM_IN 22             // Input signal do LED dos nebulizadores em modo manual
#define LEDLI_IN 23             // Input signal do LED da iluminaÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o em modo manual
#define LEDNBATpowerPin 38      // output power to LED do controlo dos nebulizadores em modo automatico
#define LEDRATpowerPin 40       // output power to LED da rega automatica
#define LEDLIATpowerPin 36      // output power to LED da iluminaÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o automatica

#define d_second 1000

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

byte rowPins[ROWS] = {46,47,48,49}; //connect to the row pinouts of the keypad
byte colPins[COLS] =  {50,51,52,53};//connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
              
//--- Inicializacao dos Sensores 
dht DHT;                                        //Inicializa o sensor
RTC_DS1307 RTC;

//--- Correr ILUMINACAO so 1x por dia   (esta no config.h e no config.ino)         
//unsigned long currentMillis = 0;
//unsigned long currentMillisSM = 0;

/*********************************************************************************************************************************************
************************************************************ VOID SETUP *********************************************************************/
void setup() {
  
  Serial.begin(57600);   
  lcd.begin(16, 2);                    // start the library
  keypad.addEventListener(rega); // Add an event listener for this keypad

  // Inicializacao do RTC
  Wire.begin();
  RTC.begin();
     
  //--- BOOT
  Serial.println(F("Garduino V18.6.2"));
  Serial.print(F("\n"));
  
  lcd.setCursor(0,0);                  //Situamos o cursor no caracter 0, linha 
  lcd.print(F("BOOTING..."));
  delay(1000); 
  lcd.clear();
  lcd.print(F("BOOTING......"));
  delay(1000); 
  lcd.clear();
  lcd.print(F("BOOTING........."));
  delay(1000);   
  lcd.clear();                  
  lcd.print(F("GARDUINO V18.6.2"));
  delay(1500);       
  
  //--- Config values
 Config();            
             
//--- ACERTAR A HORA 
  // Acertar_Hora();
  
   //--- Analog pins
  pinMode(SMsensorPin,INPUT);
  pinMode(DHT11sensorPin,INPUT);
  pinMode(LIsensorPin,INPUT);

  //--- Digital pins
  digitalWrite(RL1WSRpowerPin,HIGH);
  pinMode(RL1WSRpowerPin,OUTPUT);
  digitalWrite(RL2WSHTPApowerPin,HIGH);
  pinMode(RL2WSHTPApowerPin,OUTPUT);
  pinMode(RL3MTpowerPin,OUTPUT);
  digitalWrite(RL3MTpowerPin,HIGH);
  pinMode(RL4LIpowerPin,OUTPUT);
  digitalWrite(RL4LIpowerPin,HIGH);
  pinMode(RL5EXTpowerPin,OUTPUT);
  digitalWrite(RL5EXTpowerPin,HIGH);  
    
  pinMode(LEDRMpowerPin,OUTPUT);
  pinMode(LEDHMpowerPin,OUTPUT);
  pinMode(LEDLIpowerPin,OUTPUT);
  pinMode(LEDRM_IN,INPUT);
  pinMode(LEDHM_IN,INPUT);
  pinMode(LEDLI_IN,INPUT);
  pinMode(LEDNBATpowerPin,OUTPUT);
  pinMode(LEDRATpowerPin,OUTPUT);
  pinMode(LEDLIATpowerPin, OUTPUT);

//--- TESTE DOS LEDS
Teste_Leds();

//--- Print dos parametros 
Print_config_values();
}

/************************************************************* VOID LOOP *********************************************************************/
void loop() {
KeyPad();
   Data_Print();
KeyPad();
   Read_sensors();
KeyPad();
   Print_values();
KeyPad();
   Sensor_Luz();
KeyPad();
   Sensor_Humidade();
KeyPad();
   Temperatura_Estufa();
KeyPad();
   Sensor_Rega();

}
/********************************************************** FIM VOID LOOP *******************************************************************/

/***********************************************************************************************************************************/
void rega(KeypadEvent key){
    switch (keypad.getState()){  
   //case PRESSED:
     case HOLD:

//////////////////////////////////////  ESCOLHER QUAIS OS SENSORES ON OU OFF - TECLA A  ////////////////////////////////////////////////
     if (key == 'A') {                                
      
       state = 1;
                
            lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
            lcd.print(F("- PROGRAMACAO -"));           
            lcd.setCursor(0, 1);
            lcd.print(F("--- SENSORES ---  "));
            
            Serial.println(F("- PROGRAMACAO -"));
            Serial.println(F("--- SENSORES ---  "));
            Serial.print(F("\n"));
            delay(2000);
            
            lcd.clear();
              while( state == 1) {
                A:
                lcd.clear();
                lcd.setCursor(0, 0); 
                lcd.print(F("ESCOLHA SENSOR:"));                
                lcd.setCursor(0, 1);
                lcd.print(F("PRIMA TECLA..."));
                Serial.print(F("ESCOLHA SENSOR:"));
                lcd.print(F("PRIMA TECLA..."));                
                Serial.print(F("\n"));
                delay(250);
                char key = keypad.getKey();

//ESCOLHER SENSOR:      
// 1- DHT11 HUMIDADE AR
// 2- SENSOR H2O NO SOLO REGA POR %
// 3- SENSOR H2O NO SOLO REGA POR TEMPO
// 4- DHT11 TEMPERATURA NO AR
// 5- REGA EXTERIOR (NABOS)
// 6- ILUMINAÇÃO
            
                  if (key == '*') {   
                    lcd.clear();
                    lcd.setCursor(0, 0);
                    lcd.print(F("EXITING..."));
                    Serial.println(F("EXITING..."));
                    Serial.print(F("\n"));
                    delay(3000);
                    lcd.clear();
                    state = 0;
                    break;
                    }
              
                 if (key == '1') {  // sensor Humidade no ar
                    lcd.clear();
                    lcd.setCursor(0, 0); 
                    lcd.print(F("SENSOR HUMD. AR:"));
                    Serial.print(F("SENSOR HUMD. AR:"));
                    delay(2000);
                    lcd.clear();
                    lcd.setCursor(0, 0);
                    lcd.print(F("PRIMA TECLA..."));
                    lcd.setCursor(0, 1);    
                    lcd.print(F("INT.NOVO ESTADO:"));                                        
                    Serial.println(F("SENSOR HUMD. AR:"));
                    Serial.print(F("INT.NOVO ESTADO:"));
                    Serial.print(F("\n"));
                    delay(1000);
                
                   PROGstateHM = 1;
                     while (PROGstateHM == 1) {
                       char key = keypad.getKey(); 
                       if (key == '1') {
                          stateHM = 1;
                          EEPROM.write(45,stateHM);
                          lcd.clear();            
                          lcd.setCursor(0, 0);
                          lcd.print(stateHM);
                          lcd.setCursor(0, 1);
                          lcd.print(F("SENSOR ON"));
                          Serial.println(F("SENSOR HUMIDADE ON"));
                          Serial.print(F("\n"));
                          delay(3000);
                          PROGstateHM = 0;
                          //state = 0;
                          goto A;
                          break;
                          }
                        if (key == '0') {  
                          stateHM = 0;
                          EEPROM.write(45,stateHM);
                          lcd.clear(); 
                          lcd.setCursor(0, 0);
                          lcd.print(stateHM);
                          lcd.setCursor(0, 1);
                          lcd.print(F("SENSOR OFF"));
                          Serial.println(F("SENSOR HUMIDADE OFF"));
                          Serial.print(F("\n"));
                          delay(3000);
                          PROGstateHM = 0;
                          //state = 0;
                          goto A;
                          break;
                          }
                         if (key == '*') {  
                          PROGstateHM =0; 
                          lcd.clear();
                          lcd.setCursor(0, 0);
                          lcd.print(F("EXITING..."));
                          Serial.println(F("EXITING..."));
                          Serial.print(F("\n"));
                          delay(3000);
                          state = 0;
                          break;
                          }
                  
                }
              }

            if (key == '2') {  // sensor agua no solo
                lcd.clear();
                lcd.setCursor(0, 0); 
                lcd.print(F("SENSOR AG.SOLO:"));
                lcd.setCursor(0, 1);
                lcd.print(F("INT.NOVO ESTADO:"));
                Serial.println(F("SENSOR AG.SOLO:"));
                Serial.print(F("\n"));              
                Serial.println(F("NOVO ESTADO:"));
                Serial.print(F("\n"));
                  
                PROGstateSM = 1;
                  while (PROGstateSM == 1) {
                    char key = keypad.getKey();
                    if (key == '1') {
                      stateSM = 1; 
                      EEPROM.write(53, stateSM);
                      lcd.setCursor(0, 1);
                      lcd.print(stateSM);
                      delay(1000);
                      lcd.setCursor(0, 1);
                      lcd.print(F("SENSOR ON"));
                      Serial.println(F("SENSOR AGUA NO SOLO ON"));
                      Serial.print(F("\n"));
                      delay(3000);
                      PROGstateSM = 0;
                      //state = 0;
                      goto A;
                      break;
                      }
                      
                    if (key == '0') {  
                      stateSM = 0; 
                      EEPROM.write(53, stateSM);
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print(stateSM);
                      lcd.setCursor(0, 1);
                      lcd.print(F("SENSOR OFF"));
                      Serial.println(F("SENSOR AGUA NO SOLO OFF"));
                      Serial.print(F("\n"));
                      delay(3000);
                      PROGstateSM = 0;
                      //state = 0;
                      goto A;
                      break;
                      }
                      
                    if (key == '*') {  
                      PROGstateSM =0; 
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print(F("EXITING..."));
                      Serial.println(F("EXITING"));
                      Serial.print(F("\n"));
                      delay(3000);
                      PROGstateSM = 0;
                      state = 0;
                      break;
                      }
                   } 
                 }
           
          
             if (key == '3') {  // Tempo de rega
                  lcd.clear();
                  lcd.setCursor(0, 0); 
                  lcd.print(F("REGA P/TEMPO:"));
                  lcd.setCursor(0, 1);
                  lcd.print(F("INT.NOVO ESTADO:"));          // 0- OFF  1- ON
                  Serial.println(F("REGA P/TEMPO:"));
                  Serial.print(F("\n"));
                  delay(1000);                  
                  Serial.println(F("NOVO ESTADO:"));
                    
                  PROGstateRG = 1;
                  while (PROGstateRG == 1) {
                    char key = keypad.getKey();
                    
                    if (key == '1') {
                      stateRG = 1; 
                      EEPROM.write(49,stateRG);
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print(stateRG);
                      lcd.setCursor(0, 1);
                      lcd.print(F("SENSOR ON"));
                      Serial.println(F("SENSOR REGA ON"));
                      Serial.print(F("\n"));
                      delay(3000);
                      PROGstateRG = 0;
                      //state = 0;
                      goto A;
                      break;
                      }
                      
                    if (key == '0') {  
                      stateRG = 0; 
                      EEPROM.write(49, stateRG);
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print(stateRG);
                      lcd.setCursor(0, 1);
                      lcd.print(F("SENSOR OFF"));
                      Serial.println(F("SENSOR REGA OFF"));
                      Serial.print(F("\n"));
                      delay(3000);
                      PROGstateRG = 0;
                      //state=0;
                      goto A;
                      break;
                      }
                      
                    if (key == '*') {  
                      PROGstateRG = 0; 
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print(F("EXITING..."));
                      Serial.println(F("EXITING..."));
                      Serial.print(F("\n"));
                      delay(3000);
                      PROGstateRG = 0;
                      state=0;
                      break;
                      }
                   }
                  } 
          
              if (key == '4') {  // Temperatura da estufa
                    
                 lcd.clear();
                 lcd.setCursor(0, 0); 
                 lcd.print(F("SENSOR TEMP.:"));
                 lcd.setCursor(0, 1);
                 lcd.print(F("NOVO ESTADO:"));             // 0- OFF  1- ON
                 Serial.println(F("SENSOR TEMP.:"));
                 Serial.print(F("\n"));                 
                 Serial.println(F("NOVO ESTADO:"));
                 Serial.print(F("\n"));
                        
                 PROGstateTP = 1;
                   while (PROGstateTP == 1) {
                     char key = keypad.getKey();
                     
                     if (key == '1') {
                       stateTP = 1;
                       EEPROM.write(47, stateTP);
                       lcd.clear(); 
                       lcd.setCursor(0, 0);
                       lcd.print(stateTP);
                       lcd.setCursor(0, 1);
                       lcd.print(F("SENSOR ON"));
                       Serial.println(F("SENSOR TEMP. ON"));
                       Serial.print(F("\n"));
                       delay(3000);
                       PROGstateTP = 0;
                       //state = 0;
                       goto A;
                       break;
                       }
              
                     if (key == '0') {  
                       stateTP = 0; 
                       EEPROM.write(47, stateTP);
                       lcd.clear();
                       lcd.setCursor(0, 0);
                       lcd.print(stateTP);
                       lcd.setCursor(0, 1);
                       lcd.print(F("SENSOR OFF"));
                       Serial.println(F("SENSOR TEMP. OFF"));
                       Serial.print(F("\n"));
                       delay(3000);
                       PROGstateTP = 0;
                       //state = 0;
                       goto A;
                       break;
                       }
              
                     if (key == '*') {  
                       PROGstateTP =0; 
                       lcd.clear();
                       lcd.setCursor(0, 0);
                       lcd.print(F("EXITING..."));
                       Serial.println(F("EXITING..."));
                       Serial.print(F("\n"));
                       delay(3000);
                       PROGstateTP = 0;
                       state = 0;
                       break;
                       }
                     }
                   }
                   
                   
                 if (key == '5') {  // REGA EXTERIOR ESTUFA
                    
                 lcd.clear();
                 lcd.setCursor(0, 0); 
                 lcd.print(F("REGA EXTERIOR:"));
                 lcd.setCursor(0, 1);
                 lcd.print(F("NOVO ESTADO:"));             // 0- OFF  1- ON
                 Serial.println(F("REGA EXTERIOR:"));
                 Serial.print(F("\n"));                 
                 Serial.println(F("NOVO ESTADO:"));
                 Serial.print(F("\n"));
                        
                 PROGstateRE = 1;
                   while (PROGstateRE == 1) {
                     char key = keypad.getKey();
                     
                     if (key == '1') {
                       stateRE = 1;
                       EEPROM.write(63, stateRE);
                       lcd.clear(); 
                       lcd.setCursor(0, 0);
                       lcd.print(stateRE);
                       lcd.setCursor(0, 1);
                       lcd.print(F("SENSOR ON"));
                       Serial.println(F("SENSOR TEMP. ON"));
                       Serial.print(F("\n"));
                       delay(3000);
                       PROGstateRE = 0;
                       //state = 0;
                       goto A;
                       break;
                       }
              
                     if (key == '0') {  
                       stateRE = 0; 
                       EEPROM.write(63, stateRE);
                       lcd.clear();
                       lcd.setCursor(0, 0);
                       lcd.print(stateRE);
                       lcd.setCursor(0, 1);
                       lcd.print(F("SENSOR OFF"));
                       Serial.println(F("REGA EXT. OFF"));
                       Serial.print(F("\n"));
                       delay(3000);
                       PROGstateRE = 0;
                       //state = 0;
                       goto A;
                       break;
                       }
              
                     if (key == '*') {  
                       PROGstateRE =0; 
                       lcd.clear();
                       lcd.setCursor(0, 0);
                       lcd.print(F("EXITING..."));
                       Serial.println(F("EXITING..."));
                       Serial.print(F("\n"));
                       delay(3000);
                       PROGstateRE = 0;
                       state = 0;
                       break;
                       }
                     }
                   }
     
                  if (key == '6') {  // Iluminacao ESTUFA
                    
                 lcd.clear();
                 lcd.setCursor(0, 0); 
                 lcd.print(F("ILUMINACAO:"));
                 lcd.setCursor(0, 1);
                 lcd.print(F("NOVO ESTADO:"));             // 0- OFF  1- ON
                 Serial.println(F("ILUMINACAO:"));
                 Serial.print(F("\n"));                 
                 Serial.println(F("NOVO ESTADO:"));
                 Serial.print(F("\n"));
                        
                 PROGstateIL = 1;
                   while (PROGstateIL == 1) {
                     char key = keypad.getKey();
                     
                     if (key == '1') {
                       stateRE = 1;
                       EEPROM.write(73, stateIL);
                       lcd.clear(); 
                       lcd.setCursor(0, 0);
                       lcd.print(stateIL);
                       lcd.setCursor(0, 1);
                       lcd.print(F("SENSOR ON"));
                       Serial.println(F("SENSOR ILUM"));
                       Serial.print(F("\n"));
                       delay(3000);
                       PROGstateIL = 0;
                       //state = 0;
                       goto A;
                       break;
                       }
              
                     if (key == '0') {  
                       stateIL = 0; 
                       EEPROM.write(73, stateIL);
                       lcd.clear();
                       lcd.setCursor(0, 0);
                       lcd.print(stateIL);
                       lcd.setCursor(0, 1);
                       lcd.print(F("SENSOR OFF"));
                       Serial.println(F("ILUM. OFF"));
                       Serial.print(F("\n"));
                       delay(3000);
                       PROGstateIL = 0;
                       //state = 0;
                       goto A;
                       break;
                       }
              
                     if (key == '*') {  
                       PROGstateIL =0; 
                       lcd.clear();
                       lcd.setCursor(0, 0);
                       lcd.print(F("EXITING..."));
                       Serial.println(F("EXITING..."));
                       Serial.print(F("\n"));
                       delay(3000);
                       PROGstateIL = 0;
                       state = 0;
                       break;
                       }
                     }
                   }

 }
   }

//////////////////////////////////////  REGA EXTERIOR - NABOS  ////////////////////////////////////////////////
     if (key == 'D') {                                
                    
            lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
            lcd.print(F("REGA EXTERIOR..."));           
            lcd.setCursor(0, 1);
            lcd.print(F("MODO MANUAL"));
            delay(2000);
            
      digitalWrite(RL5EXTpowerPin, LOW);
      delay(1000);
      digitalWrite(RL3MTpowerPin, LOW);
      digitalWrite(LEDRATpowerPin, HIGH);
      delay(300000);
      digitalWrite(RL3MTpowerPin, HIGH);
      delay(1000);
      digitalWrite(RL5EXTpowerPin,HIGH);    // turn off Rega
      digitalWrite(LEDRATpowerPin, LOW);    // turn off LED
                   
    }
  }
}

 byte decToBcd(byte val) {
  return ((val/10*16) + (val%10));
}
byte bcdToDec(byte val) {
  return ((val/16*10) + (val%16));
}

/******************************************************************************************************************************************/
void setTime() {
 
  Serial.print(F("Please enter the current year, 00-99. - "));
  year = readByte();
  Serial.println(year);
  Serial.print(F("Please enter the current month, 1-12. - "));
  month = readByte();
  Serial.println(months[month-1]);
  Serial.print(F("Please enter the current day of the month, 1-31. - "));
  monthday = readByte();
  Serial.println(monthday);
  Serial.println(F("Please enter the current day of the week, 1-7."));
  Serial.print(F("1 Sun | 2 Mon | 3 Tues | 4 Weds | 5 Thu | 6 Fri | 7 Sat - "));
  weekday = readByte();
  Serial.println(days[weekday-1]);
  Serial.print(F("Please enter the current hour in 24hr format, 0-23. - "));
  hour = readByte();
  Serial.println(hour);
  Serial.print(F("Please enter the current minute, 0-59. - "));
  minute = readByte();
  Serial.println(minute);
  second = 0;
  Serial.println(F("The data has been entered."));
 
  // The following codes transmits the data to the RTC
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekday));
  Wire.write(decToBcd(monthday));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(byte(0));
  Wire.endTransmission();
  // Ends transmission of data
}

byte readByte() {
  while (!Serial.available()) delay(10);
  byte reading = 0;
  byte incomingByte = Serial.read();
  while (incomingByte != '\n') {
    if (incomingByte >= '0' && incomingByte <= '9')
      reading = reading * 10 + (incomingByte - '0');
    else;
    incomingByte = Serial.read();
  }
  Serial.flush();
  return reading;
}

/******************************************************************************************************************************************/
void printTime() {
  char buffer[3];
  readTime();
  Serial.print(days[weekday-1]);
  Serial.print(F(" "));
  Serial.print(months[month-1]);
  Serial.print(F(" "));
  Serial.print(monthday);
  Serial.print(F(", 20"));
  Serial.print(year);
  Serial.print(F(" "));
  /*if (hour > 12) {
    hour -= 12;
    AMPM = " PM";
  }
  else AMPM = " AM";*/
  Serial.print(hour);
  Serial.print(F(":"));
  sprintf(buffer, "%02d", minute);
  Serial.print(buffer);
  //Serial.println(AMPM);
}

/*****************************************************************************************************************************************/
void readTime() {
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.endTransmission();
  Wire.requestFrom(DS1307, 7);
  second = bcdToDec(Wire.read());
  minute = bcdToDec(Wire.read());
  hour = bcdToDec(Wire.read());
  weekday = bcdToDec(Wire.read());
  monthday = bcdToDec(Wire.read());
  month = bcdToDec(Wire.read());
  year = bcdToDec(Wire.read());
}

/*********************************************************************************************************************************************
************************************************************** FIM  DO PROGRAMA *************************************************************
*********************************************************************************************************************************************/



