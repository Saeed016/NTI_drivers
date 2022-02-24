/*
 * LM35.c
 *
 * Created: 2/16/2022 9:34:29 AM
 *  Author: Mr Happy
 */ 
#include "LM35_CFG.h"
#include "LM35.h"
#include "ADC.h"

void LM35_INIT(void)
{
	ADC_INIT();
}

u16  LM35_READ(void)
{
	return ADC_READ()/2.046;
}