MCU = atmega328p
F_CPU = 16000000
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall
LDFLAGS = -mmcu=$(MCU)

all: main.elf

main.elf: main.o
	avr-gcc $(LDFLAGS) -o $@ $^

main.o: main.c
	avr-gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o *.elf
