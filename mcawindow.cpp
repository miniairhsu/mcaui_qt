#include "mcawindow.h"
#include "ui_mcawindow.h"
using namespace ionet;
using namespace dp;
dp::DataProcessor *adaProc;
dp::DataProcessor *adbProc;
MCAWindow::MCAWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MCAWindow)
{
    ui->setupUi(this);
    //============set up GUI============//
    //==================================//
    //============plot=========//
    ui->plotGrid->addWidget(ui->adaGraph, 0, 0, 1, 1);
    ui->plotGrid->addWidget(ui->adbGraph, 0, 1, 1, 1);
    //============plot settings=========//
    ui->plotSetGrid->addWidget(ui->channelBox, 0, 0, 1, 1);
    ui->plotSetGrid->addWidget(ui->scaleXBox,0, 1, 1, 1);
    ui->plotSetGrid->addWidget(ui->scaleYBox, 0, 2, 1, 1);
    ui->plotSetGrid->addWidget(ui->modeBox,1, 0, 1, 1);
    ui->plotSetGrid->addWidget(ui->plotButton, 1, 1, 1, 1);
    ui->plotSetGrid->addWidget(ui->stopButton,1, 2, 1, 1);
    ui->plotBox->setLayout(ui->plotSetGrid);
    //============LED=========//
    ui->ledGrid->addWidget(ui->ledButton1,0, 0, 1, 1);
    ui->ledGrid->addWidget(ui->ledButton2,0 ,1, 1, 1);
    ui->ledGrid->addWidget(ui->ledButton3,0, 2, 1, 1);
    ui->ledGrid->addWidget(ui->ledButton4,0, 3, 1, 1);
    ui->ledGrid->addWidget(ui->ledOn,1 ,0 ,1 , 1);
    ui->ledGrid->addWidget(ui->ledOff,1 ,1 ,1 ,1);
    ui->ledBox->setLayout(ui->ledGrid);
    //===========settings=====//
    ui->settingGrid->addWidget(ui->commandLabel,0, 0, 1, 1);
    ui->settingGrid->addWidget(ui->commandEdit, 0, 1, 1, 1);
    ui->settingGrid->addWidget(ui->commandButton, 1, 1, 1, 1);
    ui->settingGrid->addWidget(ui->networkBox,1, 0, 1, 1);
    ui->settingBox->setLayout(ui->settingGrid);
    ionet::Network *udpServer = new ionet::Udpserver;
    adaProc = new dp::AdProcessor(ui->adaGraph, ADA_HH, ADA_HL);
    adbProc = new dp::AdProcessor(ui->adbGraph, ADB_HH, ADB_HL);
    udpServer->registerObserver(adaProc);
    udpServer->registerObserver(adbProc);
    //=========network setup===========//
    QHostAddress hostAddr = QHostAddress("169.254.154.115");
    udpClient = new ionet::Udpclient(hostAddr, 1111);
    //=========configure ui============//
    //=========set range box===========//
    QStringList xScaleList;
    xScaleList.append("X scale");
    xScaleList.append("40");
    xScaleList.append("80");
    xScaleList.append("200");
    xScaleList.append("400");
    xScaleList.append("800");
    xScaleList.append("1200");
    xScaleList.append("1600");
    xScaleList.append("2000");
    xScaleList.append("4000");
    xScaleList.append("6000");
    xScaleList.append("8000");
    xScaleList.append("6000");
    xScaleList.append("8000");
    xScaleList.append("10000");
    xScaleList.append("12000");
    xScaleList.append("14000");
    xScaleList.append("16000");
    xScaleList.append("18000");
    xScaleList.append("20000");
    xScaleList.append("40000");
    xScaleList.append("80000");
    xScaleList.append("100000");
    xScaleList.append("500000");
    xScaleList.append("1000000");
    ui->scaleXBox->addItems(xScaleList);
    QStringList yScaleList;
    yScaleList.append("Y scale");
    yScaleList.append("0.1");
    yScaleList.append("2");
    yScaleList.append("20");
    yScaleList.append("50");
    yScaleList.append("200");
    yScaleList.append("500");
    yScaleList.append("1000");
    yScaleList.append("2000");
    yScaleList.append("4000");
    yScaleList.append("6000");
    yScaleList.append("8000");
    yScaleList.append("10000");
    yScaleList.append("15000");
    yScaleList.append("20000");
    yScaleList.append("40000");
    yScaleList.append("80000");
    yScaleList.append("200000");
    yScaleList.append("400000");
    yScaleList.append("800000");
    yScaleList.append("1000000");
    ui->scaleYBox->addItems(yScaleList);
    QStringList modeList;
    modeList.append("Mode");
    modeList.append("Time");
    modeList.append("FFT");
    ui->modeBox->addItems(modeList);
    connect(ui->scaleXBox, SIGNAL(currentIndexChanged(int)), SLOT(on_scaleXBox_currentIndexChanged(int)));
    connect(ui->scaleYBox, SIGNAL(currentIndexChanged(int)), SLOT(on_scaleYBox_currentIndexChanged(int)));
    //=======send button================//
    connect(ui->commandButton, SIGNAL(clicked()), SLOT(on_commandButton_clicked()));
    //=======command field==============//
    connect(ui->commandEdit, SIGNAL(returnPressed()), SLOT(on_commandEdit_returnPressed()));
    //=======radio buttons==============//
    connect(ui->ledButton1, SIGNAL(clicked()), SLOT(on_ledButton1_clicked()));
    connect(ui->ledButton2, SIGNAL(clicked()), SLOT(on_ledButton2_clicked()));
    connect(ui->ledButton3, SIGNAL(clicked()), SLOT(on_ledButton3_clicked()));
    connect(ui->ledButton4, SIGNAL(clicked()), SLOT(on_ledButton4_clicked()));
    connect(ui->ledOn, SIGNAL(clicked()), SLOT(on_ledOn_clicked()));
    connect(ui->ledOff, SIGNAL(clicked()), SLOT(on_ledOff_clicked()));
    //======set plot channel===========//
    QStringList channelList;
    channelList.append("ADC channel");
    channelList.append("1");
    channelList.append("2");
    channelList.append("3");
    channelList.append("4");
    ui->channelBox->addItems(channelList);
    connect(ui->plotButton, SIGNAL(pressed()), SLOT(on_plotButton_pressed()));
    connect(ui->stopButton, SIGNAL(pressed()), SLOT(on_stopButton_pressed()));
    //=====set up graph================//
    ui->adaGraph->xAxis->setRange(0, 5000);
    ui->adaGraph->yAxis->setRange(-100, 2000);
    ui->adbGraph->xAxis->setRange(0, 5000);
    ui->adbGraph->yAxis->setRange(-300, 2000);
    ui->adaGraph->addGraph();
    ui->adbGraph->addGraph();
    QPen pen;
    pen.setColor(QColor(255, 0, 0));
    ui->adbGraph->graph()->setPen(pen);
}

MCAWindow::~MCAWindow()
{
    delete ui;
}


void MCAWindow::on_scaleXBox_currentIndexChanged(int index)
{
    if( index != 0 ){
        int xScale = ui->scaleXBox->currentText().toInt();
        ui->adaGraph->xAxis->setRange(0, xScale);
        ui->adbGraph->xAxis->setRange(0, xScale);
    }
}

void MCAWindow::on_scaleYBox_currentIndexChanged(int index)
{
    if(index != 0){
        int yScale = ui->scaleYBox->currentText().toInt();
        ui->adaGraph->yAxis->setRange(-yScale, yScale);
        ui->adbGraph->yAxis->setRange(-yScale, yScale);
    }
}

void MCAWindow::on_commandButton_clicked()
{
    QString cmd = ui->commandEdit->text();
    udpClient->txData(cmd);
}

void MCAWindow::on_commandEdit_returnPressed()
{
    QString cmd = ui->commandEdit->text();
    udpClient->txData(cmd);
}

void MCAWindow::on_ledButton1_clicked()
{
    udpClient->txData(LED1);
}

void MCAWindow::on_ledButton2_clicked()
{
    udpClient->txData(LED2);
}

void MCAWindow::on_ledButton3_clicked()
{
    udpClient->txData(LED3);
}

void MCAWindow::on_ledButton4_clicked()
{
    udpClient->txData(LED4);
}

void MCAWindow::on_ledOn_clicked()
{
    udpClient->txData(LEDALL);
}

void MCAWindow::on_ledOff_clicked()
{
    udpClient->txData(LEDOFF);
}

void MCAWindow::on_plotButton_pressed()
{
    QString cmd = "enad:1";
    udpClient->txData(cmd);
    QThread::msleep(10);
    if(ui->channelBox->currentIndex() != 0){
        QString cmd1 = "setadch:"+ui->channelBox->currentText();
        udpClient->txData(cmd1);
    }
    if(ui->modeBox->currentIndex() != 0){
        adaProc->setMode(ui->modeBox->currentIndex());
        adbProc->setMode(ui->modeBox->currentIndex());
    }else{
        adaProc->setMode(1);
        adbProc->setMode(1);
    }
}

void MCAWindow::on_stopButton_pressed()
{
    QString cmd = "enad:0";
    udpClient->txData(cmd);
    QThread::msleep(10);
    QString cmd1 = "setadch:0";
    udpClient->txData(cmd1);
}
