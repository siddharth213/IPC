
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : tell-tales.c
  * @brief          : program to display the tell-tale lamps of Instrument Panel Cluster
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ---------------------------------------------------------/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * seatBelt_status reads the specified pin, compares the value and accordingly
 * 		the output value is set/reset on the specified pin
  */
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

/* handBrake_status read the specified pin, compares the value and accordingly
 * 		 the output value is set/reset on the specified pin*/
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

int generateRandom_nums(int lower, int upper)
{
       unsigned int num =0;
        num = (rand() % (upper - lower + 1)) + lower;
       // printf("%d ", num);
        return num;
}
/* fuelLevel_status gives the output to PWM pin based on the input level of fuel*/
void fuelLevel_status(void)
{
/*  0 to 200  --> Empty
	500 to 750 -->Half
	900 to 1023 -->Full     */
	unsigned int lower = 0;
	unsigned int upper = 1023;
	unsigned int fuel_value = 0;
	    // Use current time as
	    // seed for random generator
	    srand(time(0));

	    fuel_value = printRandom_nums(lower, upper);
	    if((fuel_value > 0) && (fuel_value <200) )
	    {
	    	/* Fuel is empty,PWM angle for motor is 0 deg */

	    }
	    else if((fuel_value>500) && (fuel_value <750))
	    {
	    /* Fuel is half ,PWM angle for motor is 45 deg */

	    }
	    else if((fuel_value >= 950) && (fuel_value <= 1023))
	    {
	     /* Fuel is full, PWM angle for motor is 90 deg */
	    }

}


