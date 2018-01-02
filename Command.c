#include "msp430.h"
#include "macros.h"
#include "functions.h"
extern int b;
extern char display_line_1[DISPLAY_INIT];
extern char display_line_2[DISPLAY_INIT];
extern char display_line_3[DISPLAY_INIT];
extern char display_line_4[DISPLAY_INIT];
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern volatile char USB_Char_Rx[SMALL_RING_SIZE] ;
extern volatile int baud;
extern int array;
extern int BLACK_LINE;
extern int start;
char *comstring;
// L = BAUDLOW, H= BAUDHIGH, F= FORWARD, R= RIGHT, E = LEFT
void Commands(volatile char* input){
  for (b = 0; b<= 13; b++){
if(input[b] == '.' && input[b+1] == 'L' && input[b+2] == '\r'){
display_3 = "BAUDLOW";

Display_Process();
baud = 0;
for (array = 0; array <= 15; array ++){ input[array] = '\0';}
Transmit_Str("HIGH BAUD, 115200 ");

}


else if(input[b] == '.' && input[b+1] == 'H' && input[b+2] == '\r'){
display_3 = "BAUDHIGH";
Display_Process();
baud = 1;
for (array = 0; array <= 15; array ++){ input[array] = '\0';}
Transmit_Str("LOW BAUD, 9600 ");


}

else if(input[b] == '.' && input[b+1] == 'F' && input[b+2] == '\r'){
display_3 = "FORWARD";
Display_Process();
start = 1;
 PWM_REVERSE ( 9000  ,  8000 );              
 five_msec_sleep(250);              
PWM_STOP();
five_msec_sleep(1);


 five_msec_sleep(ONE_INIT); 
for (array = 0; array <= 15; array ++){ input[array] = '\0';}
Transmit_Str("FORWARD ");


}
else if(input[b] == '.' && input[b+1] == 'X' && input[b+2] == '\r'){
display_3 = "FORXXX";
Display_Process();
start = 1;
 PWM_REVERSE ( 7500  ,  9000 );              
 five_msec_sleep(2000);              
PWM_STOP();
five_msec_sleep(1);


 five_msec_sleep(ONE_INIT); 
for (array = 0; array <= 15; array ++){ input[array] = '\0';}
Transmit_Str("FORWARD ");


}

else if(input[b] == '.' && input[b+1] == 'R' && input[b+2] == '\r'){
display_3 = "RIGHT";
Display_Process();

for (array = 0; array <= 15; array ++){ input[array] = '\0';}

  PWM_REVERSE ( 2000  ,  9000 );              
 five_msec_sleep(250);              
PWM_STOP();
five_msec_sleep(1);



//else if (input[b] )
}

else if(input[b] == '.' && input[b+1] == 'E' && input[b+2] == '\r'){
display_3 = "LEFT";
Display_Process();

   PWM_FORWARD ( 8600  ,  2000 );              
 five_msec_sleep(250);              
PWM_STOP();
five_msec_sleep(1);
  
  
  



for (array = 0; array <= 15; array ++){ input[array] = '\0';}




//else if (input[b] )
}
else if(input[b] == '.' && input[b+1] == 'B' && input[b+2] == '\r'){
display_3 = "BLINE";
PWM_REVERSE(8000,8000);
Display_Process();
  

for (array = 0; array <= 15; array ++){ input[array] = '\0';}
//else if (input[b] )
}
  }}
