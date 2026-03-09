#include "Moter_Dispatch.hpp"
#include "DataConfig.hpp"

void Moter_dispatch::Init(void *argument){
    Moter_Init *init = static_cast<Moter_Init*>(argument);
    qhandle = init->qhandle;
    buf = init->buf;
}

void *Moter_dispatch::GetData(void *argument){
    osMessageQueueGet(qhandle, buf, NULL, osWaitForever);
    return buf;
}