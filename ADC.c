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
//
// Globals
//
char ADC_Channel=ZERO_INIT;
extern volatile int ADC_Thumb;
extern volatile int ADC_RIGHT_DETECT;
extern volatile int ADC_LEFT_DETECT;
extern char adc_char[5];
//
// Function Prototypes
//
void Init_ADC(void);
void ADC_Process(void);


//------------------------------------------------------------------------------
// Configure ADC10_B
void Init_ADC(void){
 ADC10CTL0 = RESET_STATE; // Clear ADC10CTL0
 ADC10CTL0 |= ADC10SHT_2; // 16 ADC clocks
 ADC10CTL0 &= ~ADC10MSC; // Single Sequence
 ADC10CTL0 |= ADC10ON; // ADC ON - Core Enabled
 
 ADC10CTL1 = RESET_STATE; // Clear ADC10CTL1
 ADC10CTL1 |= ADC10SHS_0; // ADC10SC bit
 ADC10CTL1 |= ADC10SHP; // SAMPCON signal sourced from sampling timer
 ADC10CTL1 &= ~ADC10ISSH; // The sample-input signal is not inverted.
 ADC10CTL1 |= ADC10DIV_0; // ADC10_B clock divider – Divide by 1.
 ADC10CTL1 |= ADC10SSEL_0; // MODCLK
 ADC10CTL1 |= ADC10CONSEQ_0; // Single-channel, single-conversion
 
 ADC10CTL2 = RESET_STATE; // Clear ADC10CTL2
 ADC10CTL2 |= ADC10DIV_0; // Pre-divide by 1
 ADC10CTL2 |= ADC10RES; // 10-bit resolution
 ADC10CTL2 &= ~ADC10DF; // Binary unsigned
 ADC10CTL2 &= ~ADC10SR; // supports up to approximately 200 ksps
//for thumbwheel
 ADC10MCTL0 = RESET_STATE; // Clear ADC10MCTL0
 ADC10MCTL0 |= ADC10SREF_0; // V(R+) = AVCC and V(R-) = AVSS
 ADC10MCTL0 |= ADC10INCH_3; // Channel A3 Thumb Wheel
 ADC10IE |= ADC10IE0; // Enable ADC conversion complete interrupt
//for right_detect
 ADC10MCTL0 |= ADC10INCH_0; // Channel A0 Right Detect
//for left_detect
 ADC10MCTL0 |= ADC10INCH_1; // Channel A1 Left Detect

}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ADC10 interrupt service routine
// ADC_Right_Detector; // A00 ADC10INCH_0 - P1.0
// ADC_Left_Detector; // A01 ADC10INCH_1 - P1.1
// ADC_Thumb; // A03 ADC10INCH_3 - P1.3
// ADC_Temp; // A10 ADC10INCH_10 – Temperature REF module
// ADC_Bat; // A11 ADC10INCH_11 - Internal
#pragma vector=ADC10_VECTOR
 __interrupt void ADC10_ISR(void){
 switch(__even_in_range(ADC10IV,TWELVE_INIT)) { 
 case ZERO_INIT : break; // No interrupt
 case TWO_INIT  : break; // conversion result overflow
 case FOUR_INIT : break; // conversion time overflow
 case SIX_INIT  : break; // ADC10HI
 case EIGHT_INIT: break; // ADC10LO
 case TEN_INIT  : break; // ADC10IN
 case TWELVE_INIT:
    // Need this to change the ADC10INCH_x value.
    ADC10CTL0 &= ~ADC10ENC; // Turn off the ENC bit of the ADC10CTL0
    switch ( ADC_Channel ){
    case ZERO_INIT:
      ADC10MCTL0 = ADC10INCH_1; // Next channel A1
      ADC_RIGHT_DETECT = ADC10MEM0; // Current Channel result for A0
        ADC_Channel++;
      break;
    case ONE_INIT:
      ADC10MCTL0 = ADC10INCH_3; // Next channel A3
      ADC_LEFT_DETECT = ADC10MEM0; // Current Channel result for A1
        ADC_Channel++;
      break;
    case TWO_INIT:
      ADC10MCTL0 = ADC10INCH_0; // Next channel A0
      ADC_Thumb = ADC10MEM0; // Current Channel result for A3
        ADC_Channel=ZERO_INIT;
    }
 break;
 default: break;
 }
 ADC10CTL0 |= ADC10ENC; // Turn on the ENC bit of the ADC10CTL0
 ADC10CTL0 |= ADC10SC; // Start next sample.
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void ADC_Process(void){
 while (ADC10CTL1 & BUSY); // Wait if ADC10 core is active
 ADC10CTL0 |= ADC10ENC + ADC10SC; // Sampling and conversion start
}
//------------------------------------------------------------------------------

int abs( int input ){
  
  if( input < 0 ){
    return (-input);
  }
  else
    return input;
  
}

