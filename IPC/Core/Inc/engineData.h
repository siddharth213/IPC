/*
 * engineData.h
 *
 *  Created on: May 3, 2020
 *      Author: Siddharth
 */

#ifndef SRC_ENGINEDATA_H_
#define SRC_ENGINEDATA_H_

#include "main.h"

#define MAX_RPM 6000


void getenginedata();

void rx_data();

typedef struct
{

	uint8_t data_pkt[8];

}ENGINE_DATA;


#endif /* SRC_ENGINEDATA_H_ */
