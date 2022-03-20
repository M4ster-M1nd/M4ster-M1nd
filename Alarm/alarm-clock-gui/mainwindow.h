#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QSoundEffect>
#include <QUrl>
#include <QKeyEvent>

#include "widgetchangevalue.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static const int secsInMinute = 60;
    static const int secsInHour = 3600;
private:
    Ui::MainWindow *ui;
    QTimer timer;
    QTime currentTime, alarmTime;
    QSoundEffect soundEffect;

    void initFormWidgets();
    void connectS2S();
    void displayTime(const QTime &time);    
protected:
    void keyPressEvent(QKeyEvent *event);
private slots:
    void stopSoundEffect();

    void pushButtonSetSysTime_clicked();

    void timer_timeout();
    void hours_buttonPressed(int value);
    void minutes_buttonPressed(int value);
    void seconds_buttonPressed(int value);

    void radioButtonSetTime_toggled(bool checked);
    void radioButtonSetAlarm_toggled(bool checked);


    void checkBoxAlarmEnabled_stateChanged(int state);

    void soundEffect_playingChanged();

};

#endif // MAINWINDOW_H
