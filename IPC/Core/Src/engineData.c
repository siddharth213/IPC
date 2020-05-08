/*
 * engineData.c
 *
 *  Created on: May 3, 2020
 *      Author: siddharth
 */
#include "engineData.h"

ENGINE_DATA enginedata;

uint16_t   rpm = 0;

/*This function decodes from CAN RX and store engine rpm */
void getenginedata()
{
	rx_data();

	    uint16_t msg[2] = {0};
	    uint8_t engine_fault_sts = 0;
	    uint8_t rawTemp = 0;
	    double engineTemp = 0;


	    /*Engine RPM decode*/
	    msg[0] = (((uint16_t)enginedata.data_pkt[0]) & 0x001f) << 8;
	    msg[1] = (((uint16_t)enginedata.data_pkt[1]) & 0x00FF);

	    rpm = msg[0] | msg[1];

	    if (rpm > MAX_RPM)
	    	rpm = MAX_RPM;

        /*Engine Temperature Decode*/
	    msg[2] = (((uint16_t)enginedata.data_pkt[2]) & 0x000f) << 8;
	    msg[3] = (((uint16_t)enginedata.data_pkt[3]) & 0x00FF);
	    rawTemp = msg[2] | msg[3];

	    engineTemp = (rawTemp * 3300) / 0xfff;
	    engineTemp /= 1000.0;
	    engineTemp -= 0.760; // Subtract the reference voltage at 25°C
	    engineTemp /= .0025; // Divide by slope 2.5mV
	    engineTemp += 25.0; // Add the 25°C



}

/*This function encodes engine data in to CAN TX data buffer and it is coming from ECM*/
void rx_data()
{
	uint16_t rpm_value = ((rand () % 6000) + 1);
	uint16_t engine_temp = ((rand () % 4095) + 1);


	enginedata.data_pkt[0] = ((rpm_value >> 8) & 0x1f); //LSB Engine RPM
	enginedata.data_pkt[1] = (rpm_value & 0xff); //MSB Engine RPM

	enginedata.data_pkt[2] = ((engine_temp >> 8) & 0x0f); //LSB Engine Temperature ADC value
	enginedata.data_pkt[3] = (engine_temp & 0xff); //MSB Engine Temperature ADC value

	enginedata.data_pkt[4] = 0x00; // 0x00 - no fault, 0xFF - fault
}





#if 0
HAL_GPIO_EXTI_Callback(GPIO_Pin)
{
	rpm = 60*1000/(millis() - timeold);

	  timeold = millis();

}
#endif












