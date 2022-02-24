/*
 * SSD.h
 *
 * Created: 09/02/2022 09:45:40 ص
 *  Author: dell
 */ 


#ifndef SSD_H_
#define SSD_H_

#include "STD_TYPES.h"

void SSD_INIT(void);
void SSD_DISPLAY(u8);
void SSD_COUNT_DOWN(s8);
void SSD_COUNT_UP(u8);
void SSD_DISPLAY_BLINK(u8);
void SSD_DISPLAY_DIGIT(u8,u8);

#define R_SSD       1
#define L_SSD       2

#endif /* SSD_H_ */