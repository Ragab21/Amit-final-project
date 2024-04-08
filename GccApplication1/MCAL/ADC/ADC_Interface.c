/*
 * ADC_Interface.c
 *
 * Created: 10/7/2023 12:10:21 PM
 *  Author: oraga
 */ 

#include "ADC_Private.h"

void ADC_Initialize(adc_vref voltage , adc_prescaler prescaler)
{
	cli();
	ADMUX |= 0x40;
	ADCSRA |= 0xFF;
	SFIOR |= 0xE0;
	sei();
}
uint16_t ADC_Read()
{
	uint16_t val = 0;
	ADMUX |= 0x00;
	val = ADC_VAL;
	return val;
}
