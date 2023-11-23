#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	PORTD=0x00;
	DDRD=0x80;
	ASSR=0x00;
	TCCR2=0x6C;
	TCNT2=0x00;
	OCR2=0x00;
	TIMSK=0x00;
	while (1)
	{
		while(OCR2<0xff)
		{
			OCR2=OCR2+0x01;
			_delay_ms(500);
		}
		while(OCR2>0x00)
		{
			OCR2=OCR2-0x01;
			_delay_ms(500);
		}
	}
}