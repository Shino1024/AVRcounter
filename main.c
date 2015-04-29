/**************************************
The following program is to be
compiled in the AVR-gcc GNU compiler.
You can use the Eclipse IDE with the
AVR plug-in in order to build this
project and flash your microcontroller
with it.

The user is expected to connect
4 7-segment LED displays to the
microcontroller.

The program counts the number of
keypresses. In order to make it work,
the following pins should be connected:
PA0: microswitch.
PB0 - PB7: pins on the 7-segment LEDs.
PC0 - PC7: pins for multiplexing (one
display to be turned on at a time).

THE AUTHOR OF THIS PROGRAM HOLDS NO
RESPONSIBILITY FOR ANY DAMAGES CAUSED
TO THE DEVICE AS A RESULT OF
INAPPROPRIATE USAGE. USE IT WITH
CAUTION AND CHECK THE CONNECTIONS
TWICE BEFORE FLASHING THE
MICROCONTROLLER.
**************************************/
#include <avr/io.h>
#include <util/delay.h>

int convert(int from);

int main(void) {
	char* digits = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
	PORTA = 0xFF;
	DDRA = 0xFF;
	
	return 0;
}

char* convert(int from, char* digits) {
	int digits, help, i = 0;
	if (from < 10)
		digits = 1;
	else if (from > 9 && from < 100)
		digits = 2;
	else if (from > 99 && from < 1000)
		digits = 3;
	else
		digits = 4;
	char tab[digits + 1];
	while (digits > 0) {
		help = from - (from / 10) * 10;
		tab[i] = digits[help];
		++i;
		--digits;
	}
	tab[i] = NULL;
	return tab;
}
