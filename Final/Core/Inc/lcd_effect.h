/*
 * lcd_effect.h
 *
 *  Created on: May 20, 2025
 *      Author: Windows
 */
#ifndef LCD_EFFECT_H
#define LCD_EFFECT_H

#include "main.h"
#include "Setup_LCD_Status.h"

typedef struct{
	uint8_t page;
	uint8_t effect1;
	uint8_t effect2;
	uint8_t effect3;
	uint8_t effect4;
	uint8_t back;
	uint8_t fft;
	uint8_t nomal;
	uint8_t current_effect;  // 0 = none, 1 = effect1, 2 = effect2, ...
	uint8_t End_Flag ;
}BackGroundTouchSignal;

void startlcd(void);
void runlcd(void);
void readtouch();



#endif
