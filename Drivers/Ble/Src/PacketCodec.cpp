#include "DataConfig.hpp"
#include "PacketCodec.hpp"


void *PacketCodec::Encoding(void *argument){
    data = *static_cast<Data*>(argument);
    buf[0] = SOF;
    buf[1] = data.mode_data;
    buf[2] = data.gripper;
    
    buf[3] = (uint8_t)(data.moter_x);
    buf[4] = (uint8_t)(data.moter_x >> 8);

    buf[5] = (uint8_t)(data.moter_y);
    buf[6] = (uint8_t)(data.moter_y >> 8);

    buf[7] = (uint8_t)(data.servo_top);
    buf[8] = (uint8_t)(data.servo_top >> 8);

    buf[9] = (uint8_t)(data.servo_mid);
    buf[10] = (uint8_t)(data.servo_mid >> 8);

    buf[11] = (uint8_t)(data.servo_bot);
    buf[12] = (uint8_t)(data.servo_bot >> 8);



    buf[13] = 0;
    for(uint8_t i = 0; i < Packet_len-1; i++){
        buf[13] ^= buf[i];
    }
    return buf;
}

//여기서부터 다시 수정
void *PacketCodec::Decoding(void *argument){
    uint8_t *buf = static_cast<uint8_t *>(argument);
    data.mode_data = 0;
    data.mode_data = static_cast<uint16_t>(buf[1]);

    data.gripper = 0;
    data.gripper = static_cast<uint16_t>(buf[2]);

    data.moter_x = 0;
    data.moter_x = static_cast<uint16_t>(buf[3]);
    data.moter_x |= static_cast<uint16_t>(buf[4] << 8);

    data.moter_y = 0;
    data.moter_y = static_cast<uint16_t>(buf[5]);
    data.moter_y |= static_cast<uint16_t>(buf[6] << 8);

    data.servo_top = 0;
    data.servo_top = static_cast<uint16_t>(buf[7]);
    data.servo_top |= static_cast<uint16_t>(buf[8] << 8);

    data.servo_mid = 0;
    data.servo_mid = static_cast<uint16_t>(buf[9]);
    data.servo_mid |= static_cast<uint16_t>(buf[10] << 8);

    data.servo_bot = 0;
    data.servo_bot = static_cast<uint16_t>(buf[11]);
    data.servo_bot |= static_cast<uint16_t>(buf[12] << 8);

    return &data;
}