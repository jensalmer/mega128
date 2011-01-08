#include "defs.h"

#include <avr/io.h>
#include <util/delay.h>

#include "lcd.h"
#include "spi.h"

void lcd_init(void)
{
	//initalize the LCD to receive data
	_delay_ms(15);   

	// Must get SPIF in SPSR set for spi_write() to work
	// Otherwise spi_write() will loop forever
	// You should not need to do this again, even is you kill SPI.
	// The bit should stay set after you have sent data once
	SPDR = 0x00;

	// Set for 8 bits, 2 line display
	lcd_command(LCD_FUNCSET | LCD_DL | LCD_LINES);
	lcd_clk();
	_delay_us(37);

	// Set pointer to increment in DDRAM
	lcd_command(LCD_ENTSET | LCD_INCR);
	lcd_clk();
	_delay_us(37);

	// Turn display on, show cursor
	lcd_command(LCD_DISCON | LCD_ON | LCD_CURS);
	lcd_clk();
	_delay_us(37);

	// Make sure DDRAM get cleared
	lcd_command(LCD_CLEAR);
	lcd_clk();
	_delay_ms(1.6);
}

//twiddles bit 3, PORTF creating the enable signal for the LCD
void lcd_clk(void)
{
	PORTF |= 0x08;
	PORTF &= ~0x08;
}

void lcd_command(char command)
{
	// Set RS to 0
	spi_write(0x00);
	spi_write(command);
}

void lcd_write(char data)
{
	// Set RS to 1
	spi_write(0x01);
	spi_write(data);
}

void lcd_clear(void)
{
	lcd_command(LCD_CLEAR);
	lcd_command(LCD_HOME);

	lcd_clk();

	_delay_ms(1.6);   //obligatory waiting for slow LCD
}

void lcd_line2(void)
{
	lcd_command(LCD_SET_DDADDR | LCD_ADDR_LINE2);	
	lcd_clk(); 
	_delay_us(37);
}

void lcd_putc(char c)
{
	lcd_write(c);
	lcd_clk();  //toggle the enable bit
	_delay_us(37);
}

void lcd_puts(char *s)
{
	while (*s)	lcd_putc(*(s++));
}
