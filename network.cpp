#include "network.h"

namespace ionet {
Network::Network(){}
    Network::Network(QHostAddress addr, quint16 port){
        this->addr = addr;
        this->port = port;
    }

}
