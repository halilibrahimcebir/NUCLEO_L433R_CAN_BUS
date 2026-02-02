/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "variables.h"
#include <stdio.h>


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan1;

I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_rx;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_CAN1_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)

{


		  HAL_StatusTypeDef status = HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, Received_Data);

		    if (status != HAL_OK)
		    {
		        printf("CAN receiver system error!\n");
		    }
		    else
		    {
		    	if(CAN_Adress==999&&RxHeader.IDE == CAN_ID_STD)
		    	{


		    				CAN_Adress = RxHeader.StdId;  // 11-bit ID







		    	//   	printf("CAN!%lu\n",RxHeader.StdId);
		    			if (RxHeader.DLC == 8) // Gelen mesajın veri uzunluğu 8 byte ise
		    			{

		            uint32_t stdIdToIndex[] = { 0x201, 0x203, 0x204, 0x205, 0x209, 0x214,
		                                        0x301, 0x303, 0x304, 0x305, 0x309, 0x314,0x405,0x406};

		            size_t stdIdToIndexSize = sizeof(stdIdToIndex) / sizeof(stdIdToIndex[0]);

		            for (size_t i = 0; i < stdIdToIndexSize; i++)
		            {
		                if (RxHeader.StdId == stdIdToIndex[i])
		                {

		                    size_t messageSize = sizeof(CAN_Messages[i]) / sizeof(CAN_Messages[i][0]);
		                    size_t receivedDataSize = sizeof(Received_Data) / sizeof(Received_Data[0]);


		                    if (receivedDataSize <= messageSize)
		                    {
		                        for (size_t j = 0; j < receivedDataSize; j++)
		                        {
		                            CAN_Messages[i][j] = Received_Data[j];


		                        }
		                    }
		                    else
		                    {
		                        printf("Verinin boyutu mesaj dizisinin boyutunu aştı!\n");
		                        E_Can_Fault=true;
		                    }
		                    break;
		                }
		            }
		        }
		        else
		        {
		            printf("Gelen mesajın DLC'si 8 değil!\n");
		            E_Can_Fault=true;
		        }

		    	}
		  		    }


}
void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan)
{



    if (hcan->Instance == CAN1)
    {
    	 //  printf("Gonderim tamamlandi0\n");
    	   txInProgress = 0;
    	          txQueueHead = (txQueueHead + 1) % CAN_TX_QUEUE_SIZE;
    	          CAN_SendNextFromQueue();
    }

}
void HAL_CAN_TxMailbox1CompleteCallback(CAN_HandleTypeDef *hcan)
{



    if (hcan->Instance == CAN1)
    {
    	   printf("Gonderim tamamlandi1\n");
    	   txInProgress = 0;
    	          txQueueHead = (txQueueHead + 1) % CAN_TX_QUEUE_SIZE;
    	          CAN_SendNextFromQueue();
    }

}
void HAL_CAN_TxMailbox2CompleteCallback(CAN_HandleTypeDef *hcan)
{



    if (hcan->Instance == CAN1)
    {
    	   printf("Gonderim tamamlandi2\n");
    	   txInProgress = 0;
    	          txQueueHead = (txQueueHead + 1) % CAN_TX_QUEUE_SIZE;
    	          CAN_SendNextFromQueue();
    }

}






/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

CAN_RxHeaderTypeDef RxHeader;
CAN_TxHeaderTypeDef TxHeader;
uint8_t Received_Data[8];
uint32_t TxMailbox;
size_t totalAdressAmount = sizeof(CAN_Adresler) / sizeof(CAN_Adresler[0]);






float previous_f_M1_pos = 0.0f;  // Bir önceki değer
float delta_pos_M1 = 0.0f;          // Fark

float previous_f_M0_pos = 0.0f;  // Bir önceki değer
float delta_pos_M0 = 0.0f;          // Fark

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */


	void DWT_Init(void) {
	    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;  // DWT birimini etkinleştir
	    DWT->CYCCNT = 0;  // Sayaç sıfırlama
	    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;  // Sayaç başlat
	}



  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */


	HAL_Init();

  /* USER CODE BEGIN Init */

  CAN_Com_Init();
  GPIO_Init();  // GPIO'yu başlat
  DWT_Init();
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_CAN1_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
 // HAL_UART_Receive_DMA(&huart1, Rx_Buffer, 1);
  //HAL_UART_Receive_IT(&huart1, Rx_Buffer, 1);
  HAL_CAN_Start(&hcan1);
  HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
  HAL_CAN_ActivateNotification(&hcan1, CAN_IT_TX_MAILBOX_EMPTY);
  HAL_TIM_Base_Start(&htim2);




  HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);  // Kesme önceliğini ayarla
  HAL_NVIC_EnableIRQ(TIM2_IRQn);  // Kesmeyi etkinleştir
  S_Should_Reset=true;
  Calibration_Fail=true;
  uint32_t last_heartbeat_time = 0;

  const uint32_t heartbeat_interval_ms = 150; // 1 saniye
  const uint32_t Check_Panlen_Life = 3000; // 1 saniye


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	   F_SW_Read();
	   F_Can_Seperate();
	 //   F_Panel_Alive();
	   // BPM_Calibration( b_SW_1, b_SW_2);
	    // F_BPM_BPM_Start_Up_Chk();
	    //  F_BPM_Logic();
	    // F_BPM_Stop_Seq();
     Exo_Calibration(b_SW_1,b_SW_2);



	   F_Starup_Check();
	   S_System_Check();






	    uint32_t now = HAL_GetTick();
	    if (now - last_heartbeat_time >= heartbeat_interval_ms)
	    {
	        last_heartbeat_time = now;
	        send_heartbeat();  // CAN, UART veya başka bir kanal üzerinden alive mesajı

	    }
	  /*  if (now - last_heartbeat_time >= Check_Panlen_Life)
		    {
		        last_heartbeat_time = now;
		        send_heartbeat();  // CAN, UART veya başka bir kanal üzerinden alive mesajı

		    }
*/









if(!S_Should_Reset)
{



				  if(b_Exo_StartUp)
				  {
					  uint8_t Float_buffer[8];


					 if (f_m1_pos_for_PID!=0 && f_m0_pos_for_PID!=0 )
						{
						  Logic();


						 if(abs(f_m0_pos_for_PID)-abs(f_m1_pos_for_PID)>50&&b_Mode_With_Move_Can==0)
						 									  {
							 b_Mode_With_Move_Can+=1;
							 b_Mode_First_Trig=true;
						 									  }
						 else if(abs(f_m0_pos_for_PID)-abs(f_m1_pos_for_PID)<10&&abs(f_m0_pos_for_PID)-abs(f_m1_pos_for_PID)>0)
						 {
							 b_Mode_First_Trig=false;
						 }
						 if(b_Mode_With_Move_Can==1&& !b_Mode_First_Trig)
						 {
							 if(abs(f_m0_pos_for_PID)-abs(f_m1_pos_for_PID)>50)
													 									  {
														 b_Mode_With_Move_Can+=1;
													 									  }
							 else if(abs(f_m1_pos_for_PID)-abs(f_m0_pos_for_PID)>50 )
							 {
								 b_Mode_With_Move_Can-=1;
							 }
						 }
						 if(abs(f_m1_pos_for_PID)-abs(f_m0_pos_for_PID)>50&&b_Mode_With_Move_Can==2)
											 									  {
							 b_Mode_With_Move_Can-=1;
							 b_Mode_First_Trig=true;
											 									  }
						 else if(abs(f_m1_pos_for_PID)-abs(f_m0_pos_for_PID)<10&& abs(f_m1_pos_for_PID)-abs(f_m0_pos_for_PID)>0)
						 {
							 b_Mode_First_Trig=false;
						 }


						 if(b_Mode_With_Move_Can==2)
						 {
							 b_Mode_With_Move=true;
						 }
						 else if(b_Mode_With_Move_Can==0)
						 {
							 b_Mode_With_Move=false;
						 }
						  m0_Sigmoid_result= predict_motor_state_M0(Chc_Vel_1,movement_1,Chc_Cur_1);
						  m0_Sigmoid_result_Rev= Reverse_predict_motor_state_M0(f_m0_vel,movement_1,f_m0_iq_setpoint);


										  if (m0_Sigmoid_result > 0.75) {

											  //printf("KalkisM0 \n");
											  pid_can_run_1=true;
																  } else if (m0_Sigmoid_result < 0.55) {

														//	  printf("DurusM0 \n");
																	  pid_can_run_1=false;
																  }
						  m1_Sigmoid_result= predict_motor_state_M1(Chc_Vel_2,movement_2,Chc_Cur_2);
						  m1_Sigmoid_result_Rev= Reverse_predict_motor_state_M1(f_m1_vel,movement_1,f_m1_iq_setpoint);

						  if (m1_Sigmoid_result > 0.75) {
													 // printf("KalkisM1 \n");
													  pid_can_run_2=true;
												  } else if (m1_Sigmoid_result <0.45) {
													//  printf("DurusM1 \n");
													  pid_can_run_2=false;
												  }

						  PID_Control_M0(0.5,0.5,0.01,0);
						  Calculate_M0(f_m0_pos_for_PID);
						  PID_Control_M1(0.5,0.05,0.01,0);
						  Calculate_M1(f_m1_pos_for_PID);







							  //	CAN_Set_Bytes_to_Float(-0.1, 0, 0x30e);
						  if(b_Mode_With_Move)
						  {

								  if(m1_Sigmoid_result_Rev <0.7 && m0_Sigmoid_result_Rev >= 0.3 && M1_Walking_Steps!=1)
								  	  {
									  M1_Walking_Steps=1;
									  if(abs(f_m0_pos_for_PID)-abs(f_m1_pos_for_PID)>7)
									  {
										  CAN_Set_Bytes_to_Float (0.1,0,Float_buffer);

										 									  	  CAN_QueueMessage(0x30e , Float_buffer, 4);
										 									  	  printf("M0 Adım onde \n");
									  }



									  	  CAN_Set_Bytes_to_Float (0,0,Float_buffer);

									  	  CAN_QueueMessage(0x20e , Float_buffer, 8);
								  	  } if(m1_Sigmoid_result_Rev >=0.7&& M1_Walking_Steps!=2)
									  {
								  		M1_Walking_Steps=2;
								  											  CAN_Set_Bytes_to_Float (0,0,Float_buffer);

								  											  CAN_QueueMessage(0x30e , Float_buffer, 4);

									  }





								  if(m0_Sigmoid_result_Rev < 0.7 && m1_Sigmoid_result_Rev >=0.3&& M0_Walking_Steps!=1)
								  {
									  M0_Walking_Steps=1;
									  if(abs(f_m1_pos_for_PID)-abs(f_m0_pos_for_PID)>7)
									 									  {
										  CAN_Set_Bytes_to_Float (-0.1,0,Float_buffer);

																			  CAN_QueueMessage(0x20e , Float_buffer, 4);
																			  	  printf("M1 Adım onde \n");
									 									  }


									  	  CAN_Set_Bytes_to_Float (0,0,Float_buffer);
									  	  CAN_QueueMessage(0x30e , Float_buffer, 8);
								  }
								   if(m0_Sigmoid_result_Rev >= 0.7 &&  M0_Walking_Steps!=2)
								  {
									   M0_Walking_Steps=2;
									  CAN_Set_Bytes_to_Float (0,0,Float_buffer);

									  CAN_QueueMessage(0x20e , Float_buffer, 4);

								  }









						  }
						  else
						  {
								 if(f_m0_pos_for_PID>-1||f_m1_pos_for_PID<1 ||f_m0_pos_for_PID<-130||f_m1_pos_for_PID>130 )
													  {
									 	 	 	 	 	// if(Lift_Steps!=1)

									 	 	 	 	 	 Lift_Steps=1;

									 	 	 	 	 	 Reset_M0();

									 	 	 	 	 	 CAN_Set_Bytes_to_Float (0.0,0,Float_buffer);

									 	 	 	 	 	 CAN_QueueMessage(0x20e , Float_buffer, 8);
									 	 	 	 	 	 Reset_M1();

									 	 	 	 	 	 CAN_Set_Bytes_to_Float (0.0,0,Float_buffer);
									 	 	 	 	 	 CAN_QueueMessage(0x30e , Float_buffer, 8);


									 	 	 	 	 Desire_Of_Lift=0;






														 	 }







													  else
													  {

														  if(pid_can_run_1&& pid_can_run_2)
															  {
															 if(Desire_Of_Lift>0)
															  {
																	 CAN_Set_Bytes_to_Float (final_out_0,0,Float_buffer);

																	 CAN_QueueMessage(0x20e , Float_buffer, 4);
																	 CAN_Set_Bytes_to_Float (final_out_1,0,Float_buffer);
																	 CAN_QueueMessage(0x30e , Float_buffer, 4);
																        printf("Out_0: %.4f |Out_1: %.4f |",output_M0,output_M1);
															  }
															  Desire_Of_Lift=Desire_Of_Lift+1;


																 Lift_Steps=0;


															  }
														  	  else
														  	  {
														  		Desire_Of_Lift=0;
														  		  Lift_Steps=2;
																			 if(f_m0_pos_for_PID<-1&&f_m1_pos_for_PID>1 )
																		{
																			 Reset_M0();
																			 Reset_M1();

																			 CAN_Set_Bytes_to_Float (0,0,Float_buffer);
																			 CAN_QueueMessage(0x20e , Float_buffer, 4);

																			 CAN_Set_Bytes_to_Float (-0,0,Float_buffer);

																			 CAN_QueueMessage(0x30e , Float_buffer, 4);
																																			 }





																						// printf("Sürekli hareket \n");

														  	  }



													  }







						  }
							f_m1_pos_for_PID=0.0f;
							f_m0_pos_for_PID=0.0f;
					}

				  }
				  else if(Calibraion_For_Profile)
				  {
					  if(movement_1>7&&movement_2>7)
					  {
						  printf("");
					  }
				  }


		  }




  	  	  }

}

static inline int32_t unpack_i32_from_8(const uint8_t in[8]) {
    int32_t v = 0;
    memcpy(&v, in, 4);  // ilk 4 byte int32_t
    return v;           // işaret korunur (two's complement)
}



void send_heartbeat()
{
	  uint8_t Alive_Buf[8];


		  if(S_Should_Reset)
		  {
			  if(Calibration_Fail)
			 		  {
			 			  CAN_Set_Signed_int32(0, 1, 8, Alive_Buf);
			 			 			 CAN_QueueMessage(0x500, Alive_Buf, 8);
			 		  }
			  else
			  {
				  CAN_Set_Signed_int32(0, 0, 8, Alive_Buf);
					 CAN_QueueMessage(0x500, Alive_Buf, 8);
			  }

		  }
		  else if(b_Exo_StartUp&&b_Mode_With_Move)
		  {
			  CAN_Set_Signed_int32(3, 0, 8, Alive_Buf);
			  		 			 CAN_QueueMessage(0x500, Alive_Buf, 8);
		  }
		  else if(!b_Exo_StartUp&&b_Mode_With_Move)
				  {
					  CAN_Set_Signed_int32(4, 0, 8, Alive_Buf);
								 					 		 CAN_QueueMessage(0x500, Alive_Buf, 8);
				  }
		  else if(b_Exo_StartUp)
		  {
			  CAN_Set_Signed_int32(1, 0, 8, Alive_Buf);
			 			  		 			 CAN_QueueMessage(0x500, Alive_Buf, 8);
		  }
		  else if(!b_Exo_StartUp)
				  {
			  CAN_Set_Signed_int32(2, 0, 8, Alive_Buf);
			 					 		 CAN_QueueMessage(0x500, Alive_Buf, 8);
				  }






   // HAL_CAN_AddTxMessage(&hcan1, &txHeader, txData, &txMailbox);
}
void send_Batary_Req()
{
	  uint8_t Alive_Buf[8];


	  CAN_Send_Extended(0x400FF80, Alive_Buf, 8);


   // HAL_CAN_AddTxMessage(&hcan1, &txHeader, txData, &txMailbox);
}

  /* USER CODE BEGIN 6 */
void F_SW_Read(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10,1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11,1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14,1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15,1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12,1);

	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0))
	{
		b_SW_1 = true;
	}
	else
	{
		b_SW_1 = false;
	}
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2))
		{
		b_SW_2 = true;
		}
	else
	{
		b_SW_2 = false;

	}

}
void F_Can_Seperate(void)
{

	  if(CAN_Adress!=999)
			  {

				  uint8_t* message = CANN_Get_Message(CAN_Adress);

				  CAN_64to32values = CANN_64to32(message);

				  if (CAN_Adress==(uint32_t)0x101)
												  {
					  F_BPM_Start(true);

												  }
								  if (CAN_Adress==(uint32_t)0x102)
																  {
									  F_BPM_Stop(true);

																  }
								  if (CAN_Adress==(uint32_t)0x103)
																  {
									  	  printf("Reset");
									  F_BPM_Reset(true);

															}
								  if (CAN_Adress==(uint32_t)0x400)
																  {

									  Panel_Life_Error=false;
									  Panel_Life_Counter=0;

																  }

				  if (CAN_Adress==(uint32_t)0x401)
								  {
					  F_Start_Exo(true);

								  }
				  if (CAN_Adress==(uint32_t)0x402)
												  {
					  F_Stop_Exo(true);

												  }
				  if (CAN_Adress==(uint32_t)0x403)
												  {

					  System_Reset(true);
					  Reset_Ack=false;
											}
				  if (CAN_Adress==(uint32_t)0x405)
																  {

					  Panel_Power_Value=bytesToFloat((uint8_t*)&CAN_64to32values.value1);
					  M1_Power_Value=Panel_Power_Value;
					  M0_Power_Value=Panel_Power_Value;

					  Panel_Battery_Lev=bytesToFloat((uint8_t*)&CAN_64to32values.value2);


															}



				  if (CAN_Adress==(uint32_t)0x201)
				  {
					  	  	  i_m0_current_state=(CAN_64to32values.value2 )  & 0xFF;
				  }
				  else if (CAN_Adress==0x203)
				  {
							  if ((CAN_64to32values.value1 != 0) && (CAN_64to32values.value1 != 0))
							  {
								  printf("Axis 0'da Motor hatası!\n");
								  CANN_Motor0_Error(CAN_64to32values);
								  i_m0_Motor_Error = CAN_64to32values.value1+CAN_64to32values.value1;
							  }
							  else
							  {
								  i_m0_Motor_Error=0;
							  }
				  }
				  /*
				  else if (CAN_Adress==0x204)
				  {
							  if ((CAN_64to32values.value1 != 0) && (CAN_64to32values.value2 != 0))
							  {
								  printf(" Axis 0'da encoder hatası!\n");
								  CANN_Encoder0_Error(CAN_64to32values);
								  i_m0_Encoder_Error = CAN_64to32values.value1+CAN_64to32values.value1;

							  }
							  else
							  {
								  i_m0_Encoder_Error=0;
							  }
				  }
				  else if (CAN_Adress==0x205)
				  {
							  if ((CAN_64to32values.value1 != 0) && (CAN_64to32values.value2 != 0))
							  {
								  printf("Axis 0'da sensorless hatası!\n");
								  CAN_Sensorless0_Error(CAN_64to32values);
								  i_m0_Sensorless_Error = CAN_64to32values.value1+CAN_64to32values.value1;
							  }
							  else
							  {
								  i_m0_Sensorless_Error=0;
							  }
				  }
				  */
				  else if (CAN_Adress==0x406)
				 				  {



					//  Panel_Mode_Value= unpack_i32_from_8(CAN_64to32values.value1);


					  Panel_Mode_Value=(CAN_64to32values.value1)& 0xFF;
					   if(Panel_Mode_Value==1)
					  {Mode_Walk=true;}
					  else
					  {Mode_Walk=false;}
					  Panel_Status_Value=(CAN_64to32values.value2)& 0xFF;


				 				  }

				  else if (CAN_Adress==521)
				  {

					  	  	  f_m0_pos=bytesToFloat((uint8_t*)&CAN_64to32values.value1);
					  	  	 f_m0_pos=5.625*f_m0_pos;
					  	  	f_m0_pos_for_PID=f_m0_pos;
					  	  f_m0_pos_for_Alive=f_m0_pos;
							  f_m0_vel=bytesToFloat((uint8_t*)&CAN_64to32values.value2);
				  }
				  else if (CAN_Adress==532)
				  {

					  	  	  f_m0_iq_setpoint = bytesToFloat((uint8_t*)&CAN_64to32values.value1);
					  	  	  f_m0_iq_measured = bytesToFloat((uint8_t*)&CAN_64to32values.value2);

				  }
				  else if (CAN_Adress==0x301)
				  {

					  	  	  i_m1_current_state=(CAN_64to32values.value2)& 0xFF;
				  }

				  else if (CAN_Adress==0x303)
				  {
					  	  	  if ((CAN_64to32values.value1 != 0) && (CAN_64to32values.value2 != 0))
							  {
								  printf("Axis 1'de Motor hatası!\n");
								  CANN_Motor1_Error(CAN_64to32values);
								  i_m1_Motor_Error = CAN_64to32values.value1+CAN_64to32values.value1;
							  }
							  else
							  {
								  i_m1_Motor_Error=0;
							  }
				  }
				  /*
				  else if (CAN_Adress==0x304)
				  {
					  	  	  if ((CAN_64to32values.value1 != 0) && (CAN_64to32values.value2 != 0))
							  {
								  printf("Axis 1'de encoder hatası!\n");
								  CANN_Encoder1_Error(CAN_64to32values);
								  i_m1_Encoder_Error = CAN_64to32values.value1+CAN_64to32values.value1;
							  }
							  else
							  {
								  i_m1_Encoder_Error=0;
							  }
				  }
				  else if (CAN_Adress==0x305)
				  {
							  if ((CAN_64to32values.value1 != 0) && (CAN_64to32values.value2 != 0))
							  {
								  printf("Motor 1' de hata!\n");
								  CAN_Sensorless1_Error(CAN_64to32values);
								  i_m1_Sensorless_Error = CAN_64to32values.value1+CAN_64to32values.value1;
							  }
							  else
							  {
								  i_m1_Sensorless_Error=0;
							  }
				  }
				  */
				  else if (CAN_Adress==777)
				  {

							  f_m1_pos=bytesToFloat((uint8_t*)&CAN_64to32values.value1);
							  f_m1_pos=5.625*f_m1_pos;
							 	f_m1_pos_for_PID=f_m1_pos;
								  f_m1_pos_for_Alive=f_m1_pos;
							  f_m1_vel=bytesToFloat((uint8_t*)&CAN_64to32values.value2);


				  }
				  else if (CAN_Adress==788)
				  {


							  f_m1_iq_measured=bytesToFloat((uint8_t*)&CAN_64to32values.value2);
							  f_m1_iq_setpoint=bytesToFloat((uint8_t*)&CAN_64to32values.value1);
				  }
				  else
				  {

					 //E_Can_Fault=true;
				  }

				  CAN_Driver_Error = i_m0_Motor_Error+i_m1_Motor_Error+i_m0_Encoder_Error+i_m1_Encoder_Error+i_m1_Sensorless_Error+i_m0_Sensorless_Error;
				  if(CAN_Driver_Error>0)
				  {
					  CAN_Driver_Error=true;
				  }
			  }
	  CAN_Adress=999;

}

void F_Starup_Check(void)
{

	    if(i_m1_current_state==8&&i_m0_current_state==8&&b_Exo_StartUp==false)
						     {
		   	   	   	   	   	   	   	   	 new_pos_1 = f_m0_pos;
		   								new_pos_2 = f_m1_pos;
		   								old_pos_1 = new_pos_1;
		   								old_pos_2 = new_pos_2;
		   								b_Exo_StartUp = true;

						     }


	   else if(i_m1_current_state!=8||i_m0_current_state!=8)
	   {
		 	 b_Exo_StartUp = false;

	   }



}
void F_BPM_BPM_Start_Up_Chk()
{
	if(i_m0_current_state==8&& f_m0_pos > -4.0 &&BPM_Start_Up==false&&BPM_Start_req)
			{
				BPM_Start_Up=true;
				BPM_Start_req=false;
			}
}
void F_BPM_Logic()
{

		if(BPM_Start_Up)
		{
			if(f_m0_pos>-6.0 && BPM_Forward==false)
			{
				BPM_Forward=true;
				BPM_Reverse=false;
				 F_BPM_Forward();
			}
			if(f_m0_pos<-1070.0&& BPM_Reverse==false)
						{
							BPM_Forward=false;
							BPM_Reverse=true;
							 F_BPM_Reverse();
						}
		}


}
void F_BPM_Forward()
{
	  uint8_t Float_buffer[8];
	  CAN_Set_Bytes_to_Float (-192.0,0,Float_buffer);

								 CAN_QueueMessage(0x20c , Float_buffer, 4);
}
void F_BPM_Reverse()
{
	  uint8_t Float_buffer[8];
		  CAN_Set_Bytes_to_Float (0.0,0,Float_buffer);

									 CAN_QueueMessage(0x20c , Float_buffer, 4);
}
void F_BPM_Stop_Seq()
{
	  uint8_t buf2[8];
	if(b_BPM_Stopped)
	{
		if(f_m0_pos>-4)
		{
			CAN_Set_Signed_int32(1, 0, 8, buf2);
										 CAN_QueueMessage(0x207, buf2, 4);
										 b_BPM_Stopped=false;
		}

	}
}

void F_BPM_Start(bool Start_Req)
{
	 if(i_m0_current_state==1&&BPM_Calibration_Fail==false)
								     {
			 HAL_Delay(10);

				  uint8_t buf2[8];

				 			  uint8_t buf4[8];





				  CAN_Set_Signed_int32(8, 0, 8, buf2);
				 CAN_QueueMessage(0x207, buf2, 4);

				  CAN_Set_Signed_int32(3, 5, 8, buf4);
							 CAN_QueueMessage(0x20b, buf4, 8);

							 i_m0_current_state=9;




						BPM_Start_req=true;

								     }
}
void F_BPM_Stop(bool Stop_Req)
{


					  uint8_t buf2[8];

					  BPM_Reverse=false;
					  BPM_Forward=false;

					  b_BPM_Stopped=true;
					  CAN_Set_Bytes_to_Float (0.00,0,buf2);
					  CAN_QueueMessage(0x20c, buf2, 4);
						 BPM_Start_Up=false;





}
void F_BPM_Reset(bool Reset_Req)
{
		printf("BPM Reset");
					uint8_t buffer2[8];




					  BPM_Reverse=false;
					  BPM_Forward=false;

					CAN_Set_Signed_int32(3, 0, 8, buffer2);
					CAN_QueueMessage(0x207 , buffer2, 4);


					HAL_Delay(10000);






									CAN_Set_Signed_int32(0, 0, 8, buffer2);
									CAN_QueueMessage(0x219 , buffer2, 4);

					i_m0_current_state=9;
					 BPM_Start_Up=false;

}


void BPM_Calibration(bool SW_1,bool SW_2)
{


			if((SW_1) && (SW_2)&&!BPM_Forward&&!BPM_Reverse&&!BPM_Start_req)
			{
				if( f_m0_pos >-4 )
								{
					BPM_Calibration_Fail=false;
								}
				else
								{
					if(!b_BPM_Stopped)
					{
						BPM_Calibration_Fail=true;
					}

					//F_BPM_Stop(true);
								}




			}










			 SW_1=false;
			 SW_2=false;
}


void F_Panel_Alive()
{
	if(Panel_Life_Counter>=10000&&!Panel_Life_Error)
	{
		Panel_Life_Error=true;
	}
	if(Panel_Life_Counter<10001)
	{
		Panel_Life_Counter+=1;
	}
}

void F_Start_Exo(bool Panel_Star )
{

	 if(i_m0_current_state==1 &&i_m1_current_state==1)
							     {
		 HAL_Delay(10);
		  uint8_t buf1[8];
			  uint8_t buf2[8];
			  uint8_t buf3[8];
			 			  uint8_t buf4[8];
			  CAN_Set_Signed_int32(8, 0, 8, buf1);
			 CAN_QueueMessage(0x207, buf1, 4);

			 CAN_Set_Signed_int32(1, 1, 8, buf3);
						 CAN_QueueMessage(0x20b, buf3, 8);

			  CAN_Set_Signed_int32(8, 0, 8, buf2);
			 CAN_QueueMessage(0x307, buf2, 4);

			  CAN_Set_Signed_int32(1, 1, 8, buf4);
						 CAN_QueueMessage(0x30b, buf4, 8);
						 i_m0_current_state=9;
						 i_m0_current_state=9;
							     }

	// HAL_Delay(100);


}

void F_Stop_Exo(bool Panel_Stop)
{
	if(i_m0_current_state==8 &&i_m1_current_state==8)
								     {
		  uint8_t buf1[8];
				  uint8_t buf2[8];
				 CAN_Set_Signed_int32(1, 0, 8, buf1);
				 CAN_QueueMessage(0x207, buf1, 4);


				 CAN_Set_Signed_int32(1, 0, 8, buf2);
				 CAN_QueueMessage(0x307, buf2, 4);


								     }

}
void S_System_Check(void)
{

	if(CAN_Driver_Error||E_Can_Fault||E_System_Fault||Calibration_Fail)
	{
		E_Exo_Fault=true;
		b_Exo_StartUp=false;
	}
	if(E_EMG_Pressed||E_Exo_Fault)
	{
		S_Should_Reset=true;

	}
	if(S_Should_Reset&&E_EMG_Status==false)
	{




				Can_Reset=true;


	}
	else
	{
		Can_Reset=false;
	}

	if(S_Should_Reset==false)
	{


		//Uart_Start=false;


	}


}

void System_Reset(bool Panel_Reset)
{
	if(Can_Reset)
	{



			HAL_CAN_Stop(&hcan1);
			HAL_CAN_DeInit(&hcan1);
			MX_CAN1_Init();   // Bu fonksiyon CubeMX tarafından oluşturulmuş olmalı
			HAL_CAN_Start(&hcan1);
			  uint8_t buffer1[8];
							uint8_t buffer2[8];
							if(Calibration_Fail)
							{


				CAN_Set_Signed_int32(3, 0, 8, buffer1);
				CAN_QueueMessage(0x207 , buffer1, 4);




				CAN_Set_Signed_int32(3, 0, 8, buffer2);
				CAN_QueueMessage(0x307 , buffer2, 4);


				HAL_Delay(10000);
				CAN_Set_Signed_int32(0, 0, 8, buffer1);
													CAN_QueueMessage(0x219 , buffer1, 4);




													CAN_Set_Signed_int32(0, 0, 8, buffer2);
													CAN_QueueMessage(0x319 , buffer2, 4);
									i_m0_current_state=9;
									i_m1_current_state=9;

							}



							CAN_Driver_Error=false;
								E_Can_Fault=false;
								E_Uart_Fault=false;
								E_System_Fault=false;
								E_Exo_Fault=false;
								E_EMG_Pressed=false;
								S_Should_Reset=false;
								Calibration_Fail=false;




	}




}
  /* USER CODE END 6 */






  /* USER CODE END 3 */


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CAN1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN1_Init(void)
{

  /* USER CODE BEGIN CAN1_Init 0 */

  /* USER CODE END CAN1_Init 0 */

  /* USER CODE BEGIN CAN1_Init 1 */

  /* USER CODE END CAN1_Init 1 */
  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 20;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_10TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_5TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN1_Init 2 */
  	  CAN_FilterTypeDef sFilterConfig;
      sFilterConfig.FilterActivation = ENABLE;
      sFilterConfig.FilterBank = 13;
      sFilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
      sFilterConfig.FilterIdHigh = 0;
      sFilterConfig.FilterIdLow = 0;
      sFilterConfig.FilterMaskIdHigh = 0x0000;
      sFilterConfig.FilterMaskIdLow = 0X0000;
      sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
      sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
      sFilterConfig.SlaveStartFilterBank = 0;
      HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig);
  /* USER CODE END CAN1_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x10D19CE4;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 20000-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel5_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin : BTN1_Pin */
  GPIO_InitStruct.Pin = BTN1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(BTN1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PA1 */
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB2 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB11 PB12 PB13
                           PB14 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
}
int _write(int file, char *ptr, int len)
{
  (void)file;
  int DataIdx;

  for (DataIdx = 0; DataIdx < len; DataIdx++)
  {
	  //__io_putchar(*ptr++);
    ITM_SendChar(*ptr++);
  }
  return len;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */

  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
