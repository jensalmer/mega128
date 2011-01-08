#include "defs.h"

#include <avr/io.h>

#include "uart.h"

void uart_init(void)
{
	// UART0
	PORTE		= 0x00;
	DDRE		= 0xFF;
	UCSR0A		= 0x00;
	UCSR0B		= 0x18;
	UCSR0C		= 0x06;
	UBRR0H		= 0x00;
	UBRR0L		= 0x67;
}

char uart_getc(void)
{
	uint16_t timer = 0;
	while (!(UCSR0A & (1<<RXC0))) {
		timer++;
		if (timer >= 16000)
			return (0);
	}  // Wait for byte to arrive

	return (UDR0);
}

void uart_putc(char c)
{
	while (!(UCSR0A&(1<<UDRE)));	// Wait for previous transmissions
	UDR0 = c;	// Send data byte
	while (!(UCSR0A&(1<<UDRE)));	// Wait for previous transmissions
}

// Takes a string and sends each charater to be sent to USART0
void uart_puts(char *s)
{
	while (*s)	uart_putc(*(s++));
}
