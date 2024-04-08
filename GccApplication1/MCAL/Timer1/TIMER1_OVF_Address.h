/*
 * TIMER0_OVF_Address.h
 *
 * Created: 10/14/2023 11:29:31 AM
 *  Author: oraga
 */ 


#ifndef TIMER1_OVF_ADDRESS_H_
#define TIMER1_OVF_ADDRESS_H_

#define TCCR0  (*(volatile uint8_t*)(0x53))
#define TCNT0  (*(volatile uint8_t*)(0x52))
#define TIMSK  (*(volatile uint8_t*)(0x59))
#define TIFR  (*(volatile uint8_t*)(0x58))
#define OCR0  (*(volatile uint8_t*)(0x5C))




#endif /* TIMER0_OVF_ADDRESS_H_ */