#include <avr/io.h>


void EEPROM_write(unsigned int uiAddress, unsigned char ucData)
{
while(EECR & (1<<EEPE)); // wachten tot EEPE nul wordt (vorige schrijfactie)
EEAR = uiAddress;
EEDR = ucData;		// instellen van EEPROM adres en toewijzen data
EECR |= (1<<EEMPE);	// schrijven van '1' naar EEMPE
EECR |= (1<<EEPE); 	// start schrijven naar EEPROM
}

unsigned char EEPROM_read(unsigned int uiAddress)
{
while(EECR & (1<<EEPE)); 	// wachten tot EEWE nul wordt (vorige schrijfactie)
EEAR = uiAddress; 	// instellen van EEPROM adres
EECR |= (1<<EERE);	// start lezen naar EEPROM
return EEDR;	// terugkeren met waarde 
}

void EEPROM_write_string(unsigned int StartAddress, char buffer[16])
{
unsigned char p=0;
for (unsigned int i=StartAddress; i<(StartAddress+16); i++)
	{
	EEPROM_write(i, buffer[p]);
	p++;
	}
}

void EEPROM_read_string(unsigned int StartAddress, char buffer[16])
{
unsigned char t=0;
do
	{
	buffer[t]=EEPROM_read(StartAddress+t);
	t++;
	} while (t<16);
}

