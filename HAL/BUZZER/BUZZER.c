/*
 * LED.c
 *
 * Created: 2/8/2022 11:12:36 AM
 *  Author: Mr Happy
 */ 
#include "BUZZER.h"
#include "BUZZER_CFG.h"
#include "DIO.h"
#include <util/delay.h>

void BUZZER_INIT(void)
{
	PIN_MODE(BUZZER_PIN, OUTPUT);
}
void BUZZER_ON(void)
{
	PIN_WRITE(BUZZER_PIN, HIGH);
}
void BUZZER_OFF(void)
{
	PIN_WRITE(BUZZER_PIN, LOW);
}
void BUZZER_TOG(void)
{
	PIN_TOG(BUZZER_PIN);
}
void BUZZER_ONCE(void)
{
	BUZZER_ON();
	_delay_ms(800);
	BUZZER_OFF();
}
void BUZZER_TWICE(void)
{
	BUZZER_ONCE();
	_delay_ms(800);
	BUZZER_ONCE();
}
void BUZZER_THRICE(void)
{
	BUZZER_ONCE();
	_delay_ms(500);
	BUZZER_ONCE();
	_delay_ms(500);
	BUZZER_ONCE();
}
void BUZZER_LONG(void)
{
	BUZZER_ON();
	_delay_ms(1000);
	BUZZER_OFF();
}