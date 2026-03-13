#ifndef __PACKETCODEC_HPP__
#define __PACKETCODEC_HPP__

#include <cstdint>
#include "IDataProcessor.hpp"
#include "DataConfig.hpp"

class PacketCodec : public IDataProcessor{
    private:
        uint8_t buf[Packet_len];
        Data data;
    public:
        void *Encoding(void *) override;
        void *Decoding(void *) override;
};

#endif