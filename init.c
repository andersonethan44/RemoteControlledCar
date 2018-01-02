//------------------------------------------------------------------------------
//
//  Description: This file contains to intialize the system
//
//
//  Ethan Anderson
//  September 2016
//  Built with IAR Embedded Workbench Version: V7.3.1.3987 (6.50.1)
//------------------------------------------------------------------------------
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

//
// Globals
//
extern char display_line_1[DISPLAY_INIT];
extern char display_line_2[DISPLAY_INIT];
extern char display_line_3[DISPLAY_INIT];
extern char display_line_4[DISPLAY_INIT];
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;

//
// Fucntion Prototypes
//
void Init_Conditions(void);

//
// Function Definitions
//
void Init_Conditions(void){
//==============================================================================
// Function name: Init_Conditions
//
// Description: This function initializes display conditions
//
// Passed : no variables passed
// Locals: no locals
// Returned: no values returned
// Globals: no globals
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================-
// Interrupts are disabled by default, enable them.
  enable_interrupts();
  display_1 = &display_line_1[ZERO_INIT];
  display_2 = &display_line_2[ZERO_INIT];
  display_3 = &display_line_3[ZERO_INIT];
  display_4 = &display_line_4[ZERO_INIT];

//------------------------------------------------------------------------------
}