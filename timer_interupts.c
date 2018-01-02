//------------------------------------------------------------------------------
//
//  Description: This file contains the timer intrupts
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
extern volatile int Timer_Counter;
extern volatile char SW1_PRESSED;
extern volatile char SW2_PRESSED;
extern volatile char SW1_DEBOUNCE;
extern volatile char SW2_DEBOUNCE;
extern volatile char SW1_DCOUNT;
extern volatile char SW2_DCOUNT;
extern volatile int Thumbwheel_Counter;
extern volatile int Motion_Update_Counter;
extern volatile int AVG_Compare_Counter;
volatile int time;
//------------------------------------------------------------------------------
// TimerA0 0 Interrupt handler
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_A0_ISR(void){
//==============================================================================
// Function name: Timer0_A0_ISR
//
// Description: interrupt for Timer A0 0 which updates Timer_Counter every 5msec
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
Timer_Counter++; //increment Timer_Counter variable every 5msec
AVG_Compare_Counter++;

TA0CCR0 += TA0CCR0_INTERVAL; // Add Offset to TACCR0
}

//------------------------------------------------------------------------------
// TimerA0 1-2, Overflow Interrupt Vector (TAIV) handler
#pragma vector=TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR(void){
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
switch(__even_in_range(TA0IV,Aoverflow)){
case ZERO_INIT: break; // No interrupt
case CCR1: // CCR1 used as 200msec debounce timer for switch 1
 
  SW1_DCOUNT++;
  TA0CCR1 += TA0CCR1_INTERVAL; // Add Offset to TACCR1
    if( SW1_DCOUNT > FIVE_INIT){
  //SW1_PRESSED = ZERO_INIT;
  //P4IES ^= SW1; // SW1 Lo/Hi edge interrupt
  P4IFG &= ~SW1; // Clear any current timer interrupt.
  P4IE |= SW1; // Enable the Switch Interrupt.
  TA0CCTL1 &= ~CCIE; // turn off debounce timer
  SW1_DCOUNT=ZERO_INIT;
  
  /* old code
  P4IES ^= SW1; // SW1 Lo/Hi edge interrupt
  P4IE |= SW1; // Enable the Switch Interrupt.
  TA0CCR1 += TA0CCR1_INTERVAL; // Add Offset to TACCR1
  TA0CCTL1 &= ~CCIE; // turn off debounce timer
  */
break;
case CCR2: // CCR2 used as 200msec debounce timer for switch 2
  
  SW2_DCOUNT++;
  TA0CCR2 += TA0CCR2_INTERVAL; // Add Offset to TACCR1
    if(SW2_DCOUNT > FIVE_INIT){
      //SW2_PRESSED = ZERO_INIT;
  //P4IES ^= SW2; // SW1 Lo/Hi edge interrupt
  P4IFG &= ~SW2; // Clear any current timer interrupt.
  P4IE |= SW2; // Enable the Switch Interrupt.
  TA0CCTL2 &= ~CCIE; // turn off debounce timer
  SW2_DCOUNT=ZERO_INIT;
    }
  
  /*
  P4IES ^= SW2; // SW1 Lo/Hi edge interrupt
  P4IE |= SW2; // Enable the Switch Interrupt.
  TA0CCR1 += TA0CCR2_INTERVAL; // Add Offset to TACCR1
  TA0CCTL2 &= ~CCIE; // turn off debounce timer
  */
break;
case Aoverflow: // overflow
//...... Add What you need happen in the interrupt ......
break;
default: break;
}
}
//----------------------------------------------------------------------------
}
//------------------------------------------------------------------------------
// TimerA1 0 Interrupt handler
#pragma vector = TIMER1_A0_VECTOR
__interrupt void Timer1_A0_ISR(void){
//==============================================================================
// Function name: Timer0_A1_ISR
//
// Description: interrupt for Timer A1 0 which updates Timer_Counter every 50msec
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
Thumbwheel_Counter++; //increment Timer_Counter variable every 5msec !!!!!!!!!!!!!!!!!!!change this variable

TA1CCR0 += TA1CCR0_INTERVAL; // Add Offset to TACCR0
}

//------------------------------------------------------------------------------
// TimerB0 0 Interrupt handler
#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer0_B0_ISR(void){
//==============================================================================
// Function name: Timer0_A0_ISR
//
// Description: interrupt for Timer A0 0 which updates Timer_Counter every 5msec
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
Motion_Update_Counter++; //increment Timer_Counter variable every 5msec
time ++;
TB0CCR0 += TB0CCR0_INTERVAL; // Add Offset to TACCR0
}
