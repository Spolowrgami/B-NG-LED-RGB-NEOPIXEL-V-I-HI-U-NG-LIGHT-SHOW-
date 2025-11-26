/*
 * Setup_LCD_Status.h
 *
 *  Created on: May 20, 2025
 *      Author: Windows
 */
#ifndef SETUP_LCD_STATUS_H
#define SETUP_LCD_STATUS_H
#include "ili9341.h"
#include "main.h"

#define BUTTON_PRESSED_COLOR				COLOR_GREEN


//FFT
#define FFT_BUTTON_COLOR				COLOR_WHITE
void UpdateFFTButton(uint16_t color,uint16_t color2);
//NOMAL
#define NOMAL_BUTTON_COLOR				COLOR_WHITE
void UpdateNOMALButton(uint16_t color, uint16_t color2);
//EFFECT 1
#define EF1_BUTTON_COLOR				COLOR_WHITE
void UpdateEF1Button(uint16_t color1, uint16_t color2);
//EFFECT 2
#define EF2_BUTTON_COLOR				COLOR_WHITE
void UpdateEF2Button(uint16_t color1, uint16_t color2);
//EFFECT 3
#define EF3_BUTTON_COLOR				COLOR_WHITE
void UpdateEF3Button(uint16_t color1, uint16_t color2);
//EFFECT 4
#define EF4_BUTTON_COLOR				COLOR_WHITE
void UpdateEF4Button(uint16_t color1, uint16_t color2);
///


#define DOWN_BUTTON_X					30 //Vị trí nút "Down".
#define DOWN_BUTTON_Y					210 //Vị trí nút "Down".
#define DOWN_BUTTON_RADIUS				18
#define DOWN_BUTTON_COLOR				COLOR_WHITE  //Màu của nút "Down" khi bình thường
#define DOWN_BUTTON_PRESSED_COLOR		COLOR_GREENYELLOW //Màu của nút "Down" khi  khi nhấn.
void tetrisDrawStatus();
void tetrisDrawDownButton(uint16_t x, uint16_t y, uint16_t color);//Vẽ nút "Down".
void tetrisUpdateDownButton(uint16_t color);//Cập nhật màu của nút "Down".
unsigned long testDrawImage();
unsigned long testDrawImage2();
unsigned long testDrawImage1();
void giao_dien_batdau();
void giao_dien_1();
void giao_dien_2();

void LCD_DrawRoundIcon(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t radius,
                       const char *text, uint16_t frameColor, uint16_t textColor, uint16_t bgColor);


#endif
