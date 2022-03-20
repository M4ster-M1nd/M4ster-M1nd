#ifndef WIDGETCHANGEVALUE_H
#define WIDGETCHANGEVALUE_H

#include <QWidget>
#include <QFrame>
#include <QTimer>
#include <QMouseEvent>
#include <QLabel>
#include <QString>

namespace Ui {
class WidgetChangeValue;
}

class WidgetChangeValue : public QFrame
{
    Q_OBJECT

public:
    explicit WidgetChangeValue(QWidget *parent = 0);
    ~WidgetChangeValue();

private:
    Ui::WidgetChangeValue *ui;
    QTimer timer;
    static const int timerInterval = 100;
    static const int waitCyclesCount = 5;
    int valueToSend;
    int waitCyclesCounter;
    void timerStart() {waitCyclesCounter = waitCyclesCount; timer.start();}

public:
    QString title() const;   
public slots:
    void setTitle(QString title);    
protected slots:
    void toolButtonInc_clicked();
    void toolButtonDec_clicked();
    void toolButtonInc_pressed();
    void toolButtonInc_released();
    void toolButtonDec_pressed();
    void toolButtonDec_released();
    void timer_timeout();
signals:
    void buttonPressed(int);


};

#endif // WIDGETCHANGEVALUE_H
