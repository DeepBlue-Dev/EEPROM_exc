#include <avr/io.h>

void init_usart()
{
	//	set RX(PD0) as input, TX(PD1) as output and high
	DDRD &= ~(1 << DDRD0);
	DDRD |= (1 << DDRD1);
	PORTD |= (1 << PORTD1);
	//	normal speed
	UCSR0A &= ~(1 << U2X0);
	//	set baud rate to 9600 (23 for the register)
	UBRR0 = 23;
	//	mode select: asynchronous USART
	UCSR0C &= ~((1 << UMSEL00) | (1 << UMSEL01));
	//	No parity
	UCSR0C &= ~((1 << UPM00) | (1 << UPM01));
	//	1 stop bit
	UCSR0C &= ~(1 << USBS0);
	//	8 databits
	UCSR0B &= ~(1 << UCSZ02);
	UCSR0C |=((1 << UCSZ00) | (1 << UCSZ01));
	//	we want to trigger an interrupt when the receive buffer is full
	UCSR0B |= (1 << RXCIE0);
	//	enable receive and transmit port
	UCSR0B |= ((1 << RXEN0) | (1 << TXEN0));
}

char isCharAvailable()
{
if ( (UCSR0A & (0x80)) ) return 1; // Als RXC0 == 1 dan is er data aanwezig in het dataregister
else return 0;
}

char receiveChar()
{
return UDR0; 
}

void sendChar(char data)
{
while( ! (UCSR0A & 0x20) ); //wachten tot zendbuffer is leeg
UDR0 = data;
}

void sendString(char s[])
{
int i = 0;
while(i < 64) 
	{
	if( s[i] == '\0' ) break; 
	sendChar(s[i++]);
	}
}
