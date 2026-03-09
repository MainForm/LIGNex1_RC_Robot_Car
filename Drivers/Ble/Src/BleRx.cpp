#include "BleRx.hpp"
#include "PacketCodec.hpp"

//반드시 Interrupt 설정 필요함
//flag = 1
// void USART1_IRQHandler(void)
// {
//   /* USER CODE BEGIN USART1_IRQn 0 */
//   if (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_IDLE) != RESET){
//     __HAL_UART_CLEAR_IDLEFLAG(&huart1);
    
//     osMessageQueuePut(qhandle, &flag, 0, 0);
//   }
//   /* USER CODE END USART1_IRQn 0 */
//   HAL_UART_IRQHandler(&huart1);
//   /* USER CODE BEGIN USART1_IRQn 1 */

//   /* USER CODE END USART1_IRQn 1 */
// }


void BleRx::Init(void *argument){
    Init_type *handle = static_cast<Init_type*>(argument);
    huart = handle->huart;
    qhandle = handle->qhandle;
    servo_q = handle->servo_q;
    moter_q = handle->moter_q;

    rx_old_pos = 0;
    if (processor == nullptr){
        processor = new (std::nothrow) PacketCodec;
        configASSERT(processor != nullptr);
     }
     HAL_UART_Receive_DMA(huart, rx_buf, RX_BUF_SIZE);
     __HAL_DMA_DISABLE_IT(huart->hdmarx, DMA_IT_HT);
     __HAL_UART_ENABLE_IT(huart, UART_IT_IDLE);
}

uint16_t BleRx::uart_dma_read(void *argument){
    (void)argument;
    const uint16_t pos = (uint16_t)(RX_BUF_SIZE - __HAL_DMA_GET_COUNTER(huart->hdmarx));
    const uint16_t avail = (pos >= rx_old_pos)
        ? (uint16_t)(pos - rx_old_pos)
        : (uint16_t)((RX_BUF_SIZE - rx_old_pos) + pos);
    if (avail == 0) return 0;

    uint16_t scan_pos = rx_old_pos;
    uint16_t scanned  = 0;
    while (scanned < avail) {
        if (rx_buf[scan_pos] == SOF) break;
        scan_pos++;
        if (scan_pos >= RX_BUF_SIZE) scan_pos = 0;
        scanned++;
    }

    if (scanned == avail) {
        rx_old_pos = pos;
        return 0;
    }

    const uint16_t sof_pos = scan_pos;
    rx_old_pos = sof_pos;
    const uint16_t new_avail = (pos >= sof_pos)
        ? (uint16_t)(pos - sof_pos)
        : (uint16_t)((RX_BUF_SIZE - sof_pos) + pos);

    if (new_avail < Packet_len) {
        return 0;
    }

    uint16_t copy_pos = sof_pos;
    for (uint16_t i = 0; i < Packet_len; i++) {
        tmp[i] = rx_buf[copy_pos];
        copy_pos++;
        if (copy_pos >= RX_BUF_SIZE) copy_pos = 0;
    }

    if (tmp[0] != SOF) {
        rx_old_pos = (uint16_t)((sof_pos + 1) % RX_BUF_SIZE);
        return 0;
    }

    uint8_t expected = 0;
    for (uint16_t i = 0; i < Packet_len - 1; i++) {
        expected ^= tmp[i];
    }    
    const uint8_t received = tmp[Packet_len - 1];

    if (expected != received) {
        rx_old_pos = (uint16_t)((sof_pos + 1) % RX_BUF_SIZE);
        return 0;
    }

    rx_old_pos = copy_pos;

    return Packet_len;
}

// 컨트롤러와 rc카에 각 디바이스를 구분할 수 있는 표시 해야함
void BleRx::GetFromRx(void *argument){
    osMessageQueueGet(*qhandle, &receive_flag, NULL, osWaitForever);
    if (uart_dma_read()){
        Data *data = processor.Decoding(tmp);
    #if isRCCar
        if (data->mode_data == driving){
            osMessageQueuePut(*moter_q, data, 0, 10);
        }
        else if(data->mode_data == arm){
            osMessageQueuePut(*servo_q, data, 0, 10);
        }
    #else
        if (data->mode_data == ack_driving){
            //HAL_GPIO_WritePin(~~);
        }
        else if (data->mode_data == ack_arm){
            //HAL_GPIO_WritePin(~~);
        }
        else
    #endif
        
    }
}