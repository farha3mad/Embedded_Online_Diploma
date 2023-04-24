/*****************************************************************/
/* Author      : Farha Emad                                      */
/* Date        : 23 April 2023                                   */      
/*****************************************************************/

#ifndef	STM32F103C6_USART_DRIVER_H
#define STM32F103C6_USART_DRIVER_H

#include "stm32f103x6.h"
#include "STM32F103C6_RCC_DRIVER.h"
#include "STM32F103C6_GPIO_Driver.h"

typedef struct{

	uint8_t 		USART_MODE;				//specifies Rx/Tx enable/disable
											//This parameter must be set from @ref USART_MODE_define

	uint32_t 		USART_BAUD_RATE;		//specifies USART communication baud rate
										    //This parameter must be set from @ref USART_BAUDRATE_define

	uint8_t 		USART_PAYLOAD;		    //specifies USART pay-load or data length
											//This parameter must be set from @ref USART_PAYLOAD_define

	uint8_t 		USART_STOP_BIT;		    //specifies USART number of stop bit
											//This parameter must be set from @ref USART_STOP_BIT_define

	uint8_t 		USART_PARITY_BIT;		//specifies USART parity bit mode
											//This parameter must be set from @ref USART_PARITY_BIT_define

	uint8_t 		USART_HWFlowCtrl;		//specifies USART flow control mode
											//This parameter must be set from @ref USART_HW_FLOWCONTROL_define

	uint8_t 		USART_IRQ;				//specifies USART interrupts enable
											//This parameter must be set from @ref USART_IRQ_ENABLE_define

	void (* P_IRQ_CallBack) (void);		//Set the C function to be called once the interrupt happen

}USART_config;



//---------------------------------
//Macros Configuration References
//---------------------------------
//@ref Module_REF_NAME_define


//@ref USART_MODE_define
#define		USART_MODE_RX						(uint32_t)(1<<2)	//Bit 2 RE: Receiver enable
#define		USART_MODE_TX						(uint32_t)(1<<3)	//Bit 3 TE: Transmitter enable
#define		USART_MODE_TX_RX					(uint32_t)(1<<2 | 1<<3)

//@ref USART_BAUDRATE_define
#define		USART_BAUDRATE_2400					(2400)
#define		USART_BAUDRATE_9600					(9600)
#define		USART_BAUDRATE_19200				(19200)
#define		USART_BAUDRATE_57600				(57600)
#define		USART_BAUDRATE_115200				(115200)
#define		USART_BAUDRATE_230400				(230400)
#define		USART_BAUDRATE_460800				(460800)
#define		USART_BAUDRATE_921600				(921600)
#define		USART_BAUDRATE_2250000				(2250000)
#define		USART_BAUDRATE_4500000				(4500000)

//@ref USART_PAYLOAD_define
//Bit 12 M: Word length
#define		USART_PAYLOAD_8						(uint32_t)(0)
#define		USART_PAYLOAD_9						(uint32_t)(1<<12)

//@ref USART_STOP_BIT_define
//Bits 13:12 STOP: STOP bits
#define		USART_STOP_BIT_HALF					(uint32_t)(0b01<<12)
#define		USART_STOP_BIT_1_HALF				(uint32_t)(0b11<<12)
#define		USART_STOP_BIT_1					(uint32_t)(0)
#define		USART_STOP_BIT_2					(uint32_t)(0b10<<12)


//@ref USART_PARITY_define
#define		USART_PARITY_NONE					(uint32_t)(0)  				 //Bit 10 PCE: Parity control enable
#define		USART_PARITY_EVEN					(uint32_t)(1<<10)    		 //Bit 10 PCE: Parity control enable
#define		USART_PARITY_ODD					(uint32_t)(1<<10 | 1<<9) 	 //Bit 9 PS: Parity selection

//@ref USART_HW_FLOWCONTROL_define
#define     USART_HW_FLOWCONTROL_NONE			(uint32_t)(0)
#define		USART_HW_FLOWCONTROL_CTS			(uint32_t)(1<<9)  			 //Bit 9 CTSE: CTS enable
#define		USART_HW_FLOWCONTROL_RTS			(uint32_t)(1<<8)  		 	 //Bit 8 RTSE: RTS enable
#define		USART_HW_FLOWCONTROL_CTS_RTS		(uint32_t)(1<<8 | 1<<9)  	 //Bit 8 RTSE: RTS enable

//@ref USART_IRQ_ENABLE_define
#define     USART_IRQ_ENABLE_NONE			(uint32_t)(0)
#define     USART_IRQ_ENABLE_PE				(uint32_t)(1<<8) 				//Bit 8 PEIE: PE interrupt enable
#define     USART_IRQ_ENABLE_TXE			(uint32_t)(1<<7) 				//Bit 7 TXEIE: TXE interrupt enable
#define     USART_IRQ_ENABLE_TC				(uint32_t)(1<<6) 				//Bit 6 TCIE: Transmission complete interrupt enable
#define     USART_IRQ_ENABLE_RXNE			(uint32_t)(1<<5) 				//Bit 5 RXNEIE: RXNE interrupt enable

//---------------------------------

//Baud rate calculations


#define 	USART_DIV(FCLK , BAUDRATE)							 (uint32_t)(FCLK / (BAUDRATE * 16))
#define 	USART_DIV_MUL_100(FCLK , BAUDRATE)					 (uint32_t)((100*FCLK) / (BAUDRATE * 16))

#define 	USART_DIV_Mantissa(FCLK , BAUDRATE)		   			 (uint32_t)USART_DIV( FCLK , BAUDRATE)
#define 	USART_DIV_Mantissa_MUL_100(FCLK , BAUDRATE)		     (uint32_t)USART_DIV_Mantissa(FCLK , BAUDRATE) * 100

#define 	USART_DIV_Fraction_MUL_100(FCLK , BAUDRATE)		 	 (uint32_t)((USART_DIV_MUL_100(FCLK , BAUDRATE) - USART_DIV_Mantissa_MUL_100(FCLK , BAUDRATE))*16)
#define 	USART_DIV_Fraction(FCLK , BAUDRATE)		 			 (uint32_t)(USART_DIV_Fraction_MUL_100(FCLK , BAUDRATE)	/ 100)

#define 	USART_BRR_VALUE(FCLK , BAUDRATE)		 			 (uint32_t)((USART_DIV_Mantissa(FCLK , BAUDRATE)	<<4) | (USART_DIV_Fraction(FCLK , BAUDRATE)<<0))


//---------------------------------
//Enums
//---------------------------------
enum polling
{
	enable,
	disable
};



//---------------------------------
//APIs
//---------------------------------

void MCAL_USART_init(USART_TypeDef *USARTx , USART_config *USART_conf);
void MCAL_USART_deinit(USART_TypeDef *USARTx);

void MCAL_USART_SendData(USART_TypeDef *USARTx , uint16_t *data_buffer , enum polling poll);
void MCAL_USART_Wait_TC(USART_TypeDef *USARTx);

void MCAL_USART_ReceiveData(USART_TypeDef *USARTx , uint16_t *data_buffer , enum polling poll);

void MCAL_GPIO_USART_SetPins(USART_TypeDef *USARTx);

#endif
