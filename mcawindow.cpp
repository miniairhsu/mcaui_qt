#include "mcawindow.h"
#include "ui_mcawindow.h"
using namespace ionet;
using namespace dp;
MCAWindow::MCAWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MCAWindow)
{
    ui->setupUi(this);
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
