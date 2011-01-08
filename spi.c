#include <avr/io.h>

#include "spi.h"

void spi_init(void)
{
	DDRF	|= 0x08;  //port F bit 3 is enable for LCD
	PORTB	|= 0x00; //port B initalization for SPI
	DDRB	|= 0x07;  //Turn on SS, MOSI, SCLK 

	//Master mode, Clock=clk/2, Cycle half phase, Low polarity, MSB first  
	SPCR	= 0x50;
	SPSR	= 0x01;
}

void spi_write(char c)
{
	// Wait on SPI queue
	while (!(SPSR & 0x80));

	// Load 'er up
	SPDR = c;
	
	// Wait again. If the SPI bus were disabled in next couple instructions,
	// the data transmit could fail
	while (!(SPSR & 0x80));
}

