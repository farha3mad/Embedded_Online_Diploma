/*
 * 		  file: STM32F103C6_GPIO_Driver.c
 *  Created on: Jul 31, 2022
 *      Author: Eng.Farha
 */


#include "INC/STM32F103C6_GPIO_Driver.h"

uint8_t get_pin_position(uint16_t PinNumber){

	switch(PinNumber){

	/***CRL***/
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;

	/***CRH***/
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;

	}

return 1;


}



/**================================================================
 * @Fn			- MCAL_GPIO_init
 * @brief 		- initialize the GPIOx PINy according to the specific parameters in the Pin_Config
 * @param [in]	- GPIOx: where x can be (A...E depending on the device used) to select the GPIO peripheral
 * @param [in] 	- pin pointer to GPIO_Pin_Config_t structure which contains the configuration information about the pin
 * @retval 		- None
 * Note			- STM32F103C6 MCU has GPIO A,B,C,D,E modules
 * 				  but LQFP48 package has only A,B, part of C,D exported as external pins from the modules
 **================================================================*/

void MCAL_GPIO_init(GPIO_TypeDef *GPIOx , GPIO_Pin_Config_t *pin){

	//Port configuration register low (GPIOx_CRL) configure pins from 0 --> 7
	//Port configuration register high (GPIOx_CRH) configure pins from 8 --> 15

	uint8_t pin_config = 0;

	//pointer to the configuration register
	volatile uint32_t* ConfigRegister = NULL;
	ConfigRegister = (pin->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH;

	//clear  CNF[1:0] MODE[1:0]
	(*ConfigRegister) &= ~(0xf << get_pin_position(pin->GPIO_PinNumber));

	//if pin is output
	if((pin->GPIO_PinConfig == GPIO_PIN_MODE_OUTPUT_PP) || (pin->GPIO_PinConfig == GPIO_PIN_MODE_OUTPUT_OD) || (pin->GPIO_PinConfig == GPIO_PIN_MODE_ALT_OUTPUT_PP) || (pin->GPIO_PinConfig == GPIO_PIN_MODE_ALT_OUTPUT_OD))
	{
		//set CNF[1:0] MODE[1:0]
		pin_config = ((((pin->GPIO_PinConfig - 4) <<2) | (pin->GPIO_Output_Speed)) & 0x0F);
	}

	//if pin is input
	else
	{
		if((pin->GPIO_PinConfig == GPIO_PIN_MODE_Analog) || (pin->GPIO_PinConfig == GPIO_PIN_MODE_INPUT_FLOA))
		{
			pin_config = (((pin->GPIO_PinConfig << 2) | 0x0) & 0x0F);
		}
		//configured as input floating
		else if (pin->GPIO_PinConfig == GPIO_PIN_MODE_ALT_INPUT)
		{
			pin_config = (((GPIO_PIN_MODE_INPUT_FLOA<< 2) | 0x0) & 0x0F);
		}
		else
		{
			//PU or PD input
			pin_config = (((GPIO_PIN_MODE_INPUT_PU << 2) | 0x0) & 0x0F);

			if(pin->GPIO_PinConfig == GPIO_PIN_MODE_INPUT_PU)
			{
				//Table 20. Port bit configuration table
				//PxODR register = 1
				GPIOx->ODR |= pin->GPIO_PinNumber;
			}
			else if (pin->GPIO_PinConfig == GPIO_PIN_MODE_INPUT_PD)
			{
				//Table 20. Port bit configuration table
				//PxODR register = 0
				GPIOx->ODR &= ~(pin->GPIO_PinNumber);
			}
		}
	}

	(*ConfigRegister) |= (pin_config << get_pin_position(pin->GPIO_PinNumber));

}

/**================================================================
 * @Fn			- MCAL_GPIO_deinit
 * @brief 		- reset all GPIOx registers
 * @param [in]	- GPIOx: where x can be (A...E depending on the device used) to select the GPIO peripheral
 * @retval 		- None
 * Note			- None
 **================================================================*/

void MCAL_GPIO_deinit(GPIO_TypeDef *GPIOx){

	/***using the reset values for all registers***/
	/*
	GPIOx->CRL   = 0x44444444;
	GPIOx->CRH   = 0x44444444;
	//GPIOx->IDR=; (READ ONLY)
	GPIOx->ODR   = 0x00000000;
	GPIOx->BSRR  = 0x00000000;
	GPIOx->BRR   = 0x00000000;
	GPIOx->LCKR  = 0x00000000;
	*/


	/***using rest controller ***/
	//APB2 peripheral reset register (RCC_APB2RSTR)
	//Set and cleared by software.

	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}
}

/**================================================================
 * @Fn			- MCAL_GPIO_ReadPin
 * @brief 		- read specific pin value
 * @param [in]	- GPIOx: where x can be (A...E depending on the device used) to select the GPIO peripheral
 * @param [in]	- PinNumber: set pin number according to @ref GPIO_PINS_define
 * @retval 		- the input pin value according to @ref GPIO_PIN_STATE_define
 * Note			- None
 **================================================================*/

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber){

	uint8_t PinStatus;
	if(((GPIOx->IDR & PinNumber) != (uint8_t)GPIO_PIN_STATE_LOW))
	{
		PinStatus = GPIO_PIN_STATE_HIGH;
	}
	else
	{
		PinStatus = GPIO_PIN_STATE_LOW;
	}

	return PinStatus;
}

/**================================================================
 * @Fn			- MCAL_GPIO_ReadPort
 * @brief 		- read the whole port value
 * @param [in]	- GPIOx: where x can be (A...E depending on the device used) to select the GPIO peripheral
 * @retval 		- the input port value
 * Note			- None
 **================================================================*/

uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx){

	uint16_t PortStatus = (uint16_t) GPIOx->IDR;
	return PortStatus;
}

/**================================================================
 * @Fn			- MCAL_GPIO_WritePin
 * @brief 		- write on specific output pin
 * @param [in]	- GPIOx: where x can be (A...E depending on the device used) to select the GPIO peripheral
 * @param [in]	- PinNumber: set pin number according to @ref GPIO_PINS_define
 * @param [in]	- value: pin value
 * @retval 		- None
 * Note			- None
 **================================================================*/

void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t value){

	if((value != (uint8_t)GPIO_PIN_STATE_LOW))
	{
		//Port output data register (GPIOx_ODR)
		//GPIOx->ODR |= PinNumber;

		//using Port bit set/reset register (GPIOx_BSRR)
		/*Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		 *These bits are write-only and can be accessed in Word mode only.
		 *0: No action on the corresponding ODRx bit
		 *1: Set the corresponding ODRx bit */

		GPIOx->BSRR = (uint32_t)PinNumber;
	}
	else
	{
		//Port output data register (GPIOx_ODR)
		//GPIOx->ODR &= ~PinNumber;

		//Port bit reset register (GPIOx_BRR)
		/*Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		 *These bits are write-only and can be accessed in Word mode only.
		 *0: No action on the corresponding ODRx bit
		 *1: Reset the corresponding ODRx bit */

		GPIOx->BRR = (uint32_t)PinNumber;
	}





}

/**================================================================
 * @Fn			- MCAL_GPIO_WritePort
 * @brief 		- write on specific output port
 * @param [in]	- GPIOx: where x can be (A...E depending on the device used) to select the GPIO peripheral
 * @param [in]	- value: port value
 * @retval 		- None
 * Note			- None
 **================================================================*/

void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t value){

	GPIOx->ODR = (uint32_t) value;

}

/**================================================================
 * @Fn			- MCAL_GPIO_TogglePin
 * @brief 		- Toggle a specific output pin
 * @param [in]	- GPIOx: where x can be (A...E depending on the device used) to select the GPIO peripheral
 * @param [in]	- PinNumber: set pin number according to @ref GPIO_PINS_define
 * @retval 		- None
 * Note			- None
 **================================================================*/

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber){

	GPIOx->ODR ^= (PinNumber);

}

/**================================================================
 * @Fn			- MCAL_GPIO_LockPin
 * @brief 		- Lock a specific pin which allow the IO Configuration to be frozen
 * @param [in]	- GPIOx: where x can be (A...E depending on the device used) to select the GPIO peripheral
 * @param [in]	- PinNumber: set pin number according to @ref GPIO_PINS_define
 * @retval 		- Ok if pin is locked or Error if pin is not locked (according to @ref GPIO_RETURN_LOCK_define)
 * Note			- None
 **================================================================*/

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber){

	/*Bit 16 LCKK[16]: Lock key
	 *This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	 *0: Port configuration lock key not active
	 *1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	 *LOCK key writing sequence:
	 *Write 1
	 *Write 0
	 *Write 1
	 *Read 0
	 *Read 1 (this read is optional but confirms that the lock is active)
	 *Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	 *Any error in the lock sequence will abort the lock.
	 *Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	 *These bits are read write but can only be written when the LCKK bit is 0.
	 *0: Port configuration not locked
	 *1: Port configuration locked.
	 * */

	//set LCKK[16]
	volatile uint32_t temp = (1<<16);
	//set LCKy
	temp |= PinNumber;

	//LOCK key writing sequence:
	//Write 1
	GPIOx->LCKR = temp;
	//Write 0
	GPIOx->LCKR &= ~(1<<16);
	//Write 1
	GPIOx->LCKR = temp;
	//Read 0
	temp = GPIOx->LCKR;
	//Read 1

	if(((uint32_t)GPIOx->LCKR & (1<<16)) != GPIO_RETURN_LOCK_ERORR)
	{
		return (uint8_t)GPIO_RETURN_LOCK_ENABLE;
	}
	else
	{
		return (uint8_t)GPIO_RETURN_LOCK_ERORR;
	}

}




