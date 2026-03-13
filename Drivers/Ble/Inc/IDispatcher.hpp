#ifndef __IDISPATCHER_HPP__
#define __IDISPATCHER_HPP__

class Dispatcher{
    public:
        virtual void Init(void *) = 0;
        virtual void GetData(void *) = 0;
        virtual ~Dispatcher() = default;
};

#endif