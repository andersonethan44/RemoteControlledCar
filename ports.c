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
// Function Prototypes
//



//
// Function Definitions
//
void Init_Ports(void){
//==============================================================================
// Function name: Init_Ports
//
// Description: This function initializes all ports by calling each 
// port init funciton indivdually
//
// Passed : no variables passed
// Locals: no variables declared
// Returned: no values returned
// Globals: no globals used
//
// Author: Ethan Anderson
// Date: Sept 2016
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.60.1)
//==============================================================================
Init_Port1(); //initializes port 1
Init_Port2(); //initializes port 2
Init_Port3(); //initializes port 3
Init_Port4(); //initializes port 4
Init_PortJ(); //initializes port J
//------------------------------------------------------------------------------
}

void Init_Port1(void){
//==============================================================================
// Function name: Init_Port1
//
// Description: This function initializes all pins in Port 1
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
// Configure Port 1-------------------------------------------------------------
//#define V_DETECT_R      (0x01) // Voltage from Right Detector
//#define V_DETECT_L      (0x02) // Voltage from Right Detector
//#define LCD_BACKLITE    (0x04) // Control Signal for LCD_BACKLITE
//#define V_THUMB         (0x08) // Voltage from Thumb Wheel
//#define SPI_CS_LCD      (0x10) // LCD Chip Select
//#define RESET_LCD       (0x20) // LCD Reset
//#define SPI_SIMO        (0x40) // SPI mode
//- slave in/master out of USCI_B0
//#define SPI_SOMI        (0x80) // SPI mode
//- slave out/master in of USCI_B0
//------------------------------------------------------------------------------
P1SEL0 = BYTE_HEX_ZERO;        		// P1 set as I/0
P1SEL1 = BYTE_HEX_ZERO;       		// P1 set as I/0
P1DIR  = BYTE_HEX_ZERO;       		// Set P1 direction to input
// Pin 0
P1SEL0 |= V_DETECT_R; 		// V_DETECT_R selected
P1SEL1 |= V_DETECT_R; 		// V_DETECT_R selected
//P1OUT &=~ V_DETECT_R;
// Pin 1
P1SEL0 |= V_DETECT_L; 		// V_DETECT_L selected
P1SEL1 |= V_DETECT_L; 		// V_DETECT_L selected
//P1OUT &=~ V_DETECT_L;
// Pin 2
P1SEL0 &= ~LCD_BACKLITE; 	// IR_LED GPI/O selected
P1SEL1 &= ~LCD_BACKLITE; 	// IR_LED GPI/O selected
P1OUT |= LCD_BACKLITE; 		// P1 IR_LED Port Pin set low                        
P1DIR |= LCD_BACKLITE; 		// Set P1 IR_LED direction to output
// Pin 3
P1SEL0 |= V_THUMB; 		// V_THUMB selected
P1SEL1 |= V_THUMB; 		// V_THUMB selected
P1OUT &=~ V_THUMB;
// Pin 4
P1SEL0 &= ~SPI_CS_LCD; 		// SPI_CS_LCD GPI/O selected
P1SEL1 &= ~SPI_CS_LCD; 		// SPI_CS_LCD GPI/O selected
P1OUT |= SPI_CS_LCD; 		// SPI_CS_LCD Port Pin set high
P1DIR |= SPI_CS_LCD; 		// Set SPI_CS_LCD output direction
// Pin 5
P1SEL0 &= ~RESET_LCD; 		// RESET_LCD GPI/O selected
P1SEL1 &= ~ RESET_LCD; 		// RESET_LCD GPI/O selected
P1OUT &= ~ RESET_LCD; 		// RESET_LCD Port Pin set low
P1DIR |= RESET_LCD; 		// Set RESET_LCD output direction
// Pin 6
P1SEL0 &= ~SPI_SIMO; 		// SIMO_B selected
P1SEL1 |= SPI_SIMO; 		// SIMO_B selected
P1OUT &= ~SPI_SIMO; 		// SOMI_B is used on the LCD
// Pin 7
P1SEL0 &=~ SPI_SOMI;
P1SEL1 |= SPI_SOMI; 		// SOMI_B is used on the LCD
P1OUT &=~ SPI_SOMI; 		// SOMI_B Port Pin set for Pull-up
P1REN |= SPI_SOMI; 		// Enable pullup resistor
//------------------------------------------------------------------------------
}

void Init_Port2(void){
//==============================================================================
// Function name: Init_Port2
//
// Description: This function initializes all pins in Port 2
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
// Configure Port 2-------------------------------------------------------------
//#define USB_TXD (0x01) // 
//#define USB_RXD (0x02) // 
//#define SPI_SCK (0x04) // 
//#define UCA0    (0x08) // 
//#define UCA1    (0x10) // 
//#define CPU_TXD (0x20) // 
//#define CPU_RXD (0x40) // 
//#define UNKNOWN (0x80) // 
//------------------------------------------------------------------------------
P2SEL0 = BYTE_HEX_ZERO; // P2 set as I/0
P2SEL1 = BYTE_HEX_ZERO; // P2 set as I/0
P2DIR  = BYTE_HEX_ZERO; // Set P2 direction to input
P2OUT = BYTE_HEX_ZERO;
// Pin 0
P2SEL0 &= ~USB_TXD; //set SEL0 to 0 for USB_TXD
P2SEL1 |= USB_TXD; //set SEL1 to 1 for USB_TXD
//P2OUT &= ~USB_TXD; // set output to 0 for USB_TXD
// Pin 1
P2SEL0 &= ~USB_RXD; //set SEL0 to 0 for USB_RXD
P2SEL1 |= USB_RXD; //set SEL1 to 1 for USB_RXD
//P2OUT &= ~USB_RXD; // set output to 0 for USB_RXD
//P2REN &= ~USB_RXD; // Enable pull-down resistor
// Pin 2
P2SEL0 &= ~SPI_SCK; //set SEL0 to 0 for SPI_SCK
P2SEL1 |= SPI_SCK; //set SEL1 to 1 for SPI_SCK
P2OUT |= SPI_SCK; // set output to 1 for SPI_SCK
// Pin 3
//P2SELC &= ~UCA0;
//P2SEL1 |= UCA0;
//
//// Pin 4 
//P2SELC &= ~UCA1;
//P2SEL1 |= UCA1;
// Pin 5
P2SEL0 &= ~CPU_TXD; //set SEL0 to 0 for CPU_TXD
P2SEL1 |= CPU_TXD; //set SEL1 to 1 for CPU_TXD
P2OUT &= ~CPU_TXD; // set output to 0 for CPU_TXD
// Pin 6
P2SEL0 &= ~CPU_RXD; //set SEL0 to 0 for CPU_RXD
P2SEL1 |= CPU_RXD; //set SEL1 to 1 for CPU_RXD
P2OUT &= ~CPU_RXD; // set output to 0 for CPU_RXD
P2REN &= ~CPU_RXD; // Enable pull-down resistor
// Pin 7 (UNKNOWN SIGNAL)
P2SEL0 &= ~UNKNOWN;
P2SEL1 &= ~UNKNOWN;
P2OUT &= ~UNKNOWN;
P2REN &= ~UNKNOWN;
//------------------------------------------------------------------------------
}

void Init_Port3(void){
  //==============================================================================
// Function name: Init_Port3
//
// Description: This function initializes all pins in Port 3
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
// Configure Port 3-------------------------------------------------------------
//#define X (0x01) // 
//#define Y (0x02) // 
//#define Z_A (0x04) // 
//#define IR_LED (0x08) //
//#define R_FORWARD (0x10) // 
//#define L_FORWARD (0x20) // 
//#define R_REVERSE (0x40) //
//#define L_REVERSE (0x80) // 
//------------------------------------------------------------------------------
P3SEL0 = BYTE_HEX_ZERO; // P3 set as I/0
P3SEL1 = BYTE_HEX_ZERO; // P3 set as I/0
P3DIR  = BYTE_HEX_ZERO; // Set P3 direction to input
// Pin 0
P3SEL0 &= ~X; //set SEL0 to 0 for X
P3SEL1 &= ~X; //set SEL1 to 1 for X
P3OUT &= ~X; // set output to 0 for X
P3DIR &= ~X; // Set direction to input
P3REN &= ~X; // Enable pull-down resistor
// Pin 1
P3SEL0 &= ~Y; //set SEL0 to 0 for Y
P3SEL1 &= ~Y; //set SEL1 to 1 for Y
P3OUT &= ~Y; // set output to 0 for Y
P3DIR &= ~Y; // Set direction to input
P3REN &= ~Y; // Enable pull-down resistor
// Pin 2
P3SEL0 &= ~Z_A; //set SEL0 to 0 for Z_A
P3SEL1 &= ~Z_A; //set SEL1 to 1 for Z_A
P3OUT &= ~Z_A; // set output to 0 for Z_A
P3DIR &= ~Z_A; // Set direction to input
P3REN &= ~Z_A; // Enable pull-down resistor
// Pin 3
P3SEL0 &= ~IR_LED; //set SEL0 to 0 for IR_LED
P3SEL1 &= ~IR_LED; //set SEL1 to 1 for IR_LED
P3OUT &= ~IR_LED; // set output to 0 for IR_LED
P3DIR |= IR_LED; // Set direction to output
// Pin 4
P3SEL0 |= R_FORWARD; //set SEL0 to 0 for R_FORWARD
P3SEL1 &= ~R_FORWARD; //set SEL1 to 1 for R_FORWARD
//P3OUT &= ~R_FORWARD; // set output to 0 for R_FORWARD
P3DIR |= R_FORWARD; // Set direction to output
// Pin 5
P3SEL0 |= L_FORWARD; //set SEL0 to 0 for L_FORWARD
P3SEL1 &= ~L_FORWARD; //set SEL1 to 1 for L_FORWARD
//P3OUT &= ~L_FORWARD; // set output to 0 for L_FORWARD 
P3DIR |= L_FORWARD; // Set direction to output
// Pin 6
P3SEL0 |= R_REVERSE; //set SEL0 to 0 for R_REVERSE
P3SEL1 &= ~R_REVERSE; //set SEL1 to 1 for R_REVERSE
//P3OUT &= ~R_REVERSE; // set output to 0 for R_REVERSE 
P3DIR |= R_REVERSE; // Set direction to output
// Pin 7
P3SEL0 |= L_REVERSE; //set SEL0 to 0 for L_REVERSE
P3SEL1 &= ~L_REVERSE; //set SEL1 to 1 for L_REVERSE
//P3OUT &= ~L_REVERSE; // set output to 0 for L_REVERSE
P3DIR |= L_REVERSE; // Set direction to output
//------------------------------------------------------------------------------
}

void Init_Port4(void){
//==============================================================================
// Function name: Init_Port4
//
// Description: This function initializes all pins in Port 4
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
// Configure PORT 4
// Port 4 has only two pins
// SW1 (0x01) // Switch 1
// SW2 (0x02) // Switch 2
P4SEL0 = BYTE_HEX_ZERO; // P4 set as I/0
P4SEL1 = BYTE_HEX_ZERO; // P4 set as I/0
P4DIR = BYTE_HEX_ZERO; // Set P4 direction to input
// Switch 1
P4SEL0 &= ~SW1; // SW1 set as I/0
P4SEL1 &= ~SW1; // SW1 set as I/0
P4DIR &= ~SW1; // SW1 Direction = input
P4OUT |= SW1; // Configure pull-up resistor SW1
P4REN |= SW1; // Enable pull-up resistor SW1
P4IES |= SW1; // SW1 Hi/Lo edge interrupt
P4IFG &= ~SW1; // IFG SW1 cleared
P4IE |= SW1; // SW1 interrupt Enabled
// Switch 2
P4SEL0 &= ~SW2; // SW2 set as I/0
P4SEL1 &= ~SW2; // SW2 set as I/0
P4DIR &= ~SW2; // SW2 Direction = input
P4OUT |= SW2; // Configure pull-up resistor SW2
P4REN |= SW2; // Enable pull-up resistor SW2
P4IES |= SW2; // SW2 Hi/Lo edge interrupt
P4IFG &= ~SW2; // IFG SW2 cleared
P4IE |= SW2; // SW2 interrupt enabled
}
//------------------------------------------------------------------------------


void Init_PortJ(void){
//==============================================================================
// Function name: Init_PortJ
//
// Description: This function initializes all pins in Port J
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
// Port J Pins
//#define IOT_WAKEUP (0x01) // LED 5
//#define IOT_FACTORY (0x02) // LED 6
//#define IOT_STA_MINIAP (0x04) // LED 7
//#define IOT_RESET (0x08) // LED 8
// XINR (0x10) // XINR
// XOUTR (0x20) // XOUTR
//------------------------------------------------------------------------------
PJSEL0 = BYTE_HEX_ZERO; // PJ set as I/0
PJSEL1 = BYTE_HEX_ZERO; // PJ set as I/0
PJDIR = BYTE_HEX_ZERO; // Set PJ direction to output

PJSEL0 &= ~IOT_WAKEUP;
PJSEL1 &= ~IOT_WAKEUP;
PJOUT &= ~IOT_WAKEUP;
PJDIR |= IOT_WAKEUP; // Set PJ Pin 2 direction to output
// Pin 0
/*switch(SMCLK_INIT){
	case USE_SMCLK :                        //SWITCH 2
		PJSEL0 |= USE_SMCLK;
		PJSEL1 &= ~USE_SMCLK;
		PJOUT |= USE_SMCLK;     //output is 1
		PJDIR |= USE_SMCLK; // Set PJ Pin 1 direction to output 
		break; 
	case USE_IOT_WAKEUP :                  //SWITCH 1
		PJSEL0 &= ~IOT_WAKEUP;
		PJSEL1 &= ~IOT_WAKEUP;
		PJOUT &= ~IOT_WAKEUP;   //output is 0
		PJDIR |= IOT_WAKEUP; // Set PJ Pin 1 direction to output 
		break; 
}*/
// Pin 1
PJSEL0 &= ~IOT_FACTORY;
PJSEL1 &= ~IOT_FACTORY;
PJOUT &= ~IOT_FACTORY;
PJDIR |= IOT_FACTORY; // Set PJ Pin 2 direction to output
// Pin 2
PJSEL0 &= ~IOT_STA_MINIAP;
PJSEL1 &= ~IOT_STA_MINIAP;
PJOUT |= IOT_STA_MINIAP;
PJDIR |= IOT_STA_MINIAP; // Set PJ Pin 3 direction to output
// Pin 3
PJSEL0 &= ~IOT_RESET;
PJSEL1 &= ~IOT_RESET;
PJOUT &= ~IOT_RESET;
PJDIR |= IOT_RESET; // Set P3 Pin 4 direction to output

// XT1 Setup
// PJSEL0 |= XINR;
// PJSEL0 |= XOUTR;
//------------------------------------------------------------------------------
}
