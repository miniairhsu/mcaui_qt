#ifndef UDPCLIENT_H
#define UDPCLIENT_H
#include <iostream>
#include <QUdpSocket>
#include "network.h"
using namespace std;
namespace ionet {
    class Udpclient : public Network
    {
    private:
        QUdpSocket *socket;
    public:
        Udpclient();
        Udpclient(QHostAddress addr, quint16 port);
        void txData(QString txData);
    };
}


#endif // UDPCLIENT_H
