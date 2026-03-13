#include "cmsis_os2.h"
#include "DriveTask.hpp"


extern "C"
void DriveTaskHandler(void *argument){

    for(;;){
        
        osDelay(1); // 1ms 주기로 정밀 제어
    }
}