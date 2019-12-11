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
        cData = reinterpret_cast<char *>(data.data());
        if(cData[0] == headerH && cData[1] == headerL){
            this->refreshGraph(cData);
        }
    }
    void AdProcessor::refreshGraph(char* cData){
        unsigned short length = static_cast<unsigned short>(cData[3]<<8 | cData[2]);
        unsigned short index = static_cast<unsigned short>(cData[5]<<8 | cData[4]);
        unsigned short pkt_size = static_cast<unsigned short>(cData[7]<<8 | cData[6]);
        memmove(reinterpret_cast<unsigned char*>(&sData[index*length*sizeof(short)]), &cData[8], length * sizeof(short));
        for(int i = 0; i < length; i++){
           yData_Vec[index * length + i] = sData[i];
           xData_Vec[index * length + i] = index * length + i;
        }
        if( index == pkt_size){
            this->plot->graph(0)->data()->clear();
            this->plot->graph(0)->addData(xData_Vec, yData_Vec);
            this->plot->replot();
        }
    }
}

