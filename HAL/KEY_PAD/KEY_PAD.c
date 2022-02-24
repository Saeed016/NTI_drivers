/*
 * KEY_PAD.c
 *
 * Created: 10/02/2022 01:05:34 م
 *  Author: dell
 */ 
#include "KEY_PAD_CFG.h"
#include "STD_TYPES.h"
#include "DIO.h"
#include "KEY_PAD.h"
#define F_CPU 16000000UL
#include <util/delay.h>

u8 arr [4][4] = {{ '1' ,'2' , '3' , 'A' },
				 { '4' ,'5' , '6' , 'B' },
				 { '7' ,'8' , '9' , 'A' },
				 { '*' ,'0' , '#' , 'A' }};

void KEY_PAD_INIT(void)
{
	PIN_MODE(KEY_PAD_R0,OUTPUT);
	PIN_MODE(KEY_PAD_R1,OUTPUT);
	PIN_MODE(KEY_PAD_R2,OUTPUT);
	PIN_MODE(KEY_PAD_R3,OUTPUT);
	
	PIN_WRITE(KEY_PAD_R0,HIGH);
	PIN_WRITE(KEY_PAD_R1,HIGH);
	PIN_WRITE(KEY_PAD_R2,HIGH);
	PIN_WRITE(KEY_PAD_R3,HIGH);
	
	PIN_MODE(KEY_PAD_C0,INPUT);
	PIN_MODE(KEY_PAD_C1,INPUT);
	PIN_MODE(KEY_PAD_C2,INPUT);
	PIN_MODE(KEY_PAD_C3,INPUT);
}
u8   KEY_PAD_READ(void)
{
	u8 reading = 0;
	u8 r = 0;
	u8 c = 0;
	u8 value = RELEASED;
	for (r=KEY_PAD_R0;r<=KEY_PAD_R3;r++)
	{
		PIN_WRITE(r,LOW);
		for (c=KEY_PAD_C0;c<=KEY_PAD_C3;c++)
		{
			value = PIN_READ(c);
			if(value == PRESSED)
			{
				_delay_ms(120);
				value = PIN_READ(c);
				if (value == PRESSED)
				{
					while(PIN_READ(c) == PRESSED);
					reading =  arr[r - KEY_PAD_R0][c - KEY_PAD_C0];
				}
			}
		}
		PIN_WRITE(r,HIGH);
	}
	return reading;
}