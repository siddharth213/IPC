/*
 * engineData.h
 *
 *  Created on: May 3, 2020
 *      Author: Siddharth
 */

#ifndef SRC_ENGINEDATA_H_
#define SRC_ENGINEDATA_H_

#include "main.h"
#include "CAN.H"

#define MAX_RPM 6000
typedef struct
{
    uint16_t rpm;
	double engineTemp;
	uint8_t engine_fault_sts;

}EngineDataOut;

EngineDataOut * getenginedata(void);

void rx_data();







#endif /* SRC_ENGINEDATA_H_ */
