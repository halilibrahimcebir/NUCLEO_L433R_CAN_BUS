/*
 * Exo_Calibration.c
 * Exoskeleton Calibration Implementation
 *
 *  Created on: Feb 11, 2025
 *      Author: seken.durmaz
 */

#include "Exo_Calibration.h"
#include "CAN_Set_Messages.h"
#include "CAN_Querny_Sent.h"

void Exo_Calibration(bool SW_1, bool SW_2)
{
	if ((!SW_1) && (!SW_2))
	{
		if (f_m0_pos < 6 || f_m0_pos > -6 || f_m1_pos < 6 || f_m1_pos > -6)
		{
			Calibration_Fail = false;
		}
		else
		{
			Calibration_Fail = true;
		}
	}

	SW_1 = false;
	SW_2 = false;
}





