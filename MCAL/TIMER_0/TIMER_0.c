/*
 * TIMER_0.c
 *
 * Created: 2/16/2022 1:21:02 PM
 *  Author: Mr Happy
 */ 

#include "TIMER_0_CFG.h"
#include "TIMER_0.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//#include "avr/interrupt.h" // to get interrupt/vector table/ISR macros
#include "LED.h"
#include "DIO.h"
#include "REG.h"

#if   TIMER_0_MODE  ==  NORMAL_MODE
static u32 num_of_ov   = 0;
#elif TIMER_0_MODE  ==  CTC_MODE
static u32 num_of_cm   = 0;
#endif

static u32 total_ticks = 0;

u8  seconds = 0;
u8  minutes = 0;
u8  hours   = 0;

void (*TIMER_0_CALL_BACK)(void);


void TIMER_0_INIT(void)
{
	#if   TIMER_0_MODE      ==     NORMAL_MODE
	// to select normal mode
	CLR_BIT(TCCR0, 3);
	CLR_BIT(TCCR0, 6);
	// to enable timer0 overflow interrupt
	SET_BIT(TIMSK, 0);
	
	#elif TIMER_0_MODE      ==     CTC_MODE
	// to select CTC mode
	SET_BIT(TCCR0, 3);
	CLR_BIT(TCCR0, 6);
	// to enable timer0 compare match interrupt
	SET_BIT(TIMSK, 1);
	#endif
	
	// to enable global interrupt
	SET_BIT(SREG , 7);
}
void TIMER_0_SET_TIME(u32 desired_time)
{
	u32 tick_time   = (1024/CRYSTAL_FREQ);
	total_ticks     = (desired_time * 1000) / tick_time;
	
	#if   TIMER_0_MODE      ==     NORMAL_MODE
	num_of_ov       = total_ticks / 256;
	if (total_ticks % 256 != 0)
	{
		TCNT0 = 256 - (total_ticks % 256);
		num_of_ov++;
	}
	
	#elif TIMER_0_MODE      ==     CTC_MODE
	u8 ocr_value = 255;
	while( (total_ticks % ocr_value) != 0)
	{
		ocr_value--;
	}
	num_of_cm = total_ticks / ocr_value;
	// (-1) because comparing values takes one extra clock tick
	OCR0 = ocr_value - 1;
	#endif
}

void TIMER_0_START(void)
{
	#if    TIMER_0_D_FACTOR     ==    1024
	SET_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	#elif  TIMER_0_D_FACTOR     ==    256
	CLR_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	#endif
}
void TIMER_0_STOP(void)
{
	CLR_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);
}

void PWM_0_INIT(void)
{
	// to set pin PB3 output
	PIN_MODE(PB3, OUTPUT);
	//SET_BIT(DDRB, 3);
	#if   PWM_0_MODE     ==    FAST_PWM
	// to select FAST PWM mode
	SET_BIT(TCCR0, 3);
	SET_BIT(TCCR0, 6);
		#if   COMPARE_OUTPUT_MODE   ==   INVERTED
		// to select inverted mode
		SET_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
		#elif COMPARE_OUTPUT_MODE   ==   NON_INVERTED
		// to select non-inverted mode
		CLR_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
		#endif
	
	#elif PWM_0_MODE     ==    PHASE_CORRECT_PWM
	CLR_BIT(TCCR0, 3);
	SET_BIT(TCCR0, 6);
		#if   COMPARE_OUTPUT_MODE   ==   INVERTED
		// to select inverted mode
		//SET_BIT(TCCR0, 4);
		//SET_BIT(TCCR0, 5);
		#elif COMPARE_OUTPUT_MODE   ==   NON_INVERTED
		// to select non-inverted mode
		CLR_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
		#endif
	#endif
	
}
void PWM_0_SET_DUTY_CYCLE(u8 duty_cycle)
{
	#if   PWM_0_MODE     ==    FAST_PWM

		#if   COMPARE_OUTPUT_MODE   ==   INVERTED
		OCR0 = 255 - ((duty_cycle * 256) / 100);
		#elif COMPARE_OUTPUT_MODE   ==   NON_INVERTED
		OCR0 = ((duty_cycle * 256) / 100) - 1;
		#endif
	
	#elif PWM_0_MODE     ==    PHASE_CORRECT_PWM

		#if   COMPARE_OUTPUT_MODE   ==   INVERTED
		OCR0 = (duty_cycle * 255) / 100;
		#elif COMPARE_OUTPUT_MODE   ==   NON_INVERTED
		OCR0 = 255 - ((duty_cycle * 255) / 100);
		#endif
	#endif
}
void PWM_0_START(void)
{
	// selects pre-scalar
	TIMER_0_START();
}
void PWM_0_STOP(void)
{
	TIMER_0_STOP();
}

void SET_TIMER_0_CALL_BACK (void (*ptr)(void))
{
	TIMER_0_CALL_BACK = ptr;
}

/*
ISR(TIMER_0_ISR_VECT)
{
	static u32 counter = 0;
	counter++;
	
	#if   TIMER_0_MODE      ==     NORMAL_MODE
	if( counter == num_of_ov)
	{
		 // what to do
		 
		 TIMER_0_CALL_BACK();
		 counter = 0;
		 //seconds++;
		 TCNT0 = 256 - (total_ticks % 256);
	}
	#elif   TIMER_0_MODE      ==     CTC_MODE
	if( counter == num_of_cm)
	{
		// what to do
		
		TIMER_0_CALL_BACK();
		counter = 0;
	}
	
	#endif
}
*/