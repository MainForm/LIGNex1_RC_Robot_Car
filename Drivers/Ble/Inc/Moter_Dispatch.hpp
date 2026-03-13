#ifndef __MOTER_DISPATCH_HPP__
#define __MOTER_DISPATCH_HPP__

#include "IDispatcher.hpp"
#include "DataConfig.hpp"

extern "C"{
    #include "cmsis_os2.h"
}

class Moter_dispatch : public Dispatcher{
    private:
        osMessageQueueId_t qhandle;
        Moter_type *buf;
    public:
        void Init(void *) override;
        void GetData(void *) override;
};


#endif