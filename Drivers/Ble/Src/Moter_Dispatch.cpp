#if RC_Car
#include "Moter_Dispatch.hpp"
#include "DataConfig.hpp"

#ifdef __cplusplus
extern "C" {
#endif
    #include <string.h>
    #include "main.h"
    #include "usart.h"
#ifdef __cplusplus
}
#endif

void Moter_dispatch::Init(void *argument){
    qhandle = MOTER_QUEUE;
    buf = static_cast<Moter_type*>(argument);
}

void Moter_dispatch::GetData(void *argument){
    osStatus_t st = osMessageQueueGet(qhandle, buf, NULL, osWaitForever);
    if (st != osOK){
        const char *err = "[Moter] : Dispatch Error\n";
        HAL_UART_Transmit(DEBUG_HUART, (uint8_t*)err, strlen(err), 10);
    }
}

#endif