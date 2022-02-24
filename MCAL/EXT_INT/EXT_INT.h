/*
 * EXT_INT.h
 *
 * Created: 2/14/2022 10:27:56 AM
 *  Author: Mr Happy
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

void EXT_INT_0_INIT(void);
void EXT_INT_0_SET_CALL_BACK(void (*)(void));

#define FALLING_EDGE     1
#define RISING_EDGE      2
#define LOGICAL_CHANGE   3
#define LOW_LEVEL        4

#endif /* EXT_INT_H_ */