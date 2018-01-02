//------------------------------------------------------------------------------
//
//  Description: This file contains the macros for files in the workspace
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
extern char posL1;
extern char posL2;
extern char posL3;
extern char posL4;
extern char size_count;
extern char big;
//extern int start_moving;
//extern int moving;
extern int start_circle; //for circle pathing
extern int circle;
extern int start_figure8; //for figure8 pathing
extern int figure8;
extern int start_triangle; //for triangle pathing
extern int triangle;

//
// Function Prototype
//
void Switches_Process(void);

//
// Function Definitions
//
void Switches_Process(void){
  //==============================================================================
// Function name: Switches_Process
//
// Description: This function configures what happens when a switch is used
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
//------------------------------------------------------------------------------
  if (!(P4IN & SW1)){
    display_1 = "Current";
    posL1 = ONE_INIT;
    display_2 = "Shape";
    posL2 = TWO_INIT;
    display_3 = "=";
    posL3 = FOUR_INIT;
    display_4 = "Triangle!";
    posL4 = ONE_INIT;
    //start_triangle = ONE_INIT; //triggers circle function when S2 pressed
    Display_Process();
	//Init_PortJ(USE_IOT_WAKEUP); !*!*!*!*!*!!*!*!*! commented out for HW5
  }
  if (!(P4IN & SW2)) {
    display_1 = "Current";
    posL1 = ONE_INIT;
    display_2 = "Shape";
    posL2 = TWO_INIT;
    display_3 = "=";
    posL3 = FOUR_INIT;
    display_4 = "Figure 8!";
    posL4 = ONE_INIT;
    //start_figure8 = ONE_INIT; //triggers figure8 function when S2 pressed
    Display_Process();
	//Init_PortJ(USE_SMCLK); !*!*!*!*!*!!*!*!*! commented out for HW5
  }
//------------------------------------------------------------------------------
}