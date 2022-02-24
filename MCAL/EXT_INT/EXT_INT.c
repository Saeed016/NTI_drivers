/*
 * EXT_INT.c
 *
 * Created: 2/14/2022 10:28:09 AM
 *  Author: Mr Happy
 */ 

#include "REG.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h> // to get interrupt/vector table/ISR macros
#include "EXT_INT_CFG.h"
#include "EXT_INT.h"

void (*CALL_BACK) (void);

void EXT_INT_0_INIT(void)
{
	#if SENSE_CONTROL        ==      FALLING_EDGE 
	// to select falling edge -> activate interrupt 0
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	
	#elif SENSE_CONTROL      ==      RISING_EDGE
	CLR_BIT(MCUCR,1);
	SET_BIT(MCUCR,1);
	
	#elif SENSE_CONTROL      ==      LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	
	#elif SENSE_CONTROL      ==      LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	#endif
	// to enable global interrupt
	SET_BIT(SREG,7);
	// to enable INT0 interrupt
	SET_BIT(GICR,6);
}
// bn3ml kda 3lshan nmshy 3la el architecture bta3 autozar
void EXT_INT_0_SET_CALL_BACK(void (*ptr) (void))
{
	CALL_BACK = ptr;
}

ISR(INT0_vect)
{
	CALL_BACK();
}