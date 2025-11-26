/*
 * ili9341.h
 *
 *  Created on: 22 ���. 2018 �.
 *  Author: Andriy Honcharenko
 *  Version 1.1 date: 24.09.2019
 */

#ifndef ILI9341_H_
#define ILI9341_H_

#include "colors.h"
#include "registers.h"
#include "fonts.h"
#include "image.h"
#include <stdbool.h>

//#define LCD_BL_ON()  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET)
//#define LCD_BL_OFF() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET)
#include "stm32f4xx_hal.h"
extern const uint8_t Font8x8[];
void LCD_BL_ON(void);
void LCD_BL_OFF(void);
#define LCD_BASE0        		((uint32_t)0x60000000)
#define LCD_BASE1        		((uint32_t)0x60080000)

#define LCD_CmdWrite(command)	*(volatile uint16_t *) (LCD_BASE0) = (command)
#define LCD_DataWrite(data)		*(volatile uint16_t *) (LCD_BASE1) = (data)
#define	LCD_StatusRead()		*(volatile uint16_t *) (LCD_BASE0) //if use read  Mcu interface DB0~DB15 needs increase pull high
#define	LCD_DataRead()			*(volatile uint16_t *) (LCD_BASE1) //if use read  Mcu interface DB0~DB15 needs increase pull high

#define swap(a, b) { int16_t t = a; a = b; b = t; }

#define ILI9341_TFTWIDTH    240   // Chiều rộng màn hình ILI9341
#define ILI9341_TFTHEIGHT   320   // Chiều cao màn hình ILI9341

#define ILI9341_PIXEL_WIDTH		240
#define ILI9341_PIXEL_HEIGHT 	320
#define ILI9341_PIXEL_COUNT		ILI9341_PIXEL_WIDTH * ILI9341_PIXEL_HEIGHT


// Any LCD needs to implement these common methods, which allow the low-level
// initialisation and pixel-setting details to be abstracted away from the
// higher level drawing and graphics code.

typedef enum
{
	LCD_ORIENTATION_PORTRAIT 			= 0,
	LCD_ORIENTATION_LANDSCAPE 			= 1,
	LCD_ORIENTATION_PORTRAIT_MIRROR 	= 2,
	LCD_ORIENTATION_LANDSCAPE_MIRROR 	= 3
} lcdOrientationTypeDef;

/**
  * @brief  Draw Properties structures definition
  */


typedef struct
{
	uint32_t 	TextColor;
	uint32_t 	BackColor;
	sFONT*    	pFont;
	uint8_t		TextWrap;
}lcdFontPropTypeDef;

typedef struct
{
	unsigned short	x;
	unsigned short	y;
}lcdCursorPosTypeDef;

// This struct is used to indicate the capabilities of different LCDs
typedef struct
{
  uint16_t				width;         // LCD width in pixels (default orientation)
  uint16_t				height;        // LCD height in pixels (default orientation)
  lcdOrientationTypeDef	orientation;   // Whether the LCD orientation can be modified
  bool					touchscreen;   // Whether the LCD has a touch screen
  bool					hwscrolling;   // Whether the LCD support HW scrolling
} lcdPropertiesTypeDef;
extern lcdPropertiesTypeDef lcdProperties;


extern void lcdInit(void);
extern void lcdTest(void);
extern void	lcdFillRGB(uint16_t color);
extern void	lcdDrawPixel(uint16_t x, uint16_t y, uint16_t color);
extern void LCD_Printf(uint16_t x, uint16_t y, uint16_t color, uint16_t bgcolor, const char *str);
extern void lcdDrawHLine(uint16_t x0, uint16_t x1, uint16_t y, uint16_t color);
extern void lcdDrawVLine(uint16_t x, uint16_t y0, uint16_t y1, uint16_t color);
extern void lcdDrawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
extern void	lcdDrawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
extern void	lcdDrawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color);
extern void	lcdDrawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
extern void	lcdDrawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
extern void lcdDrawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
extern void	lcdFillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
extern void	lcdFillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);
extern void	lcdFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t fillcolor);
extern void	lcdFillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color);
extern void lcdFillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
extern void	lcdDrawImage(uint16_t x, uint16_t y, GUI_CONST_STORAGE GUI_BITMAP* pBitmap);
extern void lcdHome(void);
extern void lcdDrawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg);
extern void	lcdPrintf(const char *fmt, ...);
extern void	lcdSetTextFont(sFONT* font);
extern void	lcdSetTextColor(uint16_t c, uint16_t b);//thiết lập màu chữ (foreground) và màu nền (background)
extern void	lcdSetTextWrap(uint8_t w);// thiết lập chế độ xuống dòng tự động khi in văn bản trên màn hình.
extern void lcdSetOrientation(lcdOrientationTypeDef orientation);//thiết lập hướng hiển thị của màn hình ILI9341
extern void	lcdSetCursor(unsigned short x, unsigned short y);//đặt vị trí con trỏ hiện tại trên màn hình LCD tại tọa độ (x, y).
extern void lcdSetWindow(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1);
extern void	lcdBacklightOff(void);
extern void	lcdBacklightOn(void);
extern void	lcdInversionOff(void);
extern void	lcdInversionOn(void);
extern void	lcdDisplayOff(void);
extern void	lcdDisplayOn(void);
extern void	lcdTearingOff(void);
extern void	lcdTearingOn(bool m);
extern uint16_t lcdGetWidth(void);
extern uint16_t lcdGetHeight(void);
extern uint16_t lcdGetControllerID(void);
extern lcdOrientationTypeDef lcdGetOrientation(void);
extern sFONT*	lcdGetTextFont(void);
extern lcdPropertiesTypeDef lcdGetProperties(void);
extern uint16_t	lcdReadPixel(uint16_t x, uint16_t y);
extern uint16_t lcdColor565(uint8_t r, uint8_t g, uint8_t b);
void LCD_Print(uint16_t x, uint16_t y, char *str, uint16_t color, uint16_t bgcolor);

#endif /* ILI9341_H_ */
