/*
 * FFT.c
 *
 *  Created on: May 19, 2025
 *      Author: ACER
 */

#include "FFT.h"
#include "lcd_effect.h"

float fft_input[FFT_SIZE];
float fft_output[FFT_SIZE];
float fft_output_average = 0.0f;
float bass = 0, mid = 0, treble = 0;

uint32_t delayrate;
int brightness;

extern uint16_t adc_buffer[1024];
extern UART_HandleTypeDef huart1;
extern BackGroundTouchSignal Signal;

arm_rfft_fast_instance_f32 S;

void Calculate_FFT(void)
{
	for (int i = 0 ; i < FFT_SIZE ; i++)
	{
		fft_input[i] = (float)adc_buffer[i];
	}

	arm_rfft_fast_f32(&S, fft_input, fft_output, 0);
	for (int i = 0; i < FFT_SIZE / 2; i++)
	{
		float real = fft_output[2*i];
		float imag = fft_output[2*i + 1];
		fft_output[i] = sqrtf(real * real + imag * imag);
		fft_output_average += fft_output[i];
	}
	fft_output_average /= (FFT_SIZE / 2 - 1);
}

void Analyze_Frequency_Bands(float* bass, float* mid, float* treble)
{
	*bass = *mid = *treble = 0;

	float bin_freq = SAMPLING_FREQ / FFT_SIZE;
	float total_energy = 0.0f;

	for (int i = 0; i < FFT_SIZE / 2; i++)
	{
		float freq_output = i * bin_freq;
		float magnitude = fft_output[i];
		float norm_mag = log10f(magnitude + 1.0f);

		if (freq_output <= BASS_FREQ_MAX)
			*bass += norm_mag;
		else if (freq_output <= MID_FREQ_MAX)
			*mid += norm_mag;
		else if (freq_output <= TREBLE_FREQ_MAX)
			*treble += norm_mag;
		else
			break;
	}

	total_energy = *bass + *mid + *treble;
	if (total_energy > 0)
	{
		*bass /= total_energy;
		*mid  /= total_energy;
		*treble /= total_energy;
	}
}

void FFT_SETUP(void)
{
	arm_rfft_fast_init_f32(&S, FFT_SIZE);

	Calculate_FFT();
	Analyze_Frequency_Bands(&bass, &mid, &treble);
}

void Print_FFT(void)
{
	char buffer[100];

	snprintf(buffer, sizeof(buffer), "FFT_OUTPUT Average: %f\r\n", fft_output_average);

//	snprintf(buffer, sizeof(buffer), "FFT_OUTPUT Average: %f\r\nBass: %f\r\nMid: %f\r\nTreble: %f\r\n", fft_output_average, bass, mid, treble);

//	snprintf(buffer, sizeof(buffer), "FFT_OUTPUT Average: %f\r\nSpeedrate: %ld\r\n", fft_output_average, delayrate);

//	snprintf(buffer, sizeof(buffer), "FFT_OUTPUT Average: %f\r\nBrightness: %d\r\n", fft_output_average, brightness);

//	HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
	HAL_Delay(500);

//	for (int i = 0; i < FFT_SIZE / 2; i++)
//	{
//		// Chuyển float thành chuỗi, ví dụ 2 số thập phân
//		int len = snprintf(buffer, sizeof(buffer), "\nFFT[%d] = %.2f\r\n", i, fft_output[i]);
//
//		// Gửi chuỗi qua UART
//		HAL_UART_Transmit(&huart1, (uint8_t*)buffer, len, 100);
//		HAL_Delay(50);
//	}
}

// dùng light_bar để thay thế hiệu ứng
void Light_Bar(void)
{
	Reset_All_LED();

	float intensity = fft_output_average - SOUND_BASE;
	if (intensity > SOUND_MAX) intensity = SOUND_MAX;
	if (intensity < 0.0f) intensity = 0.0f;

	uint16_t led_on_count = (uint16_t)((intensity / SOUND_MAX) * MAX_LED);
	if (led_on_count > MAX_LED) led_on_count = MAX_LED;

	int Color_Steps = fmax(255 / MAX_LED, 1);
	for (int i = 0 ; i < led_on_count ; i++)
	{
		readtouch();
		if (Signal.End_Flag) {
			Reset_All_LED();
			Signal.End_Flag = 0;
			return;
		}

		Set_LED(i, Color_Steps * i, 0, 255);
//		Set_Brightness(13);
//		WS2812_Send();
	}
	Set_Brightness(13);
	WS2812_Send();
	HAL_Delay(20);
}

// màu sắc không đổi nhiều
void Waves(void)
{
    uint8_t red = (uint8_t)(powf(bass, 0.3) * 255);
    uint8_t green = (uint8_t)(powf(mid, 0.3) * 255);
    uint8_t blue = (uint8_t)(powf(treble, 0.3) * 255);

    if (fft_output_average > 1000.0f)
    {
    	for (int i = 0 ; i < MAX_LED ; i++)
    	{
    		Set_LED(i, red, green, blue);
    	}
    }
    Set_Brightness(13);
    WS2812_Send();
    HAL_Delay(20);
}

void Alternating_Flash(uint32_t MIN_DELAY, uint32_t MAX_DELAY)
{
    Reset_All_LED();

    // Giới hạn đầu vào
    if (fft_output_average < SOUND_BASE) fft_output_average = SOUND_BASE;
    if (fft_output_average > SOUND_MAX) fft_output_average = SOUND_MAX;

    // Bình thường: norm từ 0.0 đến 1.0
    float norm = (fft_output_average - SOUND_BASE) / (SOUND_MAX - SOUND_BASE);
    if (norm < 0.0f) norm = 0.0f;
    if (norm > 1.0f) norm = 1.0f;

    // 💡 Tăng độ phản ứng bằng bình phương (cho tăng tốc mạnh hơn)
    delayrate = (uint32_t)(MAX_DELAY - (norm * norm * (MAX_DELAY - MIN_DELAY)));

    // 💡 Giảm delay min/max để tăng tốc tổng thể
    if (delayrate < 10) delayrate = 10;   // tránh delay quá nhỏ gây lỗi
    if (delayrate > MAX_DELAY) delayrate = MAX_DELAY;

    // LED chẵn: màu tím hồng
    for (int i = 0 ; i < MAX_LED; i += 2)
    {
        Set_LED(i, 255, 0, 150);
    }
    Set_Brightness(13);
    WS2812_Send();
    HAL_Delay(delayrate);

    Reset_All_LED();

    // LED lẻ: màu xanh dương nhạt
    for (int i = 1 ; i < MAX_LED ; i += 2)
    {
        Set_LED(i, 0, 150, 255);
    }
    Set_Brightness(13);
    WS2812_Send();
    HAL_Delay(delayrate);

    Reset_All_LED();
}


void EchoSplit()
{
	Reset_All_LED();

	if (fft_output_average < SOUND_BASE) fft_output_average = SOUND_BASE;
	if (fft_output_average > SOUND_MAX) fft_output_average = SOUND_MAX;

	const int blockSize = 5;

	// ===== Giai đoạn 1: TỪ NGOÀI VÀO GIỮA =====
	for (int i = 0; i <= (MAX_LED / 2) - blockSize; i++)
	{
		Reset_All_LED();
		readtouch();
		if (Signal.End_Flag) {
			Reset_All_LED();
			Signal.End_Flag = 0;
			return;
		}

		FFT_SETUP();
		if (fft_output_average < SOUND_BASE) fft_output_average = SOUND_BASE;
		if (fft_output_average > SOUND_MAX) fft_output_average = SOUND_MAX;


		// Trái -> vào giữa
		for (int j = 0; j < blockSize; j++)
		{
			int idx = i + j;
			if (fft_output_average < 2000.0f)
				Set_LED(idx, 8, 247, 254);
			else if (fft_output_average >2000.0f && fft_output_average < 2800.0f)
				Set_LED(idx, 9, 251, 211);
			else
				Set_LED(idx, 254, 83, 187);
		}

		// Phải -> vào giữa
		for (int j = 0; j < blockSize; j++)
		{
			int idx = MAX_LED - 1 - i - j;
			if (fft_output_average < 2000.0f)
				Set_LED(idx, 8, 247, 254);
			else if (fft_output_average >2000.0f && fft_output_average < 2800.0f)
				Set_LED(idx, 9, 251, 211);
			else
				Set_LED(idx, 254, 83, 187);
		}

		Set_Brightness(45);
		WS2812_Send();
	}

	// ===== Giai đoạn 2: TỪ GIỮA RA NGOÀI =====
	for (int i = 0; i <= (MAX_LED / 2) - blockSize; i++)
	{
//		Reset_All_LED();
		readtouch();
		if (Signal.End_Flag) {
			Reset_All_LED();
			Signal.End_Flag = 0;
			return;
		}

		FFT_SETUP();
		if (fft_output_average < SOUND_BASE) fft_output_average = SOUND_BASE;
		if (fft_output_average > SOUND_MAX) fft_output_average = SOUND_MAX;

		// Từ giữa ra trái
		for (int j = 0; j < blockSize; j++)
		{
			int idx = (MAX_LED / 2 - 1) - i - j;
			if (idx >= 0) {
				if (fft_output_average < 2000.0f)
					Set_LED(idx, 8, 247, 254);
				else if (fft_output_average >2000.0f && fft_output_average < 2800.0f)
					Set_LED(idx, 9, 251, 211);
				else
					Set_LED(idx, 254, 83, 187);
			}
		}

		// Từ giữa ra phải
		for (int j = 0; j < blockSize; j++)
		{
			int idx = (MAX_LED / 2) + i + j;
			if (idx < MAX_LED) {
				if (fft_output_average < 2000.0f)
					Set_LED(idx, 8, 247, 254);
				else if (fft_output_average >2000.0f && fft_output_average < 2800.0f)
					Set_LED(idx, 9, 251, 211);
				else
					Set_LED(idx, 254, 83, 187);
			}
		}
		Set_Brightness(45);
		WS2812_Send();
	}
}

void Sparkle(void)
{
	Reset_All_LED();

	float normalized = (fft_output_average - SOUND_BASE) / (SOUND_MAX - SOUND_BASE);
	if (normalized > 1.0f) normalized = 1.0f;
	if (normalized < 0.0f) normalized = 0.0f;

	brightness = (uint8_t)(normalized * 45.0f);

	for (int i = 0 ; i < MAX_LED ; i++)
	{
		uint8_t R = rand() % 256;
		uint8_t G = rand() % 256;
		uint8_t B = rand() % 256;

		Set_LED(i, R, G, B);
	}
	Set_Brightness(brightness);
	WS2812_Send();
	HAL_Delay(50);
}


