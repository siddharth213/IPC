/*
 * ram_test.h
 *
 *  Created on: May 12, 2020
 *      Author: Kala
 */

#ifndef RAM_TEST_H_
#define RAM_TEST_H_

/*
 * Define NULL pointer value.
 */
#ifndef NULL
#define NULL  (void *) 0
#endif

/*
 * Set the data bus width.
 */
typedef unsigned long datum;

/*
 * Function prototypes.
 */
datum   ram_Test_DataBus(volatile datum * address);
datum * ram_Test_AddressBus(volatile datum * baseAddress, unsigned long nBytes);
datum * ram_Test_Device(volatile datum * baseAddress, unsigned long nBytes);


#endif /* RAM_TEST_H_ */
