#include "BleTx.hpp"
#include "PacketCodec.hpp"
#include "DataConfig.hpp"

void BleTx::Init(void *argument){
     huart = static_cast<UART_HandleTypeDef*>(argument);
     if (processor == nullptr){
        processor = new (std::nothrow) PacketCodec;
        configASSERT(processor != nullptr);
     }
}

void BleTx::SendToTx(void *argument){
    Data *data = static_cast<Data*>(argument);
    uint8_t *buf = processor.Encoding(data);
    HAL_UART_Transmit(huart, buf, Packet_len, 10);
}