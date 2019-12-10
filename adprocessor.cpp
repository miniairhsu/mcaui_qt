#include "adprocessor.h"

namespace dp {
    AdProcessor::AdProcessor(){}
    AdProcessor:: AdProcessor(QCustomPlot *plot, char headerH, char headerL){
        this->plot = plot;
        this->headerH = headerH;
        this->headerL = headerL;
    }
    void AdProcessor::update(QByteArray &data){
        char *cData;
        cData = static_cast<char *>(data.data());
        if(cData[0] == headerH && cData[1] == headerL){
            this->refreshGraph();
        }
    }
    void AdProcessor::refreshGraph(){
        this->plot->replot();
    }
}

