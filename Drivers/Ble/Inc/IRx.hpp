#ifndef __IRX_HPP__
#define __IRX_HPP__

class IRx{
    public:
        virtual void Init(void *) = 0;
        virtual void GetFromRx(void *) = 0;
        virtual ~IRx() = default;
};

#endif