################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/stm/ili9381/DSP/Source/CommonTables/arm_common_tables.c \
C:/stm/ili9381/DSP/Source/CommonTables/arm_common_tables_f16.c \
C:/stm/ili9381/DSP/Source/CommonTables/arm_const_structs.c \
C:/stm/ili9381/DSP/Source/CommonTables/arm_const_structs_f16.c \
C:/stm/ili9381/DSP/Source/CommonTables/arm_mve_tables.c \
C:/stm/ili9381/DSP/Source/CommonTables/arm_mve_tables_f16.c 

OBJS += \
./DSP1/Source/CommonTables/arm_common_tables.o \
./DSP1/Source/CommonTables/arm_common_tables_f16.o \
./DSP1/Source/CommonTables/arm_const_structs.o \
./DSP1/Source/CommonTables/arm_const_structs_f16.o \
./DSP1/Source/CommonTables/arm_mve_tables.o \
./DSP1/Source/CommonTables/arm_mve_tables_f16.o 

C_DEPS += \
./DSP1/Source/CommonTables/arm_common_tables.d \
./DSP1/Source/CommonTables/arm_common_tables_f16.d \
./DSP1/Source/CommonTables/arm_const_structs.d \
./DSP1/Source/CommonTables/arm_const_structs_f16.d \
./DSP1/Source/CommonTables/arm_mve_tables.d \
./DSP1/Source/CommonTables/arm_mve_tables_f16.d 


# Each subdirectory must supply rules for building sources it contributes
DSP1/Source/CommonTables/arm_common_tables.o: C:/stm/ili9381/DSP/Source/CommonTables/arm_common_tables.c DSP1/Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/stm/ili9381/DSP/Include" -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Include -I"C:/stm/ili9381/DSP/Include/dsp" -I"C:/Users/Windows/STM32CubeIDE/workspace_1.18.1/Final/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DSP1/Source/CommonTables/arm_common_tables_f16.o: C:/stm/ili9381/DSP/Source/CommonTables/arm_common_tables_f16.c DSP1/Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/stm/ili9381/DSP/Include" -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Include -I"C:/stm/ili9381/DSP/Include/dsp" -I"C:/Users/Windows/STM32CubeIDE/workspace_1.18.1/Final/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DSP1/Source/CommonTables/arm_const_structs.o: C:/stm/ili9381/DSP/Source/CommonTables/arm_const_structs.c DSP1/Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/stm/ili9381/DSP/Include" -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Include -I"C:/stm/ili9381/DSP/Include/dsp" -I"C:/Users/Windows/STM32CubeIDE/workspace_1.18.1/Final/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DSP1/Source/CommonTables/arm_const_structs_f16.o: C:/stm/ili9381/DSP/Source/CommonTables/arm_const_structs_f16.c DSP1/Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/stm/ili9381/DSP/Include" -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Include -I"C:/stm/ili9381/DSP/Include/dsp" -I"C:/Users/Windows/STM32CubeIDE/workspace_1.18.1/Final/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DSP1/Source/CommonTables/arm_mve_tables.o: C:/stm/ili9381/DSP/Source/CommonTables/arm_mve_tables.c DSP1/Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/stm/ili9381/DSP/Include" -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Include -I"C:/stm/ili9381/DSP/Include/dsp" -I"C:/Users/Windows/STM32CubeIDE/workspace_1.18.1/Final/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DSP1/Source/CommonTables/arm_mve_tables_f16.o: C:/stm/ili9381/DSP/Source/CommonTables/arm_mve_tables_f16.c DSP1/Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/stm/ili9381/DSP/Include" -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Windows/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Include -I"C:/stm/ili9381/DSP/Include/dsp" -I"C:/Users/Windows/STM32CubeIDE/workspace_1.18.1/Final/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DSP1-2f-Source-2f-CommonTables

clean-DSP1-2f-Source-2f-CommonTables:
	-$(RM) ./DSP1/Source/CommonTables/arm_common_tables.cyclo ./DSP1/Source/CommonTables/arm_common_tables.d ./DSP1/Source/CommonTables/arm_common_tables.o ./DSP1/Source/CommonTables/arm_common_tables.su ./DSP1/Source/CommonTables/arm_common_tables_f16.cyclo ./DSP1/Source/CommonTables/arm_common_tables_f16.d ./DSP1/Source/CommonTables/arm_common_tables_f16.o ./DSP1/Source/CommonTables/arm_common_tables_f16.su ./DSP1/Source/CommonTables/arm_const_structs.cyclo ./DSP1/Source/CommonTables/arm_const_structs.d ./DSP1/Source/CommonTables/arm_const_structs.o ./DSP1/Source/CommonTables/arm_const_structs.su ./DSP1/Source/CommonTables/arm_const_structs_f16.cyclo ./DSP1/Source/CommonTables/arm_const_structs_f16.d ./DSP1/Source/CommonTables/arm_const_structs_f16.o ./DSP1/Source/CommonTables/arm_const_structs_f16.su ./DSP1/Source/CommonTables/arm_mve_tables.cyclo ./DSP1/Source/CommonTables/arm_mve_tables.d ./DSP1/Source/CommonTables/arm_mve_tables.o ./DSP1/Source/CommonTables/arm_mve_tables.su ./DSP1/Source/CommonTables/arm_mve_tables_f16.cyclo ./DSP1/Source/CommonTables/arm_mve_tables_f16.d ./DSP1/Source/CommonTables/arm_mve_tables_f16.o ./DSP1/Source/CommonTables/arm_mve_tables_f16.su

.PHONY: clean-DSP1-2f-Source-2f-CommonTables

