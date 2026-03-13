#include "BlueToothRxTask.hpp"
#include "IRx.hpp"
#include "BleRx.hpp"


#include "cmsis_os2.h"
#include "gpio.h"
#include "stm32f103xb.h"
#include "stm32f1xx_hal_gpio.h"

extern "C"
void BluetoothRxTaskHandler(void *argument){
    IRx *Rx = new BleRx();
    Rx->Init(nullptr);
    for(;;){
        Rx->GetFromRx(nullptr);
        
        
    }
}
