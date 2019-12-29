#ifndef MCAWINDOW_H
#define MCAWINDOW_H

#include <QMainWindow>
#include "udpserver.h"
#include "udpclient.h"
#include "adprocessor.h"
#include "dataheaders.h"
#include "commandstring.h"
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

    void on_commandButton_clicked();

    void on_commandEdit_returnPressed();

    void on_ledButton1_clicked();

    void on_ledButton2_clicked();

    void on_ledButton3_clicked();

    void on_ledButton4_clicked();

    void on_ledOn_clicked();

    void on_ledOff_clicked();

    void on_plotButton_pressed();

    void on_stopButton_pressed();

private:
    Ui::MCAWindow *ui;
    ionet::Network *udpClient;
};

#endif // MCAWINDOW_H
