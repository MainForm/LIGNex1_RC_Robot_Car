/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "DataConfig.hpp"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for DriveTask */
osThreadId_t DriveTaskHandle;
uint32_t DriveTaskBuffer[ 128 ];
osStaticThreadDef_t DriveTaskControlBlock;
const osThreadAttr_t DriveTask_attributes = {
  .name = "DriveTask",
  .cb_mem = &DriveTaskControlBlock,
  .cb_size = sizeof(DriveTaskControlBlock),
  .stack_mem = &DriveTaskBuffer[0],
  .stack_size = sizeof(DriveTaskBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for BluetoothRxTask */
osThreadId_t BluetoothRxTaskHandle;
uint32_t BluetoothRxTaskBuffer[ 128 ];
osStaticThreadDef_t BluetoothRxTaskControlBlock;
const osThreadAttr_t BluetoothRxTask_attributes = {
  .name = "BluetoothRxTask",
  .cb_mem = &BluetoothRxTaskControlBlock,
  .cb_size = sizeof(BluetoothRxTaskControlBlock),
  .stack_mem = &BluetoothRxTaskBuffer[0],
  .stack_size = sizeof(BluetoothRxTaskBuffer),
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for RobotArmTask */
osThreadId_t RobotArmTaskHandle;
uint32_t RobotArmTaskBuffer[ 128 ];
osStaticThreadDef_t RobotArmTaskControlBlock;
const osThreadAttr_t RobotArmTask_attributes = {
  .name = "RobotArmTask",
  .cb_mem = &RobotArmTaskControlBlock,
  .cb_size = sizeof(RobotArmTaskControlBlock),
  .stack_mem = &RobotArmTaskBuffer[0],
  .stack_size = sizeof(RobotArmTaskBuffer),
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for RxQhandle */
osMessageQueueId_t RxQhandleHandle;
const osMessageQueueAttr_t RxQhandle_attributes = {
  .name = "RxQhandle"
};
/* Definitions for ServoQ */
osMessageQueueId_t ServoQHandle;
const osMessageQueueAttr_t ServoQ_attributes = {
  .name = "ServoQ"
};
/* Definitions for MoterQ */
osMessageQueueId_t MoterQHandle;
const osMessageQueueAttr_t MoterQ_attributes = {
  .name = "MoterQ"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void DriveTaskHandler(void *argument);
extern void BluetoothRxTaskHandler(void *argument);
extern void RobotArmTaskHandler(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of RxQhandle */
  RxQhandleHandle = osMessageQueueNew (16, sizeof(uint8_t), &RxQhandle_attributes);

  /* creation of ServoQ */
  ServoQHandle = osMessageQueueNew (16, sizeof(Servo_type), &ServoQ_attributes);

  /* creation of MoterQ */
  MoterQHandle = osMessageQueueNew (16, sizeof(Moter_type), &MoterQ_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of DriveTask */
  DriveTaskHandle = osThreadNew(DriveTaskHandler, NULL, &DriveTask_attributes);

  /* creation of BluetoothRxTask */
  BluetoothRxTaskHandle = osThreadNew(BluetoothRxTaskHandler, NULL, &BluetoothRxTask_attributes);

  /* creation of RobotArmTask */
  RobotArmTaskHandle = osThreadNew(RobotArmTaskHandler, NULL, &RobotArmTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_DriveTaskHandler */
/**
  * @brief  Function implementing the DriveTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_DriveTaskHandler */
__weak void DriveTaskHandler(void *argument)
{
  /* USER CODE BEGIN DriveTaskHandler */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END DriveTaskHandler */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

