#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initFormWidgets();
    connectS2S();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initFormWidgets()
{
    ui->pbStopAlarm->setEnabled(false);

    ui->setHoursWidget->setTitle(QString::fromUtf8(u8"Часы"));
    ui->setMinutesWidget->setTitle(QString::fromUtf8(u8"Минуты"));
    ui->setSecondsWidget->setTitle(QString::fromUtf8(u8"Секунды"));   

    ui->radioButtonSetTime->setChecked(true);
    ui->lcdNumber->setDigitCount(8);
    currentTime.setHMS(0,0,0);
    alarmTime.setHMS(0,0,0);

    timer.setTimerType(Qt::VeryCoarseTimer);
    soundEffect.setLoopCount(5);
    soundEffect.setSource(QUrl::fromLocalFile(QApplication::applicationDirPath()+QStringLiteral("/alarm.wav")));
    timer.start(1000);

}

void MainWindow::connectS2S(){
    connect(&soundEffect, SIGNAL(playingChanged()), this, SLOT(soundEffect_playingChanged()));

    connect(ui->pushButtonSetSysTime, SIGNAL(clicked(bool)), this, SLOT(pushButtonSetSysTime_clicked()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
    connect(ui->radioButtonSetTime, SIGNAL(toggled(bool)), this, SLOT(radioButtonSetTime_toggled(bool)));
    connect(ui->radioButtonSetAlarm, SIGNAL(toggled(bool)), this, SLOT(radioButtonSetAlarm_toggled(bool)));

    connect(ui->checkBoxAlarmEnabled, SIGNAL(stateChanged(int)), this, SLOT(checkBoxAlarmEnabled_stateChanged(int)));

    connect(ui->setHoursWidget, SIGNAL(buttonPressed(int)), this, SLOT(hours_buttonPressed(int)));
    connect(ui->setMinutesWidget, SIGNAL(buttonPressed(int)), this, SLOT(minutes_buttonPressed(int)));
    connect(ui->setSecondsWidget, SIGNAL(buttonPressed(int)), this, SLOT(seconds_buttonPressed(int)));

    connect(ui->pbStopAlarm, SIGNAL(clicked()), this, SLOT(stopSoundEffect()));
}

void MainWindow::displayTime(const QTime &time){
    static QString text;
    text = QString::asprintf("%02d:%02d:%02d", time.hour(), time.minute(), time.second());
    ui->lcdNumber->display(text);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_Escape) || (event->key() == Qt::Key_Space)){
        soundEffect.stop();
    }
    QMainWindow::keyPressEvent(event);
}

void MainWindow::pushButtonSetSysTime_clicked()
{
    QTime now = QTime::currentTime();
    currentTime.setHMS(now.hour(), now.minute(), now.second());//Именно так,
    //иначе из-за наличия миллисекунд в QTime::currentTime() будильник никогда не сработает.
    if (!ui->radioButtonSetTime->isChecked()) return;
    displayTime(currentTime);
}

void MainWindow::timer_timeout(){    
    currentTime = currentTime.addSecs(1);    
    if (!ui->radioButtonSetTime->isChecked()) return;
    displayTime(currentTime);
    if (ui->checkBoxAlarmEnabled->isChecked()) {
        if (currentTime == alarmTime){
            soundEffect.play();
        }
    }
}

void MainWindow::radioButtonSetTime_toggled(bool checked){
    if (checked) {
        displayTime(currentTime);
        stopSoundEffect();
    }
}

void MainWindow::radioButtonSetAlarm_toggled(bool checked){
    if (checked) {
        displayTime(alarmTime);
        stopSoundEffect();
    }
}

void MainWindow::hours_buttonPressed(int value){
    if (ui->radioButtonSetTime->isChecked()){
        currentTime = currentTime.addSecs(value * secsInHour);
        displayTime(currentTime);
    }
    if (ui->radioButtonSetAlarm->isChecked()){
        alarmTime = alarmTime.addSecs(value * secsInHour);
        displayTime(alarmTime);
    }
}

void MainWindow::minutes_buttonPressed(int value){
    if (ui->radioButtonSetTime->isChecked()){
        currentTime = currentTime.addSecs(value * secsInMinute);
        displayTime(currentTime);
    }
    if (ui->radioButtonSetAlarm->isChecked()){
        alarmTime = alarmTime.addSecs(value * secsInMinute);
        displayTime(alarmTime);
    }
}

void MainWindow::seconds_buttonPressed(int value){
    if (ui->radioButtonSetTime->isChecked()){
        currentTime = currentTime.addSecs(value);
        displayTime(currentTime);
    }
    if (ui->radioButtonSetAlarm->isChecked()){
        alarmTime = alarmTime.addSecs(value);
        displayTime(alarmTime);
    }
}

void MainWindow::stopSoundEffect(){
    if (soundEffect.isPlaying()) soundEffect.stop();
    ui->pbStopAlarm->setEnabled(false);
}

void MainWindow::checkBoxAlarmEnabled_stateChanged(int state){
    Q_UNUSED(state)
    stopSoundEffect();
}

void MainWindow::soundEffect_playingChanged()
{
    ui->pbStopAlarm->setEnabled(soundEffect.isPlaying());
}
