/*
 * pid.c
 *
 *  Created on: Feb 17, 2025
 *      Author: seken.durmaz
 */
#include "MainLogic.h"
#include "stm32l4xx_hal.h"
#include "CAN_Bytes_to_Float.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
extern uint32_t TxMailbox;

#define VEL_DB   0.05f
#define POS_DB   0.001f
#define CUR_DB   0.2f

#define EMA_ALPHA 0.3f   // 0.2–0.4 ideal


#define DEAD_BAND(x, db) ( (fabs(x) < (db)) ? 0.0f : (x) )

int Logic(void)
{
    new_pos_1 = f_m0_pos;
    new_pos_2 = f_m1_pos;
    new_vel_1 = f_m0_vel;
    new_vel_2 = f_m1_vel;
    new_cur_1 = f_m0_iq_setpoint;
    new_cur_2 = f_m1_iq_setpoint;

    // --- Ham farklar ---
    float raw_mov_1 = old_pos_1 - new_pos_1;
    float raw_mov_2 = old_pos_2 - new_pos_2;
    float raw_vel_1 = old_vel_1 - new_vel_1;
    float raw_vel_2 = old_vel_2 - new_vel_2;
    float raw_cur_1 = old_cur_1 - new_cur_1;
    float raw_cur_2 = old_cur_2 - new_cur_2;

    // --- DEAD BAND ---
    raw_mov_1 = DEAD_BAND(raw_mov_1, POS_DB);
    raw_mov_2 = DEAD_BAND(raw_mov_2, POS_DB);
    raw_vel_1 = DEAD_BAND(raw_vel_1, VEL_DB);
    raw_vel_2 = DEAD_BAND(raw_vel_2, VEL_DB);
    raw_cur_1 = DEAD_BAND(raw_cur_1, CUR_DB);
    raw_cur_2 = DEAD_BAND(raw_cur_2, CUR_DB);

    // --- EMA FILTER (zaman kararlılığı) ---
    movement_1 = EMA_ALPHA * raw_mov_1 + (1.0f - EMA_ALPHA) * movement_1;
    movement_2 = EMA_ALPHA * raw_mov_2 + (1.0f - EMA_ALPHA) * movement_2;

    Chc_Vel_1  = EMA_ALPHA * raw_vel_1 + (1.0f - EMA_ALPHA) * Chc_Vel_1;
    Chc_Vel_2  = EMA_ALPHA * raw_vel_2 + (1.0f - EMA_ALPHA) * Chc_Vel_2;

    Chc_Cur_1  = EMA_ALPHA * raw_cur_1 + (1.0f - EMA_ALPHA) * Chc_Cur_1;
    Chc_Cur_2  = EMA_ALPHA * raw_cur_2 + (1.0f - EMA_ALPHA) * Chc_Cur_2;

    // --- Debug ---
    if (b_SW_2)
    {
        printf(
          "Vel1: %.4f | Vel2: %.4f | Cur1: %.4f | Cur2: %.4f | Mov1: %.4f | Mov2: %.4f\r\n",
          Chc_Vel_1, Chc_Vel_2, Chc_Cur_1, Chc_Cur_2, movement_1, movement_2
        );
    }

    // --- Eski değerleri güncelle ---
    old_pos_1 = new_pos_1;
    old_pos_2 = new_pos_2;
    old_vel_1 = new_vel_1;
    old_vel_2 = new_vel_2;
    old_cur_1 = new_cur_1;
    old_cur_2 = new_cur_2;

    return 0;
}

