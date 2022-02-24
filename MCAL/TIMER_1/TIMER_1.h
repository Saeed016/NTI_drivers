/*
 * TIMER_1.h
 *
 * Created: 2/23/2022 9:31:49 AM
 *  Author: Mr Happy
 */ 


#ifndef TIMER_1_H_
#define TIMER_1_H_

#include "STD_TYPES.h"

void TIMER_1_INIT(void);
void TIMER_1_SET_TIME(u32);
void TIMER_1_START(void);
void TIMER_1_STOP(void);

void PWM_1_INIT(void);
void PWM_1_SET_FREQUENCY(u16);
void PWM_1_SET_DUTY_CYCLE(u8);
void PWM_1_START(void);
void PWM_1_STOP(void);

void SET_TIMER_1_CALL_BACK (void (*)(void));

#define TIMER_1_CTC_MODE          1
#define FAST_PWM_TOP_ICR1         2


#endif /* TIMER_1_H_ */