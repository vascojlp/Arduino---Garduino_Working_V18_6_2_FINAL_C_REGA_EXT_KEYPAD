//PROGRAMACAO DE VARIAVEIS
int state;
int stateIL;
int stateHM;
int stateTP;
int stateRG;
int stateSM;
int stateRE;
int PROGstateHM;
int PROGstateIL;
int PROGstateTP;
int PROGstateRG;
int PROGstateSM; 
int PROGstateRE;
int count;
boolean waitingInput;
int i;
int num;
int num1;
int key1;
int t;
int t1;

                                                
//--- Sensor de Iluminacao
int LI_min;

//--- Sensor de Humidade
int HM_min;

//--- Sensor de Temperatura
int TPA_max;
int TPA_valueventax;    // valor maximo para o arranque da Ventax

//--- Sensor de Humidade no solo
int SM_min ;
                                          
int X ;
int Y ;
int I ;
int F ;
int L ;
int M ;
int W;
int Z;

char key;

int tempo;
int tempo1;
int tempof; 
int te;
int te1;
int tef;

float HM_value;
int Hr;
float LI_val; 
int SM_val;
int TPA_value;

   int temp1;
   int temp2;
   int temp3;
   int temp4;
   int temp5;
   int temp6;
   int temp7;
   int temp8;
   int temp9;
   int temp10;
   int temp;
   
//Temperatura dentro do quadro eletrico
int maxi;
int mini;

//--- Correr ILUMINACAO so 1x por dia            
unsigned long currentMillis;
unsigned long currentMillisSM;
unsigned long currentMillisEXT;
unsigned long currentMillisRG;


/************************************************ RTC - Definicao Chars **********************************************************************/
const int DS1307 = 0x68; // Address of DS1307 see data sheets
const char* days[] =
{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char* months[] =
{"January", "February", "March", "April", "May", "June", "July", "August","September", "October", "November", "December"};
 
byte second = 0;
byte minute = 0;
byte hour = 0;
byte weekday = 0;
byte monthday = 0;
byte month = 0;
byte year = 0;
    





