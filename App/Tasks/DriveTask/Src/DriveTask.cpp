#include "DriveTask.hpp"

#include "cmsis_os2.h"

extern "C"
void DriveTaskHandler(void *argument){
    int a=0;
    
    for(;;){
        osDelay(1);
    }
}