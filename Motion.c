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

// Global Variables

void PWM_FORWARD ( int DutyCycle_Right ,  int DutyCycle_Left ){

  if( !TB2CCR1 && !TB2CCR2 ){
      TB1CCR1 = DutyCycle_Right; // P3.4 Right Forward PWM duty cycle                
      TB1CCR2 = DutyCycle_Left ; // P3.5 Left Forward PWM duty cycle
  }
}

void PWM_REVERSE ( int DutyCycle_Right ,  int DutyCycle_Left  ){

  if( !TB1CCR1 && !TB1CCR2 ){
      TB2CCR1 = DutyCycle_Right; // P3.4 Right Forward PWM duty cycle                
      TB2CCR2 = DutyCycle_Left ; // P3.5 Left Forward PWM duty cycle
  }
}


void Correct_L ( void ) {
  
   TB1CCR1 = OFF; // P3.4 Right Forward PWM duty cycle                
   TB1CCR2 = OFF ; // P3.5 Left Forward PWM duty cycle
   
   TB2CCR2 = 3300 ; 
   TB1CCR1 = 2600;
  
   five_msec_sleep( 145 );
   
   TB2CCR2 = OFF ;
   TB2CCR1 = OFF ;
}

void Correct_R ( void ) {
  
   TB1CCR1 = OFF; // P3.4 Right Forward PWM duty cycle                
   TB1CCR2 = OFF ; // P3.5 Left Forward PWM duty cycle
   
   TB2CCR1 = 3300 ; 
   TB1CCR2 = 2500 ;
   
   five_msec_sleep( 90 );
   
   TB2CCR2 = OFF ;
   TB2CCR1 = OFF ;
  
  
}

void PWM_STOP(void){
  TB1CCR1= OFF;
  TB1CCR2 = OFF;
  TB2CCR1 = OFF;
  TB2CCR2 = OFF;
  
  
  
}