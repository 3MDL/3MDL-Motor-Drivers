#define F_CPU 800000UL
#define delay 10

#include <avr/io.h>
#include <util/delay.h>

#define voltage 0.08
#define voltageADC (voltage*1024.0)/5.0

//PB3 is digital switch output
//PB4 is ADC feedback input

int main() {
	ADCSRA |= (1 << ADEN); //enable ADC
	DDRB |= (1 << PB3) | (1 << PB2); //PB2 & PB3 output
	ADMUX = (1 << MUX1);// | (1 << REFS1); //A1 with 1.1V internal ref
  while (1) {
		ADCSRA |= (1 << ADSC); //start reading

		while (ADCSRA & (1 << ADSC));
		int adcLow = ADCL;
		int adcHigh = ADCH;
		float adcVal = (adcHigh << 8) | adcLow;

		if (adcVal > 10){
			PORTB &= ~(1 << PB3); //turn switch OFF
		} else {
			PORTB |= (1 << PB3); //turn switch ON
		}	
		PINB = (1 << PB2); //toggle PB2 to measure freq.
		//_delay_us(delay);
  }
}
