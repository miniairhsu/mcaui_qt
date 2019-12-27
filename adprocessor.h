#ifndef ADPROCESSOR_H
#define ADPROCESSOR_H
#include <iostream>
#include "dataprocessor.h"
#include "dataprocessor.h"
namespace dp {
    class AdProcessor : public DataProcessor
    {
    public:
        AdProcessor();
        AdProcessor(QCustomPlot *plot,char headerH, char headerL);
        void update(QByteArray &data);
        void refreshGraph(unsigned char* cData);

    private:
        QVector<double> yData_Vec;
        QVector<double> xData_Vec;
        short sData[65536];
        float fData[65536];
        int index = 0;
        unsigned short pkt_size = 8;
        unsigned short mode;
        float meanVal;
        float varVal;
        float stdVal;
        float covVal;
        float crossVal;
        float powerVal;
        QCPItemText *textLabel;
    };
}


#endif // ADPROCESSOR_H
