#include <serialio.h>
#include <wiring_private.h>

void
setup_atmega328p_serial(serial *port)
{
	serial_setup(port, &UBRR0H, &UBRR0L, &UCSR0A, &UCSR0B, &UDR0, RXEN0,
		TXEN0, RXCIE0, UDRE0, U2X0);
}

void
text_print_header(serial *port, char *name)
{
	serial_write(port, ':');
	serial_print(port, name);
	serial_write(port, ':');
}

void
text_print(serial *port, char *txt)
{
	text_print_header(port, "first try headers");
	serial_print(port, txt);
	serial_write(port, '\n');
}

int main(void) {
	uint8_t query;
	/*double avg;*/
	serial port;
	setup_atmega328p_serial(&port) ;
	init() ;
	text[] = "Hello World!" ;
	serial_begin(&port, 9600) ;
	text_print(&port, text) ;
//	serial_print(&port, "Hello World!") ;
	serial_flush(&port) ;
	serial_end(&port) ;
	return 0 ;
}

