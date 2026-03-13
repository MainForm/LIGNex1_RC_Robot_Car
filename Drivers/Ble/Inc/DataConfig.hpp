#ifndef __DATACONFIG_HPP__
#define __DATACONFIG_HPP__

#ifdef __cplusplus
extern "C" {
#endif
    #include <stdint.h>
    #include "usart.h"
    #include "cmsis_os.h"
#ifdef __cplusplus
}
#endif
//RC Car에서는 RC_Car = 1, RC_Controller = 0
#define RC_Controller 0
#define RC_Car 1


#define Packet_len 14
#define SOF 0xAA
#define RX_BUF_SIZE 128

//모드 정의
#define driving 0xFF
#define rotate 0xDD
#define arm 0x00
#define ack_driving 0xA5
#define ack_arm 0x5A


//UART 설정
//*****************************//
//디버깅 용 UART 설정
#define DEBUG_UART_NUM 2

//BLE용 UART 설정
#define RX_UART_NUM 1
#define TX_UART_NUM 1




#if DEBUG_UART_NUM == 1
#define DEBUG_HUART (&huart1)

#elif DEBUG_UART_NUM == 2
#define DEBUG_HUART (&huart2)

#elif DEBUG_UART_NUM == 3
#define DEBUF_HUART (&huart3)
#endif

#if RX_UART_NUM == 1
#define RX_HUART (&huart1)

#elif RX_UART_NUM == 2
#define RX_HUART (&huart2)

#elif RX_UART_NUM == 3
#define RX_HUART (&huart3)
#endif

#if TX_UART_NUM == 1
#define TX_HUART (&huart1)

#elif TX_UART_NUM == 2
#define TX_HUART (&huart2)

#elif TX_UART_NUM == 3
#define TX_HUART (&huart3)
#endif

//**************************//





#ifdef __cplusplus
extern "C"{
#endif

extern UART_HandleTypeDef huart1;
extern osMessageQueueId_t RxQhandleHandle;

#if RC_Car
extern osMessageQueueId_t ServoQHandle;
extern osMessageQueueId_t MoterQHandle;
#endif
#ifdef __cplusplus
}
#endif

#if RC_Car
#define SERVO_QUEUE (ServoQHandle)
#define MOTER_QUEUE (MoterQHandle)
#endif
#define COM_QUEUE (RxQhandleHandle)



typedef struct{
    uint8_t mode_data;
    uint8_t gripper;
    uint16_t moter_x;
    uint16_t moter_y;
    uint16_t servo_top;
    uint16_t servo_mid;
    uint16_t servo_bot;
}Data;

typedef struct{
    UART_HandleTypeDef *huart;
    osMessageQueueId_t qhandle;
    osMessageQueueId_t servo_q;
    osMessageQueueId_t moter_q;
}Init_type;

typedef struct{
    uint16_t servo_top;
    uint16_t servo_mid;
    uint16_t servo_bot;
    uint8_t gripper;
}Servo_type;

typedef struct{
    osMessageQueueId_t qhandle;
    Servo_type *buf;
}Servo_Init;

typedef struct{
    uint8_t mode_data;
    uint16_t moter_x;
    uint16_t moter_y;
}Moter_type;


typedef struct{
    osMessageQueueId_t qhandle;
    Moter_type *buf;
}Moter_Init;

#endif

// 필요한 MessageQueue : 
// 1. Controller의 Rx용 Message Queue
// 2. RC의 Rx용 MessageQueue
// 3. RC의 Servo용 MessageQueue
// 4. RC의 Moter용 MessageQueue 