#ifndef MCAWINDOW_H
#define MCAWINDOW_H

#include <QMainWindow>
#include "udpserver.h"
#include "udpclient.h"
#include "adprocessor.h"
#include "dataheaders.h"
namespace Ui {
class MCAWindow;
}

class MCAWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MCAWindow(QWidget *parent = nullptr);
    ~MCAWindow();

private slots:
    void on_scaleXBox_currentIndexChanged(int index);

    void on_scaleYBox_currentIndexChanged(int index);

private:
    Ui::MCAWindow *ui;
    ionet::Network *udpClient;
};

#endif // MCAWINDOW_H
