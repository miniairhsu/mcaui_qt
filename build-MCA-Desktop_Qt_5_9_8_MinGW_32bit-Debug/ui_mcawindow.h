/********************************************************************************
** Form generated from reading UI file 'mcawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MCAWINDOW_H
#define UI_MCAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MCAWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *adaGraph;
    QCustomPlot *adbGraph;
    QWidget *grid1;
    QGridLayout *plotGrid;
    QLineEdit *commandEdit;
    QLabel *commandLabel;
    QGroupBox *plotBox;
    QWidget *gridLayoutWidget;
    QGridLayout *plotSetGrid;
    QPushButton *commandButton;
    QComboBox *scaleXBox;
    QComboBox *networkBox;
    QComboBox *channelBox;
    QPushButton *plotButton;
    QComboBox *scaleYBox;
    QRadioButton *ledButton1;
    QRadioButton *ledButton2;
    QRadioButton *ledButton3;
    QRadioButton *ledButton4;
    QGroupBox *ledBox;
    QRadioButton *ledOn;
    QRadioButton *ledOff;
    QWidget *gridLayoutWidget_2;
    QGridLayout *ledGrid;
    QGroupBox *settingBox;
    QWidget *gridLayoutWidget_3;
    QGridLayout *settingGrid;
    QPushButton *stopButton;
    QComboBox *modeBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *radioGroup;

    void setupUi(QMainWindow *MCAWindow)
    {
        if (MCAWindow->objectName().isEmpty())
            MCAWindow->setObjectName(QStringLiteral("MCAWindow"));
        MCAWindow->resize(1700, 944);
        centralWidget = new QWidget(MCAWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        adaGraph = new QCustomPlot(centralWidget);
        adaGraph->setObjectName(QStringLiteral("adaGraph"));
        adaGraph->setGeometry(QRect(10, 659, 261, 51));
        adbGraph = new QCustomPlot(centralWidget);
        adbGraph->setObjectName(QStringLiteral("adbGraph"));
        adbGraph->setGeometry(QRect(840, 669, 800, 41));
        grid1 = new QWidget(centralWidget);
        grid1->setObjectName(QStringLiteral("grid1"));
        grid1->setGeometry(QRect(10, 40, 1700, 650));
        plotGrid = new QGridLayout(grid1);
        plotGrid->setSpacing(6);
        plotGrid->setContentsMargins(11, 11, 11, 11);
        plotGrid->setObjectName(QStringLiteral("plotGrid"));
        commandEdit = new QLineEdit(centralWidget);
        commandEdit->setObjectName(QStringLiteral("commandEdit"));
        commandEdit->setGeometry(QRect(140, 820, 165, 22));
        commandLabel = new QLabel(centralWidget);
        commandLabel->setObjectName(QStringLiteral("commandLabel"));
        commandLabel->setGeometry(QRect(350, 820, 209, 29));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        commandLabel->setFont(font);
        plotBox = new QGroupBox(centralWidget);
        plotBox->setObjectName(QStringLiteral("plotBox"));
        plotBox->setGeometry(QRect(10, 710, 451, 101));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(760, 800, 160, 51));
        plotSetGrid = new QGridLayout(gridLayoutWidget);
        plotSetGrid->setSpacing(6);
        plotSetGrid->setContentsMargins(11, 11, 11, 11);
        plotSetGrid->setObjectName(QStringLiteral("plotSetGrid"));
        plotSetGrid->setContentsMargins(0, 0, 0, 0);
        commandButton = new QPushButton(centralWidget);
        commandButton->setObjectName(QStringLiteral("commandButton"));
        commandButton->setGeometry(QRect(440, 820, 80, 15));
        scaleXBox = new QComboBox(centralWidget);
        scaleXBox->setObjectName(QStringLiteral("scaleXBox"));
        scaleXBox->setGeometry(QRect(540, 810, 55, 22));
        networkBox = new QComboBox(centralWidget);
        networkBox->setObjectName(QStringLiteral("networkBox"));
        networkBox->setGeometry(QRect(10, 820, 55, 22));
        channelBox = new QComboBox(centralWidget);
        channelBox->setObjectName(QStringLiteral("channelBox"));
        channelBox->setGeometry(QRect(80, 820, 55, 22));
        plotButton = new QPushButton(centralWidget);
        plotButton->setObjectName(QStringLiteral("plotButton"));
        plotButton->setGeometry(QRect(620, 810, 80, 15));
        scaleYBox = new QComboBox(centralWidget);
        scaleYBox->setObjectName(QStringLiteral("scaleYBox"));
        scaleYBox->setGeometry(QRect(1620, 830, 55, 22));
        ledButton1 = new QRadioButton(centralWidget);
        radioGroup = new QButtonGroup(MCAWindow);
        radioGroup->setObjectName(QStringLiteral("radioGroup"));
        radioGroup->addButton(ledButton1);
        ledButton1->setObjectName(QStringLiteral("ledButton1"));
        ledButton1->setGeometry(QRect(1640, 720, 63, 15));
        ledButton2 = new QRadioButton(centralWidget);
        radioGroup->addButton(ledButton2);
        ledButton2->setObjectName(QStringLiteral("ledButton2"));
        ledButton2->setGeometry(QRect(1470, 770, 63, 15));
        ledButton3 = new QRadioButton(centralWidget);
        radioGroup->addButton(ledButton3);
        ledButton3->setObjectName(QStringLiteral("ledButton3"));
        ledButton3->setGeometry(QRect(1640, 750, 63, 15));
        ledButton4 = new QRadioButton(centralWidget);
        radioGroup->addButton(ledButton4);
        ledButton4->setObjectName(QStringLiteral("ledButton4"));
        ledButton4->setGeometry(QRect(1450, 740, 63, 15));
        ledBox = new QGroupBox(centralWidget);
        ledBox->setObjectName(QStringLiteral("ledBox"));
        ledBox->setGeometry(QRect(470, 710, 321, 101));
        ledOn = new QRadioButton(centralWidget);
        radioGroup->addButton(ledOn);
        ledOn->setObjectName(QStringLiteral("ledOn"));
        ledOn->setGeometry(QRect(1620, 800, 63, 15));
        ledOff = new QRadioButton(centralWidget);
        radioGroup->addButton(ledOff);
        ledOff->setObjectName(QStringLiteral("ledOff"));
        ledOff->setGeometry(QRect(1550, 730, 71, 16));
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(950, 800, 160, 41));
        ledGrid = new QGridLayout(gridLayoutWidget_2);
        ledGrid->setSpacing(6);
        ledGrid->setContentsMargins(11, 11, 11, 11);
        ledGrid->setObjectName(QStringLiteral("ledGrid"));
        ledGrid->setContentsMargins(0, 0, 0, 0);
        settingBox = new QGroupBox(centralWidget);
        settingBox->setObjectName(QStringLiteral("settingBox"));
        settingBox->setGeometry(QRect(800, 709, 361, 101));
        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(1130, 820, 131, 21));
        settingGrid = new QGridLayout(gridLayoutWidget_3);
        settingGrid->setSpacing(6);
        settingGrid->setContentsMargins(11, 11, 11, 11);
        settingGrid->setObjectName(QStringLiteral("settingGrid"));
        settingGrid->setContentsMargins(0, 0, 0, 0);
        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(1270, 830, 93, 28));
        modeBox = new QComboBox(centralWidget);
        modeBox->setObjectName(QStringLiteral("modeBox"));
        modeBox->setGeometry(QRect(1250, 740, 73, 22));
        MCAWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MCAWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1700, 26));
        MCAWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MCAWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MCAWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MCAWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MCAWindow->setStatusBar(statusBar);

        retranslateUi(MCAWindow);

        QMetaObject::connectSlotsByName(MCAWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MCAWindow)
    {
        MCAWindow->setWindowTitle(QApplication::translate("MCAWindow", "MCAWindow", Q_NULLPTR));
        commandLabel->setText(QApplication::translate("MCAWindow", "Command", Q_NULLPTR));
        plotBox->setTitle(QApplication::translate("MCAWindow", "Plot", Q_NULLPTR));
        commandButton->setText(QApplication::translate("MCAWindow", "Send", Q_NULLPTR));
        plotButton->setText(QApplication::translate("MCAWindow", "Start", Q_NULLPTR));
        ledButton1->setText(QApplication::translate("MCAWindow", "LED1", Q_NULLPTR));
        ledButton2->setText(QApplication::translate("MCAWindow", "LED2", Q_NULLPTR));
        ledButton3->setText(QApplication::translate("MCAWindow", "LED3", Q_NULLPTR));
        ledButton4->setText(QApplication::translate("MCAWindow", "LED4", Q_NULLPTR));
        ledBox->setTitle(QApplication::translate("MCAWindow", "LED control", Q_NULLPTR));
        ledOn->setText(QApplication::translate("MCAWindow", "All on", Q_NULLPTR));
        ledOff->setText(QApplication::translate("MCAWindow", "All off", Q_NULLPTR));
        settingBox->setTitle(QApplication::translate("MCAWindow", "Settings", Q_NULLPTR));
        stopButton->setText(QApplication::translate("MCAWindow", "stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MCAWindow: public Ui_MCAWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MCAWINDOW_H
