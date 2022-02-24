/*
 * TIMER_1.c
 *
 * Created: 2/23/2022 9:32:02 AM
 *  Author: Mr Happy
 */ 

#include "BIT_MATH.h"
#include "TIMER_1_CFG.h"
#include "TIMER_1.h"
#include "STD_TYPES.h"
#include "REG.h"
#include "LED.h"
#include <avr/interrupt.h>

void (*TIMER_1_CALL_BACK)(void);

#if   TIMER_1_MODE  ==  NORMAL_MODE
static u32 num_of_ov_timer1   = 0;
#elif TIMER_1_MODE  ==  TIMER_1_CTC_MODE
static u32 num_of_cm_timer1   = 0;
#endif

static u32 total_ticks = 0;

void TIMER_1_INIT(void)
{
	// B_LED OUTPUT
	
	#if   TIMER_1_MODE  ==  TIMER_1_CTC_MODE
		// to select CTC mode, OCR1A -> TOP
		CLR_BIT(TCCR1A, 0);
		CLR_BIT(TCCR1A, 1);
		SET_BIT(TCCR1B, 3);
		CLR_BIT(TCCR1B, 4);
	
		// normal CTC mode
		CLR_BIT(TCCR1A, 6);
		CLR_BIT(TCCR1A, 7);			// enable OCR1A compare match interrupt		SET_BIT(TIMSK, 4);
	#endif
	// enable general interrupt	SET_BIT(SREG, 7);
}

void TIMER_1_SET_TIME(u32 desired_time)
{
	u32 tick_time   = (1024/CRYSTAL_FREQ);
	total_ticks     = (desired_time * 1000) / tick_time;
	
	#if   TIMER_1_MODE      ==     NORMAL_MODE
	num_of_ov_timer1       = total_ticks / 65536;
	if (total_ticks % 65536 != 0)
	{
		TCNT0 = 65536 - (total_ticks % 65536);
		num_of_ov_timer1++;
	}
	
	#elif TIMER_1_MODE      ==     TIMER_1_CTC_MODE
	//LED_ON(B_LED);
	u32 ocr_value = 65535;
	while( (total_ticks % ocr_value) != 0)
	{
		ocr_value--;
	}
	num_of_cm_timer1 = total_ticks / ocr_value;
	// (-1) because comparing values takes one extra clock tick
	OCR1A_VALUE = ocr_value - 1;
	#endif
}

void TIMER_1_START(void)
{
	SET_BIT(TCCR1B, 0);
	CLR_BIT(TCCR1B, 1);
	SET_BIT(TCCR1B, 2);
}
void TIMER_1_STOP(void)
{
	CLR_BIT(TCCR1B, 0);
	CLR_BIT(TCCR1B, 1);
	CLR_BIT(TCCR1B, 2);
}

void PWM_1_INIT(void)
{
	// to make pin PD5 output -> generated pwm signal is connected to it
	SET_BIT(DDRD, 5);
		
	#if PWM_1_MODE  ==  FAST_PWM_TOP_ICR1
		// to select waveform generation mode number 14 (fast PWM, TOP -> ICR1)
		CLR_BIT(TCCR1A, 0);
		SET_BIT(TCCR1A, 1);
		SET_BIT(TCCR1B, 3);
		SET_BIT(TCCR1B, 4);
	
		// to select non-inverted mode
		CLR_BIT(TCCR1A, 6);
		SET_BIT(TCCR1A, 7);
	
		ICR1_VALUE  = 312;
	#endif
}

void PWM_1_SET_FREQUENCY(u16 frequency)
{
	ICR1_VALUE = (((u32)CRYSTAL_FREQ * 1000000) / (TIMER_1_D_FACTOR * frequency));
}

void PWM_1_SET_DUTY_CYCLE(u8 duty_cycle)
{
	OCR1A_VALUE = ((ICR1_VALUE * (u32)duty_cycle) / 100) - 1;
}
void PWM_1_START(void)
{
	// to select 1024 prescalar -> which starts it
	SET_BIT(TCCR1B, 0);
	CLR_BIT(TCCR1B, 1);
	SET_BIT(TCCR1B, 2);
}
void PWM_1_STOP(void)
{
	// disable prescalar -> which stops it
	CLR_BIT(TCCR1B, 0);
	CLR_BIT(TCCR1B, 1);
	CLR_BIT(TCCR1B, 2);
}

void SET_TIMER_1_CALL_BACK (void (*ptr)(void))
{
	TIMER_1_CALL_BACK = ptr;
}

ISR(TIMER1_COMPA_vect)
{
	static u32 counter = 0;
	counter++;
	
	#if   TIMER_1_MODE      ==     NORMAL_MODE
	if( counter == num_of_ov_timer1)
	{
		// what to do
		
		TIMER_1_CALL_BACK();
		counter = 0;
		//seconds++;
		TCNT0 = 65536 - (total_ticks % 256);
	}
	#elif   TIMER_1_MODE      ==     TIMER_1_CTC_MODE
	if( counter == num_of_cm_timer1)
	{
		// what to do
		
		TIMER_1_CALL_BACK();
		counter = 0;
	}
	
	#endif
}