#include "BleTx.hpp"
#include "IDataProcessor.hpp"
#include "PacketCodec.hpp"
#include "DataConfig.hpp"

#ifdef __cplusplus
extern "C" {
#endif
    #include "main.h"
    #include "usart.h"
    #include <string.h>
#ifdef __cplusplus
}
#endif

void BleTx::Init(void *argument){
    huart = TX_HUART;
    processor = new PacketCodec;
    tx_busy = false;
}

void BleTx::SendToTx(void *argument){
    Data *data = static_cast<Data*>(argument);
    if (huart->gState != HAL_UART_STATE_READY){
        return;   
    }
    buf = (uint8_t*)(processor->Encoding(data));
    HAL_UART_Transmit_DMA(huart, buf, Packet_len);
}

BleTx::~BleTx(){
    delete processor;
}