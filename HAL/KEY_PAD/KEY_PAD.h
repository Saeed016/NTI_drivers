/*
 * KEY_PAD.h
 *
 * Created: 10/02/2022 01:05:46 م
 *  Author: dell
 */ 


#ifndef KEY_PAD_H_
#define KEY_PAD_H_

#include "STD_TYPES.h"

void KEY_PAD_INIT(void);
u8   KEY_PAD_READ(void);

#define PRESSED    0
#define RELEASED   1


#endif /* KEY_PAD_H_ */