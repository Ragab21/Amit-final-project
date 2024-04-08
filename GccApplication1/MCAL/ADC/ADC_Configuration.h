/*
 * ADC_Configuration.h
 *
 * Created: 10/7/2023 12:09:48 PM
 *  Author: oraga
 */ 


#ifndef ADC_CONFIGURATION_H_
#define ADC_CONFIGURATION_H_
#include "ADC_Address.h"

typedef enum
{
	AREF =0,
	AVCC = 1,
	Internal = 2
}adc_vref;
typedef enum
{
	ADC_0 = 0,
	ADC_1 = 1,
	ADC_2 = 2,
	ADC_3 = 3,
	ADC_4 = 4,
	ADC_5 = 5,
	ADC_6 = 6,
	ADC_7 = 7
	
}adc_channel;

typedef enum
{
	ADC_PRE0 = 0,
	ADC_PRE2 = 1,
	ADC_PRE4 = 2,
	ADC_PRE8 = 3,
	ADC_PRE16 = 4,
	ADC_PRE32 = 5,
	ADC_PRE64 = 6,
	ADC_PRE128 = 7
}adc_prescaler;



#endif /* ADC_CONFIGURATION_H_ */