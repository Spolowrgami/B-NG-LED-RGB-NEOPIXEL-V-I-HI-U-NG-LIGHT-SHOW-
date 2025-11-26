#include "WS2812.h"

uint8_t LED_Data[MAX_LED][4];
uint8_t LED_Mod[MAX_LED][4];
uint16_t pwmData[(24*MAX_LED)+50];


extern TIM_HandleTypeDef htim3;
extern int datasentflag;
extern int adc_average_value;

void Set_LED (int LEDnum, int Red, int Green, int Blue)
{
	LED_Data[LEDnum][0] = LEDnum;
	LED_Data[LEDnum][1] = Green;
	LED_Data[LEDnum][2] = Red;
	LED_Data[LEDnum][3] = Blue;
}

void Get_LED(int LEDnum, uint8_t *r, uint8_t *g, uint8_t *b)
{
	*r = LED_Data[LEDnum][2];
	*g = LED_Data[LEDnum][1];
	*b = LED_Data[LEDnum][3];
}

void Reset_All_LED()
{
	for (int i = 0 ; i < MAX_LED ; i++)
	{
		Set_LED(i, 0, 0, 0);
	}
	Set_Brightness(13);
	WS2812_Send();
}

void Set_Brightness (int brightness)
{
	if (brightness > 45) brightness = 45;
	for (int i=0; i<MAX_LED; i++)
	{
		LED_Mod[i][0] = LED_Data[i][0];
		for (int j=1; j<4; j++)
		{
			float angle = 90-brightness;
			angle = angle*PI / 180;
			LED_Mod[i][j] = (LED_Data[i][j])/(tan(angle));
		}
	}
}

void WS2812_Send (void)
{
	uint32_t indx=0;
	uint32_t color;
	for (int i= 0; i<MAX_LED; i++)
	{
		#if USE_BRIGHTNESS
			color = ((LED_Mod[i][1]<<16) | (LED_Mod[i][2]<<8) | (LED_Mod[i][3]));
		#else
			color = ((LED_Data[i][1]<<16) | (LED_Data[i][2]<<8) | (LED_Data[i][3]));
		#endif

		for (int i=23; i>=0; i--)
		{
			if (color&(1<<i))
			{
			pwmData[indx] = 60;
			}
			else pwmData[indx] = 30;
			indx++;
		}
	}
	for (int i=0; i<50; i++)
	{
		pwmData[indx] = 0;
		indx++;
	}
	HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t *)pwmData, indx);
	while (!datasentflag){};
	datasentflag = 0;
}

// Effect
void Effect_1(void)
{
	int Color_Step = 255 / MAX_LED;
	for (int i = 0 ; i < MAX_LED / 2 - 1 ; i++)
	{
	  Set_LED(i ,0, 255 - Color_Step * i , Color_Step * i);
	  Set_LED(MAX_LED - 1 - i, 0, 255 - Color_Step * (MAX_LED - 1 - i), Color_Step * (MAX_LED - 1 - i));
	  Set_Brightness(13);
	  WS2812_Send();
	  HAL_Delay(50);

	  Set_LED(i,0,0,0);
	  Set_LED(MAX_LED - 1 - i, 0, 0, 0);
	  Set_Brightness(13);
	  WS2812_Send();
	  HAL_Delay(50);
	}
}


