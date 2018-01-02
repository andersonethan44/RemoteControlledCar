//
// Code development module
//==============================================================================

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

//
// Project 3b code
//

// Circle
//similar to code before, but only one wheel on at a time

void Circle(){
//==============================================================================
// Function name: Circle
//
// Description: This function moves the car in a small circle twice
//
// Passed : None
// Locals: TIME_COUNTER
// Returned: None
// Globals: None
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
// 0.5 second delay 
five_msec_sleep( ONE_TENTH_SEC ); // 200ms delay

// turn only the right wheel on
P3OUT |= R_FORWARD; // turn on Right wheel in forward direction

// keep the wheels on for 150 msec
five_msec_sleep( TWO_FIFTY_INIT ); // 250 msec delay

// turn them off after-wards
P3OUT &= ~R_FORWARD; // turn off wheel-forward
P3OUT &= ~L_FORWARD; // turn on wheel-forward
//==============================================================================
}

// Figure 8 - when switch is hit - runs twice
//half circle - full circle - half circle (direction matters)
void Figure8(){
//==============================================================================
// Function name: Figure8
//
// Description: This function moves the car in a figure 8, twice
//
// Passed : None
// Locals: TIME_COUNTER
// Returned: None
// Globals: None
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
// 0.5 second delay 
five_msec_sleep( ONE_TENTH_SEC ); // 200ms delay

// turn only the right wheel on
P3OUT |= R_FORWARD; // turn on Right wheel in forward direction

// keep the wheels on for 150 msec
five_msec_sleep( TWO_FIFTY_INIT ); // 250 msec delay

// turn them off after-wards
P3OUT &= ~R_FORWARD; // turn off wheel-forward
P3OUT &= ~L_FORWARD; // turn on wheel-forward
//==============================================================================
}

// triangle - when other switch is hit - runs twice
//straight for a time, turn 30degrees, straight again, repeat
void Triangle(){
//==============================================================================
// Function name: Triangle
//
// Description: This function moves the car in a Triangle, twice
//
// Passed : None
// Locals: TIME_COUNTER
// Returned: None
// Globals: None
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
// 0.5 second delay 
five_msec_sleep( ONE_TENTH_SEC ); // 200ms delay

// turn only the right wheel on
P3OUT |= R_FORWARD; // turn on Right wheel in forward direction

// keep the wheels on for 150 msec
five_msec_sleep( TWO_FIFTY_INIT ); // 250 msec delay

// turn them off after-wards
P3OUT &= ~R_FORWARD; // turn off wheel-forward
P3OUT &= ~L_FORWARD; // turn on wheel-forward
//==============================================================================
}