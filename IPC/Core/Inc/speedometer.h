
#ifndef SRC_SPEEDOMETER_H_
#define SRC_SPEEDOMETER_H_


#include "main.h"
#include "engineData.h"
extern uint16_t rpm;
#define ONEKM 43
#define RESOLUTION (140/MAX_RPM)

void speed(EngineDataOut * engineSpeed);




#endif
