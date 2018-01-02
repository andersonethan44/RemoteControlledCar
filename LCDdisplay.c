//------------------------------------------------------------------------------
//
//  Description: This file contains the functions for making shapes with the car
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

// Global Variables=============================================================
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char posL1;
extern char posL2;
extern char posL3;
extern char posL4;
extern char thumb_adc_char[EIGHT_INIT];
extern char rightD_adc_char[EIGHT_INIT];
extern char leftD_adc_char[EIGHT_INIT];
extern char adc_char[FIVE_INIT];

extern int Motion_Left;
extern int Motion_Right;


// function prototypes
void Display_Process(void);
void HEXtoBCD(int hex_value);
//
// Function Definitions
//
void Display_Process(void){
//==============================================================================
// Function name: Display_Process
//
// Description: This function clears then sets the display
//
// Passed : no variables passed
// Locals: no locals
// Returned: no values returned
// Globals: no globals
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
  ClrDisplay();
  lcd_out(display_1, LCD_HOME_L1, posL1);
  lcd_out(display_2, LCD_HOME_L2, posL2);
  lcd_out(display_3, LCD_HOME_L3, posL3);
  lcd_out(display_4, LCD_HOME_L4, posL4);
}


//------------------------------------------------------------------------------
//******************************************************************************
// Hex to BCD Conversion
// Convert a Hex number to a BCD for display on an LCD or monitor
//
//------------------------------------------------------------------------------
void HEXtoBCD(int hex_value){
 int value;
 adc_char[ZERO_INIT] = ASCII_0;
 if (hex_value > ONE_THOUS_INIT){
 hex_value = hex_value - ONE_THOUS_INIT;
 adc_char[ZERO_INIT] = ASCII_1;
 }
 
 value = ZERO_INIT;
 while (hex_value > NINETY_NINE_INIT){
 hex_value = hex_value - ONE_HUNDR_INIT;
 value = value + ONE_INIT;
 }
 adc_char[ONE_INIT] = Baseline_ASCII + value;
 
 value = ZERO_INIT;
 while (hex_value > NINE_INIT){
 hex_value = hex_value - TEN_INIT;
 value = value + ONE_INIT;
 }
 adc_char[TWO_INIT] = Baseline_ASCII + value;
 
 adc_char[THREE_INIT] = Baseline_ASCII + hex_value;
}
//******************************************************************************
//------------------------------------------------------------------------------




void toRightDetect( unsigned int input ){
    HEXtoBCD(input);
  for(int i = ZERO_INIT;i<FOUR_INIT;i++){
  rightD_adc_char[i+THREE_INIT]=adc_char[i];
  }
  
    Motion_Right =  rightD_adc_char[FOUR_INIT];
    
}

void toLeftDetect( unsigned int input ){
    HEXtoBCD(input);
  for(int i = ZERO_INIT;i<FOUR_INIT;i++){
  leftD_adc_char[i+THREE_INIT]=adc_char[i];
  }
  
    Motion_Left = leftD_adc_char[FOUR_INIT];
}