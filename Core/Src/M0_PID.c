#include "M0_PID.h"
#include <stdio.h>


void PID_Control_M0(float kp, float ki, float kd, float initialSetPoint)
{
	Kp_M0 = kp;
	Ki_M0 = ki;
	Kd_M0 = kd;
	setPoint_M0 = initialSetPoint;

}

float Calculate_M0(float currentValue)
{
	if(currentValue>=setPoint_M0)
	{
		Reset_M0();		  //Reset() or Reboot();
	}

	error_M0 = setPoint_M0 - currentValue;
	integral_M0 += error_M0;
	derivative_M0 = (error_M0 - previousError_M0);
	output_M0 = Kp_M0 * error_M0 + Ki_M0 * integral_M0 + Kd_M0 * derivative_M0;

    if(output_M0<0)
    {
    	output_M0 = 0;
    }
	if(output_M0>20)
	{
    	output_M0 = 20;
	}


	previousError_M0 = error_M0;


	if (integral_M0 > 10)
	{
		integral_M0 = 10;
	}

	else if (integral_M0 < -10)
	{
		integral_M0 = -10;
	}

	output_M0 = output_M0 / 20.0f;
	final_out_0=M0_Power_Value*output_M0;
	return output_M0;
}

	void SetSetPoint_M0(float newSetPoint)
	{
		setPoint_M0 = newSetPoint;
	}
	void Reset_M0()
	{


			integral_M0 = 0;
			previousError_M0 = 0;
			error_M0 = 0;
			derivative_M0 = 0;
			output_M0=0;

	}

