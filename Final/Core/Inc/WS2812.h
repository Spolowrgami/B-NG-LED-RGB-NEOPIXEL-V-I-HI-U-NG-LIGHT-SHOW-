#ifndef WS2812_H
#define WS2812_H

#include "main.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fast_math_functions.h>

#define MAX_LED 				300
#define USE_BRIGHTNESS 			1

void Set_LED(int LEDnum, int Red, int Green, int Blue);
void Get_LED(int LEDnum, uint8_t *r, uint8_t *g, uint8_t *b);
void Reset_All_LED();
void Set_Brightness(int brightness);
void WS2812_Send(void);

#endif
