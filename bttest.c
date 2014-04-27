#include <avr/io.h>
#define F_CPU	7372800UL
#include <util/delay.h>
#define BAUD	115200
#define BAUDBT	9600
#include <stdio.h>
#include <string.h>

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
	c = UDR0;
	//UDR1 = c;
	printf("return : %c %x\n", c, c);
	return c;
}

unsigned char PutChar0 (unsigned char c)
{
	while (!(UCSR0A & 0x20)) ;
	UDR0 = c;
	printf("%c %x\n\r", c, c);
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
	/*
	UCSR0A=0x00;
    UCSR0B=0x98;
    UCSR0C=0x06;
    UBRR0H=0;
    UBRR0L=47;*/

	//while(1) {
		atcommand("at+btinfo?\r ");
		//_delay_ms(3000);
		printf("@@@@@@@@@@@@@@\n");
		for (i = 0; i < 100; i++) {
			printf("(%d)", i );
			GetChar0();
		}
		printf("@@@@@@@@@@@@@@\n");
		
		//atcommand("at\n\r ");
	/*	_delay_ms(3000);
		printf("@@@@@@@@@@@@@@\n");
		GetChar0();
		printf("@@@@@@@@@@@@@@\n");

		atcommand("at ");
		_delay_ms(3000);
		printf("@@@@@@@@@@@@@@\n");
		GetChar0();
		printf("@@@@@@@@@@@@@@\n");*/
	//}
}
