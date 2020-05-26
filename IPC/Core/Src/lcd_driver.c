/*
 * lcd_rtc_int.c
 *
 *  Created on: May 7, 2020
 *      Author: Kala
 */
#include "main.h"
#include "lcd_driver.h"
#include <stdio.h>

I2C_HandleTypeDef hi2c1;


/**
 * @brief Send Data to LCD
 * @param data: Data to be sent to LCD
 * @retval None
 */
void LCD_Send_Data(uint8_t data)
{
	uint8_t data_u = 0;
	uint8_t data_l = 0;
	uint8_t data_u_tx[2];
	uint8_t data_l_tx[2];

	/*Store upper nibble*/
	data_u = (data & 0xF0);

	/*Store lower nibble*/
	data_l = ((data << 4) & 0xF0);

	/* Construct upper byte-> compatible for LCD*/
	data_u_tx[0] = data_u|BACKLIGHT|PIN_EN|PIN_RS;
	data_u_tx[1] = data_u|BACKLIGHT|PIN_RS;

	/* Construct lower byte-> compatible for LCD*/
	data_l_tx[0] = data_l|BACKLIGHT|PIN_EN|PIN_RS;
	data_l_tx[1] = data_l|BACKLIGHT|PIN_RS;

	/* Transmit upper nibble using I2C APIs*/
	if(HAL_I2C_IsDeviceReady(& hi2c1, I2C_SLAVE_ADDRESS, 1, 10) == HAL_OK)
		HAL_I2C_Master_Transmit(&hi2c1,I2C_SLAVE_ADDRESS, data_u_tx, 2, 100);

	/*Provide a delay */
	HAL_Delay(1);

	/* Transmit lower nibble using I2C APIs*/
	if(HAL_I2C_IsDeviceReady(& hi2c1, I2C_SLAVE_ADDRESS, 1, 10) == HAL_OK)
		HAL_I2C_Master_Transmit(& hi2c1,I2C_SLAVE_ADDRESS, data_l_tx, 2, 100);

    /*Provide a delay */
    HAL_Delay(5);
}





/**
 * @brief  Initializes LCD
 * @retval None
 */
void LCD_Init(void)
{
	/* Configure GPIOs */
	//GPIO_Config();

	/*Configure I2C */
//	I2C_Config();
	MX_I2C1_Init();
	/* Wait for 15ms */
	HAL_Delay(15);

	/*Function Set - As per HD44780U*/
	LCD_Send_Cmd(LCD_FUNCTION_SET1);

	/*Function Set -As per HD44780U*/
	LCD_Send_Cmd(LCD_FUNCTION_SET2);

	/*Set 4bit mode and 2 lines */
	LCD_Send_Cmd(LCD_4BIT_2LINE_MODE);

	/*Display on, cursor off*/
	LCD_Send_Cmd(0x0C);

	/* SET Row1 and Col1 (1st Line) */
	LCD_Send_Cmd(0x80);

	/*Clear Display*/
	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

}



/**
 * @brief Send Strings to LCD
 * @param str: pointer to strings
 * @retval None
 */
void LCD_Send_String(char *str)
{
	while (*str)
	{
		LCD_Send_Data(*str++);
	}
}


/**
 * @brief Clears screen first, then displays the given string
 * @param str: pointer to strings
 * @retval None
 */
void LCD_Clear_Then_Display(char *str)
{
	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	LCD_Send_String(str);
}



/**
 * @brief Display the strings on Line1
 * @param str: pointer to strings
 * @retval None
 */
void LCD_Send_String_On_Line1(char *str)
{
	LCD_Send_Cmd(LCD_SET_ROW1_COL1);
	LCD_Send_String(str);
}


/**
 * @brief Display the strings on Line2
 * @param str: pointer to strings
 * @retval None
 */
void LCD_Send_String_On_Line2(char *str)
{
	LCD_Send_Cmd(LCD_SET_ROW2_COL1);
	LCD_Send_String(str);
}



/********************************* LCD APIs - END ************************************/


