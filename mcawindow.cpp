#include "mcawindow.h"
#include "ui_mcawindow.h"

MCAWindow::MCAWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MCAWindow)
{
    ui->setupUi(this);
}

MCAWindow::~MCAWindow()
{
    delete ui;
}
