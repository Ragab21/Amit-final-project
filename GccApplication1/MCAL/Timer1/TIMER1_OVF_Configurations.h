/*
 * TIMER0_OVF_Configurations.h
 *
 * Created: 10/14/2023 11:29:59 AM
 *  Author: oraga
 */ 


#ifndef TIMER1_OVF_CONFIGURATIONS_H_
#define TIMER1_OVF_CONFIGURATIONS_H_

//#include "TIMER0_OVF_Address.h"
#include "CPU_CONFIGURATIONS.h"
#include "MCAL_Structs.h"

#define OVF_FREQ        16
#define OVF_PRES        1024
#define OVF1_BITS        65536
#define OVF_MICROSECOND 1000

typedef enum
{
	OVF1_No_Clock_Source = 0,
	OVF1_No_Prescaling = 1,
	OVF1_PRESCALER_8 = 2,
	OVF1_PRESCALER_64 = 3,
	OVF1_PRESCALER_256 = 4,
	OVF1_PRESCALER_1024 = 5,
	OVF1_External_Falling = 6,
	OVF1_External_Rising = 7
}timer1_ovf_prescaler;






#endif /* TIMER0_OVF_CONFIGURATIONS_H_ */