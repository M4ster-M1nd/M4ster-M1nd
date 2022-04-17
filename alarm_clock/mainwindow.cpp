#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->lcdNumber->setDigitCount(8);
  lcdDisplay();

  connect(ui->radioAlarm, SIGNAL (toggled(bool)), this, SLOT (alarmChecked(bool)) );
  connect(ui->radioTime, SIGNAL (toggled(bool)), this, SLOT (timeChecked(bool)) );
  connect(ui->pushSync, SIGNAL (clicked()), this, SLOT (syncClicked()));
  connect(ui->pushHourPlus, SIGNAL (clicked()), this, SLOT (hourPlusClicked()));
  connect(ui->pushHourMinus, SIGNAL (clicked()), this, SLOT (hourMinusClicked()));
  connect(ui->pushMinPlus, SIGNAL (clicked()), this, SLOT (minPlusClicked()));
  connect(ui->pushMinMinus, SIGNAL (clicked()), this, SLOT (minMinusClicked()));
  connect(ui->pushSecPlus, SIGNAL (clicked()), this, SLOT (secPlusClicked()));
  connect(ui->pushSecMinus, SIGNAL (clicked()), this, SLOT (secMinusClicked()));
  ui->radioTime->setChecked(true);
  timeChecked(true);

  connect(timer, SIGNAL (timeout()), this, SLOT (timerSlot()) );

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::timerSlot(){

  if (ui->radioTime->isChecked()){
  lcdDisplay();
    }
  else
   lcdDisplay();

}

void MainWindow::alarmChecked(bool checked)
{

  if (!checked)
    return;

  if (ui->alarmBox->isChecked()){
      if (alarmTime==QTime::currentTime()){
      effect.setSource(QUrl::fromLocalFile("alarm.wav"));
      effect.setLoopCount(QSoundEffect::Infinite);
      effect.play();
      ui->statusbar->setStatusTip("BEEP!");
        }
    }
}

void MainWindow::timeChecked(bool checked)
{
  if (!checked){
    timer->stop();
    return;
    }

 timer->start(1000);

}

void MainWindow::lcdDisplay()
{

  alarmTime.setHMS(time.hour()+hourShift,time.minute()+minShift,(time.second()+secShift));

  if (ui->radioTime->isChecked()){
  QString text = QTime::currentTime().toString("hh:mm:ss");
   ui->lcdNumber->display(text);
    }
  else
    {

    QString text = alarmTime.toString("hh:mm:ss");
      ui->lcdNumber->display(text);

    }
}


void MainWindow::syncClicked()
{
    hourShift=0;
    minShift=0;
    secShift=0;
    lcdDisplay();
}

void MainWindow::hourPlusClicked()
{
  if ((alarmTime.hour()+hourShift)>23){
  return;
    }
  ++hourShift;
  lcdDisplay();
}

void MainWindow::hourMinusClicked()
{
  if ((alarmTime.hour()+hourShift)<0){
  return;
    }
  --hourShift;
  lcdDisplay();
}
void MainWindow::minPlusClicked()
{
  if ((alarmTime.minute()+minShift)>59){
  return;
    }
   ++minShift;
  lcdDisplay();
}

void MainWindow::minMinusClicked()
{
  if ((alarmTime.minute()+minShift)<0){
  return;
    }
  --minShift;
  lcdDisplay();
}
void MainWindow::secPlusClicked()
{
  if ((alarmTime.second()+secShift)>59){
  return;
    }
  ++secShift;
  lcdDisplay();
}

void MainWindow::secMinusClicked()
{
  if ((alarmTime.second()+secShift)<0){
  return;
    }
  --secShift;
  lcdDisplay();
}

void MainWindow::on_pushKillAlarm_clicked()
{
    effect.stop();
}

void MainWindow::on_alarmBox_stateChanged()
{
ui->statusbar->setStatusTip(alarmTime.toString("hh:mm:ss"));
}
