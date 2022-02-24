/*
 * P_B.c
 *
 * Created: 10/02/2022 09:39:38 ص
 *  Author: dell
 */ 
#include "P_B_CFG.h"
#include "STD_TYPES.h"
#include "P_B.h"
#include "DIO.h"

#define F_CPU 16000000UL
#include <avr/delay.h>

void P_B_INIT(u8 p_b)
{
	switch(p_b)
	{
		case P_B_1:
		PIN_MODE(P_B_1_PIN,INPUT);
		break;
		case P_B_2:
		PIN_MODE(P_B_2_PIN,INPUT);
		break;
		case P_B_3:
		PIN_MODE(P_B_3_PIN,INPUT);
		break;
		case P_B_4:
		PIN_MODE(P_B_4_PIN,INPUT);
		break;
		default:
		break;
	}
}
u8   P_B_READ(u8 p_b)
{
	u8 value = RELEASED;
	switch(p_b)
	{
		case P_B_1:
		_delay_ms(20);
		if (PIN_READ(P_B_1_PIN) == PRESSED)
		{
			while(PIN_READ(P_B_1_PIN) == PRESSED);
			value = PRESSED;
		}
		break;
		case P_B_2:
		_delay_ms(20);
		if (PIN_READ(P_B_2_PIN) == PRESSED)
		{
			while(PIN_READ(P_B_2_PIN) == PRESSED);
			value = PRESSED;
		}
		break;
		case P_B_3:
		_delay_ms(20);
		if (PIN_READ(P_B_3_PIN) == PRESSED)
		{
			while(PIN_READ(P_B_3_PIN) == PRESSED);
			value = PRESSED;
		}
		break;
		case P_B_4:
		_delay_ms(20);
		if (PIN_READ(P_B_4_PIN) == PRESSED)
		{
			while(PIN_READ(P_B_4_PIN) == PRESSED);
			value = PRESSED;
		}
		break;
		default:
		break;
	}	
	return value;
}