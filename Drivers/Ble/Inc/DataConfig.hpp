#ifndef __DATACONFIG_HPP__
#define __DATACONFIG_HPP__

#include <cstdint>

extern "C"{
    #include "usart.h"
}

#define Packet_len 17
#define SOF 0xAA
#define RX_BUF_SIZE 128

#define driving 0xFF
#define arm 0x00
#define ack_driving 0xA5
#define ack_arm 0x5A

typedef struct{
    uint8_t mode_data;
    uint8_t moter_x;
    uint8_t moter_y;
    uint8_t gripper;
    uint32_t servo_top;
    uint32_t servo_mid;
    uint32_t servo_bot;
}Data;

typedef struct{
    void *huart;
    void *qhandle;
    void *servo_q;
    void *moter_q;
}Init_type;

typedef struct{
    uint32_t servo_top;
    uint32_t servo_mid;
    uint32_t servo_bot;
    uint8_t gripper;
}Servo_type;

typedef struct{
    osMessageQueueId_t qhandle;
    Servo_type *buf;
}Servo_Init;

typedef struct{
    uint8_t moter_x;
    uint8_t moter_y;
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