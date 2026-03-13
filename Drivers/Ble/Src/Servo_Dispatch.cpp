#if RC_Car
#include "Servo_Dispatch.hpp"
#include "DataConfig.hpp"

#ifdef __cplusplus
extern "C" {
#endif
    #include "main.h"
    #include "cmsis_os2.h"
    #include <string.h>
#ifdef __cplusplus
}
#endif

void Servo_dispatch::Init(void *argument){
    this->qhandle = SERVO_QUEUE;
    this->buf = static_cast<Servo_type*>(argument);
}


void Servo_dispatch::GetData(void *argument){
    osStatus_t st = osMessageQueueGet(this->qhandle, buf, NULL, osWaitForever);
    if (st != osOK){
        const char *err = "[Servo] : Dispatch Error\n";
        HAL_UART_Transmit(DEBUG_HUART, (uint8_t*)err, strlen(err), 10);
    }
}


#endif