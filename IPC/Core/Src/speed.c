
#include "speedometer.h"
void speed()
{
  
  uint16_t speed = rpm * RESOLUTION;
  
  uint16_t tempVar = 0;
  uint16_t countVal = 0;
  uint16_t odometerCount = 0;
  
  for(tempVar = 0; tempVar <= rpm; tempVar++)
  {
    countVal = countVal + 1;
    if(countVal == 43)  
    {
      odometerCount = odometerCount + 1;
      countVal = 0;
    }
  }
   
}

 
 
 
 
