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
#include <string.h>

// Globals
extern char display_line_1[DISPLAY_INIT];
extern char display_line_2[DISPLAY_INIT];
extern char display_line_3[DISPLAY_INIT];
extern char display_line_4[DISPLAY_INIT];
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern volatile unsigned int usb_tx_ring_wr;
extern volatile unsigned int usb_rx_ring_wr;
extern volatile unsigned int usb_tx_ring_rd;
extern volatile unsigned int usb_rx_ring_rd;
extern volatile char USB_Char_Tx[LARGE_RING_SIZE];
extern volatile char USB_Char_Rx[SMALL_RING_SIZE];
int ipstate=1;
extern volatile unsigned int iot_tx_ring_wr;
extern volatile unsigned int iot_rx_ring_wr;
extern volatile unsigned int iot_tx_ring_rd;
extern volatile unsigned int iot_rx_ring_rd;
extern volatile char IOT_Char_Tx[LARGE_RING_SIZE];
extern volatile char IOT_Char_Rx[SMALL_RING_SIZE];
extern volatile unsigned int transmit_2_pc_ok;
extern int temp;
int l;
int m;
char *str1;
char *str2;
char array1[9];
char array2[9];
extern volatile int baud;

void Init_Serial_UCA0(void){
//----------------------------------------------------------------------------
 int i;
 for(i=0; i<SMALL_RING_SIZE; i++){
 USB_Char_Rx[i] = 0x00; // USB Rx Buffer
 }
 usb_rx_ring_wr = BEGINNING;
 usb_rx_ring_rd = BEGINNING;

 for(i=0; i<LARGE_RING_SIZE; i++){ // May not use this
 USB_Char_Tx[i] = 0x00; // USB Tx Buffer
 }
 usb_tx_ring_wr =   BEGINNING    ;
 usb_tx_ring_rd = BEGINNING;
 // Configure UART 0
 UCA0CTLW0 = 0; // Use word register
 UCA0CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK
 UCA0CTLW0 |= UCSWRST; // Set Software reset enable

// 9,600 Baud Rate
// 1. Calculate N = fBRCLK / Baudrate
// N = SMCLK / 9,600 => 8,000,000 / 9,600 = 833.3333333
// if N > 16 continue with step 3, otherwise with step 2
// 2. OS16 = 0, UCBRx = INT(N)
// continue with step 4
// 3. OS16 = 1,
// UCx = INT(N/16),
// = INT(N/16) = 833.333/16 => 52
// UCFx = INT([(N/16) EINT(N/16)] × 16)
//      = ([833.333/16-INT(833.333/16)]*16)
//      = (52.08333333-52)*16
//      = 0.083*16 = 1
// 4. UCSx is found by looking up the fractional part of N (= N-INT(N)) in table Table 18-4
// Decimal of SMCLK / 8,000,000 / 9,600 = 833.3333333 => 0.333 yields 0x49 [Table]
// 5. If OS16 = 0 was chosen, a detailed error calculation is recommended to be performed
// TX error (%) RX error (%)
// BRCLK        Baudrate UCOS16 UCBRx   UCFx    UCSx    neg     pos     neg     pos
// 8000000      9600     1      52      1       0x49    -0.08    0.04   -0.10   0.14
UCA0BRW = 52; // 9,600 Baud

// UCA0MCTLW = UCSx concatenate UCFx concatenate UCOS16;
// UCA0MCTLW = 0x49 concatenate 1 concatenate 1;

 UCA0MCTLW = 0x4911 ;
 UCA0CTL1 &= ~UCSWRST; // Release from reset
UCA0IE |= UCRXIE; 
 
}
//------------------------------------------------------------------------------


void Init_Serial_UCA1(void){
//----------------------------------------------------------------------------
 int i;
 for(i=0; i<SMALL_RING_SIZE; i++){
 IOT_Char_Rx[i] = 0x00; // USB Rx Buffer
 }
 iot_rx_ring_wr = BEGINNING;
 iot_rx_ring_rd = BEGINNING;

 for(i=0; i<LARGE_RING_SIZE; i++){ // May not use this
 IOT_Char_Tx[i] = 0x00; // USB Tx Buffer
 }
 iot_tx_ring_wr = BEGINNING;
 iot_tx_ring_rd = BEGINNING;
 // Configure UART 0
 UCA1CTLW0 = 0; // Use word register
 UCA1CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK
 UCA1CTLW0 |= UCSWRST; // Set Software reset enable

// 9,600 Baud Rate
// 1. Calculate N = fBRCLK / Baudrate
// N = SMCLK / 9,600 => 8,000,000 / 9,600 = 833.3333333
// if N > 16 continue with step 3, otherwise with step 2
// 2. OS16 = 0, UCBRx = INT(N)
// continue with step 4
// 3. OS16 = 1,
// UCx = INT(N/16),
// = INT(N/16) = 833.333/16 => 52
// UCFx = INT([(N/16) EINT(N/16)] × 16)
//      = ([833.333/16-INT(833.333/16)]*16)
//      = (52.08333333-52)*16
//      = 0.083*16 = 1
// 4. UCSx is found by looking up the fractional part of N (= N-INT(N)) in table Table 18-4
// Decimal of SMCLK / 8,000,000 / 9,600 = 833.3333333 => 0.333 yields 0x49 [Table]
// 5. If OS16 = 0 was chosen, a detailed error calculation is recommended to be performed
// TX error (%) RX error (%)
// BRCLK        Baudrate UCOS16 UCBRx   UCFx    UCSx    neg     pos     neg     pos
// 8000000      9600     1      52      1       0x49    -0.08    0.04   -0.10   0.14

if (baud == 0){UCA1BRW = 52; // 9,600 Baud

// UCA0MCTLW = UCSx concatenate UCFx concatenate UCOS16;
// UCA0MCTLW = 0x49 concatenate 1 concatenate 1;

 UCA1MCTLW = 0x4911 ;
 UCA1CTL1 &= ~UCSWRST; // Release from reset
UCA1IE |= UCRXIE; 
 }
 if (baud == 1){UCA1BRW = 4; // 9,600 Baud

// UCA0MCTLW = UCSx concatenate UCFx concatenate UCOS16;
// UCA0MCTLW = 0x49 concatenate 1 concatenate 1;

 UCA1MCTLW = 0x5551 ;
 UCA1CTL1 &= ~UCSWRST; // Release from reset
UCA1IE |= UCRXIE; 
 }
//------------------------------------------------------------------------------
}


void Transmit_Char( char trans_char ){
  while( !(UCA0IFG & UCTXIFG) );
  UCA0TXBUF = trans_char;
}

void out_wifi(char wifi_char){
  while (!(UCA1IFG&UCTXIFG));
  UCA1TXBUF = wifi_char;
}

void Transmit_Str(char volatile *string){
     if (string != '\0') {
  while ( *string != '\0' ) {            /* Transmit data */           
    Transmit_Char( *string );
    out_wifi( *string);
    string++;}
  
     }}
/*
void line(void){
  if (BLACK_LINE == 1){
   P3OUT |= IR_LED; 
  while (1){
    if( AVG_Compare_Counter >= 8 ){
    ADC10IE &= ~ADC10IE0; // disable the interrupt
    
    ADC_Process(); // call to ADC
 
    HEXtoBCD(ADC_Thumb);
    toRightDetect( ADC_RIGHT_DETECT );
    toLeftDetect( ADC_LEFT_DETECT );
    
    display_2 = rightD_adc_char;
    posL2 = ZERO_INIT;
    display_3 = leftD_adc_char;
    posL3 = ZERO_INIT;
    Display_Process();
    AVG_Compare_Counter = 0;
    ADC10IE |= ADC10IE0; //re-enable the interrupt
    }
      
      PWM_FORWARD ( 8600  ,  2000 );              
      five_msec_sleep(5);              
      PWM_STOP();
      five_msec_sleep(1);
      display_4 = "Forward";
    while (ADC_LEFT_DETECT <=300 && ADC_RIGHT_DETECT >= 700){
      Correct_L();
      display_4 = "LEFT";
      
    }
    while (ADC_RIGHT_DETECT <= 300 && ADC_LEFT_DETECT >= 700){
      Correct_R();
      display_4 = "RIGHT";
      
    }
  }
}

}
*/

void Wifi_Setup(void){
  Transmit_Str("AT+S.SSIDTXT=ncsu \r");
  Transmit_Str("AT+S.SSIDTXT \r");
  Transmit_Str("AT+S.SCFG=ip_hostname,ECE-306_26_E \r");
  Transmit_Str("AT+S.GCFG=ip_hostname\r");
  Transmit_Str("AT+S.SCFG=wifi_priv_mode,0 \r");
  Transmit_Str("AT+S.GCFG=wifi_priv_mode \r");
  Transmit_Str("AT+S.SCFG=wifi_mode,1 \r");
  Transmit_Str("AT+S.GCFG=wifi_mode \r");
  Transmit_Str("AT&W \r");
  Transmit_Str("AT+CFUN=1 \r");
  
  
}

void IPADDR(void){
  for (l=0; l<= 13; l++) {
    if(IOT_Char_Rx[l] == '1' && IOT_Char_Rx[l+1] == '0' && IOT_Char_Rx[l+2] == '.'){
      for (m = 0; m<= 15; m++){
        if (m < 9) {
          array1[m] = IOT_Char_Rx[m];
        }
        array1[8] = '\0';
        if (m>= 9){
          array2[m-9] = IOT_Char_Rx[m];
        }
        array2[8] = '\0';
      }
     display_1 = array1;
     display_2 = array2;
     five_msec_sleep(20);
     Display_Process();
     five_msec_sleep(20);
    }
    
  }
 
}

void displayload(char *input){
  int x;
  for (x = 0; x<= 10; x++ ){
  display_1 = input;
  display_1++;
  display_2 = input;
  display_2++;
  input++;
  }
  
}