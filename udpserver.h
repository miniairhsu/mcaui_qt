#ifndef UDPSERVER_H
#define UDPSERVER_H
#include <QUdpSocket>
#include "network.h"
namespace ionet {
    class Udpserver: public Network
    {
    private:
        QUdpSocket *socket;
        void notify(QByteArray &data);
    public:
        Udpserver();
        void registerObserver(dp::DataProcessor *observer);
    public slots:
        void rxData();
    signals:
        void rxDataReceived(QByteArray *data);
    };
}

#endif // UDPSERVER_H
