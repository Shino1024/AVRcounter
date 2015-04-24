#include <avr/io.h>
#include <util/delay.h>
int main(void) {
	char* digits = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
	PORTA = 0xFF;
	DDRA = 0xFF;
	return 0;
}
