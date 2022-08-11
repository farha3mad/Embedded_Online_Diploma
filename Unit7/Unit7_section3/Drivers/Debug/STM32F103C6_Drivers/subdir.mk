################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.c \
../STM32F103C6_Drivers/lcd.c 

OBJS += \
./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.o \
./STM32F103C6_Drivers/lcd.o 

C_DEPS += \
./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.d \
./STM32F103C6_Drivers/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.o: ../STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded/Learn_in_Depth/Embedded_Online_Diploma_Assignments/Unit7/Unit7_section3/Drivers/SevenSegment/INC" -I"D:/Embedded/Learn_in_Depth/Embedded_Online_Diploma_Assignments/Unit7/Unit7_section3/Drivers/KeyPad_Driver/INC" -I"D:/Embedded/Learn_in_Depth/Embedded_Online_Diploma_Assignments/Unit7/Unit7_section3/Drivers/LCD_Driver/INC" -I"D:/Embedded/Learn_in_Depth/Embedded_Online_Diploma_Assignments/Unit7/Unit7_section3/Drivers/STM32F103C6_Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/lcd.o: ../STM32F103C6_Drivers/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded/Learn_in_Depth/Embedded_Online_Diploma_Assignments/Unit7/Unit7_section3/Drivers/SevenSegment/INC" -I"D:/Embedded/Learn_in_Depth/Embedded_Online_Diploma_Assignments/Unit7/Unit7_section3/Drivers/KeyPad_Driver/INC" -I"D:/Embedded/Learn_in_Depth/Embedded_Online_Diploma_Assignments/Unit7/Unit7_section3/Drivers/LCD_Driver/INC" -I"D:/Embedded/Learn_in_Depth/Embedded_Online_Diploma_Assignments/Unit7/Unit7_section3/Drivers/STM32F103C6_Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

