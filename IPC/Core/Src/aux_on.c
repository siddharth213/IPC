/*
 * aux_on.c
 *
 *  Created on: May 9, 2020
 *      Author: siddharth
 */

#include "main.h"
#include "telltales.h"
uint8_t flag = 1;

void aux_on_condition()
{
	if(flag)
	{

	/* All telltales on*/
	HAL_GPIO_WritePin(GPIOC,oilFault_LED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,handBrake_LED_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,seatBelt_LED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,engineFaultSts_Pin, GPIO_PIN_SET);

	/*Gauges needle to 0 degree */
	servo_write(0, FUEL_LEVEL_GAUGE);
	servo_write(0, ENGINE_SPEED_GAUGE);
	servo_write(0, ENGINE_TEMP_GAUGE);

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


