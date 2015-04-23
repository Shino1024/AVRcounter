#include <avr/io.h>
#include <util/delay.h>
int main(void) {
	PORTA = 0xFF;
	DDRA = 0xFF;
	return 0;
}
