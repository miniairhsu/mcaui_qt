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
        void refreshGraph(char* cData);
    private:
        QVector<double> yData_Vec;
        QVector<double> xData_Vec;
        short sData[8192];
    };
}


#endif // ADPROCESSOR_H
