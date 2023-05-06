/*****************************************************************/
/* Author      : Farha Emad                                      */
/* Date        : 30 April 2023                                   */      
/*****************************************************************/


#include "INC/STM32F103C6_SPI_DRIVER.h"


/**************** General Variables *******************/

SPI_config *	global_SPI1 = NULL;
SPI_config *	global_SPI2 = NULL;

/*********************** APIs *************************/


/**================================================================
 * @Fn			- MCAL_SPI_init
 * @brief 		- initialize the SPIx according to the specific parameters
 * @param [in]	- SPIx: where x can be (1 or 2 depending on the device used) to select the SPI peripheral
 * @param [in] 	- SPI_conf: pointer to SPI_config structure which contains the configuration information
 * @retval 		- None
 * Note			- Support Full Duplex only (Master/slave) & NSS is hardware only with slave mode
 **================================================================*/

void MCAL_SPI_init(SPI_TypeDef * SPIx , SPI_config * SPI_conf )
{
	uint16_t CR1_temp = 0;
	uint16_t CR2_temp = 0;

	if(SPIx == SPI1)
	{
		global_SPI1 = SPI_conf;
		SPI1_CLOCK_ENABLE();
	}
	else if(SPIx == SPI2)
	{
		global_SPI2 = SPI_conf;
		SPI2_CLOCK_ENABLE();

	}

	//Enable SPI peripheral .. Bit 6 SPE: SPI enable
	CR1_temp |= (1<<6);

	//Configure mode (Master/Slave)
	CR1_temp |= SPI_conf->SPI_MODE;

	//Configure communication mode
	CR1_temp |= SPI_conf->SPI_Communication;

	//Define 8- or 16-bit data frame format
	CR1_temp |= SPI_conf->SPI_Frame_Size;

	//Configure data order (LSB/MSB)
	CR1_temp |= SPI_conf->SPI_Data_Order;

	//Configure Clock Polarity
	CR1_temp |= SPI_conf->SPI_Clock_Polarity;

	//Configure Clock Polarity
	CR1_temp |= SPI_conf->SPI_Clock_Phase;

	//Configure baud rate prescalers
	CR1_temp |= SPI_conf->SPI_Baud_Rate_Prescaler;

	/*******************NSS******************/
	if(SPI_conf->SPI_NSS == SPI_NSS_HARDWARE_MASTER_OUTPUT  )
	{

		CR2_temp |= SPI_conf->SPI_NSS;
	}
	else if( SPI_conf->SPI_NSS == SPI_NSS_HARDWARE_MASTER_INPUT )
	{

		CR2_temp &= SPI_conf->SPI_NSS;
	}
	else
	{
		CR1_temp |= SPI_conf->SPI_NSS;
	}

	/******************IRQ********************/
	if(SPI_conf->SPI_IRQ != SPI_IRQ_ENABLE_NONE)
	{
		CR2_temp |= SPI_conf->SPI_IRQ;

		/***************NVIC incomplete**************/

		if(SPIx == SPI1)
		{
			//Enable NVIC interrupt mask
			//!!!!!REQUIRED!!!!!!!!!
		}
		else if(SPIx == SPI2)
		{
			//Enable NVIC interrupt mask
			//!!!!!REQUIRED!!!!!!!!!
		}
	}

	SPIx->SPI_CR1 = CR1_temp;
	SPIx->SPI_CR2 = CR2_temp;

}


/**================================================================
 * @Fn			- MCAL_SPI_deinit
 * @brief 		- Deinitialize the SPIx
 * @param [in]	- SPIx: where x can be (1 or 2 depending on the device used) to select the SPI peripheral
 * @retval 		- None
 * Note			- Reset the module by RCC
 **================================================================*/

void MCAL_SPI_deinit(SPI_TypeDef * SPIx){

	if(SPIx == SPI1)
	{
		SPI1_CLOCK_DISABLE();
		//Disable NVIC interrupt mask
		//!!!!!REQUIRED!!!!!!!!!
	}
	else if(SPIx == SPI2)
	{
		SPI2_CLOCK_DISABLE();
		//Disable NVIC interrupt mask
		//!!!!!REQUIRED!!!!!!!!!
	}

}

/**================================================================
 * @Fn			- MCAL_SPI_SendData
 * @brief 		- Transmit data by the SPIx according to the specific parameters
 * @param [in]	- SPIx: where x can be (1 or 2 depending on the device used) to select the SPI peripheral
 * @param [in] 	- data_buffer: 8-bit or 16-bit data to be transmitted
 * @param [in] 	- poll: Enable/disable polling mechanism
 * @retval 		- None
 * Note			- Should initialize SPI first
 *				  Support only Full duplex mode
 **================================================================*/
void MCAL_SPI_SendData(SPI_TypeDef *SPIx , uint16_t *data_buffer , enum polling poll){

	if(poll == enable)
	{
		//SPI status register (SPI_SR)
		//Bit 1 TXE: Transmit buffer empty
		//0: Tx buffer not empty
		//1: Tx buffer empty


		while(!((SPIx->SPI_SR ) & (1<<1))); //wait until the buffer is empty

	}
	if(SPIx == SPI1)
	{
		if(global_SPI1->SPI_Frame_Size == SPI_FRAME_SIZE_8)
		{

			SPI1->SPI_DR = (*data_buffer & (uint16_t)0x00FF);
		}
		else
		{
			SPI1->SPI_DR = (*data_buffer & (uint16_t)0xFFFF);

		}
	}
	else if(SPIx == SPI2)
	{

		if(global_SPI2->SPI_Frame_Size == SPI_FRAME_SIZE_8)
		{

			SPI2->SPI_DR = (*data_buffer & (uint16_t)0x00FF);
		}
		else
		{
			SPI2->SPI_DR = (*data_buffer & (uint16_t)0xFFFF);

		}

	}


}

/**================================================================
 * @Fn			- MCAL_SPI_ReceiveData
 * @brief 		- Receive data by the SPIx
 * @param [in]	- SPIx: where x can be (1 or 2 depending on the device used) to select the SPI peripheral
 * @param [in] 	- data_buffer: 8-bit or 16-bit data to be transmitted
 * @param [in] 	- poll: Enable/disable polling mechanism
 * @retval 		- NONE
 * Note			-
 **================================================================*/

void MCAL_SPI_ReceiveData(SPI_TypeDef *SPIx , uint16_t *data_buffer , enum polling poll)
{
	if(poll==enable)
	{
		//SPI status register (SPI_SR)
		//Bit 0 RXNE: Receive buffer not empty
		//0: Rx buffer empty
		//1: Rx buffer not empty

		while(!((SPIx->SPI_SR ) & (1<<0))); //wait until the buffer is NOT empty
	}

	*data_buffer =  SPIx->SPI_DR ;

}

/**================================================================
 * @Fn			- MCAL_GPIO_SPI_SetPins
 * @brief 		- Initialize GPIO pins
 * @param [in]	- SPIx: where x can be (1 or 2 depending on the device used) to select the SPI peripheral
 * @retval 		- NONE
 * Note			- Should enable RCC clock for the corresponding ALT and GPIO called after MCAL_SPI_init()
 **================================================================*/

void MCAL_GPIO_SPI_SetPins(SPI_TypeDef *SPIx)
{
	GPIO_Pin_Config_t Pin_config ;

	if(SPIx == SPI1)
	{
		//PA4	-->	SPI1_NSS
		//PA5	-->	SPI1_SCK
		//PA6	-->	SPI1_MISO
		//PA7	-->	SPI1_MOSI

		if(global_SPI1->SPI_MODE == SPI_MODE_MASTER)
		{
			//SPI1_NSS
			if(global_SPI1->SPI_NSS == SPI_NSS_HARDWARE_MASTER_INPUT)
			{
				Pin_config.GPIO_PinNumber = GPIO_PIN_4;
				Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
				MCAL_GPIO_init(GPIOA , &Pin_config);
			}
			else if(global_SPI1->SPI_NSS == SPI_NSS_HARDWARE_MASTER_OUTPUT)
			{
				Pin_config.GPIO_PinNumber = GPIO_PIN_4;
				Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
				Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
				MCAL_GPIO_init(GPIOA , &Pin_config);

			}

			//SPI1_SCK
			Pin_config.GPIO_PinNumber = GPIO_PIN_5;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
			Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
			MCAL_GPIO_init(GPIOA , &Pin_config);

			//SPI1_MISO
			Pin_config.GPIO_PinNumber = GPIO_PIN_6;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
			MCAL_GPIO_init(GPIOA , &Pin_config);

			//SPI1_MOSI .. full duplex mode
			Pin_config.GPIO_PinNumber = GPIO_PIN_7;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
			Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
			MCAL_GPIO_init(GPIOA , &Pin_config);



		}
		else
		{
			//SPI1_NSS
			if(global_SPI1->SPI_NSS == SPI_NSS_HARDWARE_SLAVE_INPUT)
			{
				Pin_config.GPIO_PinNumber = GPIO_PIN_4;
				Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
				MCAL_GPIO_init(GPIOA , &Pin_config);
			}

			//SPI1_SCK
			Pin_config.GPIO_PinNumber = GPIO_PIN_5;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
			MCAL_GPIO_init(GPIOA , &Pin_config);

			//SPI1_MISO
			Pin_config.GPIO_PinNumber = GPIO_PIN_6;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
			Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
			MCAL_GPIO_init(GPIOA , &Pin_config);

			//SPI1_MOSI .. full duplex mode
			Pin_config.GPIO_PinNumber = GPIO_PIN_7;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
			MCAL_GPIO_init(GPIOA , &Pin_config);

		}

	}
	else if(SPIx == SPI2)
	{
		//PB12	-->	SPI2_NSS
		//PB13	-->	SPI2_SCK
		//PB14	-->	SPI2_MISO
		//PB15	-->	SPI2_MOSI

		if(global_SPI2->SPI_MODE == SPI_MODE_MASTER)
		{
			//SPI2_NSS
			if(global_SPI2->SPI_NSS == SPI_NSS_HARDWARE_MASTER_INPUT)
			{
				Pin_config.GPIO_PinNumber = GPIO_PIN_12;
				Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
				MCAL_GPIO_init(GPIOB , &Pin_config);
			}
			else if(global_SPI2->SPI_NSS == SPI_NSS_HARDWARE_MASTER_OUTPUT)
			{
				Pin_config.GPIO_PinNumber = GPIO_PIN_12;
				Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
				Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
				MCAL_GPIO_init(GPIOB , &Pin_config);

			}

			//SPI2_SCK
			Pin_config.GPIO_PinNumber = GPIO_PIN_13;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
			Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
			MCAL_GPIO_init(GPIOB , &Pin_config);

			//SPI2_MISO
			Pin_config.GPIO_PinNumber = GPIO_PIN_14;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
			MCAL_GPIO_init(GPIOB , &Pin_config);

			//SPI2_MOSI .. full duplex mode
			Pin_config.GPIO_PinNumber = GPIO_PIN_15;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
			Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
			MCAL_GPIO_init(GPIOB , &Pin_config);


		}
		else
		{

			//SPI2_NSS
			if(global_SPI2->SPI_NSS == SPI_NSS_HARDWARE_SLAVE_INPUT)
			{
				Pin_config.GPIO_PinNumber = GPIO_PIN_12;
				Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
				MCAL_GPIO_init(GPIOB , &Pin_config);
			}

			//SPI2_SCK
			Pin_config.GPIO_PinNumber = GPIO_PIN_13;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
			MCAL_GPIO_init(GPIOB , &Pin_config);

			//SPI2_MISO
			Pin_config.GPIO_PinNumber = GPIO_PIN_14;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_ALT_OUTPUT_PP;
			Pin_config.GPIO_Output_Speed = GPIO_PIN_SPEED_10MHZ;
			MCAL_GPIO_init(GPIOB , &Pin_config);

			//SPI2_MOSI .. full duplex mode
			Pin_config.GPIO_PinNumber = GPIO_PIN_15;
			Pin_config.GPIO_PinConfig = GPIO_PIN_MODE_INPUT_FLOA;
			MCAL_GPIO_init(GPIOB , &Pin_config);

		}
	}

}

//ISRs
void SPI1_IRQHandler()
{

	struct IRQ_Source interrupt_source;

	interrupt_source.TXEIE  = ((SPI1->SPI_SR >> 1) & 1);
	interrupt_source.RXNEIE = ((SPI1->SPI_SR >> 0) & 1);
	interrupt_source.ERRIE  = ((SPI1->SPI_SR >> 4) & 1);

	global_SPI1->P_IRQ_CallBack(interrupt_source);

}
void SPI2_IRQHandler ()
{
	struct IRQ_Source interrupt_source;

	interrupt_source.TXEIE  = ((SPI2->SPI_SR >> 1) & 1);
	interrupt_source.RXNEIE = ((SPI2->SPI_SR >> 0) & 1);
	interrupt_source.ERRIE  = ((SPI2->SPI_SR >> 4) & 1);

	global_SPI2->P_IRQ_CallBack(interrupt_source);

}
