#ifndef __BLETX_HPP__
#define __BLETX_HPP__

extern "C"{
    #include "usart.h"
}
#include "IDataProcessor.hpp"
#include "DataConfig.hpp"
#include "ITx.hpp"

class BleTx : public ITx{
    private:
        UART_HandleTypeDef *huart;
        uint8_t *buf;
        uint8_t tx_busy;
        IDataProcessor *processor;
    public:
         void Init(void *) override;
         void SendToTx(void *) override;
         void TxCompleteCallback();
         ~BleTx();
};

#endif