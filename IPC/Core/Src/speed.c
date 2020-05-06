
#include "speedometer.h"

uint16_t g_tripOneCount=0;
uint16_t g_tripTwoCount=0;

void speed()
{
  
  uint16_t speed = rpm * RESOLUTION;  
  uint16_t tempVar = 0;
  uint16_t countVal = 0;
  uint16_t odometerCount = 0;
  
  
  uint16_t tripOneMeter=0;
  uint16_t tripTwoMeter=0;
  
  uint16_t trip_1_switch=0;
  uint16_t trip_2_switch=0;
  
  
  for(tempVar = 0; tempVar <= rpm; tempVar++)
  {
    countVal = countVal + 1;
    if(countVal == 43)  
    {
      odometerCount = odometerCount + 1;
      tripOneMeter = tripOneMeter + 1;
      tripTwoMeter = tripTwoMeter + 1;
      
      if((trip_1_switch == 1 || tripOneMeter == 99))
      {
          
          if(tripOneMeter==99)
          {
             g_tripOneCount = tripOneMeter;
          }
          tripOneMeter =0;
      }
      
      
       if((trip_2_switch == 1 || tripTwoMeter == 999))
      {
          
          if(tripTwoMeter == 999)
          {
             g_tripTwoCount = tripTwoMeter;
          }
          
          tripTwoMeter =0;
      }
      
      countVal = 0;
    }
  }
   
}

 
 
 
 
