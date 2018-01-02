// Function prototypes main
void main(void);
void Init_Conditions(void);
void Switches_Process(void);
void Init_Timers(void);
void Init_LEDs(void);
void Display_Process(void);
void five_msec_sleep(unsigned int fivemsec);
void Timer_code(void);

// Function prototypes clocks
void Init_Clocks(void);

// Function prototypes systems
void enable_interrupts(void);

// Function prototypes
__interrupt void Timer0_B0_ISR(void);
__interrupt void Timer2_B0_ISR(void);
 __interrupt void TIMER2_B1_ISR(void);
void Init_Timer_A0(void);
void Init_Timer_B0(void);
void Init_Timer_B1(void);
void Init_Timer_B2(void);
void measure_delay(void);
void usleep10(unsigned int usec);

// Function prototypes ports
void Init_Ports(void);
void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(void);
void Init_Port4(void);
void Init_PortJ(void);

// LCD
void Init_LCD(void);
void WriteIns(char instruction);
void WriteData(char data);
void ClrDisplay(void);
void SetPostion(char pos);
void DisplayOnOff(char data);
void lcd_BIG_mid(void);
void lcd_4line(void);
void lcd_out(char *s, char line, char position);

void grab_a_character(void);
int wait_for_character(void);
void menu(void);

// SPI
void Init_SPI_B0(void);
void SPI_B0_write(char byte);

// Switches
void Init_Switches(void);
void switch_control(void);
void enable_switch_SW1(void);
void enable_switch_SW2(void);
void disable_switch_SW1(void);
void disable_switch_SW2(void);
void Switches_Process(void);

// Added for project 3
void FIVE_INCH_MOVE(void);

// for car operation
void forward(void);
void stop(void);
void Circle(void);
void Figure8(void);
void Triangle(void);
void clockwise(void);
void counterclock(void);
void reverse(void);

void ADC_Process(void);
void Init_ADC(void);
void toCharThumb( unsigned int input);
void toRightDetect( unsigned int input );
void toLeftDetect( unsigned int input );
void HEXtoBCD(int hex_value);

// for PWM & Motion
void PWM_FORWARD ( int DutyCycle_Right ,  int DutyCycle_Left );
void PWM_REVERSE ( int DutyCycle_Right ,  int DutyCycle_Left );

int abs( int input );
void Correct_L ( void );
void Correct_R ( void );
void PWM_STOP( void);
// for Serial Com
void Init_Serial_UCA0( void );
void Init_Serial_UCA1(void);
void Transmit_Char( char trans_char );
__interrupt void USCI_A0_ISR(void);
__interrupt void USCI_A1_ISR(void);
void Transmit_Char( char trans_char );

//command.c
void uart_puts(const char *str);
void ua0rt_puts(const char *str);
void ua1rt_puts(const char *str);
void line(void);
void Commands(volatile char* input);
void Transmit_Str(char volatile *string);
void Wifi_Setup(void);
void IPADDR(void);
void displayload(char *input);