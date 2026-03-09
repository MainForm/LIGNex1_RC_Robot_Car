#ifndef __BLETX_HPP__
#define __BLETX_HPP__

extern "C"{
    #include "usart.h"
}
#include "IDataProcessor.hpp"

class BleTx : public ITx{
    private:
        UART_HandleTypeDef *huart;
        uint8_t buf[Packet_len];
        IDataProcessor *processor;
    public:
         void Init(void *) override;
         void SendToTx(void *) override;
};

#endif