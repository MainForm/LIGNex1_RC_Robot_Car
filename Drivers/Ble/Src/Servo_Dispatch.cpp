#include "Servo_Dispatch.hpp"
#include "DataConfig.hpp"

void Servo_dispatch::Init(void *argument){
    Servo_Init *init = static_cast<Servo_Init*>(argument);
    this->qhandle = init->qhandle;
    this->buf = init->buf;
}


void *Servo_dispatch::GetData(void *argument){
    osMessageQueueGet(qhandle, buf, NULL, osWaitForever);
    return buf;
}

