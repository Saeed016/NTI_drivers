/*
 * ADC.h
 *
 * Created: 2/15/2022 1:05:27 PM
 *  Author: Mr Happy
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "STD_TYPES.h"

void ADC_INIT(void);
u16  ADC_READ(void);
void ADC_SET_CALL_BACK(void (*) (void));

#define AVCC        1
#define AREF_PIN    2
#define _2V         3

#define R_ADJUST    0
#define L_ADJUST    1

#define CHANNEL_0   0


#endif /* ADC_H_ */