/*
 * MCAL_Structs.h
 *
 * Created: 2/17/2024 12:22:29 PM
 *  Author: oraga
 */ 


#ifndef MCAL_STRUCTS_H_
#define MCAL_STRUCTS_H_

typedef struct
{
	char frequency[14];
	char duty_cy[7];
	uint8_t acceptable;
	uint16_t dutyCycle;
}FreqAndDuty;



#endif /* MCAL_STRUCTS_H_ */