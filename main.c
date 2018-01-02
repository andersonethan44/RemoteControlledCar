//------------------------------------------------------------------------------
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//
//  Ethan Anderson
//  September 2016
//  Built with IAR Embedded Workbench Version: V7.3.1.3987 (6.50.1)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"
#include <stdlib.h>
#include <stdio.h>
// Global Variables=============================================================
volatile unsigned char control_state[CNTL_STATE_INDEX];
volatile unsigned int Time_Sequence;
char led_smclk;
volatile char one_time;
extern int ipstate;
volatile unsigned int five_msec_count;
extern char display_line_1[DISPLAY_INIT];
extern char display_line_2[DISPLAY_INIT];
extern char display_line_3[DISPLAY_INIT];
extern char display_line_4[DISPLAY_INIT];
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char array1[9];
char *string;
extern char array2[9];
char posL1;
char posL2;
char posL3;
char posL4;
char size_count;
char big;
// for use in shapes.c
int start_circle; //for circle pathing
int circle;
int start_figure8; //for figure8 pathing
int figure8;
int start_triangle; //for triangle pathing
int triangle;
// for use in timer_interupts
volatile int Timer_Counter=ZERO_INIT;
volatile int Thumbwheel_Counter=ZERO_INIT;
volatile char SW1_PRESSED = ZERO_INIT;
volatile char SW2_PRESSED = ZERO_INIT;
volatile char SW1_DEBOUNCE = ZERO_INIT;
volatile char SW2_DEBOUNCE = ZERO_INIT;
volatile char SW1_DCOUNT = ZERO_INIT;
volatile char SW2_DCOUNT = ZERO_INIT;
// for use in TimerB (PWM)
volatile int left_forward_rate = WHEEL_PERIOD; // set PWM to 100% by default
volatile int right_forward_rate = WHEEL_PERIOD;// set PWM to 100%
volatile int right_reverse_rate = WHEEL_PERIOD;// set PWM to 100%
volatile int left_reverse_rate = WHEEL_PERIOD; // set PWM to 100%
// to init LCD to blinking
volatile char Blinking = ONE_INIT;
//ADCtoBCD variable
char thumb_adc_char[EIGHT_INIT] = "TW ";
char rightD_adc_char[EIGHT_INIT] = "RD ";
char leftD_adc_char[EIGHT_INIT] = "LD ";
//ADC thumbwheel
volatile int ADC_Thumb;
volatile int ADC_RIGHT_DETECT;
volatile int ADC_LEFT_DETECT;
char adc_char[FIVE_INIT];
// Displaying state of motion
int Motion_Left = ZERO_INIT;
int Motion_Right = ZERO_INIT;
// Detecting the black line
char Black_Line_Detect = ZERO_INIT;
char On_Black_Line = ZERO_INIT;
// while on the black line
char Line_On_Right = ZERO_INIT;
char Line_On_Left = ZERO_INIT;

char ADC_AVG_COUNTER = ZERO_INIT;

long int Right_ADC_TEMP = ZERO_INIT;
long int Left_ADC_TEMP = ZERO_INIT;
long int Right_ADC_AVG = ZERO_INIT;
long int Left_ADC_AVG = ZERO_INIT;

int Black_Threshold = 350;
int start = 0;
char Correct_Left = ZERO_INIT;
char Correct_Right = ZERO_INIT;
int AVG_Compare = ZERO_INIT;

volatile int Motion_Update_Counter;
volatile int AVG_Compare_Counter;
extern volatile int time;
char Ready = ZERO_INIT;

int Calibration = ZERO_INIT;
// for-loop variable
int i;
// globals for Serial Com
volatile char USB_Char_Tx[LARGE_RING_SIZE];
volatile unsigned int usb_rx_ring_wr = ZERO_INIT;
volatile unsigned int usb_tx_ring_wr = ZERO_INIT;
volatile unsigned int usb_tx_ring_rd = ZERO_INIT;
volatile unsigned int usb_rx_ring_rd = ZERO_INIT;
volatile char USB_Char_Rx[SMALL_RING_SIZE] ;
volatile unsigned int transmit_2_pc_ok = ZERO_INIT;

volatile unsigned int iot_rx_ring_wr = ZERO_INIT;
volatile unsigned int iot_tx_ring_wr = ZERO_INIT;
volatile unsigned int iot_tx_ring_rd = ZERO_INIT;
volatile unsigned int iot_rx_ring_rd = ZERO_INIT;
volatile char IOT_Char_Tx[LARGE_RING_SIZE];
volatile char IOT_Char_Rx[SMALL_RING_SIZE];
volatile int baud = 0;

char Temp_Char[SMALL_RING_SIZE] = " ";
char Transmit = ZERO_INIT;
int Transmission_Num;
int b;
int array;
char Transmit_Char_Low;
char Transmit_Char_High;
int macFG =0;
int temp = ZERO_INIT;
int update_display = ZERO_INIT;
int BLACK_LINE;
//==============================================================================

void main(void){
//------------------------------------------------------------------------------
// Main Program
// This is the main routine for the program. Execution of code starts here.
// The operating system is Back Ground Fore Ground.
//
//------------------------------------------------------------------------------
    Init_Ports();                             // Initialize Ports
  Init_Clocks();                            // Initialize Clock System
  Init_Conditions();
  Time_Sequence = ZERO_INIT;                        
  Init_Timers();                            // Initialize Timers
  five_msec_sleep(FIFTY_INIT);              // 250 msec delay for the clock to settle
  Init_LCD();                               // Initialize LCD
  Init_ADC();
  Init_Serial_UCA0(); // Initialize Serial Port for USB
  Init_Serial_UCA1();

//             1234567890
  display_1 = "";
  posL1 = ZERO_INIT;
  display_2 = "";
  posL2 = ZERO_INIT;
  display_3 = "";
  posL3 = ZERO_INIT;
  display_4 = "WAITINPUT";
  posL4 = ZERO_INIT;
  big = ZERO_INIT;
  Display_Process();
 // five_msec_sleep(THREE_HUNDR_INIT); 
  Transmission_Num = 0;
  transmit_2_pc_ok = 0;

baud = 0; // 0 = 9600, 1 = 115200
 
PJOUT &= ~ IOT_WAKEUP;
//PJOUT |= IOT_STA_MINAP;
PJOUT &= ~IOT_FACTORY;
PJOUT &= ~IOT_RESET;
 five_msec_sleep(10);  
 
PJOUT |= IOT_RESET;

//PJOUT &= ~IOT_STA_MINIAP;
//five_msec_sleep(THREE_HUNDR_INIT); 
// Pin 1

//------------------------------------------------------------------------------
// Begining of the "While" Operating System
//------------------------------------------------------------------------------
Wifi_Setup();
while(ALWAYS) {
  IPADDR();
  if (Motion_Update_Counter >= 2000){
  //Transmit_Str(IOT_Char_Rx);
    
    Display_Process();
  PJOUT &= ~IOT_RESET;
  five_msec_sleep(10);  
  PJOUT |= IOT_RESET;
  if (start == 1){
   //itoa(time, string,10);
    //display_4 = string ;
  }
  Motion_Update_Counter = 0;
  }
Commands(IOT_Char_Rx);
Commands(USB_Char_Rx); 

} // end while
 
 
}
// END MAIN
