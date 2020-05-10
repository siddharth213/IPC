/*
 * CAN.H
 *
 *  Created on: May 10, 2020
 *      Author: sidhu
 */

#ifndef INC_CAN_H_
#define INC_CAN_H_


typedef struct  {
  uint32_t  id;                 // message bit identifier
  uint8_t  data_pkt[8];           // Data field
  uint8_t  len;                // Length of data field in bytes
  uint8_t  format;             // 0 - STANDARD, 1- EXTENDED IDENTIFIER
  uint8_t type;               // 0 - DATA FRAME, 1 - REMOTE FRAME
} CAN_msg;



#endif /* INC_CAN_H_ */
