################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/ACER/STM32CubeIDE/workspace_1.18.0/stm32-ws2812-master/src/color_values.c \
C:/Users/ACER/STM32CubeIDE/workspace_1.18.0/stm32-ws2812-master/src/ws2812.c \
C:/Users/ACER/STM32CubeIDE/workspace_1.18.0/stm32-ws2812-master/src/ws2812_demos.c 

OBJS += \
./src/color_values.o \
./src/ws2812.o \
./src/ws2812_demos.o 

C_DEPS += \
./src/color_values.d \
./src/ws2812.d \
./src/ws2812_demos.d 


# Each subdirectory must supply rules for building sources it contributes
src/color_values.o: C:/Users/ACER/STM32CubeIDE/workspace_1.18.0/stm32-ws2812-master/src/color_values.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -IC:/Users/ACER/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/ACER/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/ACER/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/ACER/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Include -I"C:/Users/ACER/STM32CubeIDE/workspace_1.18.0/stm32-ws2812-master/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/ws2812.o: C:/Users/ACER/STM32CubeIDE/workspace_1.18.0/stm32-ws2812-master/src/ws2812.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -IC:/Users/ACER/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/ACER/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/ACER/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/ACER/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Include -I"C:/Users/ACER/STM32CubeIDE/workspace_1.18.0/stm32-ws2812-master/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/ws2812_demos.o: C:/Users/ACER/STM32CubeIDE/workspace_1.18.0/stm32-ws2812-master/src/ws2812_demos.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -IC:/Users/ACER/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/ACER/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/ACER/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/ACER/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Include -I"C:/Users/ACER/STM32CubeIDE/workspace_1.18.0/stm32-ws2812-master/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/color_values.cyclo ./src/color_values.d ./src/color_values.o ./src/color_values.su ./src/ws2812.cyclo ./src/ws2812.d ./src/ws2812.o ./src/ws2812.su ./src/ws2812_demos.cyclo ./src/ws2812_demos.d ./src/ws2812_demos.o ./src/ws2812_demos.su

.PHONY: clean-src

