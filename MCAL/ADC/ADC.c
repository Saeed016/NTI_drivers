/*
 * ADC.c
 *
 * Created: 2/15/2022 1:05:38 PM
 *  Author: Mr Happy
 */ 

#include "STD_TYPES.h"
#include "REG.h"
#include "BIT_MATH.h"
#include "ADC_CFG.h"
#include "ADC.h"
#include <avr/interrupt.h> // to get interrupt/vector table/ISR macros

void (*CALL_BACK) (void);

void ADC_INIT(void)
{
	#if   V_REF          ==      AVCC
	CLR_BIT(ADMUX, 7);
	SET_BIT(ADMUX, 6);
	#elif V_REF          ==      AREF_PIN
	CLR_BIT(ADMUX, 7);
	CLR_BIT(ADMUX, 6);
	#elif V_REF          ==      _2V
	SET_BIT(ADMUX, 7);
	SET_BIT(ADMUX, 6);
	#endif
	
	#if   ADJUST        ==    R_ADJUST
	CLR_BIT(ADMUX,5);
	#elif ADJUST        ==    H_ADJUST
	SET_BIT(ADMUX,5);
	#endif
	
	#if   ADC_CHANNEL   ==  CHANNEL_0
	CLR_BIT(ADMUX,0);
	CLR_BIT(ADMUX,1);
	CLR_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);
	//#elif ADC_CHANNEL   ==  CHANNEL_1
	#endif
	
	#if PRESCALAR_D_FACTOR    ==   128
	SET_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);
	#endif
	// to enable auto trigger mode
	SET_BIT(ADCSRA, 5);
	
	// to enable ADC interrupt
	//SET_BIT(ADCSRA, 3);
	//SET_BIT(SREG, 7);
	
	// to enable ADC
	SET_BIT(ADCSRA, 7);
}


u16  ADC_READ(void)
{
	SET_BIT(ADCSRA, 6);
	while( GET_BIT(ADCSRA, 4) == 0 );
	return ADC_VALUE;
}

void ADC_SET_CALL_BACK(void (*ptr) (void))
{
	CALL_BACK = ptr;
}

ISR(ADC_vect)
{
	CALL_BACK();
}