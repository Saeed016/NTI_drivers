/*
 * DC_MOTOR.c
 *
 * Created: 2/21/2022 1:21:50 PM
 *  Author: Mr Happy
 */ 

#include "DC_MOTOR_CFG.h"
#include "DC_MOTOR.h"
#include "TIMER_0.h"
#include "DIO.h"

void DC_MOTOR_INIT(void)
{
	PIN_MODE(DC_MOTOR_PIN_A, OUTPUT);
	PIN_MODE(DC_MOTOR_PIN_B, OUTPUT);
	PWM_0_INIT();
}

void DC_MOTOR_START(void)
{
	PWM_0_START();
}

void DC_MOTOR_STOP(void)
{
	PWM_0_STOP();
}

void DC_MOTOR_SET_SPEED(u8 speed)
{
	PWM_0_SET_DUTY_CYCLE(speed);
}

void DC_MOTOR_SET_DIR(u8 direction)
{
	switch(direction)
	{
		case CLK:
		PIN_WRITE(DC_MOTOR_PIN_A, HIGH);
		PIN_WRITE(DC_MOTOR_PIN_B, LOW);
		break;
		case ACLK:
		PIN_WRITE(DC_MOTOR_PIN_A, LOW);
		PIN_WRITE(DC_MOTOR_PIN_B, HIGH);
		break;
		default:
		break;
	}
}