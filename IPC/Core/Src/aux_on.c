/*
 * aux_on.c
 *
 *  Created on: May 9, 2020
 *      Author: sidhu
 */

#include "main.h"
uint8_t flag = 1;

void aux_on_condition()
{
	if(flag)
	{
	HAL_GPIO_WritePin(GPIOC,oilFault_LED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,handBrake_LED_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,seatBelt_LED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,engineFaultSts_Pin, GPIO_PIN_SET);

	}


}

/*call back function after 2 sec of aux mode this will check condition of all faults */
HAL_TIM_PeriodElapsedCallback(htim)
{
	flag = 0;

	if(HAL_GPIO_ReadPin(GPIOC,seatBeltSts_Pin) == 0)
		HAL_GPIO_WritePin(GPIOC,seatBelt_LED_Pin, GPIO_PIN_SET);

	else
		HAL_GPIO_WritePin(GPIOC,seatBelt_LED_Pin, GPIO_PIN_RESET);

	if(HAL_GPIO_ReadPin(GPIOC,oilSts_Inp_Pin) == 0)
		HAL_GPIO_WritePin(GPIOC,oilFault_LED_Pin, GPIO_PIN_SET);

	else
		HAL_GPIO_WritePin(GPIOC,oilFault_LED_Pin, GPIO_PIN_RESET);

	if(HAL_GPIO_ReadPin(GPIOC,handBrakeSts_Pin) == 0)
		HAL_GPIO_WritePin(GPIOC,handBrake_LED_Pin,GPIO_PIN_SET);

	else
		HAL_GPIO_WritePin(GPIOC,handBrake_LED_Pin, GPIO_PIN_RESET);


	HAL_TIM_Base_Stop_IT(&htim);

	//__HAL_TIM_SET_COUNTER(htim, 0);

}


#if 0
HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	if(count++ == 5)
	{
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 1);
		HAL_TIM_Base_Stop_IT(&htim6);
		count = 0;
		__HAL_TIM_SET_COUNTER(&htim6, 0);
		count = 0;
	}

#endif
