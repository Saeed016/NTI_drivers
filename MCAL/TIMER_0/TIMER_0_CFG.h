/*
 * TIMER_0_CFG.h
 *
 * Created: 2/16/2022 1:21:20 PM
 *  Author: Mr Happy
 */ 


#ifndef TIMER_0_CFG_H_
#define TIMER_0_CFG_H_

/* TIMER_0_MODE options -> [ NORMAL_MODE, CTC_MODE ] */
#define TIMER_0_MODE   NORMAL_MODE

/* TIMER_0_ISR_VECT options -> [ TIMER0_COMP_vect, TIMER0_OVF_vect ] */
#define TIMER_0_ISR_VECT   TIMER0_OVF_vect

/* TIMER_0_D_FACTOR options -> [ 1024, 256, ... ] */
#define TIMER_0_D_FACTOR     1024

/* crystal frequency in Mega Hz */
#define CRYSTAL_FREQ   16

/* PWM_0_MODE options -> [ FAST_PWM, PHASE_CORRECT_PWM, ... ]  */
#define PWM_0_MODE   PHASE_CORRECT_PWM

/* COMPARE_OUTPUT_MODE options -> [ NON_INVERTED, INVERTED, ... ]  */
#define COMPARE_OUTPUT_MODE   NON_INVERTED

#endif /* TIMER_0_CFG_H_ */