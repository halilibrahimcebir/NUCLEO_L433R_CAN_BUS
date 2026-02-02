#include "M1_PID.h"
#include <stdio.h>


void PID_Control_M1(float kp, float ki, float kd, float initialSetPoint)
{
	Kp_M1 = kp;
	Ki_M1 = ki;
	Kd_M1 = kd;
	setPoint_M1 = initialSetPoint;

}

float Calculate_M1(float currentValue)
{
	if(currentValue<=setPoint_M1)
	{
		Reset_M1();		  //Reset() or Reboot();
	}

	error_M1 = setPoint_M1 - currentValue;
	integral_M1 += error_M1;
	derivative_M1 = (error_M1 - previousError_M1);
	output_M1 = Kp_M1 * error_M1 + Ki_M1 * integral_M1 + Kd_M1 * derivative_M1;

    if(output_M1>0)
    {
    	output_M1 = 0;
    }
	if(output_M1<-20)
	{
    	output_M1 = -20;
	}


	previousError_M1 = error_M1;


	if (integral_M1 > 10)
	{
		integral_M1 = 10;
	}

	else if (integral_M1 < -10)
	{
		integral_M1 = -10;
	}

	output_M1 = output_M1 / 20.0f;
	final_out_1=M1_Power_Value*output_M1;
	return output_M1;
}

	void SetSetPoint_M1(float newSetPoint)
	{
		setPoint_M1 = newSetPoint;
	}
	void Reset_M1()
	{


			integral_M1 = 0;
			previousError_M1 = 0;
			error_M1 = 0;
			derivative_M1 = 0;
			output_M1=0;

	}

