################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SevenSegment/seven_segment.c 

OBJS += \
./SevenSegment/seven_segment.o 

C_DEPS += \
./SevenSegment/seven_segment.d 


# Each subdirectory must supply rules for building sources it contributes
SevenSegment/seven_segment.o: ../SevenSegment/seven_segment.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded/Learn_in_Depth/Embedded_Online_Diploma_Assignments/Unit7/Unit7_section3/Drivers/SevenSegment/INC" -I"D:/Embedded/Learn_in_Depth/Embedded_Online_Diploma_Assignments/Unit7/Unit7_section3/Drivers/KeyPad_Driver/INC" -I"D:/Embedded/Learn_in_Depth/Embedded_Online_Diploma_Assignments/Unit7/Unit7_section3/Drivers/LCD_Driver/INC" -I"D:/Embedded/Learn_in_Depth/Embedded_Online_Diploma_Assignments/Unit7/Unit7_section3/Drivers/STM32F103C6_Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"SevenSegment/seven_segment.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

