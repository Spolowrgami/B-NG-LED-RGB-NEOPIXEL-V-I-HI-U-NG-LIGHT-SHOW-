/*
 * Setup_LCD_Status.c
 *
 *  Created on: May 20, 2025
 *      Author: Windows
 */
#include "Setup_LCD_Status.h"
#include "stdio.h"
#include <string.h>

uint16_t boardColor;
uint16_t downButtonColor;
uint16_t normalcolor;
uint16_t fftcolor;
uint16_t ef1color;
uint16_t ef2color;
uint16_t ef3color;
uint16_t ef4color;

uint16_t startButtonColor;
void tetrisDrawStatus()
{
	boardColor = COLOR_DARKGREY;
	downButtonColor = DOWN_BUTTON_COLOR;
//	startButtonColor = START_BUTTON_COLOR;
	tetrisDrawDownButton(DOWN_BUTTON_X, DOWN_BUTTON_Y, downButtonColor);

}
void tetrisDrawDownButton(uint16_t x, uint16_t y, uint16_t color)
{

	lcdDrawCircle(x,y,DOWN_BUTTON_RADIUS-3,color);
	lcdDrawCircle(x,y,DOWN_BUTTON_RADIUS,color);
	lcdDrawTriangle(x+5,y-10,x+5,y+10,x-5,y,color);

}
void tetrisUpdateDownButton(uint16_t color)
{
	if(downButtonColor != color)
	{
		downButtonColor = color;
		tetrisDrawDownButton(DOWN_BUTTON_X,DOWN_BUTTON_Y,downButtonColor);
	}
}
void UpdateFFTButton(uint16_t color, uint16_t color2)
{
	if(fftcolor != color)
		{
		fftcolor = color;
			LCD_DrawRoundIcon(100, 100, 120, 40, 10, "O_N F_F_T",fftcolor,color2, COLOR_WHITE);
		}
}
//void UpdateNOMALButton(uint16_t color, uint16_t color2){
//	if(normalcolor != color)
//		{
//			normalcolor = color;
//			LCD_DrawRoundIcon(90, 120, 120, 40, 10, "N-O-R-M-A-L", normalcolor , color2 , COLOR_WHITE);
//		}
//}

void UpdateEF1Button(uint16_t color1 , uint16_t color2){
	if(ef1color != color1){
		ef1color = color1;
		LCD_DrawRoundIcon(30, 50, 120, 40, 10, "Light_Bar",ef1color, color2, COLOR_WHITE);
	}
}
void UpdateEF2Button(uint16_t color1 , uint16_t color2){
	if(ef2color != color1){
		ef2color = color1;
		LCD_DrawRoundIcon(180,50, 120, 40, 10, "Sparkle", ef2color, color2, COLOR_WHITE);
	}
}
void UpdateEF3Button(uint16_t color1 , uint16_t color2){
	if(ef3color != color1){
		ef3color = color1;
		LCD_DrawRoundIcon(30, 120, 120, 40, 10, "Flash",ef3color, color2, COLOR_WHITE);
	}
}
void UpdateEF4Button(uint16_t color1 , uint16_t color2){
	if(ef4color != color1){
		ef4color = color1;
		LCD_DrawRoundIcon(180, 120, 120, 40, 10, "EchoSplit",ef4color, color2 ,COLOR_WHITE);
	}
}





void giao_dien_batdau(){
		lcdSetTextFont(&Font16);
		lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
		lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
		testDrawImage();
}
void giao_dien_1(){
	 	lcdSetTextFont(&Font16);
	 	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
		lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
		testDrawImage1();
}
void giao_dien_2(){
 	lcdSetTextFont(&Font16);
 	lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	testDrawImage2();
}
unsigned long testDrawImage()
{
	unsigned long start;

	lcdFillRGB(COLOR_BLACK);
	start = HAL_GetTick();
	if (lcdGetOrientation() == LCD_ORIENTATION_LANDSCAPE || lcdGetOrientation() == LCD_ORIENTATION_LANDSCAPE_MIRROR)
	{
		lcdDrawImage((lcdGetWidth() - bmSTLogo.xSize) / 2, 0, &bmSTLogo);
	}
	else
	{
		lcdDrawImage(0, (lcdGetHeight() - bmSTLogo.ySize) / 2, &bmSTLogo);
	}

	//in cac icon
	 LCD_DrawRoundIcon(100, 100, 120, 40, 10, "O_N F_F_T", COLOR_BLUE, COLOR_BLACK , COLOR_WHITE);
	 //LCD_DrawRoundIcon(90, 120, 120, 40, 10, "N-O-R-M-A-L", COLOR_BLUE, COLOR_BLACK, COLOR_WHITE);
//	lcdDrawImage(20, 20, &bmSTIcon1 );

	return HAL_GetTick() - start;

}
void LCD_DrawRoundIcon(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t radius,
                       const char *text, uint16_t frameColor, uint16_t textColor, uint16_t bgColor)
{
    // 1. Vẽ nền bo góc tròn
    lcdFillRoundRect(x, y, width, height, radius, bgColor);
	// Vẽ khung bo góc tròn
	    lcdDrawRoundRect(x, y, width, height, radius, frameColor);

	    // Tính toán vị trí chữ để căn giữa
	    uint16_t textX = x + (width / 2) - (strlen(text) * 4);  // Mỗi ký tự rộng ~8px
	    uint16_t textY = y + (height / 2) - 8;                  // Mỗi ký tự cao ~16px

	    // In chữ vào giữa khung mà không có nền
	    LCD_Print(textX, textY, (char *)text, textColor, textColor);
}
unsigned long testDrawImage2()
{
	unsigned long start;

	lcdFillRGB(COLOR_BLACK);
	start = HAL_GetTick();
	if (lcdGetOrientation() == LCD_ORIENTATION_LANDSCAPE || lcdGetOrientation() == LCD_ORIENTATION_LANDSCAPE_MIRROR)
	{
		lcdDrawImage((lcdGetWidth() - bmSTLogo2.xSize) / 2, 0, &bmSTLogo2);
	}
	else
	{
		lcdDrawImage(0, (lcdGetHeight() - bmSTLogo2.ySize) / 2, &bmSTLogo2);
	}


	 LCD_DrawRoundIcon(30, 50, 120, 40, 10, "EFFECT 1", COLOR_BLUE, COLOR_ORANGE, COLOR_WHITE);
	 LCD_DrawRoundIcon(180,50, 120, 40, 10, "EFFECT 2", COLOR_BLUE, COLOR_ORANGE,COLOR_WHITE);
	 LCD_DrawRoundIcon(30, 120, 120, 40, 10, "EFFECT 3", COLOR_BLUE, COLOR_ORANGE,COLOR_WHITE);
	 LCD_DrawRoundIcon(180, 120, 120, 40, 10, "EFFECT 4", COLOR_BLUE, COLOR_ORANGE,COLOR_WHITE);

	 tetrisDrawDownButton(30, 210, COLOR_WHITE);



	return HAL_GetTick() - start;
}

unsigned long testDrawImage1()
{
	unsigned long start;

	lcdFillRGB(COLOR_BLACK);
	start = HAL_GetTick();
	if (lcdGetOrientation() == LCD_ORIENTATION_LANDSCAPE || lcdGetOrientation() == LCD_ORIENTATION_LANDSCAPE_MIRROR)
	{
		lcdDrawImage((lcdGetWidth() - bmSTLogo2.xSize) / 2, 0, &bmSTLogo2);
	}
	else
	{
		lcdDrawImage(0, (lcdGetHeight() - bmSTLogo2.ySize) / 2, &bmSTLogo2);
	}


	 LCD_DrawRoundIcon(30, 50, 120, 40, 10, "Light_Bar", COLOR_BLUE, COLOR_BLACK, COLOR_WHITE);
	 LCD_DrawRoundIcon(180,50, 120, 40, 10, "Sparkle", COLOR_BLUE, COLOR_BLACK, COLOR_WHITE);
	 LCD_DrawRoundIcon(30, 120, 120, 40, 10, "Flash", COLOR_BLUE, COLOR_BLACK, COLOR_WHITE);
	 LCD_DrawRoundIcon(180, 120, 120, 40, 10, "EchoSplit", COLOR_BLUE, COLOR_BLACK, COLOR_WHITE);

	 tetrisDrawDownButton(30, 210, COLOR_WHITE);



	return HAL_GetTick() - start;
}

