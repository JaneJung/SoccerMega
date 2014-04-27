#include <avr/io.h>
#define F_CPU	7372800UL
#include <util/delay.h>
#define BAUD	115200
#define BAUDBT	9600
#include <stdio.h>
#include <string.h>

static int uart_putchar(char c, FILE *stream);
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

enum STATE {ready, start};

static int uart_putchar(char c, FILE *stream) {
	if (c == '\n') {
		uart_putchar('\r', stream);
	}
	loop_until_bit_is_set(UCSR1A, UDRE1);
	UDR1 = c;
	return 0;
}

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

int main(void) {
	
	unsigned short int ubrr;
	char c;

	ubrr = ((F_CPU/(16L*BAUD)) - 1);

	UCSR1A = 0x00;
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
	UCSR1C = (1<<UCSZ11)|(1<<UCSZ10);
	UBRR1H = (unsigned char)(ubrr >> 8);
	UBRR1L = (unsigned char)ubrr;
	stdout = &mystdout;

	printf("bluetooth test!!\n");

	ubrr = ((F_CPU/(16L*BAUDBT)) - 1);
	UCSR0A=0x00;
    UCSR0B=(1<<RXEN1)|(1<<TXEN1);
    UCSR0C=(1<<UCSZ11)|(1<<UCSZ10);
    UBRR0H=(unsigned char)(ubrr >> 8);
    UBRR0L=(unsigned char)ubrr;


	//atcommand("at+btkey=7777\r ");
	atcommand("at+btmode,0\r ");
	//atcommand("at+btinfo?\r ");
	//atcommand("at+btcancel\r ");
	//atcommand("at+btinq?\r ");
	
	atcommand("atd201301300278\r "); // 17¹ø ARM BOARD
	atcommand("at+btinfo?\r ");
	//atcommand("at+mlist?\r ");
	
	atcommand("GO\r ");

	while(1) {
		c = GetChar0();
		if ( (c >> 4) == 6 && (c&0x0F) <= 6 ) {
			// TODO : control motor
			atcommand("5\r ");
		} else {
			atcommand("0\r ");
		}
	}
}
