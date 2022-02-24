/*
 * ADC_CFG.h
 *
 * Created: 2/15/2022 1:05:46 PM
 *  Author: Mr Happy
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/* V_REF options --> [ AVCC, AREF_PIN, _2V ] */
#define V_REF      AVCC
/* ADJUST options --> [ L_ADJUST, R_ADJUST ] */
#define ADJUST     R_ADJUST
/* ADC_CHANNEL options --> [ CHANNEL_0, CHANNEL_1, ... ] */
#define ADC_CHANNEL     CHANNEL_0

/* PRESCALAR_D_FACTOR options --> [ 2, ..., 128 ] */
#define PRESCALAR_D_FACTOR     128

#endif /* ADC_CFG_H_ */