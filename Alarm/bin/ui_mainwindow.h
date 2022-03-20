/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widgetchangevalue.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QLCDNumber *lcdNumber;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonSetTime;
    QRadioButton *radioButtonSetAlarm;
    QCheckBox *checkBoxAlarmEnabled;
    QPushButton *pushButtonSetSysTime;
    WidgetChangeValue *setHoursWidget;
    WidgetChangeValue *setMinutesWidget;
    WidgetChangeValue *setSecondsWidget;
    QPushButton *pbStopAlarm;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(572, 354);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lcdNumber);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButtonSetTime = new QRadioButton(centralWidget);
        radioButtonSetTime->setObjectName(QString::fromUtf8("radioButtonSetTime"));

        verticalLayout->addWidget(radioButtonSetTime);

        radioButtonSetAlarm = new QRadioButton(centralWidget);
        radioButtonSetAlarm->setObjectName(QString::fromUtf8("radioButtonSetAlarm"));

        verticalLayout->addWidget(radioButtonSetAlarm);

        checkBoxAlarmEnabled = new QCheckBox(centralWidget);
        checkBoxAlarmEnabled->setObjectName(QString::fromUtf8("checkBoxAlarmEnabled"));

        verticalLayout->addWidget(checkBoxAlarmEnabled);

        pushButtonSetSysTime = new QPushButton(centralWidget);
        pushButtonSetSysTime->setObjectName(QString::fromUtf8("pushButtonSetSysTime"));

        verticalLayout->addWidget(pushButtonSetSysTime);


        horizontalLayout->addLayout(verticalLayout);

        setHoursWidget = new WidgetChangeValue(centralWidget);
        setHoursWidget->setObjectName(QString::fromUtf8("setHoursWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(setHoursWidget->sizePolicy().hasHeightForWidth());
        setHoursWidget->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(setHoursWidget);

        setMinutesWidget = new WidgetChangeValue(centralWidget);
        setMinutesWidget->setObjectName(QString::fromUtf8("setMinutesWidget"));
        sizePolicy1.setHeightForWidth(setMinutesWidget->sizePolicy().hasHeightForWidth());
        setMinutesWidget->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(setMinutesWidget);

        setSecondsWidget = new WidgetChangeValue(centralWidget);
        setSecondsWidget->setObjectName(QString::fromUtf8("setSecondsWidget"));
        sizePolicy1.setHeightForWidth(setSecondsWidget->sizePolicy().hasHeightForWidth());
        setSecondsWidget->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(setSecondsWidget);


        verticalLayout_2->addLayout(horizontalLayout);

        pbStopAlarm = new QPushButton(centralWidget);
        pbStopAlarm->setObjectName(QString::fromUtf8("pbStopAlarm"));

        verticalLayout_2->addWidget(pbStopAlarm);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\247\320\260\321\201\321\213 - \320\261\321\203\320\264\320\270\320\273\321\214\320\275\320\270\320\272", nullptr));
        radioButtonSetTime->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        radioButtonSetAlarm->setText(QCoreApplication::translate("MainWindow", "\320\221\321\203\320\264\320\270\320\273\321\214\320\275\320\270\320\272", nullptr));
        checkBoxAlarmEnabled->setText(QCoreApplication::translate("MainWindow", "\320\222\320\272\320\273. \320\261\321\203\320\264\320\270\320\273\321\214\320\275\320\270\320\272", nullptr));
        pushButtonSetSysTime->setText(QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\321\205\321\200\320\276\320\275\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214\n"
"\321\201 \321\201\320\270\321\201\321\202\320\265\320\274\320\275\321\213\320\274 \320\262\321\200\320\265\320\274\320\265\320\275\320\265\320\274", nullptr));
        pbStopAlarm->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\321\200\320\262\320\260\321\202\321\214 \320\267\320\262\321\203\320\272\320\276\320\262\320\276\320\271 \321\201\320\270\320\263\320\275\320\260\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
