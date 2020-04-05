#ifndef ADPROCESSOR_H
#define ADPROCESSOR_H
#include <iostream>
#include <aquila/global.h>
#include <aquila/source/generator/SineGenerator.h>
#include <aquila/transform/FftFactory.h>
#include <aquila/tools/TextPlot.h>
#include "dataprocessor.h"
#include "dataprocessor.h"
#define SIZE 1024
namespace dp {
    class AdProcessor : public DataProcessor
    {
    public:
        AdProcessor();
        AdProcessor(QCustomPlot *plot,char headerH, char headerL);
        void update(QByteArray &data);
        void refreshGraph(unsigned char* cData);
        void setMode(int mode);

    private:
        QVector<double> yData_Vec;
        QVector<double> xData_Vec;
        short sData[65536];
        double sDataTemp[SIZE];
        float fData[65536];
        int index = 0;
        unsigned short pkt_size = 30;
        unsigned short mode;
        float meanVal;
        float varVal;
        float stdVal;
        float covVal;
        float crossVal;
        float powerValA;
        float powerValB;
        int corrPeak;
        float corrPeakVal;
        int fftMode = 1;
        QCPItemText *textLabel;
    };
}


#endif // ADPROCESSOR_H
