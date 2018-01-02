//------------------------------------------------------------------------------
//
//  Description: This file contains the functions for making shapes with the car
//
//
//  Matthew Sonnenberg
//  September 2016
//  Built with IAR Embedded Workbench Version: V7.3.1.3987 (6.50.1)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

// Global Variables=============================================================
extern int start_circle; //for circle pathing
extern int circle;
extern int start_figure8; //for figure8 pathing
extern int figure8;
extern int start_triangle; //for triangle pathing
extern int triangle;

extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char posL1;
extern char posL2;
extern char posL3;
extern char posL4;

// function prototypes
void forward(void);
void stop(void);
void Circle(void);
void Figure8(void);
void Triangle(void);
void clockwise(void);
void counterclock(void);
void reverse(void);

//
// Function Definitions
//

void Figure8(void){
//==============================================================================
// Function name: Circle
//
// Description: This function moves the car in a Figure 8
//
// Passed : None
// Locals: TIME_COUNTER
// Returned: None
// Globals: None
//
// Author: Matthew Sonnenberg
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
// slight delay
five_msec_sleep( ONE_TENTH_SEC );
five_msec_sleep( ONE_TENTH_SEC );

int j; // loop variable

// Half circle left
P3OUT |= R_FORWARD; 
P3OUT |= L_FORWARD; 

for(j=ZERO_INIT;j<TEN_INIT;j++){
P3OUT &= ~L_FORWARD;
five_msec_sleep( SEVENTEEN_INIT );

P3OUT |= L_FORWARD; 
five_msec_sleep( TWO_INIT );

} //end for loop

// turn them off after-wards
P3OUT &= ~R_FORWARD; 
P3OUT &= ~L_FORWARD; 

//------------------------------------------------------------------------------
// Full circle right

P3OUT |= R_FORWARD; 
P3OUT |= L_FORWARD;

for(j=ZERO_INIT;j<TWENTY_INIT;j++){
P3OUT &= ~R_FORWARD;
five_msec_sleep( SEVENTEEN_INIT );

P3OUT |= R_FORWARD; 
five_msec_sleep( TWO_INIT );

} //end for loop

// turn them off after-wards
P3OUT &= ~R_FORWARD; 
P3OUT &= ~L_FORWARD; 

//------------------------------------------------------------------------------
// Half circle left

P3OUT |= R_FORWARD; 
P3OUT |= L_FORWARD;

for(j=ZERO_INIT;j<ELEVEN_INIT;j++){
P3OUT &= ~L_FORWARD;
five_msec_sleep( SEVENTEEN_INIT );

P3OUT |= L_FORWARD; 
five_msec_sleep( TWO_INIT );

} //end for loop

// turn them off after-wards
P3OUT &= ~R_FORWARD; 
P3OUT &= ~L_FORWARD; 
//==============================================================================
}

void Circle(void){
//==============================================================================
// Function name: Figure8
//
// Description: This function moves the car in a Circle 
//
// Passed : None
// Locals: TIME_COUNTER
// Returned: None
// Globals: None
//
// Author: Matthew Sonnenberg
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//============================================================================== 
five_msec_sleep( ONE_TENTH_SEC ); 

int j; // loop variable

// turn both wheels on
P3OUT |= R_FORWARD; 
P3OUT |= L_FORWARD; 

for(j=ZERO_INIT;j<TEN_INIT;j++){
P3OUT &= ~L_FORWARD;
five_msec_sleep( THIRTEEN_INIT );

P3OUT |= L_FORWARD; 
five_msec_sleep( TWO_INIT );

} //end for loop

// turn them off after-wards
P3OUT &= ~R_FORWARD; 
P3OUT &= ~L_FORWARD; 
//==============================================================================
}

void Triangle(void){
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
// Author: Matthew Sonnenberg
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================

int j; // for-loop variable

for(j=ZERO_INIT;j<THREE_INIT;j++){ // loops 3 times
  
// GO straight for half a side length
P3OUT |= R_FORWARD; // turn on Right wheel in forward direction
P3OUT |= L_FORWARD; // turn on Left wheel in forward direction
five_msec_sleep( HALF_SIDE_LENGTH ); 

// turn 60degrees
P3OUT &= ~L_FORWARD;
five_msec_sleep( SIXTY_DEGREES );
P3OUT |= L_FORWARD;

// GO straight for a half a side length
five_msec_sleep( HALF_SIDE_LENGTH ); 

// turn wheels off after-wards
P3OUT &= ~R_FORWARD; 
P3OUT &= ~L_FORWARD; 

} // end of for-loop

//==============================================================================
}


void stop(void){
  P3OUT &= ~L_FORWARD;
  P3OUT &= ~R_FORWARD;
  P3OUT &= ~L_REVERSE;
  P3OUT &= ~R_REVERSE;
}

void forward(void){

  if(!(L_FORWARD & R_FORWARD)){
  
  P3OUT |= L_FORWARD;
  P3OUT |= R_FORWARD;
 
  }
}



void clockwise(void){

  P3OUT |= L_FORWARD;
  P3OUT |= R_REVERSE;

  
}
void counterclock(void){
     
    P3OUT |= L_REVERSE;
    P3OUT |= R_FORWARD;
    
}
void reverse(void){
  
  if(!(L_REVERSE & R_REVERSE)){
  
  P3OUT |= L_REVERSE;
  P3OUT |= R_REVERSE;
 
  }
   
}