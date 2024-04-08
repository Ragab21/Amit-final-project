/*
 * TIMER0_OVF_Private.h
 *
 * Created: 10/14/2023 11:30:15 AM
 *  Author: oraga
 */ 


#ifndef TIMER1_OVF_PRIVATE_H_
#define TIMER1_OVF_PRIVATE_H_

#include "TIMER1_OVF_Configurations.h"

void Timer1_OVF_WithoutInterrupt_Initialize(void);
void Timer1_OVF_WithoutInterrupt_Start(timer1_ovf_prescaler prescale);
void Timer1_OVF_WithoutInterrupt_Stop(void);
void Timer1_OVF_WithoutInterrupt_SetDelay(uint32_t delay);
		  
void Timer1_OVF_WithInterrupt_Initialize(void);
void Timer1_OVF_WithInterrupt_Start(timer1_ovf_prescaler prescale);
void Timer1_OVF_WithInterrupt_Stop(void);
void Timer1_OVF_WithInterrupt_SetDelay(uint32_t delay);
void ICU_Initialize(void);
FreqAndDuty Get_FreqAndDuty();




#endif /* TIMER0_OVF_PRIVATE_H_ */