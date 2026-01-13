#include "RobotArmTask.hpp"

#include "cmsis_os2.h"

extern "C"
void RobotArmTaskHandler(void *argument){

    for(;;){
        osDelay(1);
    }
}