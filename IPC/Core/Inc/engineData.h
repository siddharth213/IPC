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


typedef struct  {
  uint32_t  id;                 // message bit identifier
  uint8_t  data_pkt[8];           // Data field
  uint8_t  len;                // Length of data field in bytes
  uint8_t  format;             // 0 - STANDARD, 1- EXTENDED IDENTIFIER
  uint8_t type;               // 0 - DATA FRAME, 1 - REMOTE FRAME
} CAN_msg;





#endif /* SRC_ENGINEDATA_H_ */
