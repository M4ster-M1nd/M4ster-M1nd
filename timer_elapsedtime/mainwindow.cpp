#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->lcdNumber->hide();

  beep.setSource(QUrl::fromLocalFile(QApplication::applicationDirPath()+QDir::separator()+"beep.wav"));
  beep.setLoopCount(3);


  timer= new QTimer(this);
  ui->spinBox_Days->setMaximum(364);
  ui->spinBox_Hours->setMaximum(23);
  ui->spinBox_Minutes->setMaximum(59);
  ui->spinBox_Seconds->setMaximum(59);
  ui->spinBox_Milisecounds->setMaximum(999);
  //el_timer = new QElapsedTimer(this);
  connect(timer, SIGNAL (timeout()), this, SLOT (timer_slot()) );
}

MainWindow::~MainWindow()
{
  delete ui;
}

int MainWindow::time_conversion(){
  int elapsedTime=
    (ui->spinBox_Days->value()*DAY)+
    (ui->spinBox_Hours->value()*HOUR)+
    (ui->spinBox_Minutes->value()*MINUTE)+
    (ui->spinBox_Seconds->value()*SECOUND)+
    ui->spinBox_Milisecounds->value();
  return elapsedTime;
}

void MainWindow::timer_slot() {

  if (stored_time==0) {
      timer->stop();
      ui->start_stop_Button->setText("START");
      beep.play();
      ui->spinBox_Days->show();
      ui->spinBox_Hours->show();
      ui->spinBox_Minutes->show();
      ui->spinBox_Seconds->show();
      ui->spinBox_Milisecounds->show();
      ui->label->show();
      ui->label_2->show();
      ui->label_3->show();
      ui->label_4->show();
      ui->label_5->show();
      ui->lcdNumber->hide();


    }

    //ui->start_stop_Button->setText(QString::number(stored_time));
    int day,hour,min,sec,mil;
    day=(stored_time/DAY);
    hour=(stored_time%DAY/HOUR);
    min=(stored_time%HOUR/MINUTE);
    sec=(stored_time%MINUTE/SECOUND);
    mil=((stored_time)%SECOUND);

    ui->spinBox_Days->setValue(day);
    ui->spinBox_Hours->setValue(hour);
    ui->spinBox_Minutes->setValue(min);
    ui->spinBox_Seconds->setValue(sec);
    ui->spinBox_Milisecounds->setValue(mil);


    ui->lcdNumber->display(QString::number(day) + " d   " + QString("%1").arg(hour, 2) + " : " + QString("%1").arg(min, 2) + " : " + QString("%1").arg(sec, 2) + " . " + QString("%1").arg(mil, 3));

    --stored_time;

}

void MainWindow::on_start_stop_Button_clicked()
{
  stored_time=time_conversion();

  if (timer->isActive()){
            ui->spinBox_Days->show();
            ui->spinBox_Hours->show();
            ui->spinBox_Minutes->show();
            ui->spinBox_Seconds->show();
            ui->spinBox_Milisecounds->show();
            ui->label->show();
            ui->label_2->show();
            ui->label_3->show();
            ui->label_4->show();
            ui->label_5->show();
            ui->lcdNumber->hide();
      stored_time=time_conversion();
      timer->stop();
      ui->start_stop_Button->setText("START");

  }
  else{
      ui->spinBox_Days->hide();
      ui->label->hide();
      ui->label_2->hide();
      ui->label_3->hide();
      ui->label_4->hide();
      ui->label_5->hide();
      ui->spinBox_Hours->hide();
      ui->spinBox_Minutes->hide();
      ui->spinBox_Seconds->hide();
      ui->spinBox_Milisecounds->hide();

      ui->lcdNumber->setDigitCount(QString::number(time_conversion()).size()+17);
      ui->lcdNumber->show();

      timer->setInterval(1);
      timer->start();
      ui->start_stop_Button->setText("STOP");

    }


}


