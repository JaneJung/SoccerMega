#include <avr/io.h>
#define F_CPU	7372800UL
#include <util/delay.h>
#define BAUD	115200
#define BAUDBT	9600
#include <stdio.h>
#include <string.h>

static char flag;
static char buf[100];
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

unsigned char GetChar0 ()
{
	char c;
	while (!(UCSR0A & 0x80)) ;
	//buf[cnt++] = UDR0;
	c = UDR0;
	while (!(UCSR1A & 0x20)) ;
	UDR1 = c;

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
	char data[100];
	int i;

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
	
	//atcommand("at+btsec,0,0\r ");
	//atcommand("ath\r ");
	//atcommand("atd28987BB2F4F1\r ");
	atcommand("atd201301300278\r ");
	atcommand("at+btinfo?\r ");
	atcommand("hello bt\r ");
	//atcommand("at+mlist?\r ");
	printf("\n@@@@@@@@@@@@@@\n");
	
	for(i = 0; i < 100; i++) {
		GetChar0();
	}
	
}
