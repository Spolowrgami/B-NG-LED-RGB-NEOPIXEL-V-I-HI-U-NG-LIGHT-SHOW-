/*
 * FFT.h
 *
 *  Created on: May 19, 2025
 *      Author: ACER
 */

#ifndef INC_FFT_H_
#define INC_FFT_H_

#include "arm_math.h"
#include "stm32f4xx_hal.h"
#include <string.h>
#include "WS2812.h"
#include "stdio.h"
#include <stdlib.h>

#define SAMPLING_FREQ     			10000.0f
#define FFT_SIZE          			512
#define SOUND_BASE					1800
#define BASS_FREQ_MAX     			200.0f
#define MID_FREQ_MAX      			2000.0f
#define TREBLE_FREQ_MAX   			8000.0f

//#define MIN_DELAY 					200
//#define MAX_DELAY 					1000

#define SOUND_MAX 					3000.0f


void Calculate_FFT(void);
void Analyze_Frequency_Bands(float* bass, float* mid, float* treble);

void FFT_SETUP(void);
void Print_FFT(void);

void Alternating_Flash(uint32_t MIN_DELAY, uint32_t MAX_DELAY);
void Light_Bar(void);
void EchoSplit();
void Sparkle(void);

// not sure :)
//void Waves(void);



#endif /* INC_FFT_H_ */
