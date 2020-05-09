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

void seatBelt_status(void);
void handBrake_status(void);
int generateRandom_nums(int,int);
void fuelLevel_status(void);
void oilFault_status(void);
void servo_write(int angle);
int map(int st1, int fn1, int st2, int fn2, int value);
#endif 
