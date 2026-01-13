#include "DriveTask.hpp"

#include "cmsis_os2.h"

extern "C"
void DriveTaskHandler(void *argument){

    for(;;){
        osDelay(1);
    }
}