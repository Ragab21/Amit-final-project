/*
 * TIMER0_OVF_Interface.c
 *
 * Created: 10/14/2023 11:30:47 AM
 *  Author: oraga
 */ 

#include "TIMER1_OVF_Private.h"

//Blocking Mode if timer0
void Timer1_OVF_WithoutInterrupt_Initialize(void)
{
	TCCR1A &=~ ((1<<WGM10) | (1<<WGM11) | (1<<WGM12) | (1<<WGM13) | (1<<COM1A1) | (1<<COM1B1) | (1<<COM1A0) | (1<<COM1B0));
	TIMSK &=~ ((1<<TOIE1));
}
void Timer1_OVF_WithoutInterrupt_Start(timer1_ovf_prescaler prescale)
{
	switch (prescale)
	{
		case OVF1_No_Clock_Source:
		TCCR1B &=~ ((1<<CS12)|(1<<CS11)|(1<<CS10));
		break;
		case OVF1_No_Prescaling:
		TCCR1B &=~ ((1<<CS12)|(1<<CS11));
		TCCR1B |= (1<<CS10);
		break;
		case OVF1_PRESCALER_8:
		TCCR1B &=~ ((1<<CS12)|(1<<CS10));
		TCCR1B |= (1<<CS11);
		break;
		case OVF1_PRESCALER_64:
		TCCR1B &=~ (1<<CS12);
		TCCR1B |= ((1<<CS10)|(1<<CS11));
		break;
		case OVF1_PRESCALER_256:
		TCCR1B &=~ ((1<<CS10)|(1<<CS11));
		TCCR1B |= (1<<CS12);
		break;
		case OVF1_PRESCALER_1024:
		TCCR1B &=~ (1<<CS11);
		TCCR1B |= ((1<<CS10)|(1<<CS12));
		break;
		case OVF1_External_Falling:
		TCCR1B &=~ (1<<CS10);
		TCCR1B |= ((1<<CS11)|(1<<CS12));
		break;
		case OVF1_External_Rising:
		TCCR1B |= ((1<<CS10)|(1<<CS11)|(1<<CS12));
		break;
	}
}
void Timer1_OVF_WithoutInterrupt_Stop(void)
{
	TCCR1B &=~ ((1<<CS12)|(1<<CS11)|(1<<CS10));
}
void Timer1_OVF_WithoutInterrupt_SetDelay(uint32_t delay)
{
	uint32_t counter = 0;
	uint8_t Tick = ((1*OVF_PRES)/OVF_FREQ);
	uint32_t Count = ((delay*OVF_MICROSECOND)/Tick);
	uint32_t OVF = (Count/OVF1_BITS);
	uint8_t Initial = (OVF1_BITS-(Count%OVF1_BITS));
	OVF++;
	TCNT1 = Initial;
	while (counter != OVF)
	{
		while(counter != OVF)
		{
			while(GET_BIT(TIFR, TOV1) != 1);
			SET_BIT(TIFR, TOV1);
			counter++;
		}
	}
}


//Non-Blocking Mode if timer0
void Timer1_OVF_WithInterrupt_Initialize(void)
{
	TCCR1A &=~ ((1<<WGM10) | (1<<WGM11) | (1<<WGM12) | (1<<WGM13) | (1<<COM1A1) | (1<<COM1B1) | (1<<COM1A0) | (1<<COM1B0));
	TIMSK |= ((1<<TOIE1));
	SREG  |= ((1<<7));
}
void Timer1_OVF_WithInterrupt_Start(timer1_ovf_prescaler prescale)
{
	switch (prescale)
	{
		case OVF1_No_Clock_Source:
		TCCR1B &=~ ((1<<CS12)|(1<<CS11)|(1<<CS10));
		break;
		case OVF1_No_Prescaling:
		TCCR1B &=~ ((1<<CS12)|(1<<CS11));
		TCCR1B |= (1<<CS10);
		break;
		case OVF1_PRESCALER_8:
		TCCR1B &=~ ((1<<CS12)|(1<<CS10));
		TCCR1B |= (1<<CS11);
		break;
		case OVF1_PRESCALER_64:
		TCCR1B &=~ (1<<CS12);
		TCCR1B |= ((1<<CS10)|(1<<CS11));
		break;
		case OVF1_PRESCALER_256:
		TCCR1B &=~ ((1<<CS10)|(1<<CS11));
		TCCR1B |= (1<<CS12);
		break;
		case OVF1_PRESCALER_1024:
		TCCR1B &=~ (1<<CS11);
		TCCR1B |= ((1<<CS10)|(1<<CS12));
		break;
		case OVF1_External_Falling:
		TCCR1B &=~ (1<<CS10);
		TCCR1B |= ((1<<CS11)|(1<<CS12));
		break;
		case OVF1_External_Rising:
		TCCR1B |= ((1<<CS10)|(1<<CS11)|(1<<CS12));
		break;
	}
}
void Timer1_OVF_WithInterrupt_Stop(void)
{
	TCCR1B &=~ ((1<<CS12)|(1<<CS11)|(1<<CS10));
}
uint8_t OVF1_Initial_Value = 0;
uint32_t OVF1_NUM = 0;
void Timer1_OVF_WithInterrupt_SetDelay(uint32_t delay)
{
	uint8_t Tick = ((1*OVF_PRES)/OVF_FREQ);
	uint32_t Count = ((delay*OVF_MICROSECOND)/Tick);
	 OVF1_NUM = (Count/OVF1_BITS);
	 OVF1_Initial_Value = (OVF1_BITS-(Count%OVF1_BITS));
	 TCNT1 = OVF1_Initial_Value;
	 OVF1_NUM++;
}

void ICU_Initialize(void)
{
	TCCR1B |= (1<<ICES1);
	TCCR1B &=~ ((1<<WGM13)|(1<<WGM12));
	TCCR1B &=~ ((1<<CS12)|(1<<CS11)|(1<<CS10));
	PORTD = 0xFF;
}

FreqAndDuty Get_FreqAndDuty(void)
{
	FreqAndDuty restults;
	restults.acceptable = 1;
	uint16_t a,b,c,high,period;
	uint8_t duty_cycle;
	TCCR1A = 0;
	TCNT1=0;
	TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag) flag */

	TCCR1B = 0x41;  	/* Rising edge, no prescaler */
	while ((TIFR&(1<<ICF1)) == 0);
	a = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
	
	TCCR1B = 0x01;  	/* Falling edge, no prescaler */
	while ((TIFR&(1<<ICF1)) == 0);
	b = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
	
	TCCR1B = 0x41;  	/* Rising edge, no prescaler */
	while ((TIFR&(1<<ICF1)) == 0);
	c = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */

	TCCR1B = 0;  		/* Stop the timer */
	
	if(a<b && b<c)  	/* Check for valid condition, 
				to avoid timer overflow reading */
	{
		high=b-a;
		period=c-a;
		
		uint32_t freq= F_CPU/period;/* Calculate frequency */

		/* Calculate duty cycle */
		duty_cycle = (uint8_t)(((uint32_t)high * 100) / period);
		ltoa(freq, restults.frequency, 10);
		itoa(duty_cycle, restults.duty_cy, 10);
		restults.dutyCycle = duty_cycle;

	}
		else
		{
			restults.acceptable = 0;
		}
		_delay_ms(50);
		return restults;
}