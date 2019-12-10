#ifndef ADPROCESSOR_H
#define ADPROCESSOR_H
#include "dataprocessor.h"
#include "dataprocessor.h"
namespace dp {
    class AdProcessor : public DataProcessor
    {
    public:
        AdProcessor();
        AdProcessor(QCustomPlot *plot,char headerH, char headerL);
        void update(QByteArray &data);
        void refreshGraph();
    private:
        short sData[2048];
    };
}


#endif // ADPROCESSOR_H
