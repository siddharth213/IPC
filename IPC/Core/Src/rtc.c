/*
 * rtc.c
 *
 *  Created on: May 12, 2020
 *      Author: Kala
 */
#include "lcd_driver.h"


RTC_HandleTypeDef hrtc;

uint8_t g_time[10];
uint8_t g_date[10];


void set_time(void)
{
	RTC_TimeTypeDef sTime = {0};
	RTC_DateTypeDef sDate = {0};

	/** Initialize RTC and set the Time and Date
	  */
	  sTime.Hours = 0x12;
	  sTime.Minutes = 0x35;
	  sTime.Seconds = 0x0;
	  sTime.TimeFormat = RTC_HOURFORMAT12_AM;
	  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
	  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sDate.WeekDay = RTC_WEEKDAY_THURSDAY;
	  sDate.Month = RTC_MONTH_MAY;
	  sDate.Date = 0x7;
	  sDate.Year = 0x20;

	  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
	  {
	    Error_Handler();
	  }
}

void get_time(void)
{
	RTC_DateTypeDef gDate;
	RTC_TimeTypeDef gTime;

	/*Get the RTC Current Time */
	HAL_RTC_GetTime(&hrtc,&gTime,RTC_FORMAT_BIN);
	/*Get the RTC current Date */
	HAL_RTC_GetDate(&hrtc,&gDate,RTC_FORMAT_BIN);

	/*Display time format : hh:mm */
	sprintf((char*)g_time,"%02d:%02d",gTime.Hours,gTime.Minutes);
	/*Display date format : dd-mm-yy */
   sprintf((char*)g_date, "%02d-%02d-%2d",gDate.Date,gDate.Month,gDate.Year);
}

void disp_time_date(void)
{
	LCD_Send_Cmd(0x80);
	LCD_Send_String(g_date);
	LCD_Send_Cmd(0x80+0xA);
	LCD_Send_String(g_time);
	LCD_Send_Cmd(0xC0+2);
	LCD_Send_String("Date");
	LCD_Send_Cmd(0xC0+0xA);
	LCD_Send_String("Time");
}

void fn_rtc(void)
{
		LCD_Init();
	  	set_time();
	  	while (1)
	  	{
	  	  get_time();
	  	  display_time();
	  	  HAL_Delay(500);
		}
}

