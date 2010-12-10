#include <wiring_private.h>
#include <serialio.h>

void
setup_atmega328p_serial(serial *port)
{
	serial_setup(port, &UBRR0H, &UBRR0L, &UCSR0A, &UCSR0B, &UDR0, RXEN0,
		TXEN0, RXCIE0, UDRE0, U2X0);
}

int main(void) {
	serial port;
	setup_atmega328p_serial(&port) ;
	init() ;
	serial_begin(&port, 9600) ;
	serial_print(&port, "Hello World!") ;
	serial_flush(&port) ;
	serial_end(&port) ;
	return 0 ;
}

