#ifndef UDPCLIENT_H
#define UDPCLIENT_H
#include <iostream>
#include <QUdpSocket>
#include "network.h"
using namespace std;
namespace ionet {
    class Udpclient : public Network{
    private:
        QUdpSocket *socket;
    public:
        Udpclient();
        Udpclient(QHostAddress addr, quint16 port);
        void txData(QString txData);
        void registerObserver(dp::DataProcessor *observer){}
        void notify(QByteArray &data){}
    };
}


#endif // UDPCLIENT_H
