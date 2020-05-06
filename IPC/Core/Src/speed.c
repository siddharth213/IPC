/* speed.c
   
*   created on: 4 May 2020
   
 *  Author : M Rajesh
   
   */

#include "speedometer.h"

/* Global Variables */
uint16_t g_tripOneCount = 0;
uint16_t g_tripTwoCount = 0;

/* This function monitor speed of vehicle 
   odometer count and trip-1 and trip 2 count */
   
void speed()
{
   
  /* Depending on input rpm  speed updates */
  uint16_t speed = rpm * RESOLUTION;  
  
  /* Local variables for odmeter count */
  uint16_t tempVar = 0;
  uint16_t countVal = 0;
  uint16_t odometerCount = 0;
  
  /*Local variables for trip-1 and trip-2 Count */
  uint16_t tripOneMeterCount = 0;
  uint16_t tripTwoMeterCount = 0;
  
  /* input switches for Reset trip-1 and trip-2 Count */
  uint16_t trip_1_Switch = 0;
  uint16_t trip_2_Switch = 0;
  
  
  for(tempVar = 0; tempVar <= rpm; tempVar++)
  {
    countVal = countVal + 1;
    
    /* for 43 rpm values one killo meter will count Odometer */ 
    if(countVal == 43)  
    {
      /* for odometer count */
      odometerCount = odometerCount + 1;
      
      /* for trip-1 count */
      tripOneMeterCount = tripOneMeterCount + 1;
      
      /* for trip-2 count */
      tripTwoMeterCount = tripTwoMeterCount + 1;
      
      
      /* for Reset trip-1 count */
      if((trip_1_Switch == 1 || tripOneMeterCount == 99))
      {
          
          if(tripOneMeterCount == 99)
          {
             g_tripOneCount = tripOneMeterCount;
          }
    
        tripOneMeterCount = 0;
      }
      
      /* for Reset trip-2 count */
       if((trip_2_Switch == 1 || tripTwoMeterCount == 999))
      {
          
          if(tripTwoMeterCount == 999)
          {
             g_tripTwoCount = tripTwoMeterCount;
          }
          
         tripTwoMeterCount = 0;
      }
      
      countVal = 0;
    }
  }
   
}

 
 
 
 
