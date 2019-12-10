#include "adprocessor.h"

namespace dp {
    AdProcessor::AdProcessor(){}
    AdProcessor:: AdProcessor(QByteArray data){
        this->data = data;
    }
    void AdProcessor::update(QByteArray &data){
    }
}

