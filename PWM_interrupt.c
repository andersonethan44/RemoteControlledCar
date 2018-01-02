//------------------------------------------------------------------------------
//
//  Description: 
//
//
//  Ethan Anderson
//  September 2016
//  Built with IAR Embedded Workbench Version: V7.3.1.3987 (6.50.1)
//------------------------------------------------------------------------------

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

// Global Variables


//------------------------------------------------------------------------------
// TimerB1 1-2, Overflow Interrupt Vector (TAIV) handler
#pragma vector=TIMER1_B1_VECTOR
__interrupt void TIMER1_B1_ISR(void){
//==============================================================================
// Function name: TIMER0_A1_ISR
//
// Description: interrupt for timer A0.1 , A0.2 , & A0.overflow
//
// Passed : no variables passed
// Locals: no locals
// Returned: no values returned
// Globals: Timer_Counter
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
switch(__even_in_range(TB1IV,Aoverflow)){
case ZERO_INIT: break; // No interrupt
case CCR1: 
 
P3OUT ^= R_FORWARD; 
  
break;
case CCR2: 
  
P3OUT ^= L_FORWARD; 
  
break;
case Aoverflow: // overflow
//...... Add What you need happen in the interrupt ......
break;
default: break;
}
}
//----------------------------------------------------------------------------