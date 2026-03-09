#ifndef __IDISPATCHER_HPP__
#define __IDISPATCHER_HPP__

class Dispatcher{
    public:
        virtual void Init(void *);
        virtual void *GetData(void *);
};

#endif