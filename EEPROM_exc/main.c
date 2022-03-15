/*
 * EEPROM_exc.c
 *
 * Created: 14/03/2022 21:55:27
 * Author : blue
 */ 

 //	THIS PROJECT CONTAINS A MODIFIED LCD.H FILE
 //	SEE #MOD IN LCD.H SOURCE CODE FOR MODIFICATIONS

 //	THIS PROJECT CONTAINS A MODIFIED SER_LIB.H FILE
//	sEE #MOD IN SER_LIB.C SOURCE CODE FOR MODIFICATIONS

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Libraries/eeprom.h"
#include "Libraries/lcd.h"
#include "Libraries/ser_lib.h"

int main(void)
{
    lcd_init(LCD_DISP_ON);
	init_usart();

	lcd_puts("VTI Waregem");
	lcd_gotoxy(0,1);	//	 set cursor to second line

    while (1) 
    {
		
    }
}

ISR(USART0_RX_vect){
	
}

