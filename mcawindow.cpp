#include "mcawindow.h"
#include "ui_mcawindow.h"
using namespace ionet;
using namespace dp;
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
    ui->plotSetGrid->addWidget(ui->scaleYBox, 1, 0, 1, 1);
    ui->plotSetGrid->addWidget(ui->plotButton, 1, 1, 1, 1);
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
    dp::DataProcessor *adaProc = new dp::AdProcessor(ui->adaGraph, ADA_HH, ADA_HL);
    dp::DataProcessor *adbProc = new dp::AdProcessor(ui->adbGraph, ADB_HH, ADB_HL);
    udpServer->registerObserver(adaProc);
    udpServer->registerObserver(adbProc);
    //=========network setup===========//
    QHostAddress hostAddr = QHostAddress("169.254.154.115");
    udpClient = new ionet::Udpclient(hostAddr, 1111);
    //=========configure ui============//
    ui->adaGraph->addGraph();
    ui->adbGraph->addGraph();
}

MCAWindow::~MCAWindow()
{
    delete ui;
}
