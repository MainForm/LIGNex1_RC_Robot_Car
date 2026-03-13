#ifndef __BLERX_HPP__
#define __BLERX_HPP__

extern "C"{
    #include "cmsis_os2.h"
    #include "usart.h"
}

#include "IRx.hpp"
#include "DataConfig.hpp"
#include "IDataProcessor.hpp"


class BleRx : public IRx{
    private:
        UART_HandleTypeDef *huart;
        osMessageQueueId_t qhandle;
        osMessageQueueId_t servo_q;
        osMessageQueueId_t moter_q;
        uint8_t rx_buf[RX_BUF_SIZE];
        uint8_t *tmp;
        uint16_t rx_old_pos;
        IDataProcessor *processor;
        uint8_t receive_flag;
        static BleRx *instance;

        uint16_t uart_dma_read(void *);
        bool check_cs(uint8_t *, uint8_t);
    public:
        void Init(void *argument) override;
        void GetFromRx(void *arguement) override;
        static void Callback(UART_HandleTypeDef *huart, uint8_t Size);
        void OnRxEvent(uint8_t size);
        ~BleRx();
};



#endif