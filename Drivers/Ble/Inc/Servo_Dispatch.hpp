#ifndef __SERVO_DISPATCHER_HPP__
#define __SERVO_DISPATCHER_HPP__

#include "IDispatcher.hpp"
#include "DataConfig.hpp"

extern "C"{
    #include "cmsis_os2.h"
}

class Servo_dispatch : public Dispatcher{
    private:
        osMessageQueueId_t qhandle;
        Servo_type *buf;
    public:
        void Init(void *) override;
        void GetData(void *) override;
};


#endif
