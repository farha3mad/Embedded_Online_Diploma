/*****************************************************************/
/* Author      : Farha Emad                                      */
/* Date        : 23 April 2023                                   */      
/*****************************************************************/

#include "INC/STM32F103C6_USART_DRIVER.h"


/**************** General Variables *******************/

USART_config * Global_USART1_conf = NULL;
USART_config * Global_USART2_conf = NULL;
USART_config * Global_USART3_conf = NULL;


/*********************** APIs *************************/

/**================================================================
 * @Fn			- MCAL_USART_init
 * @brief 		- initialize the USARTx according to the specific parameters
 * @param [in]	- USARTx: where x can be (1 .. 3 depending on the device used) to select the USART peripheral
 * @param [in] 	- USART_conf: pointer to USART_config structure which contains the configuration information
 * @retval 		- None
 * Note			-
 **================================================================*/

void MCAL_USART_init(USART_TypeDef *USARTx , USART_config *USART_conf)
{
	uint32_t Fclk,BRR;



	//Enable clock for the USART peripheral
	if(USARTx == USART1)
	{
		Global_USART1_conf = USART_conf;
		USART1_CLOCK_ENABLE();
	}
	else if(USARTx == USART2)
	{
		Global_USART2_conf = USART_conf;
		USART2_CLOCK_ENABLE();
	}
	else if(USARTx == USART3)
	{
		Global_USART3_conf = USART_conf;
		USART3_CLOCK_ENABLE();
	}

	//Enable USART peripheral
	USARTx->CR1 |= (1<<13);		//Bit 13 UE: USART enable

	//setting the configuration
	USARTx->CR1 |= USART_conf->USART_MODE;

	USARTx->CR1 |= USART_conf->USART_PAYLOAD;

	USARTx->CR1 |= USART_conf->USART_IRQ;

	USARTx->CR2 |= USART_conf->USART_STOP_BIT;

	USARTx->CR1 |= USART_conf->USART_PARITY_BIT;

	USARTx->CR3 |= USART_conf->USART_HWFlowCtrl;

	//Baud Rate
	//USART1        --> APB2 --> PCLK2
	//USART2,USART3 --> APB1 --> PCLK1

	if(USARTx == USART1)
	{
		Fclk = MCAL_RCC_GetPCLK2_Freq();
	}
	else
	{
		Fclk = MCAL_RCC_GetPCLK1_Freq();
	}

	BRR = USART_BRR_VALUE(Fclk , USART_conf->USART_BAUD_RATE);
	USARTx->BRR = BRR;

	//NVIC enable
	//***********Uncompleted***************//
}


/**================================================================
 * @Fn			- MCAL_USART_deinit
 * @brief 		- Deinitialize the USARTx
 * @param [in]	- USARTx: where x can be (1 .. 3 depending on the device used) to select the USART peripheral
 * @retval 		- None
 * Note			- Reset the module by RCC
 **================================================================*/

void MCAL_USART_deinit(USART_TypeDef *USARTx)
{

	//Disable NVIC and RCC
	if(USARTx == USART1)
	{
		USART1_CLOCK_DISABLE();
		//***NVIC***//
	}
	else if(USARTx == USART2)
	{
		USART2_CLOCK_DISABLE();
		//***NVIC***//
	}
	else if(USARTx == USART3)
	{
		USART3_CLOCK_DISABLE();
		//***NVIC***//
	}

}


/**================================================================
 * @Fn			- MCAL_USART_SendData
 * @brief 		- Transmit data by the USARTx according to the specific parameters
 * @param [in]	- USARTx: where x can be (1 .. 3 depending on the device used) to select the USART peripheral
 * @param [in] 	- data: 8-bit or 9-bit data to be transmitted
 * @param [in] 	- poll: Enable/disable polling mechanism
 * @retval 		- None
 * Note			- Should initialize USART first
 * 				  When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
 *				  the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
 *				  because it is replaced by the parity
 **================================================================*/
void MCAL_USART_SendData(USART_TypeDef *USARTx , uint16_t *data_buffer , enum polling poll){

	if(poll == enable)
	{
		//Status register (USART_SR)
		//Bit 7 TXE: Transmit data register empty
		//This bit is set by hardware when the content of the TDR register has been transferred into
		//the shift register. An interrupt is generated if the TXEIE bit =1 in the USART_CR1 register. It
		//is cleared by a write to the USART_DR register.

		while(((USARTx->SR) & 1<<7) != 1);	//wait until Data is transferred to the shift register
	}
	if(USARTx == USART1){
		if(Global_USART1_conf->USART_PAYLOAD == USART_PAYLOAD_8)
		{
			USARTx->DR = (*data_buffer & (uint16_t)0xFF);
		}
		else if(Global_USART1_conf->USART_PAYLOAD == USART_PAYLOAD_9)
		{
			USARTx->DR = (*data_buffer & (uint16_t)0x1FF);
		}

	}
	else if(USARTx == USART2){
		if(Global_USART2_conf->USART_PAYLOAD == USART_PAYLOAD_8)
		{
			USARTx->DR = (*data_buffer & (uint16_t)0xFF);
		}
		else if(Global_USART2_conf->USART_PAYLOAD == USART_PAYLOAD_9)
		{
			USARTx->DR = (*data_buffer & (uint16_t)0x1FF);
		}

	}
	else if(USARTx == USART3){
		if(Global_USART3_conf->USART_PAYLOAD == USART_PAYLOAD_8)
		{
			USARTx->DR = (*data_buffer & (uint16_t)0xFF);
		}
		else if(Global_USART3_conf->USART_PAYLOAD == USART_PAYLOAD_9)
		{
			USARTx->DR = (*data_buffer & (uint16_t)0x1FF);
		}

	}


}


/**================================================================
 * @Fn			- MCAL_USART_Wait_TC
 * @brief 		- Wait until Transmitting data by the USARTx is completed
 * @param [in]	- USARTx: where x can be (1 .. 3 depending on the device used) to select the USART peripheral
 * @retval 		- None
 * Note			-
 **================================================================*/
void MCAL_USART_Wait_TC(USART_TypeDef *USARTx){
	//Bit 6 TC: Transmission complete
	while(((USARTx->SR >> 6) & 1 )!= 1);
}


/**================================================================
 * @Fn			- MCAL_USART_ReceiveData
 * @brief 		- Receive data by the USARTx
 * @param [in]	- USARTx: where x can be (1 .. 3 depending on the device used) to select the USART peripheral
 * @param [in] 	- data: 8-bit or 9-bit data to be transmitted
 * @param [in] 	- poll: Enable/disable polling mechanism
 * @retval 		- NONE
 * Note			-
 **================================================================*/

void MCAL_USART_ReceiveData(USART_TypeDef *USARTx , uint16_t *data_buffer , enum polling poll)
{
	if(poll==enable)
	{
		//Bit 5 RXNE: Read data register not empty
		while((USARTx->SR  & 1<<5) != 1);
	}


	//check if parity bit is included
	//Bit 10 PCE: Parity control enable
	if((((USARTx->CR1)>>10 ) & 1) == 0)
	{
		//parity bit is NOT included
		//check the pay-load size
		//Bit 12 M: Word length

		if((((USARTx->CR1)>>10 ) & 1) == 0)
		{
			//all 8 bits is sent
			*data_buffer = (USARTx->DR & 0xFF);
		}
		else if((((USARTx->CR1)>>10 ) & 1) == 1)
		{
			//all 9 bits is sent
			*data_buffer = (USARTx->DR & 0x1FF);
		}

	}
	else
	{
		//parity bit is included
		if((((USARTx->CR1)>>10 ) & 1) == 0)
		{
			//sending 7 bits for data an 1 bit for parity
			*data_buffer = (USARTx->DR & 0x7F);
		}
		else if((((USARTx->CR1)>>10 ) & 1) == 1)
		{
			//sending 8 bits for data an 1 bit for parity
			*data_buffer = (USARTx->DR & 0xFF);
		}
	}



}

/**================================================================
 * @Fn			- MCAL_GPIO_USART_SetPins
 * @brief 		- Initialize GPIO pins
 * @param [in]	- USARTx: where x can be (1 .. 3 depending on the device used) to select the USART peripheral
 * @retval 		- NONE
 * Note			- Should enable RCC clock for the corresponding ALT and GPIO called after MCAL_USART_init()
 **================================================================*/

void MCAL_GPIO_USART_SetPins(USART_TypeDef *USARTx){

	GPIO_Pin_Config_t Pin_config ;

	if(USARTx == USART1)
	{

		//PA9	-->	TX
		//PA10	-->	RX
		//PA11	-->	CTS
		//PA12	-->	RTS

		//TX
		Pin_config.GPIO_PinNumber = GPIO_PIN_9;
		Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
		Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
		MCAL_GPIO_init(GPIOA , &Pin_config);

		//RTX
		Pin_config.GPIO_PinNumber = GPIO_PIN_10;
		Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_INPUT;
		MCAL_GPIO_init(GPIOA , &Pin_config);

		//CTS
		if(Global_USART1_conf->USART_HWFlowCtrl == USART_HW_FLOWCONTROL_CTS || Global_USART1_conf->USART_HWFlowCtrl == USART_HW_FLOWCONTROL_CTS_RTS)
		{
			Pin_config.GPIO_PinNumber = GPIO_PIN_11;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_INPUT;
			MCAL_GPIO_init(GPIOA , &Pin_config);

		}

		//RTS
		if(Global_USART1_conf->USART_HWFlowCtrl == USART_HW_FLOWCONTROL_RTS || Global_USART1_conf->USART_HWFlowCtrl == USART_HW_FLOWCONTROL_CTS_RTS)
		{
			Pin_config.GPIO_PinNumber = GPIO_PIN_12;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
			Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
			MCAL_GPIO_init(GPIOA , &Pin_config);

		}


	}
	else if(USARTx == USART2)
	{

		//PA0	-->	CTS
		//PA1	-->	RTS
		//PA2	-->	TX
		//PA3	-->	RX

		//TX
		Pin_config.GPIO_PinNumber = GPIO_PIN_2;
		Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
		Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
		MCAL_GPIO_init(GPIOA , &Pin_config);

		//RX
		Pin_config.GPIO_PinNumber = GPIO_PIN_3;
		Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_INPUT;
		MCAL_GPIO_init(GPIOA , &Pin_config);

		//CTS
		if(Global_USART2_conf->USART_HWFlowCtrl == USART_HW_FLOWCONTROL_CTS || Global_USART2_conf->USART_HWFlowCtrl == USART_HW_FLOWCONTROL_CTS_RTS)
		{
			Pin_config.GPIO_PinNumber = GPIO_PIN_0;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_INPUT;
			MCAL_GPIO_init(GPIOA , &Pin_config);

		}

		//RTS
		if(Global_USART2_conf->USART_HWFlowCtrl == USART_HW_FLOWCONTROL_RTS || Global_USART2_conf->USART_HWFlowCtrl == USART_HW_FLOWCONTROL_CTS_RTS)
		{
			Pin_config.GPIO_PinNumber = GPIO_PIN_1;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
			Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
			MCAL_GPIO_init(GPIOA , &Pin_config);

		}
	}
	else if(USARTx == USART3)
	{
		//PA10	-->	TX
		//PA11	-->	RX
		//PA13	-->	CTS
		//PA14	-->	RTS

		//TX
		Pin_config.GPIO_PinNumber = GPIO_PIN_10;
		Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
		Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
		MCAL_GPIO_init(GPIOB , &Pin_config);

		//RX
		Pin_config.GPIO_PinNumber = GPIO_PIN_11;
		Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_INPUT;
		MCAL_GPIO_init(GPIOB , &Pin_config);

		//CTS
		if(Global_USART3_conf->USART_HWFlowCtrl == USART_HW_FLOWCONTROL_CTS || Global_USART3_conf->USART_HWFlowCtrl == USART_HW_FLOWCONTROL_CTS_RTS)
		{
			Pin_config.GPIO_PinNumber = GPIO_PIN_13;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_INPUT;
			MCAL_GPIO_init(GPIOB , &Pin_config);

		}

		//RTS
		if(Global_USART3_conf->USART_HWFlowCtrl == USART_HW_FLOWCONTROL_RTS || Global_USART3_conf->USART_HWFlowCtrl == USART_HW_FLOWCONTROL_CTS_RTS)
		{
			Pin_config.GPIO_PinNumber = GPIO_PIN_14;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
			Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
			MCAL_GPIO_init(GPIOB , &Pin_config);

		}

	}

}


//ISR
void USART1_IRQHandler(void)
{
	Global_USART1_conf->P_IRQ_CallBack();
}
void USART2_IRQHandler(void)
{
	Global_USART2_conf->P_IRQ_CallBack();
}
void USART3_IRQHandler(void)
{
	Global_USART3_conf->P_IRQ_CallBack();
}

