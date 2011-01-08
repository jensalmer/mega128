#include "defs.h"

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "lcd.h"
#include "spi.h"
#include "uart.h"

//External RAM will reside between 8000h - FFFFh.
//There will be 2 wait states for both read and write.
void init_ext_ram(void)
{
	DDRA	= 0x00;
	DDRB	= 0xFF;
	DDRC	= 0xFF;
	DDRG	= 0xFF;
	PORTA	= 0x00;
	PORTB	= 0x00;
	PORTC	= 0x00;
	PORTG	= 0x00;
	MCUCR	= 0x80;
	XMCRA	= 0x42;
	XMCRB	= 0x80;
}

int main (void)
{
	spi_init();
	lcd_init();
	lcd_clear();

	lcd_puts("Hello");
	lcd_line2();
	lcd_puts("World");

	while (1);
}
