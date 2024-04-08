/*
 * ADC_Address.h
 *
 * Created: 10/7/2023 12:09:31 PM
 *  Author: oraga
 */ 


#ifndef ADC_ADDRESS_H_
#define ADC_ADDRESS_H_
#include "CPU_CONFIGURATIONS.h"

/*
#define ADMUX   (*(volatile uint8_t*)(0x27))
#define ADCL    (*(volatile uint8_t*)(0x24))
#define ADCH    (*(volatile uint8_t*)(0x25))
#define ADCSRA  (*(volatile uint8_t*)(0x26))
#define SFIOR   (*(volatile uint8_t*)(0x50))
*/
#define ADC_VAL (*(volatile uint16_t*)(0x24))




#endif /* ADC_ADDRESS_H_ */