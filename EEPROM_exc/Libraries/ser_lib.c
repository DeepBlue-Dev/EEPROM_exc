#include <avr/io.h>

void init_usart()
{
//Info USART0 voor Atmega324P
//Aansluitingen RXD0 - PD0 - Pin 14; TXD0 - PD1 - Pin 15
//UDR0 = Dataregister
//UCSR0A = USART0 Control and Status Register A
//UCSR0B = USART0 Control and Status Register B
//UCSR0C = USART0 Control and Status Register C
//UBRR0L and UBRR0H = USART0 Baud Rate Registers

UBRR0H = 0; 
UBRR0L = 23; //9600 bps, UBRR=23 en U2X=0 (normal snelheid)
UCSR0B = (1<<RXEN0) | (1<<TXEN0); // activeren van ontvanger en zender
//UCSR0C default ; // USART, asynchroon, 8 databits, geen pariteit en 1 stop bit
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
