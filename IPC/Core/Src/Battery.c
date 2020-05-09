
#include "main.h"

void battery_info()
{

  /* 0 to 255 --> 0%
     256 to 1023 --> 25%
     1024 to 2047 --> 50%
     2048 to 3071 --> 75%
     3072 to 4095 -->100%  */
  
  uint8_t batteryStatus[5] = {0,25,50,75,100};
  
  uint8_t batteryPercentage = 0;
  
  uint16_t adcValue = ((rand () % 4095) + 1);

  
  if(( adcValue > 0 ) && ( adcValue <= 255 ))
  {
  batteryPercentage = batteryStatus[0];
  }
  
   else if(( adcValue >= 256 ) && ( adcValue <= 1023 ))
  {
  batteryPercentage = batteryStatus[1];
  }
  
   else if(( adcValue >= 1024 ) && ( adcValue <= 2047 ))
  {
  batteryPercentage = batteryStatus[2];
  }
  
   else if(( adcValue > 2048 ) && ( adcValue <= 3071 ))
  {
  batteryPercentage = batteryStatus[3];
  }
  
   else if(( adcValue > 3072 ) && ( adcValue <= 4096 ))
  {
  batteryPercentage = batteryStatus[4];
  }


}
