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

    void AdProcessor::setMode(int mode){
        this->fftMode = mode;
    }

    void AdProcessor::refreshGraph(unsigned char* cData){

        unsigned short length = static_cast<unsigned short>(((cData[3]<<8) & 0xFF00) | (cData[2] & 0x00FF));
        memcpy(&mode, &cData[4], sizeof(unsigned short));
        if(mode == 3){
            memmove(reinterpret_cast<unsigned char*>(&fData), &cData[34], length * sizeof(float));
            for(int i = 0; i < length; i++){
                yData_Vec.push_back(static_cast<double>(fData[i]));
                xData_Vec.push_back(static_cast<double>(i));
            }
            textLabel->text().clear();
            memcpy(&powerValA,&cData[6],sizeof(float));
            memcpy(&powerValB,&cData[10],sizeof(float));
            memcpy(&corrPeakVal,&cData[14],sizeof(float));
            memcpy(&covVal,&cData[22],sizeof(float));
            memcpy(&crossVal,&cData[26],sizeof(float));
            memcpy(&corrPeak, &cData[30],sizeof(int));
            textLabel->setText("Power A " + QString::number(powerValA) + "\nPower B "+ QString::number(powerValB)\
                               + "\nCovariance " + QString::number(covVal) + "\nCorrelation " + QString::number(crossVal) + "\nCorrPeak " + QString::number(corrPeak)\
                               + "\nPeakVal " + QString::number(corrPeakVal));
            textLabel->setFont(QFont ("Courier", 8)); // make font a bit larger
            this->plot->graph(0)->setData(xData_Vec, yData_Vec, true);
            this->plot->replot();
            yData_Vec.clear();
            xData_Vec.clear();
        }else {
            memmove(reinterpret_cast<unsigned char*>(&sData), &cData[34], length * sizeof(unsigned short));
            memcpy(&meanVal,&cData[6],sizeof(float));
            memcpy(&varVal,&cData[10],sizeof(float));
            memcpy(&stdVal,&cData[14],sizeof(float));
            if( fftMode == 1){
                if (index == 0) {
                    yData_Vec.clear();
                    xData_Vec.clear();
                }
                if(index <= pkt_size){
                    for(int i = index * length, j = 0; i < index * length + length; i++, j++){
                        yData_Vec.push_back(static_cast<double>(sData[j]));
                        xData_Vec.push_back(static_cast<double>(index * length + i));
                    }
                    index++;
                    this->plot->graph(0)->setData(xData_Vec, yData_Vec, true);
                    this->plot->replot();
                }
                if( index == pkt_size ){
                    textLabel->text().clear();
                    textLabel->setText("Mean " + QString::number(meanVal) + "\nVariance "+  QString::number(varVal) +"\nStd " + QString::number(stdVal));
                    textLabel->setFont(QFont ("Courier", 8)); // make font a bit larger
                    index = 0;
                }
              }else {
                auto fft = Aquila::FftFactory::getFft(SIZE);
                std::copy(sData, sData + SIZE, sDataTemp);
                Aquila::SpectrumType spectrum = fft->fft(sDataTemp);
                for (unsigned int i = 0; i < spectrum.size(); ++i)
                {
                    yData_Vec.push_back(std::abs(spectrum[i])/SIZE);
                    xData_Vec.push_back(static_cast<double>(i));
                }
                textLabel->text().clear();
                textLabel->setText("Mean " + QString::number(meanVal) + "\nVariance "+  QString::number(varVal) +"\nStd " + QString::number(stdVal));
                textLabel->setFont(QFont ("Courier", 8)); // make font a bit larger
                this->plot->graph(0)->setData(xData_Vec, yData_Vec, true);
                this->plot->replot();
                yData_Vec.clear();
                xData_Vec.clear();
             }
         }
    }
}

