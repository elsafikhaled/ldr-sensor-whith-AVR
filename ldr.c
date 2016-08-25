/*
 * ldr.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

/*******************                   ADC         ************************/
void  ADC_Init(void)
{
	ADMUX=(1<<REFS0)|(1<<MUX0)|(1<<MUX2);   // voltage reference  = 5v Vcc ** ADC1 activated
    ADCSRA=(1<<ADEN)|(1<<ADPS1)|(1<<ADPS2); // divide factor 64 for clock
}


 unsigned int ADC_Read(void)
{
	 ADCSRA|=(1<<ADSC); // start conversion to get digital value IN ADC registers
	 while(ADCSRA & (1<<ADSC));

     return ADC ;
}
/**********************    7 SEGMENT        *****************************/



 /*    buzzer tones  */


 void segments_init(int voltage)
 {

   DDRB|=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3);
   DDRC=(1<<PC4);

   // show voltage on 7segments

    PORTC=(1<<PC4);


    PORTB=voltage;
    _delay_ms(400);




 }

int  main(void)
{

	int voltage;
	volatile int degitalValue;

	ADC_Init();

	while(1)
	{

	   degitalValue=ADC_Read();
       voltage=(degitalValue*(0.0049));  //  :) finally
       segments_init(voltage);
       _delay_ms(500);



	}

return 0;

}




