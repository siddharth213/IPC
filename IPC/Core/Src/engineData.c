/*
 * engineData.c
 *
 *  Created on: May 3, 2020
 *      Author: sidhu
 */
#include "engineData.h"

ENGINE_DATA enginedata;

void getenginedata()
{
	rx_data();

	    uint16_t msg[2] = {0};
	    uint16_t   rpm = 0;
	    uint8_t engine_fault_sts = 0;
	    double engine_temp = 0;

	    msg[0] = (((uint16_t)enginedata.data_pkt[0]) & 0x001f) << 8;
	    msg[1] = (((uint16_t)enginedata.data_pkt[1]) & 0x00FF);

	    rpm = msg[0] | msg[1];

	    engine_temp = enginedata.data_pkt[2];
	    engine_fault_sts = enginedata.data_pkt[3];

}
void rx_data()
{
	uint16_t rpm_value = ((rand () % 6000) + 1);


	enginedata.data_pkt[0] = ((rpm_value >> 8) & 0x1f); //LSB Engine RPM
	enginedata.data_pkt[1] = (rpm_value & 0xff); //MSB Engine RPM
	enginedata.data_pkt[2] = 0xAb; //Temperature
	enginedata.data_pkt[3] = 0x00; // 0x00 - no fault, 0xFF - fault
}





#if 0
HAL_GPIO_EXTI_Callback(GPIO_Pin)
{
	rpm = 60*1000/(millis() - timeold);

	  timeold = millis();

}
#endif












