################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/FFT.c \
../Core/Src/LCD_Touch.c \
../Core/Src/STLogo.c \
../Core/Src/STLogo2.c \
../Core/Src/Setup_LCD_Status.c \
../Core/Src/WS2812.c \
../Core/Src/background.c \
../Core/Src/calibrate.c \
../Core/Src/font12.c \
../Core/Src/font16.c \
../Core/Src/font20.c \
../Core/Src/font24.c \
../Core/Src/font8.c \
../Core/Src/fonts.c \
../Core/Src/icon.c \
../Core/Src/ili9341.c \
../Core/Src/lcd_effect.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/FFT.o \
./Core/Src/LCD_Touch.o \
./Core/Src/STLogo.o \
./Core/Src/STLogo2.o \
./Core/Src/Setup_LCD_Status.o \
./Core/Src/WS2812.o \
./Core/Src/background.o \
./Core/Src/calibrate.o \
./Core/Src/font12.o \
./Core/Src/font16.o \
./Core/Src/font20.o \
./Core/Src/font24.o \
./Core/Src/font8.o \
./Core/Src/fonts.o \
./Core/Src/icon.o \
./Core/Src/ili9341.o \
./Core/Src/lcd_effect.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/FFT.d \
./Core/Src/LCD_Touch.d \
./Core/Src/STLogo.d \
./Core/Src/STLogo2.d \
./Core/Src/Setup_LCD_Status.d \
./Core/Src/WS2812.d \
./Core/Src/background.d \
./Core/Src/calibrate.d \
./Core/Src/font12.d \
./Core/Src/font16.d \
./Core/Src/font20.d \
./Core/Src/font24.d \
./Core/Src/font8.d \
./Core/Src/fonts.d \
./Core/Src/icon.d \
./Core/Src/ili9341.d \
./Core/Src/lcd_effect.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/stm/ili9381/DSP/Include" -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Include -I"C:/stm/ili9381/DSP/Include/dsp" -I"C:/Users/Windows/STM32CubeIDE/workspace_1.18.1/Final/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/FFT.cyclo ./Core/Src/FFT.d ./Core/Src/FFT.o ./Core/Src/FFT.su ./Core/Src/LCD_Touch.cyclo ./Core/Src/LCD_Touch.d ./Core/Src/LCD_Touch.o ./Core/Src/LCD_Touch.su ./Core/Src/STLogo.cyclo ./Core/Src/STLogo.d ./Core/Src/STLogo.o ./Core/Src/STLogo.su ./Core/Src/STLogo2.cyclo ./Core/Src/STLogo2.d ./Core/Src/STLogo2.o ./Core/Src/STLogo2.su ./Core/Src/Setup_LCD_Status.cyclo ./Core/Src/Setup_LCD_Status.d ./Core/Src/Setup_LCD_Status.o ./Core/Src/Setup_LCD_Status.su ./Core/Src/WS2812.cyclo ./Core/Src/WS2812.d ./Core/Src/WS2812.o ./Core/Src/WS2812.su ./Core/Src/background.cyclo ./Core/Src/background.d ./Core/Src/background.o ./Core/Src/background.su ./Core/Src/calibrate.cyclo ./Core/Src/calibrate.d ./Core/Src/calibrate.o ./Core/Src/calibrate.su ./Core/Src/font12.cyclo ./Core/Src/font12.d ./Core/Src/font12.o ./Core/Src/font12.su ./Core/Src/font16.cyclo ./Core/Src/font16.d ./Core/Src/font16.o ./Core/Src/font16.su ./Core/Src/font20.cyclo ./Core/Src/font20.d ./Core/Src/font20.o ./Core/Src/font20.su ./Core/Src/font24.cyclo ./Core/Src/font24.d ./Core/Src/font24.o ./Core/Src/font24.su ./Core/Src/font8.cyclo ./Core/Src/font8.d ./Core/Src/font8.o ./Core/Src/font8.su ./Core/Src/fonts.cyclo ./Core/Src/fonts.d ./Core/Src/fonts.o ./Core/Src/fonts.su ./Core/Src/icon.cyclo ./Core/Src/icon.d ./Core/Src/icon.o ./Core/Src/icon.su ./Core/Src/ili9341.cyclo ./Core/Src/ili9341.d ./Core/Src/ili9341.o ./Core/Src/ili9341.su ./Core/Src/lcd_effect.cyclo ./Core/Src/lcd_effect.d ./Core/Src/lcd_effect.o ./Core/Src/lcd_effect.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

