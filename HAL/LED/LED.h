/*
 * LED.h
 *
 * Created: 08/02/2022 11:13:09 ص
 *  Author: dell
 */ 


#ifndef LED_H_
#define LED_H_

#include "STD_TYPES.h"

void LED_INIT(u8);
void LED_ON(u8);
void LED_OFF(u8);
void LED_TOG(u8);

#define B_LED      1
#define G_LED      2
#define R_LED      3

#endif /* LED_H_ */