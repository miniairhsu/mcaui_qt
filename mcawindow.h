#ifndef MCAWINDOW_H
#define MCAWINDOW_H

#include <QMainWindow>

namespace Ui {
class MCAWindow;
}

class MCAWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MCAWindow(QWidget *parent = nullptr);
    ~MCAWindow();

private:
    Ui::MCAWindow *ui;
};

#endif // MCAWINDOW_H
