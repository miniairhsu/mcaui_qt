#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <QObject>
#include "qcustomplot.h"
using namespace std;
namespace dp {
    class DataProcessor : public QObject
    {
        Q_OBJECT
    public:
        DataProcessor();
        DataProcessor(QCustomPlot *plot, char headerH, char headerL);
        virtual void update(QByteArray &data)=0;
        virtual void refreshGraph(char* cData) = 0;
        QCustomPlot *plot;
        char headerH;
        char headerL;
    signals:

    public slots:
    };
}


#endif // DATAPROCESSOR_H
