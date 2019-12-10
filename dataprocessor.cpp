#include "dataprocessor.h"

namespace dp {
    DataProcessor::DataProcessor() : QObject()
    {
    }
    DataProcessor::DataProcessor(QByteArray data){
        this->data = data;
    }
}

