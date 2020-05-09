#include "telltales.h"
#include "main.h"

void servo_write(int angle)
{
	htim1.Instance->CCR1 = map(0,180,50,250,angle);
}

int map(int st1, int fn1, int st2, int fn2, int value)
{
    return (1.0*(value-st1))/((fn1-st1)*1.0) * (fn2-st2)+st2;
}
