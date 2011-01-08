MCU_TARGET     = atmega128
CC = avr-gcc
CFLAGS = -O3 -mmcu=$(MCU_TARGET)

default: defs.h lcd.o main.o spi.o uart.o
	$(CC) $(CFLAGS) *.o -o main 

lcd.o: lcd.c lcd.h spi.h
	$(CC) $(CFLAGS) -o $@ -c lcd.c

main.o: main.c lcd.h spi.h uart.h
	$(CC) $(CFLAGS) -o $@ -c main.c

spi.o: spi.c spi.h
	$(CC) $(CFLAGS) -o $@ -c spi.c

uart.o: uart.c uart.h
	$(CC) $(CFLAGS) -o $@ -c uart.c

clean:
	rm *.o main
