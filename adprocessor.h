#ifndef ADPROCESSOR_H
#define ADPROCESSOR_H
#include "dataprocessor.h"
#include "qcustomplot.h"
#include "dataprocessor.h"
namespace dp {
    class AdProcessor : public DataProcessor
    {
    public:
        AdProcessor();
        AdProcessor(QByteArray data);
        void update(QByteArray &data);
    private:
        unsigned char cData[4096];
        short sData[2048];
    };
}


#endif // ADPROCESSOR_H
