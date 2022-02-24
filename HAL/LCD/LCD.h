/*
 * LCD.h
 *
 * Created: 13/02/2022 10:09:38 ص
 *  Author: dell
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "STD_TYPES.h"

void LCD_INIT(void);
void LCD_WRITE_CMD(u8);
void LCD_WRITE_CHR(u8);
void LCD_WRITE_STR(u8*);
void LCD_WRITE_NUM(u32);
void LCD_WRITE_NUM_NEG(s32);
void LCD_WRITE_NUM_FRACTION(f32);
void LCD_STOP_WATCH_DISPLAY(u8, u8, u8);
void LCD_CLR(void);
void LCD_GOTO(u8,u8);
#define _4_BIT_MODE     4
#define _8_BIT_MODE     8
#endif /* LCD_H_ */