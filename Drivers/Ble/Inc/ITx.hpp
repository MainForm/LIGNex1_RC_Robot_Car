#ifndef __ITX_HPP__
#define __ITX_HPP__

class ITx{
    public:
        virtual void Init(void *) = 0;
        virtual void SendToTx(void *) = 0;
        virtual ~ITx() = default;
};


#endif