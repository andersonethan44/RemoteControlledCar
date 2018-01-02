//------------------------------------------------------------------------------
//
//  Description: This file contains the switch intrupts
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
extern volatile char SW1_PRESSED;
extern volatile char SW2_PRESSED;
extern volatile char SW1_DEBOUNCE;
extern volatile char SW2_DEBOUNCE;
extern volatile char SW1_DCOUNT;
extern volatile char SW2_DCOUNT;

extern volatile char Blinking;

extern int circle;
extern int triangle;

//------------------------------------------------------------------------------
// Port 4 interrupt. For switches, they are disabled for the duration
// of the debounce timer. Flag is set that user space can check.


#pragma vector=PORT4_VECTOR

__interrupt void switch_interrupt(void) {
//==============================================================================
// Function name: switch_interrupt
//
// Description: interrupt for timer switches
//
// Passed : no variables passed
// Locals: no locals
// Returned: no values returned
// Globals: SW1_PRESSED, SW2_PRESSED, SW1_DCOUNT, SW2_DCOUNT
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
// Switch 1
if (P4IFG & SW1) {
  
  SW1_DCOUNT = ONE_INIT;
  SW1_PRESSED++; // Set a variable to identify the switch has been pressed.
  //SW1_DEBOUNCE = !SW1_DEBOUNCE; // Set a variable to identify the switch is being debounced.
  //SW1_DCOUNT = ZERO_INIT; // Reset the count required of the debounce.
  P4IE &= ~SW1; // Disable the Switch Interrupt.
  P4IFG &= ~SW1; // Clear any current timer interrupt.
  TA0CCR1 = TA0R + TA0CCR1_INTERVAL;
  TA0CCTL1 &= ~TAIFG; // Clear any current timer interrupt.
  TA0CCTL1 |= CCIE; // turn on debounce timer

}
// Switch 2
if (P4IFG & SW2) {
  
  SW2_DCOUNT = ONE_INIT;
  SW2_PRESSED++; // Set a variable to identify the switch has been pressed.
  //SW1_DEBOUNCE = !SW1_DEBOUNCE; // Set a variable to identify the switch is being debounced.
  //SW1_DCOUNT = ZERO_INIT; // Reset the count required of the debounce.
  P4IE &= ~SW2; // Disable the Switch Interrupt.
  P4IFG &= ~SW2; // Clear any current timer interrupt.
  TA0CCR2 = TA0R + TA0CCR2_INTERVAL;
  TA0CCTL2 &= ~TAIFG; // Clear any current timer interrupt.
  TA0CCTL2 |= CCIE; // CCR2 enable interrupt - timer for SW2 debounce

}

}
//------------------------------------------------------------------------------