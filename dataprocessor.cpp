#include "dataprocessor.h"

namespace dp {
    DataProcessor::DataProcessor() : QObject()
    {
    }
    DataProcessor::DataProcessor(QCustomPlot *plot, char headerH, char headerL){
        this->plot = plot;
        this->headerH = headerH;
        this->headerL = headerL;
    }
}

