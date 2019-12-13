#include "mcawindow.h"
#include "ui_mcawindow.h"
using namespace ionet;
using namespace dp;
MCAWindow::MCAWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MCAWindow)
{
    ui->setupUi(this);
    ui->plotGrid->addWidget(ui->adaGraph, 0, 0, 1, 1);
    ui->plotGrid->addWidget(ui->adbGraph, 0, 1, 1, 1);
    ui->settingGrid->addWidget(ui->channelBox, 0, 0, 1, 1);
    ui->settingGrid->addWidget(ui->scaleXBox,0, 1, 1, 1);
    ui->settingGrid->addWidget(ui->scaleYBox, 0, 2, 1, 1);
    ui->settingGrid->addWidget(ui->plotButton, 0, 3, 1, 1);
    ui->settingGrid->addWidget(ui->networkBox,1, 0, 1, 1);
    ui->settingGrid->addWidget(ui->commandLabel,2, 0, 1, 1);
    ui->settingGrid->addWidget(ui->commandEdit, 2, 1, 1, 1);
    ui->settingGrid->addWidget(ui->commandButton,2, 2, 1, 1);
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
