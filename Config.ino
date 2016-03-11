void Config()
{

//PROGRAMACAO DE VARIAVEIS  
stateIL=EEPROM.read(43);
stateHM=EEPROM.read(45);
stateTP=EEPROM.read(47);
stateRG=EEPROM.read(49);
stateSM=EEPROM.read(53);
stateRE=EEPROM.read(63);

PROGstateHM=0;
PROGstateIL=0;
PROGstateTP=0;
PROGstateRG=0;
PROGstateSM=0;
PROGstateRE=0;
count=0;
state = 0;
waitingInput = false;
i = 0;
num = 0;
num1 = 0;
key1 = 0;
waitingInput = false;
t = EEPROM.read(35);                 // minutos 
if (t < 2 || t > 10) { t = 2; }
t1 = t * 60*1000;                    //milisegundos

  
//--- Correr a ILUMINACAO so 1x por dia
//const unsigned int i = 86400000;            // Valor em milisegundos para a iluminacao ligar-se somente uma vez em cada 24 horas
                                                  
//--- Sensor de Iluminacao

LI_min = 200;                        // Valor minimo de LUX abaixo dos quais acende a iluminacao

//--- Sensor de Humidade
HM_min = 50;  // from 20% to 90%     // Valor minimo da Humidade dentro da estufa

//--- Sensor de Temperatura
TPA_max = 35;  // from 0ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âº to 50ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Âº     // Valor maximo da temperatura dentro da estufa
TPA_valueventax = 23;                // valor maximo de temp dentro da estufa para o arranque da Ventax

//--- Sensor de Humidade no solo
SM_min = 92;                          // Value range: 44 ~100 - dry soil: midle point hm = 72 = 50% ; Hm = 75 % para rega

                                          
X = 7;                                // Hora de inicio da rega
Y = 8;  // Hora de fim da rega
W = 19;
Z = 20;
I = 7;
F = 8;
L = 19;
M = 20;

key = 0;

tempo = 0;
tempo1 = 0;
tempof = 0;
te = 0;
te1 = 0;
tef = 0;

temp1=0;
temp2=0;
temp3=0;
temp4=0;
temp5=0;
temp6=0;
temp7=0;
temp8=0;
temp9=0;
temp10=0;
temp = 0;

//Temperatura dentro do quadro eletrico
maxi = -100, mini = 100;                   // to start max/min temperature
   
//--- Correr ILUMINACAO so 1x por dia            
currentMillis = 0;
currentMillisSM = 0; 
currentMillisEXT = 0;
currentMillisRG = 0;


}




