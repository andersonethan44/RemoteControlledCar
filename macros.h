//------------------------------------------------------------------------------
//
//  Description: This file contains the macros for files in the workspace
//
//
//  Ethan Anderson
//  September 2016
//  Built with IAR Embedded Workbench Version: V7.3.1.3987 (6.50.1)
//------------------------------------------------------------------------------

// Required defines
// In the event the universe no longer exists, this bit will reset
#define ALWAYS                  (1)
#define CNTL_STATE_INDEX        (3) // Control States
//#define LED1                 (0x01) // LED 1
//#define LED2                 (0x02) // LED 2
//#define LED3                 (0x04) // LED 3
//#define LED4                 (0x08) // LED 4
//#define LED5                 (0x10) // LED 5
//#define LED6                 (0x20) // LED 6
//#define LED7                 (0x40) // LED 7
//#define LED8                 (0x80) // LED 8
#define SW1                  (0x01) // Switch 1
#define SW2                  (0x02) // Switch 2
#define CNTL_STATE_INDEX        (3)
// LCD
#define LCD_HOME_L1	        0x80
#define LCD_HOME_L2         	0xA0
#define LCD_HOME_L3         	0xC0
#define LCD_HOME_L4         	0xE0


//MACROS for clocks.c===========================================================
#define FLLN_BITS          (0x03ffu)
#define FLLN_255           (0x00ffu)
#define CSLOCK                (0x01) // Any incorrect password locks registers

// Port J Pins
#define XINR                 (0x10) // XINR
#define XOUTR                (0x20) // XOUTR
#define CLEAR_REGISTER     (0X0000)

//MACROS for ports.c============================================================
// Configure Port 1-------------------------------------------------------------
#define V_DETECT_R      (0x01) // Voltage from Right Detector
#define V_DETECT_L      (0x02) // Voltage from Right Detector
#define LCD_BACKLITE    (0x04) // Control Signal for LCD_BACKLITE
#define V_THUMB         (0x08) // Voltage from Thumb Wheel
#define SPI_CS_LCD      (0x10) // LCD Chip Select
#define RESET_LCD       (0x20) // LCD Reset
#define SPI_SIMO        (0x40) // SPI mode
//- slave in/master out of USCI_B0
#define SPI_SOMI        (0x80) // SPI mode
//- slave out/master in of USCI_B0
//------------------------------------------------------------------------------

// Configure Port 2-------------------------------------------------------------
#define USB_TXD (0x01) // 
#define USB_RXD (0x02) // 
#define SPI_SCK (0x04) // 
//#define UCA0    (0x08) // 
//#define UCA1    (0x10) // 
#define CPU_TXD (0x20) // 
#define CPU_RXD (0x40) // 
#define UNKNOWN (0x80) // 
//------------------------------------------------------------------------------

// Configure Port 3-------------------------------------------------------------
#define X (0x01) // 
#define Y (0x02) // 
#define Z_A (0x04) // 
#define IR_LED (0x08) //
#define R_FORWARD (0x10) // 
#define L_FORWARD (0x20) // 
#define R_REVERSE (0x40) //
#define L_REVERSE (0x80) // 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Configure PORT 4
// Port 4 has only two pins
// Port 4 Pins
#define SW1 (0x01) // Switch 1
#define SW2 (0x02) // Switch 2
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Port J Pins
#define IOT_WAKEUP (0x01) // LED 5
#define IOT_FACTORY (0x02) // LED 6
#define IOT_STA_MINIAP (0x04) // LED 7
#define IOT_RESET (0x08) // LED 8
// XINR (0x10) // XINR
// XOUTR (0x20) // XOUTR
//------------------------------------------------------------------------------

//
// General MACROS
//
#define DISPLAY_INIT (11) 
#define ZERO_INIT    (0)
#define ONE_INIT     (1)
#define TWO_INIT     (2)
#define THREE_INIT   (3)
#define FOUR_INIT    (4)
#define FIVE_INIT    (5)
#define SIX_INIT     (6)
#define SEVEN_INIT   (7)
#define EIGHT_INIT   (8)
#define NINE_INIT    (9)

#define ONE_THOUS_INIT          (1000)
#define THREE_HUNDR_INIT        (300)
#define  TWO_SEVEN5_INIT        (275)
#define TWO_FIFTY_INIT          (250)
#define TWO_HUNDR_INIT          (200)
#define ONE_FIFTY_INIT          (150)
#define ONE_HUNDR_INIT          (100)
#define NINETY_NINE_INIT        (99)
#define SEVEN_FIVE_INIT         (75)
#define SIXTY_INIT              (60)
#define FIFTY_FIVE_INIT         (55)
#define FIFTY_THREE_INIT        (53)
#define FIFTY_TWO_INIT          (52)
#define FIFTY_ONE_INIT          (51)
#define FIFTY_INIT              (50)
#define FOURTY_FIVE_INIT        (45)
#define FOURTY_INIT             (40)
#define THIRTY_THREE_INIT       (33)
#define THIRTY_TWO_INIT         (32)
#define THIRTY_ONE_INIT         (31)
#define THIRTY_INIT             (30)
#define TWENTY_SIX_INIT         (26)
#define TWENTY_FIVE_INIT        (25)
#define TWENTY_THREE_INIT       (23)
#define TWENTY_INIT             (20)
#define NINETEEN_INIT           (19)
#define EIGHTEEN_INIT           (18)
#define SEVENTEEN_INIT          (17)
#define SIXTEEN_INIT            (16)
#define FIFTEEN_INIT            (15)
#define FOURTEEN_INIT           (14)
#define THIRTEEN_INIT           (13)
#define TWELVE_INIT             (12)
#define ELEVEN_INIT             (11)
#define TEN_INIT                (10)



#define BYTE_HEX_ZERO  (0x00) 

// for five_msec_sleep function 
#define ONE_TENTH_SEC  (100)
#define ONE_EIGHT_SEC  (125)

// For circle / figure 8 functions
#define HALF_CIRCLE     (150)
#define FULL_CIRCLE     (300)

#define SIXTY_DEGREES           (50)
#define HALF_SIDE_LENGTH        (10)

// For clock setup
#define USE_IOT_WAKEUP          (0x00)
#define USE_SMCLK 		(0x01)

#define NEW_CLK_DIV             (10000)

// For Timers
#define TA0CCR0_INTERVAL        (1250)  // 8,000,000 / 4 / 8 / (1 / 5msec)
#define TA0CCR1_INTERVAL        (20)// 8,000,000 / 4 / 8 / (1 / ?msec) 
#define TA0CCR2_INTERVAL        (20)// 8,000,000 / 4 / 8 / (1 / ?msec)

#define TA1CCR0_INTERVAL        (12500)  // 8,000,000 / 4 / 8 / (1 / 50msec)
#define TA1CCR1_INTERVAL        (20)// 8,000,000 / 4 / 8 / (1 / ?msec) 
#define TA1CCR2_INTERVAL        (20)// 8,000,000 / 4 / 8 / (1 / ?msec)

#define TB0CCR0_INTERVAL        (1250) // 8,000,000 / 4 / 8 / (1 / 5msec)
#define TB0CCR1_INTERVAL        (20) //not used 
#define TB0CCR2_INTERVAL        (20) //not used

#define CCR1                    (2)
#define CCR2                    (4)
#define Aoverflow               (14)

//for car manuvering
#define ONE_SEC         (400)
#define TWO_SEC         (800)

//For PWM timer B
#define OFF             (0)
#define ON              (1)
#define WHEEL_PERIOD    (12000)

//for ADC interrupts / conversion
#define RESET_STATE     (0)      // is the reset state 0????
#define Baseline_ASCII  (0x30)
#define ASCII_0         ('0')
#define ASCII_1         ('1')

// for Serial Com
#define BEGINNING       (0)
#define SMALL_RING_SIZE (16)
#define LARGE_RING_SIZE (32)
