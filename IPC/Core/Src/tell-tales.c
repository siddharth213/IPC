#include"telltales.h"

/*
  * telltales.c
  * Created on:  April 30,2020
  * Author : Kala
  */
/*
 **************************************************************************************************
 * @fn              : seatBelt_status
 * @brief           : read the specified pin, compares the value and accordingly the output value 
 *                    is set/reset on the specified pin
 * @param           : None
 * @return          : None
 **************************************************************************************************
*/

TIM_HandleTypeDef htim4;

void seatBelt_status(void)
{
	if(HAL_GPIO_ReadPin(GPIOC,seatBeltSts_Pin) == 0)
	{
	HAL_GPIO_WritePin(GPIOC,seatBelt_LED_Pin, GPIO_PIN_SET);
	}
	else
	{
	HAL_GPIO_WritePin(GPIOC,seatBelt_LED_Pin, GPIO_PIN_RESET);
	}
}

/*
 *************************************************************************************************
 * @fn               : handBrake_status
 * @breif            : read the specified pin, compares the value and accordingly the output value
 *                     is set/reset on the specified pin
 * @param            : None
 * @return           : None
 **************************************************************************************************
 */
void handBrake_status(void)
{
	if(HAL_GPIO_ReadPin(GPIOC,handBrakeSts_Pin) == 0)
	{
	HAL_GPIO_WritePin(GPIOC,handBrake_LED_Pin,GPIO_PIN_SET);
	}
	else
	{
	HAL_GPIO_WritePin(GPIOC,handBrake_LED_Pin, GPIO_PIN_RESET);
	}
}
/*
***************************************************************************************************
* @fn                 : generateRandom_nums
* @breif              : It is used to generate random numbers
* @param              : lower    specifies the lowest value to the function
* @param              : upper    specifies the highest value to the function
* @return             : None
**************************************************************************************************
*/
int generateRandom_nums(int lower, int upper)
{
       uint16_t num =0;
        num = (rand() % (upper - lower + 1)) + lower;
       // printf("%d ", num);
        return num;
}

/*
**************************************************************************************************
* @fn                   : fuelLevel_status 
* @brief                : outputs the value to PWM pin based on the input level of fuel
* @param                : None
* @return               : None
**************************************************************************************************
*/

void fuelLevel_status(void)
{
/*  0 to 200  --> Empty
	500 to 750 -->Half
	900 to 1023 -->Full     */
	uint16_t lower = 0;
	uint16_t upper = 1023;
	uint16_t fuel_value = 0;
	    // Use current time as
	    // seed for random generator
	    srand(time(0));

	     HAL_TIM_Base_Start(&htim4);
	    
	    // Start PWM at Port-D pin#12
	   HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
	    
	    fuel_value = generateRandom_nums(lower, upper);

	    if((fuel_value > 0) && (fuel_value <200) )
	    {
	    	/* Fuel is empty,PWM angle for motor is 0 deg */
             __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, 50);
	    }
	    else if((fuel_value>500) && (fuel_value <750))
	    {
	    /* Fuel is half ,PWM angle for motor is 45 deg */
             __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, 63);
	    }
	    else if((fuel_value >= 950) && (fuel_value <= 1023))
	    {
	     /* Fuel is full, PWM angle for motor is 90 deg */
	     __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, 75);
	    }


}
/*
*****************************************************************************************************
* @fn
* @brief
* @param
* @return
*****************************************************************************************************
*/
void oilFault_status(void)
{
	if(HAL_GPIO_ReadPin(GPIOC,oilSts_Inp_Pin) == 0)
		{
		HAL_GPIO_WritePin(GPIOC,oilFault_LED_Pin, GPIO_PIN_SET);
		}
		else
		{
		HAL_GPIO_WritePin(GPIOC,oilFault_LED_Pin, GPIO_PIN_RESET);
		}
}



