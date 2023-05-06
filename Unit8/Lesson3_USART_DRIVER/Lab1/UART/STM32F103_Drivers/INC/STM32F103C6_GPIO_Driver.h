/*
 * 		  file: STM32F103C6_GPIO_Driver.h
 *  Created on: Jul 31, 2022
 *      Author: Eng.Farha
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------

#include "stm32f103x6.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct{

	uint16_t GPIO_PinNumber;  //specifies the GPIO pins to be configured
							  //This parameter must be set from @ref GPIO_PINS_define

	uint8_t GPIO_PinConfig;  //specifies the GPIO pins modes
							 //This parameter can be a value of @ref GPIO_PIN_MODE_define

	uint8_t GPIO_Output_Speed;   //specifies the GPIO output pins speed
								 //This parameter can be a value of @ref GPIO_PIN_SPEED_define

}GPIO_Pin_Config_t;


//-----------------------------
//Macros Configuration References
//-----------------------------
//@ref Module_REF_NAME_define


//@ref GPIO_PINS_define

#define  GPIO_PIN_0							((uint16_t)0x0001)   /*pin 0 selected*/
#define  GPIO_PIN_1							((uint16_t)0x0002)   /*pin 1 selected*/
#define  GPIO_PIN_2							((uint16_t)0x0004)   /*pin 2 selected*/
#define  GPIO_PIN_3							((uint16_t)0x0008)   /*pin 3 selected*/
#define  GPIO_PIN_4							((uint16_t)0x0010)   /*pin 4 selected*/
#define  GPIO_PIN_5							((uint16_t)0x0020)   /*pin 5 selected*/
#define  GPIO_PIN_6							((uint16_t)0x0040)   /*pin 6 selected*/
#define  GPIO_PIN_7							((uint16_t)0x0080)   /*pin 7 selected*/
#define  GPIO_PIN_8							((uint16_t)0x0100)   /*pin 8 selected*/
#define  GPIO_PIN_9							((uint16_t)0x0200)   /*pin 9 selected*/
#define  GPIO_PIN_10						((uint16_t)0x0400)   /*pin 10 selected*/
#define  GPIO_PIN_11						((uint16_t)0x0800)   /*pin 11 selected*/
#define  GPIO_PIN_12						((uint16_t)0x1000)   /*pin 12 selected*/
#define  GPIO_PIN_13						((uint16_t)0x2000)   /*pin 13 selected*/
#define  GPIO_PIN_14						((uint16_t)0x4000)   /*pin 14 selected*/
#define  GPIO_PIN_15						((uint16_t)0x8000)   /*pin 15 selected*/
#define  GPIO_ALL_PINS						((uint16_t)0xFFFF)   /*all pins selected*/

//===============================================

//@ref GPIO_PIN_MODE_define
/*
0: Analog mode
1: Floating input (reset state)
2: Input with pull-up
3: Input with  pull-down
4: General purpose output push-pull
5: General purpose output Open-drain
6: Alternate function output Push-pull
7: Alternate function output Open-drain
8: Alternate function input (Floating input)
*/


#define GPIO_PIN_MODE_Analog				(0x00000000u)   /*Analog mode*/
#define GPIO_PIN_MODE_INPUT_FLOA			(0x00000001u)   /*Floating input mode*/
#define GPIO_PIN_MODE_INPUT_PU				(0x00000002u)   /*Input with pull-up mode*/
#define GPIO_PIN_MODE_INPUT_PD				(0x00000003u)   /*Input with pull-down mode*/
#define GPIO_PIN_MODE_OUTPUT_PP				(0x00000004u)   /*General purpose output push-pull mode*/
#define GPIO_PIN_MODE_OUTPUT_OD				(0x00000005u)   /*General purpose output Open-drain mode*/
#define GPIO_PIN_MODE_ALT_OUTPUT_PP			(0x00000006u)   /*Alternate function output Push-pull mode*/
#define GPIO_PIN_MODE_ALT_OUTPUT_OD			(0x00000007u)   /*Alternate function output Open-drain mode*/
#define GPIO_PIN_MODE_ALT_INPUT			    (0x00000008u)   /*Alternate function input mode*/

//===============================================

//@ref GPIO_PIN_SPEED_define
/*
1: Output mode, max speed 10 MHz.
2: Output mode, max speed 2 MHz.
3: Output mode, max speed 50 MHz.
*/

#define GPIO_PIN_SPEED_10MHZ				(0x00000001u)   /*max speed 10 MHz*/
#define GPIO_PIN_SPEED_2MHZ					(0x00000002u)   /*max speed 2 MHz*/
#define GPIO_PIN_SPEED_50MHZ				(0x00000003u)   /*max speed 50 MHz*/

//===============================================

//@ref GPIO_PIN_STATE_define

#define GPIO_PIN_STATE_HIGH			1
#define GPIO_PIN_STATE_LOW			0

//===============================================

//@ref GPIO_RETURN_LOCK_define


#define GPIO_RETURN_LOCK_ENABLE		1
#define GPIO_RETURN_LOCK_ERORR		0

//===============================================

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_init(GPIO_TypeDef *GPIOx , GPIO_Pin_Config_t *pin);
void MCAL_GPIO_deinit(GPIO_TypeDef *GPIOx);


uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);

void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t value);
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);


#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
