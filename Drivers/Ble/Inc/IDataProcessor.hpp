#ifndef __IDATAPROCESSOR_HPP__
#define __IDATAPROCESSOR_HPP__

class IDataProcessor{
    public:
        virtual void *Encoding(void *) = 0;
        virtual void *Decoding(void *) = 0;
        virtual ~IDataProcessor() = default;
};




#endif