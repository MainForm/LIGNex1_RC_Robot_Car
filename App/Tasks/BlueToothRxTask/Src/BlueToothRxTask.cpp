#include "BlueToothRxTask.hpp"

#include "cmsis_os2.h"
#include "gpio.h"
#include "stm32f103xb.h"
#include "stm32f1xx_hal_gpio.h"

extern "C"
void BluetoothRxTaskHandler(void *argument){

    for(;;){
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

        osDelay(1000 );
    }
}