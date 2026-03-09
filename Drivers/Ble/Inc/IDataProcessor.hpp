#ifndef __IDATAPROCESSOR_HPP__
#define __IDATAPROCESSOR_HPP__

class IDataProcessor{
    public:
        virtual void *Encoding(void *);
        virtual void *Decoding(void *);
};




#endif