#include <avr/io.h>
#define F_CPU 7372800UL
#include <util/delay.h>
#define BAUD	115200
#define BAUDBT	9600
#include <avr/interrupt.h>
#include <stdio.h>

#define sbi(x, n)	( x = (x | ( 0x01 << (n) )) )
#define cbi(x, n)	( x = (x & ~( 0x01 << (n) )) )

static int uart_putchar(char c, FILE *stream);
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

static int uart_putchar(char c, FILE *stream) {
	if (c == '\n') {
		uart_putchar('\r', stream);
	}
	loop_until_bit_is_set(UCSR1A, UDRE1);
	UDR1 = c;
	return 0;
}

volatile unsigned short int adc0, adc1, adc2, adc3, adc4;
volatile unsigned char state =0, count =0, inside = 1;

void gpio_init(void);
void timer1_init(void);
void adc_inii(void);
void pwm_init(void);

unsigned char GetChar0 ()
{
	char c;
	while (!(UCSR0A & 0x80)) ;
	c = UDR0;

	while (!(UCSR1A & 0x20)) ;
	UDR1 = c;
	
	while (!(UCSR1A & 0x20)) ;
	UDR1 = '\n';

	while (!(UCSR1A & 0x20)) ;
	UDR1 = '\r';
	
	return c;
}

unsigned char PutChar0 (unsigned char c)
{
	while (!(UCSR0A & 0x20)) ;
	UDR0 = c;
	
	while (!(UCSR1A & 0x20)) ;
	UDR1 = c;
	
	return 0;
}

void atcommand (char *s)
{
	while (*s != ' ') {
		PutChar0(*s);
		s++;
	}
}

SIGNAL(SIG_ADC)
{
	switch(state)
	{
		case 0 | 1 :
				adc2 = ADC ; //Center Sencor
				break;
		case 2 | 3 :
				adc4 = ADC ; //LeftMost
				break;
		case 4 | 5 :
				adc3 = ADC; //Left
				break;
	}
}

SIGNAL(SIG_OUTPUT_COMPARE1A)
{
	
	unsigned int avrg = 0;

	count ++ ;
	if(count > 9)
	{
		count = 0;
		switch(state)
		{
			case 0:
					ADMUX = 0x42;	// ADC2 select
					sbi(PORTE,2);
					state = 1;
					ADCSR = 0xCE;
					break;
		
			case 1:
					cbi(PORTE, 2);
					state = 2;
					break;
		
			case 2 :
					ADMUX = 0x44;	// ADC #4
					sbi(PORTE,4);
					state = 3;
					ADCSR = 0xCE;
					break;
		
			case 3 :
					cbi(PORTE, 4);
					state = 4;
					break;
		
			case 4 :
					ADMUX = 0x43;	// ADC #3
					sbi(PORTE,3);
					state = 5;
					ADCSR = 0xCE;
					break;
		
			case 5 :
					cbi(PORTE, 3);
					state = 0;
					break;
		}
	}
	
	avrg = (adc2 + adc3 + adc4) / 3;
	if (avrg >= 0x100) { // 경기장 밖으로 나갔을 때(후진)
		cbi(PORTB, 5); 
		sbi(PORTB, 6);
		OCR0 = OCR2 = 255;
		inside = 0;
	} else if (inside == 0) { // 경기장 안으로 다시 들어왔을 때
		cbi(PORTB, 5);
		cbi(PORTB, 6);
		OCR0 = OCR2 = 0;
		inside = 1;
	}
}

void gpio_init(void)
{
	DDRG |= 0x1C ;
	DDRB |= 0xF0 ;
	DDRE |= 0x7F ;
	DDRD |= 0xF0;

	sbi(DDRF, 5);
	PORTD |= 0xF0;
		
	sbi(PORTE, 6);
	sbi(PORTF, 5);
	cbi(DDRG, 0);
	cbi(DDRG, 1);
	sbi(PORTG,2);
	DDRA = 0xFF;
	DDRC = 0xFF;
	sbi(PORTB, 5);
	cbi(PORTB, 6);
}

void timer1_init(void)
{
	TCCR1A = 0x00;
	TCCR1B = 0x0A;
	TCCR1C = 0x00;
	TIMSK = 0x10;
	OCR1A =22;
}

void adc_init(void)
{
	ADMUX = 0x42;
	ADCSR = 0xCE;
}

void pwm_init(void)
{
	TCCR0 = 0x62;
	TCCR2 = 0x62;
}

void uart_init(void)
{
	unsigned short int ubrr;
	
	ubrr = ((F_CPU/(16L*BAUD)) - 1);

	UCSR1A = 0x00;
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
	UCSR1C = (1<<UCSZ11)|(1<<UCSZ10);
	UBRR1H = (unsigned char)(ubrr >> 8);
	UBRR1L = (unsigned char)ubrr;
	stdout = &mystdout;

	ubrr = ((F_CPU/(16L*BAUDBT)) - 1);
	UCSR0A=0x00;
    UCSR0B=(1<<RXEN1)|(1<<TXEN1);
    UCSR0C=(1<<UCSZ11)|(1<<UCSZ10);
    UBRR0H=(unsigned char)(ubrr >> 8);
    UBRR0L=(unsigned char)ubrr;

}

void control_motor(unsigned char dir) {

	if (!inside) return;

	switch(dir)
	{
		case 'a' : //Left & forward
				sbi(PORTB, 5);
				cbi(PORTB, 6);
				OCR0 = 100;
				OCR2 = 255;
				break;
		case 'b' : // forward
				sbi(PORTB, 5);
				cbi(PORTB, 6);
				OCR0 = OCR2 = 255;
				break;
		case 'c' : //Right & forward
				sbi(PORTB, 5);
				cbi(PORTB, 6);
				OCR0 = 250;
				OCR2 = 100;
				break;
		case 'd' : //Left & backward
				cbi(PORTB, 5); 
				sbi(PORTB, 6);
				OCR0 = 100;
				OCR2 = 255;
				break;
		case 'e' : //backward
				cbi(PORTB, 5); 
				sbi(PORTB, 6);
				OCR0 = OCR2 = 255;
				break;
		case 'f' : // Right & backward
				cbi(PORTB, 5); 
				sbi(PORTB, 6);
				OCR0 = 250;
				OCR2 = 100;
				break;
		case 'g' : // stop
				cbi(PORTB, 5);
				cbi(PORTB, 6);
				OCR0 = OCR2 = 0;
				break;
	}
}

int main(void)
{
	unsigned char c;

	gpio_init();
	timer1_init();
	pwm_init();
	adc_init();
	uart_init();

	sei();

	printf("bluetooth test!!\n");
	atcommand("at+btmode,0\r ");
	atcommand("atd201301300278\r "); // 17번 ARM BOARD
	atcommand("at+btinfo?\r ");
	atcommand("GO\r ");

	while(1)
	{
		c = GetChar0();
		if ( (c >> 4) == 6 && (c&0x0F) <= 7 ) {
			atcommand("5\r ");
			control_motor(c);
		} else {
			atcommand("0\r ");
		}
		
	}

	return 0;
}
