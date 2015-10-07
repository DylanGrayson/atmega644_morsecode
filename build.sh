!#BASH

avr-gcc -mmcu=atmega644 -Wall -Os -o blink.elf CS499_Project1.c
avr-objcopy -j .text -j .data -O ihex blink.elf blink.hex
sudo avrdude -p m644 -c usbtiny -e -U flash:w:blink.hex
