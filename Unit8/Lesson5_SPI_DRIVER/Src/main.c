#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "../STM32F103_Drivers/INC/stm32f103x6.h"
#include "../STM32F103_Drivers/INC/STM32F103C6_RCC_DRIVER.h"
#include "../STM32F103_Drivers/INC/STM32F103C6_GPIO_Driver.h"
#include "../STM32F103_Drivers/INC/STM32F103C6_USART_DRIVER.h"
#include "../STM32F103_Drivers/INC/STM32F103C6_SPI_DRIVER.h"


//#define SPI_MASTER_MODE
#define SPI_SLAVE_MODE


void clock_init(void)
{
	GPIOA_CLOCK_ENABLE() ;
	GPIOB_CLOCK_ENABLE() ;
	AFIO_CLOCK_ENABLE()  ;
}

uint16_t data ;

int main(void)
{
	clock_init();

	//***************************USART init*******************************//*

	USART_config config;
	config.USART_BAUD_RATE  = USART_BAUDRATE_115200;
	config.USART_HWFlowCtrl = USART_HW_FLOWCONTROL_NONE;
	config.USART_MODE 		= USART_MODE_TX_RX;
	config.USART_PARITY_BIT = USART_PARITY_NONE;
	config.USART_PAYLOAD 	= USART_PAYLOAD_8 ;
	config.USART_STOP_BIT   = USART_STOP_BIT_1;
	config.USART_IRQ		= USART_IRQ_ENABLE_NONE;

	//	config.P_IRQ_CallBack = UART_IRQ_CALLBACK;

	MCAL_USART_init(USART1,&config);
	MCAL_GPIO_USART_SetPins(USART1);

	//***************************SPI init*******************************//*
	SPI_config Sconf;

	Sconf.SPI_Communication = SPI_COMMUNICATION_2LINES;
	Sconf.SPI_Frame_Size = SPI_FRAME_SIZE_8;
	Sconf.SPI_Data_Order = SPI_DATA_ORDER_MSBFIRST;
	Sconf.SPI_Baud_Rate_Prescaler = SPI_BAUD_RATE_PRE_2;
	Sconf.SPI_Clock_Polarity = SPI_CLOCK_POLARITY_IDLE_LOW;
	Sconf.SPI_Clock_Phase = SPI_CLOCK_PHASE_CAPTURE_FIRST;
	Sconf.SPI_IRQ = SPI_IRQ_ENABLE_NONE;


#ifdef SPI_MASTER_MODE

	Sconf.SPI_MODE = SPI_MODE_MASTER;
	Sconf.SPI_NSS  = SPI_NSS_SOFTWARE_ENABLE_HIGH;
	Sconf.P_IRQ_CallBack  = NULL;

	GPIO_Pin_Config_t Pin_config ;

	Pin_config.GPIO_PinNumber = GPIO_PIN_4;
	Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_OUTPUT_PP;
	Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
	MCAL_GPIO_init(GPIOA , &Pin_config);

	//Make NSS for slave high (disable the slave select)
	MCAL_GPIO_WritePin(GPIOA , GPIO_PIN_4 , 1);

#endif
#ifdef SPI_SLAVE_MODE
	Sconf.SPI_MODE = SPI_MODE_SLAVE;
	Sconf.SPI_NSS  = SPI_NSS_HARDWARE_SLAVE_INPUT;
	Sconf.P_IRQ_CallBack  = NULL;

	MCAL_SPI_init(SPI1,&Sconf);
	MCAL_GPIO_SPI_SetPins(SPI1);

#endif

	MCAL_SPI_init(SPI1,&Sconf);
	MCAL_GPIO_SPI_SetPins(SPI1);



	while(1)
	{
#ifdef SPI_MASTER_MODE

		MCAL_USART_ReceiveData(USART1 , &data , enable);
		MCAL_USART_SendData(USART1 , &data , enable);

		MCAL_GPIO_WritePin(GPIOA , GPIO_PIN_4 , 0);

		MCAL_SPI_SendData(SPI1, &data , enable);
		MCAL_SPI_ReceiveData(SPI1, &data, enable);
		MCAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,1);

#endif
#ifdef SPI_SLAVE_MODE

		MCAL_SPI_ReceiveData(SPI1, &data, enable);
		MCAL_USART_SendData(USART1 , &data , enable);


#endif


	}

}
