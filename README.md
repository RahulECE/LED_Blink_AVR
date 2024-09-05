# LED Blink AVR Project

## Description

This project demonstrates how to blink an LED using an AVR microcontroller, emulated with QEMU. The LED blink is simulated by printing "LED Blink" to the terminal. The code is written for the ATmega328P microcontroller, commonly used in the Arduino UNO.

## Files

- `src/main.c`: The source code for blinking the LED.
- `build/main.elf`: The compiled ELF file.
- `build/main.hex`: The HEX file generated from the ELF file for use with QEMU.

## Prerequisites

- `avr-gcc`: AVR GCC compiler
- `avr-objcopy`: Utility to convert ELF to HEX
- `qemu-system-avr`: QEMU emulator for AVR microcontrollers

## Build and Run Instructions

1. **Clone the Repository**

   ```bash
   git clone https://github.com/RahulECE/LED_Blink_AVR.git
   cd LED_Blink_AVR
   
2. **Compile the Source Code**
````   
mkdir -p build
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -o build/main.elf src/main.c
avr-objcopy -O ihex build/main.elf build/main.hex
````
3.**Run the Emulation**
````
qemu-system-avr -M arduino-uno -bios build/main.hex -serial stdio
````
or, for non-graphical output:

```
qemu-system-avr -M arduino-uno -kernel build/main.elf -serial stdio -nographic

````
