#include "adprocessor.h"

namespace dp {
    AdProcessor::AdProcessor(){}
    AdProcessor:: AdProcessor(QCustomPlot *plot, char headerH, char headerL){
        this->plot = plot;
        this->headerH = headerH;
        this->headerL = headerL;
        // add the text label at the top:
        textLabel = new QCPItemText(this->plot);
        textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
        textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
        textLabel->position->setCoords(0.8, 0); // place position at right/top of axis rect
    }
    void AdProcessor::update(QByteArray &data){
        unsigned char *cData;
        cData = reinterpret_cast<unsigned char *>(data.data());
        if(cData[0] == headerH && cData[1] == headerL){
            this->refreshGraph(cData);
        }
    }
    void AdProcessor::refreshGraph(unsigned char* cData){

        unsigned short length = static_cast<unsigned short>(((cData[3]<<8) & 0xFF00) | (cData[2] & 0x00FF));
        memcpy(&mode, &cData[4], sizeof(unsigned short));
        memcpy(&meanVal,&cData[6],sizeof(float));
        memcpy(&varVal,&cData[10],sizeof(float));
        memcpy(&stdVal,&cData[14],sizeof(float));
        memcpy(&covVal,&cData[18],sizeof(float));
        memcpy(&crossVal,&cData[22],sizeof(float));
        memcpy(&powerVal,&cData[26],sizeof(float));
        float correlation = crossVal/ powerVal;
        if(mode == 3){
            memmove(reinterpret_cast<unsigned char*>(&fData), &cData[30], length * sizeof(float));
            if(index <= pkt_size){
                for(int i = 0; i < length; i++){
                    yData_Vec.push_back(static_cast<double>(fData[i]));
                    xData_Vec.push_back(static_cast<double>(index * length + i));
                }
                index++;
            }
        }else {
            memmove(reinterpret_cast<unsigned char*>(&sData), &cData[30], length * sizeof(unsigned short));
            if(index <= pkt_size){
                for(int i = 0; i < length; i++){
                    yData_Vec.push_back(static_cast<double>(sData[i]));;
                    xData_Vec.push_back(static_cast<double>(index * length + i));
                }
                index++;
            }
        }



        if( index == pkt_size ){
            textLabel->text().clear();
            textLabel->setText("Mean " + QString::number(meanVal) + "\nVariance "+  QString::number(varVal) +"\nStd " + QString::number(stdVal) \
                               + "\nCovariance " + QString::number(covVal) + "\nCorrelation " + QString::number(correlation));
            textLabel->setFont(QFont ("Courier", 8)); // make font a bit larger
            this->plot->graph(0)->setData(xData_Vec, yData_Vec, true);
            this->plot->replot();
            yData_Vec.clear();
            xData_Vec.clear();
            index = 0;
        }
    }
}

