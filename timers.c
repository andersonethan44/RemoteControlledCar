//------------------------------------------------------------------------------
//
//  Description: This file contains the macros for files in the workspace
//
//
// Ethan Anderson
//  September 2016
//  Built with IAR Embedded Workbench Version: V7.3.1.3987 (6.50.1)
//------------------------------------------------------------------------------

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

//
// Global Variables
//
extern volatile unsigned char control_state[CNTL_STATE_INDEX];
extern volatile unsigned int Time_Sequence;
extern char led_smclk;
extern volatile char one_time;
extern volatile unsigned int five_msec_count;
extern volatile int Timer_Counter;
extern volatile int left_forward_rate;
extern volatile int right_forward_rate;
extern volatile int right_reverse_rate;
extern volatile int left_reverse_rate;

//
// Function Prototypes


//
// Function Definitions
//
void Init_Timers(void){
//==============================================================================
// Function name: Timer_code
//
// Description: Timer Configurations
//
// Passed : no variables passed
// Locals: no local variables
// Returned: no values returned
// Globals: no globals
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
  Init_Timer_A0(); // 
 // Init_Timer_A1(); //
  Init_Timer_B0(); //
  Init_Timer_B1(); //
  Init_Timer_B2();   //  Required for provided compiled code to work
//------------------------------------------------------------------------------
}

//------------------------------------------------------------------------------
// Timer A0 initialization sets up both A0_0 and A0_1-A0_2
void Init_Timer_A0(void) {
//==============================================================================
// Function name: Init_Timer_A0
//
// Description: initializes timer A0
//
// Passed : no variables passed
// Locals: no local variables
// Returned: no values returned
// Globals: no globals
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
TA0CTL = TASSEL__SMCLK; // SMCLK source
TA0CTL |= TACLR; // Resets TA0R, clock divider, count direction
TA0CTL |= MC__CONTINOUS; // Continuous up
TA0CTL |= ID__4; // Divide clock by 2
TA0CTL &= ~TAIE; // Disable Overflow Interrupt
TA0CTL &= ~TAIFG; // Clear Overflow Interrupt flag
TA0EX0 = TAIDEX_7; // Divide clock by an additional 8

TA0CCR0 = TA0CCR0_INTERVAL; // CCR0
TA0CCTL0 &= ~CCIE; // CCR0 enable interrupt

TA0CCR1 = TA0CCR1_INTERVAL; // CCR1
TA0CCTL1 &= ~CCIE; // CCR1 disable interrupt
TA0CCR2 = TA0CCR2_INTERVAL; // CCR2
TA0CCTL2 &= ~CCIE; // CCR2 disable interrupt


}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Timer A1 initialization sets up both A1_0 and A1_1-A1_2
void Init_Timer_A1(void) {
//==============================================================================
// Function name: Init_Timer_A0
//
// Description: initializes timer A0
//
// Passed : no variables passed
// Locals: no local variables
// Returned: no values returned
// Globals: no globals
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
TA1CTL = TASSEL__SMCLK; // SMCLK source
TA1CTL |= TACLR; // Resets TA1R, clock divider, count direction
TA1CTL |= MC__CONTINOUS; // Continuous up
TA1CTL |= ID__2; // Divide clock by 2

TA1EX0 = TAIDEX_7; // Divide clock by an additional 8

TA1CCR0 = TA1CCR0_INTERVAL; // CCR0
TA1CCTL0 |= CCIE; // CCR0 enable interrupt

TA1CCR1 = TA1CCR1_INTERVAL; // CCR1
TA1CCTL1 &= ~CCIE; // CCR1 disable interrupt
TA1CCR2 = TA1CCR2_INTERVAL; // CCR2
TA1CCTL2 &= ~CCIE; // CCR2 disable interrupt

TA1CTL &= ~TAIE; // Disable Overflow Interrupt
TA1CTL &= ~TAIFG; // Clear Overflow Interrupt flag
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Timer B0 initialization sets up both A0_0 and A0_1-A0_2
void Init_Timer_B0(void) {
//==============================================================================
// Function name: Init_Timer_A0
//
// Description: initializes timer A0
//
// Passed : no variables passed
// Locals: no local variables
// Returned: no values returned
// Globals: no globals
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
TB0CTL = TASSEL__SMCLK; // SMCLK source
TB0CTL |= TACLR; // Resets TA0R, clock divider, count direction
TB0CTL |= MC__CONTINOUS; // Continuous up
TB0CTL |= ID__4; // Divide clock by 2

TB0EX0 = TAIDEX_7; // Divide clock by an additional 8

TB0CCR0 = TB0CCR0_INTERVAL; // CCR0
TB0CCTL0 |= CCIE; // CCR0 enable interrupt

TB0CCR1 = TB0CCR1_INTERVAL; // CCR1
TB0CCTL1 &= ~CCIE; // CCR1 disable interrupt
TB0CCR2 = TB0CCR2_INTERVAL; // CCR2
TB0CCTL2 &= ~CCIE; // CCR2 disable interrupt

TB0CTL &= ~TAIE; // Disable Overflow Interrupt
TB0CTL &= ~TAIFG; // Clear Overflow Interrupt flag
}
//------------------------------------------------------------------------------


void Init_Timer_B1(void) {
//----------------------------------------------------------------------------
// SMCLK source, up count mode, PWM Right Side
//----------------------------------------------------------------------------

  TB1CTL = TBSSEL__SMCLK;              // SMCLK
  TB1CTL |= MC_1;                      // Up Mode
  TB1CTL |= TBCLR;                     // Clear TAR


  right_forward_rate = OFF;            // Set Right Forward Off
  left_forward_rate = OFF;             // Set Left Forward Off

  TB1CCR0 = WHEEL_PERIOD;              // PWM Period
  TB1CCTL1 = OUTMOD_7;                 // CCR1 reset/set
  TB1CCR1 = right_forward_rate;        // P3.4 Right Forward PWM duty cycle
  TB1CCTL2 = OUTMOD_7;                 // CCR2 reset/set
  TB1CCR2 = left_forward_rate ;        // P3.5 Left Forward PWM duty cycle

//----------------------------------------------------------------------------
}

void Init_Timer_B2(void) {
//----------------------------------------------------------------------------
// SMCLK source, up count mode, PWM Right Side
//----------------------------------------------------------------------------

  TB2CTL = TBSSEL__SMCLK;              // SMCLK
  TB2CTL |= MC_1;                      // Up Mode
  TB2CTL |= TBCLR;                     // Clear TAR


  right_reverse_rate = OFF;            // Set Right Forward Off
  left_reverse_rate = OFF;             // Set Left Forward Off

  TB2CCR0 = WHEEL_PERIOD;              // PWM Period
  TB2CCTL1 = OUTMOD_7;                 // CCR1 reset/set
  TB2CCR1 = right_reverse_rate;        // P3.4 Right reverse PWM duty cycle
  TB2CCTL2 = OUTMOD_7;                 // CCR2 reset/set
  TB2CCR2 = left_reverse_rate ;        // P3.5 Left reverse PWM duty cycle

//----------------------------------------------------------------------------
}

void Timer_code(void){
//==============================================================================
// Function name: Timer_code
//
// Description: Timer A0 interrupt code
//
// Passed : no variables passed
// Locals: one_time
// Returned: no values returned
// Globals: no globals
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
  Time_Sequence++;
  one_time = ONE_INIT;
  if (five_msec_count < ONE_THOUS_INIT){
    five_msec_count++;
  }
//------------------------------------------------------------------------------
}


void five_msec_sleep(unsigned int fivemsec){
//==============================================================================
// Function name: five_msec_sleep
//
// Description: This function puts the system to sleep for a specified time
//
// Passed : unsigned int fivemsec
// Locals: five_msec_count
// Returned: no values returned
// Globals: no globals
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
//------------------------------------------------------------------------------
//Each count passed is at least x times 5 milliseconds
  Timer_Counter = ZERO_INIT;
  TA0CCTL0 &= ~CCIFG;
  TA0CCTL0 |= CCIE;
  while( Timer_Counter < fivemsec);
  TA0CCTL0 &= ~CCIE;
//------------------------------------------------------------------------------
}
