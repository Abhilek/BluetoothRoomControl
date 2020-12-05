/*
 * BluetoothHomeAutomation.c
 *
 * Created: 11-11-2018 10.53.27 PM
 * Author : Abhilekh
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define OUTPort PORTC
#define OUTddr DDRC

void usart_init(void)
{
	UCSRB=(1<<RXEN);
	UCSRC=(1<<UCSZ1)|(1<<UCSZ0)|(1<<URSEL);
	UBRRL=0x33;// baud rate 9600
}



int main(void)
{
	char code;
	OUTddr|=((1<<0)|(1<<1)|(1<<2));
	usart_init();
    while (1) 
    {
		while (! (UCSRA & (1<<RXC) ) );
		code=UDR;
		
		
		if(code=='a')
		{
			OUTPort^=(1<<0);
			_delay_ms(500);
		}
		if(code=='b')
		{
			OUTPort^=(1<<1);
			_delay_ms(500);
		}
		if(code=='c')
		{
			OUTPort^=(1<<2);
			_delay_ms(500);
		}
    }
	return 0;
}

