/*
 * DC_MOTOR.h
 *
 * Created: 2/21/2022 1:22:05 PM
 *  Author: Mr Happy
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "STD_TYPES.h"

void DC_MOTOR_INIT(void);
void DC_MOTOR_START(void);
void DC_MOTOR_STOP(void);
void DC_MOTOR_SET_SPEED(u8);
void DC_MOTOR_SET_DIR(u8);

#define CLK  0  //clk wise
#define ACLK 1  //anti-clk wise

#endif /* DC_MOTOR_H_ */