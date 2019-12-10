#include "udpclient.h"

namespace ionet {
    Udpclient::Udpclient(QHostAddress addr, quint16 port): Network(addr, port){
        this->addr = addr;
        this->port = port;
        this->socket = new QUdpSocket(this);
        this->socket->bind(this->addr, this->port);
    }
    void Udpclient::txData(QString txData){
        QByteArray Data;
        Data.append(txData);
        socket->writeDatagram(Data, this->addr, this->port);
    }
}

