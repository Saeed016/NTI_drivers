/*
 * SERVO.c
 *
 * Created: 2/23/2022 10:55:33 AM
 *  Author: Mr Happy
 */ 

#include "TIMER_1.h"
#include "SERVO_CFG.h"
#include "SERVO.h"

void SERVO_INIT(void)
{
	PWM_1_INIT();
	PWM_1_SET_FREQUENCY(SERVO_FREQUENCY);
}

void SERVO_SET_ANGLE(u16 angle)
{
	PWM_1_SET_DUTY_CYCLE( ((angle * 10) / (SERVO_MAX_ANGLE)) + 5);
}
void SERVO_START(void)
{
	PWM_1_START();
}
void SERVO_STOP(void)
{
	PWM_1_STOP();
}