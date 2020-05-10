/*
* telltales.h 
*
* Created on: May 4, 2020
* Author : Kala
*/

#include"main.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef TELLTALES_H_
#define TELLTALES_H_

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim9;
typedef enum
{
	FUEL_LEVEL_GAUGE, ENGINE_SPEED_GAUGE, ENGINE_TEMP_GAUGE
}gauge_type;

void seatBelt_status(void);
void handBrake_status(void);
int generateRandom_nums(int,int);
void fuelLevel_status(void);
void oilFault_status(void);
void servo_write(int angle, gauge_type);
int map(int st1, int fn1, int st2, int fn2, int value);
#endif 
