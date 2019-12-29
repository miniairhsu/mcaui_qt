#include "udpserver.h"

namespace ionet {
    Udpserver::Udpserver()
    {
        this->socket = new QUdpSocket();
        this->socket->bind(1111);
        QObject::connect(this->socket, SIGNAL(readyRead()), this, SLOT(rxData()));
    }
    void Udpserver::registerObserver(dp::DataProcessor *observer){
        this->dataObseverList.push_back(observer);
    }

    void Udpserver::notify(QByteArray &data){
        for(dp::DataProcessor *observer : this->dataObseverList){
            observer->update(data);
        }
    }

    void Udpserver::rxData(){
        QHostAddress addr;
        quint16 port;
        QByteArray data;
        while (socket->hasPendingDatagrams()){
            data.resize(socket->pendingDatagramSize());
            socket->readDatagram(data.data(), data.size(), &addr, &port);
        }
        this->notify(data);
    }
}

