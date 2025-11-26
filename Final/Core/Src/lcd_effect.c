/*
 * lcd_effect.c
 *
 *  Created on: May 20, 2025
 *      Author: Windows
 */
#include "lcd_effect.h"
#include "LCD_Touch.h"  // thêm dòng này
#include "FFT.h"
#include "WS2812.h"

BackGroundTouchSignal Signal;

void startlcd()
{
	tetrisDrawStatus();
	Signal.page = 0;
	Signal.fft = 0;
	Signal.nomal = 0;
	Signal.back = 0;
	Signal.current_effect = 0;

	giao_dien_batdau();
}

void runlcd(){
	FFT_SETUP();

	switch(Signal.page){
	case 0:
		if(Signal.fft == 1){
			UpdateFFTButton(BUTTON_PRESSED_COLOR, BUTTON_PRESSED_COLOR);
			HAL_Delay(500);
			giao_dien_1();
			tetrisUpdateDownButton(DOWN_BUTTON_COLOR);
			Signal.page = 2;
		}
		break;
	case 2:
		switch (Signal.current_effect) {
				case 1:
					UpdateEF1Button(BUTTON_PRESSED_COLOR, BUTTON_PRESSED_COLOR);
					tetrisUpdateDownButton(COLOR_WHITE);
					UpdateEF2Button(EF2_BUTTON_COLOR, COLOR_BLACK);
					UpdateEF3Button(EF3_BUTTON_COLOR, COLOR_BLACK);
					UpdateEF4Button(EF4_BUTTON_COLOR, COLOR_BLACK);

					Light_Bar();
					break;
				case 2:
					UpdateEF2Button(BUTTON_PRESSED_COLOR, BUTTON_PRESSED_COLOR);
					tetrisUpdateDownButton(COLOR_WHITE);
					UpdateEF1Button(EF1_BUTTON_COLOR, COLOR_BLACK);
					UpdateEF3Button(EF3_BUTTON_COLOR, COLOR_BLACK);
					UpdateEF4Button(EF4_BUTTON_COLOR, COLOR_BLACK);
					Sparkle();
					break;
				case 3:
					UpdateEF3Button(BUTTON_PRESSED_COLOR, BUTTON_PRESSED_COLOR);
					tetrisUpdateDownButton(COLOR_WHITE);
					UpdateEF1Button(EF1_BUTTON_COLOR, COLOR_BLACK);
					UpdateEF2Button(EF2_BUTTON_COLOR, COLOR_BLACK);
					UpdateEF4Button(EF4_BUTTON_COLOR, COLOR_BLACK);
					// Add effect3 code here if needed
					Alternating_Flash(100, 1500);
					break;
				case 4:
					UpdateEF4Button(BUTTON_PRESSED_COLOR, BUTTON_PRESSED_COLOR);
					tetrisUpdateDownButton(COLOR_WHITE);
					UpdateEF1Button(EF1_BUTTON_COLOR, COLOR_BLACK);
					UpdateEF2Button(EF2_BUTTON_COLOR, COLOR_BLACK);
					UpdateEF3Button(EF3_BUTTON_COLOR, COLOR_BLACK);
					EchoSplit();
					break;
				}

				if (Signal.back == 1) {
					tetrisUpdateDownButton(BUTTON_PRESSED_COLOR);
					HAL_Delay(600);
					giao_dien_batdau();
					UpdateFFTButton(FFT_BUTTON_COLOR, COLOR_BLACK);
					Signal.page = 0;
					Signal.current_effect = 0;
				}
				break;
			}


}
void readtouch()
{
	int16_t x, y;
	if (TouchIsTouched()) {
		if (TouchGetCalibratedPoint(&x, &y)) {
			if (Signal.page == 0) {
				if (x >= 135 && x <= 270 && y >= 50 && y <= 70) {
					Signal.fft = 1;
				}
			}
			else if (Signal.page == 1 || Signal.page == 2) {
				if (x >= 200 && x <= 270 && y >= 23 && y <= 70) {
					Signal.current_effect = 1;
					Signal.End_Flag = 1;
				}
				else if (x >= 280 && x <= 320 && y >= 120 && y <= 225) {
					Signal.current_effect = 2;
					Signal.End_Flag = 1;
				}
				else if (x >= 100 && x <= 165 && y >= 40 && y <= 70) {
					Signal.current_effect = 3;
					Signal.End_Flag = 1;
				}
				else if (x >= 10 && x <= 150 && y >= 120 && y <= 225) {
					Signal.current_effect = 4;
					Signal.End_Flag = 1;
				}
				else if (x >= 0 && x <= 70 && y >= 0 && y <= 35) {
					Signal.back = 1;
					Signal.End_Flag = 1;
				}
			}
		}
	} else {
		// reset tạm thời cho trạng thái chạm
		if (Signal.page == 0) {
			Signal.nomal = 0;
			Signal.fft = 0;
		}
		Signal.back = 0;
		Signal.End_Flag = 0;
	}
}
