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

        unsigned short length = static_cast<unsigned short>(((cData[3]<<8) & 0xFF00) | (cData[2] & 0x00FF));
        //unsigned short index = static_cast<unsigned short>(cData[5]<<8 | cData[4]); skip use internal counter
        //unsigned short pkt_size = static_cast<unsigned short>(cData[7]<<8 | cData[6]); skip use internal settings
        memmove(reinterpret_cast<unsigned char*>(&sData), &cData[8], length * sizeof(unsigned short));
        if(index <= pkt_size){
            for(int i = 0; i < length; i++){
                yData_Vec.push_back(static_cast<double>(sData[i]));
                xData_Vec.push_back(static_cast<double>(index * length + i));
            }
            index++;
        }
        if( index == pkt_size ){
            this->plot->graph(0)->setData(xData_Vec, yData_Vec, true);
            this->plot->replot();
            yData_Vec.clear();
            xData_Vec.clear();
            index = 0;
        }
    }
}

