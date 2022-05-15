/********************************************************************************
** Form generated from reading UI file 'widgetchangevalue.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETCHANGEVALUE_H
#define UI_WIDGETCHANGEVALUE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetChangeValue
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *line;
    QToolButton *toolButtonInc;
    QToolButton *toolButtonDec;

    void setupUi(QWidget *WidgetChangeValue)
    {
        if (WidgetChangeValue->objectName().isEmpty())
            WidgetChangeValue->setObjectName(QString::fromUtf8("WidgetChangeValue"));
        WidgetChangeValue->resize(71, 174);
        verticalLayout = new QVBoxLayout(WidgetChangeValue);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(WidgetChangeValue);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        line = new QFrame(WidgetChangeValue);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        toolButtonInc = new QToolButton(WidgetChangeValue);
        toolButtonInc->setObjectName(QString::fromUtf8("toolButtonInc"));
        sizePolicy.setHeightForWidth(toolButtonInc->sizePolicy().hasHeightForWidth());
        toolButtonInc->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/128x128/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonInc->setIcon(icon);
        toolButtonInc->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(toolButtonInc);

        toolButtonDec = new QToolButton(WidgetChangeValue);
        toolButtonDec->setObjectName(QString::fromUtf8("toolButtonDec"));
        sizePolicy.setHeightForWidth(toolButtonDec->sizePolicy().hasHeightForWidth());
        toolButtonDec->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/128x128/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonDec->setIcon(icon1);
        toolButtonDec->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(toolButtonDec);


        retranslateUi(WidgetChangeValue);

        QMetaObject::connectSlotsByName(WidgetChangeValue);
    } // setupUi

    void retranslateUi(QWidget *WidgetChangeValue)
    {
        WidgetChangeValue->setWindowTitle(QCoreApplication::translate("WidgetChangeValue", "Form", nullptr));
        label->setText(QCoreApplication::translate("WidgetChangeValue", "TextLabel", nullptr));
        toolButtonInc->setText(QCoreApplication::translate("WidgetChangeValue", "...", nullptr));
        toolButtonDec->setText(QCoreApplication::translate("WidgetChangeValue", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetChangeValue: public Ui_WidgetChangeValue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETCHANGEVALUE_H
