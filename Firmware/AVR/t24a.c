#define F_CPU 800000UL
#define delay 10

#include <avr/io.h>
#include <util/delay.h>

#define voltage 0.005
#define voltageADC (voltage*1024.0)/5.0

//PB2 is digital switch output
//PB4 is ADC feedback input

int main() {
	//char vol = 10;
	/*asm{ 
		ldi r16,(1<<USIWM0)|(1<<USICS1)
		out USICR,r16
	}*/
	//USICR = (1<<USIWM0) | (1<<USICS1);
	ADCSRA |= (1 << ADEN); //enable ADC
	DDRB |= (1 << PB2); //PB2 output
	ADMUX = (1 << MUX1);// | (1 << REFS1); //A1 with 1.1V internal ref
  while (1) {
		/*asm{
			SlaveSPITransfer:
			out USIDR,r16
			ldi r16,(1<<USIOIF)
			out USISR,r16
			SlaveSPITransfer_loop:
			in r16, USISR
			sbrs r16, USIOIF
			rjmp SlaveSPITransfer_loop
			in r16,USIDR
			ret
		}*/
		/*int i;
		for (i = 0; i < 8; i ++){
			USISR = (1<<USIOIF);
		}
		vol = USIBR;*/
		ADCSRA |= (1 << ADSC); //start reading

		while (ADCSRA & (1 << ADSC));
		int adcLow = ADCL;
		int adcHigh = ADCH;
		float adcVal = (adcHigh << 8) | adcLow;

		if (adcVal > 1000){
			PORTB &= ~(1 << PB2); //turn switch OFF
		} else {
			PORTB |= (1 << PB2); //turn switch ON
		}	
		//PINB = (1 << PB2); //toggle PB2 to measure freq.
		//_delay_us(delay);
  }
}
