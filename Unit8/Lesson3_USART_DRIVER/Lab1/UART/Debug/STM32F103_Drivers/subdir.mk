################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103_Drivers/STM32F103C6_GPIO_Driver.c \
../STM32F103_Drivers/STM32F103C6_RCC_DRIVER.c \
../STM32F103_Drivers/STM32F103C6_USART_DRIVER.c 

OBJS += \
./STM32F103_Drivers/STM32F103C6_GPIO_Driver.o \
./STM32F103_Drivers/STM32F103C6_RCC_DRIVER.o \
./STM32F103_Drivers/STM32F103C6_USART_DRIVER.o 

C_DEPS += \
./STM32F103_Drivers/STM32F103C6_GPIO_Driver.d \
./STM32F103_Drivers/STM32F103C6_RCC_DRIVER.d \
./STM32F103_Drivers/STM32F103C6_USART_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103_Drivers/STM32F103C6_GPIO_Driver.o: ../STM32F103_Drivers/STM32F103C6_GPIO_Driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103_Drivers/STM32F103C6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103_Drivers/STM32F103C6_RCC_DRIVER.o: ../STM32F103_Drivers/STM32F103C6_RCC_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103_Drivers/STM32F103C6_RCC_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103_Drivers/STM32F103C6_USART_DRIVER.o: ../STM32F103_Drivers/STM32F103C6_USART_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103_Drivers/STM32F103C6_USART_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

