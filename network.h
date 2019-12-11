#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
#include <vector>
#include <QHostAddress>
#include <QObject>
#include <QByteArray>
#include "dataprocessor.h"

using namespace std;
using namespace dp;
namespace ionet {
    class Network : public QObject{
    public:
        std::vector<class dp::DataProcessor*> dataObseverList;
        QHostAddress addr;
        quint16 port;
        Network();
        Network(QHostAddress addr, quint16 port);
        virtual void registerObserver(dp::DataProcessor *observer) = 0;
        virtual void txData(QString txData) = 0;
        virtual void notify(QByteArray &data) = 0;
     //public slots:
        //virtual void rxData() = 0; //connect this to readyRead signal
    };
}

#endif // NETWORK_H
