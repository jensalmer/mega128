/* LCD Commands
 * The LCD seems to have a Hitachi HD44780 controller
 */
#define LCD_CLEAR			(0x01) // Clear LCD
#define LCD_HOME			(0x02) // Set DDRAM pointer to home
#define LCD_ENTSET			(0x04) // Set entry settings (pointer direction...)
#define LCD_DISCON			(0x08) // Display controls (on/off...)
#define LCD_MVCURS			(0x10) // Move cursor
#define LCD_FUNCSET			(0x20) // Function setup (4/8 bit...)
#define LCD_SET_CGADDR		(0x40) // Set CGRAM address
#define LCD_SET_DDADDR		(0x80) // Set DDRAM address

// LCD_ENRSET attr
#define LCD_INCR			(0x02) // Incremental pointer
#define LCD_SHIFT			(0x01) // Shift whole display

// LCD_DISCON attr
#define LCD_ON				(0x04) // Set display on
#define LCD_CURS			(0x02) // Show cursor
#define LCD_CURS_BLINK		(0x01) // Blink cursor

// LCD_FUNCSET attr
#define LCD_DL				(0x10) // 1:8bit 0:4bit
#define LCD_LINES			(0x08) // 0:1line 1:2line
#define LCD_FONT			(0x04) // ???

// Other
#define LCD_ADDR_LINE2		(0x40)

void lcd_init(void);
void lcd_clk(void);
void lcd_command(char command);
void lcd_write(char data);
void lcd_clear(void);
void lcd_line2(void);
void lcd_putc(char c);
void lcd_puts(char *s);
