/*
 * WDT.c
 *
 * Created: 2/20/2022 1:09:27 PM
 *  Author: Mr Happy
 */ 

#include "BIT_MATH.h"
#include "REG.h"

#define F_CPU 16000000UL
#include <util/delay.h>

void WDT_INIT(void)
{
	// watchdog timer prescalar
	SET_BIT(WDTCR, 0);
	SET_BIT(WDTCR, 1);
	SET_BIT(WDTCR, 2);
	
	// watchdog timer enable
	SET_BIT(WDTCR, 3);
}

void WDT_REFRESH(void)
{
	asm("WDR");
	/*
	another solution
	SET_BIT(WDTCR, 3);
	SET_BIT(WDTCR, 4);
	CLR_BIT(WDTCR, 3);
	*/
}