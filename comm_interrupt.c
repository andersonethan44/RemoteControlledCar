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

// Globals
extern volatile unsigned int usb_tx_ring_wr;
extern volatile unsigned int usb_rx_ring_wr;
extern volatile unsigned int usb_tx_ring_rd;
extern volatile unsigned int usb_rx_ring_rd;
extern volatile char USB_Char_Tx[LARGE_RING_SIZE];
extern volatile char USB_Char_Rx[SMALL_RING_SIZE];

extern volatile unsigned int iot_tx_ring_wr;
extern volatile unsigned int iot_rx_ring_wr;
extern volatile unsigned int iot_tx_ring_rd;
extern volatile unsigned int iot_rx_ring_rd;
extern volatile char IOT_Char_Tx[LARGE_RING_SIZE];
extern volatile char IOT_Char_Rx[SMALL_RING_SIZE];
extern volatile unsigned int transmit_2_pc_ok;
extern int temp;

//----------------------------------------------------------------------------

#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void){
//------------------------------------------------------------------------------
  switch(__even_in_range(UCA0IV,0x08)){
    case 0: // Vector 0 - no interrupt
      break;
    case 2: // Vector 2 - RXIFG
      transmit_2_pc_ok = 1;
      temp = usb_rx_ring_wr;
// RX -> USB_Char_Rx character
      USB_Char_Rx[temp] = UCA0RXBUF;
///UCA0TXBUF = UCA0RXBUF;
// Circular buffer back to beginning
      if (++usb_rx_ring_wr >= (SMALL_RING_SIZE)){
        usb_rx_ring_wr = BEGINNING;
      }
//*** Begin Loop Back Test 1
// USCI_A0 TX buffer ready?
      while(!(UCA0IFG & UCTXIFG));
// TX -> RXed character
      UCA1TXBUF = USB_Char_Rx[temp];
//*** End Loop Back Test 1
      break;
    case 4: // Vector 4 ETXIFG
//    temp = usb_tx_ring_wr;
//    UCA0TXBUF = USB_Char_Tx[temp]; // RX -> USB_Char_Rx character
//    if (++usb_tx_ring_wr >= (SMALL_RING_SIZE)){
//    usb_tx_ring_wr = BEGINNING; // Circular buffer back to beginning
 //}
    break;
    default: break;
 }
//------------------------------------------------------------------------------
}
#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void){
//------------------------------------------------------------------------------
  unsigned int temp;
  switch(__even_in_range(UCA1IV,0x08)){
    case 0: // Vector 0 - no interrupt
      break;
    case 2: // Vector 2 - RXIFG
        temp = iot_rx_ring_wr;
      IOT_Char_Rx[temp] = UCA1RXBUF; // RX -> USB_Char_Rx character
      if (++iot_rx_ring_wr >= (SMALL_RING_SIZE)){
        iot_rx_ring_wr = BEGINNING; // Circular buffer back to beginning
      }
      if(transmit_2_pc_ok){
        //while (!(UCA1IFG&UCTXIFG));
// TX -> RXed character
       UCA0TXBUF = IOT_Char_Rx[temp];
       UCA1TXBUF = USB_Char_Rx[temp];
      // UCA1TXBUF = USB_Char_Rx[temp];
       // UCATXBUF = IOT_Char_Rx[temp];
      }
      break;
    case 4: // Vector 4 ETXIFG
//    temp = iot_tx_ring_wr;
  //  UCA1TXBUF = IOT_Char_Tx[temp]; // TX -> USB_Char_Rx character
//    if (++iot_tx_ring_wr >= (SMALL_RING_SIZE)){
//    iot_tx_ring_wr = BEGINNING; // Circular buffer back to beginning
// }
      break;
    default: break;
  }
//------------------------------------------------------------------------------
}



