#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progress->setLayoutDirection(Qt::LeftToRight);
    timer = new QTimer(this);
    ui->progress->setValue(0);
    connect(timer, SIGNAL(timeout()), this, SLOT(change_value()));
    connect(ui->start_button,SIGNAL(clicked()),this, SLOT(start()));

}

void MainWindow::next_step(){
    if (ui->progress->value()==100){
        step=-1;
}
    if ((ui->progress->value()==0)&&(step==-1)){
        step=1;
        change_orientation();
}

}


void MainWindow::change_orientation(){
switch (ui->progress->orientation())
{
case Qt::Horizontal:
    if ((ui->progress->layoutDirection())==Qt::RightToLeft){
        ui->progress->setLayoutDirection(Qt::LeftToRight);
        ui->progress->setOrientation(Qt::Vertical);
    }
    else
        ui->progress->setLayoutDirection(Qt::RightToLeft);


    break;

case Qt::Vertical:
    if ((ui->progress->layoutDirection())==Qt::LeftToRight){
        ui->progress->setLayoutDirection(Qt::RightToLeft);
       }
       else{
       ui->progress->setLayoutDirection(Qt::LeftToRight);
       ui->progress->setOrientation(Qt::Horizontal);
    }
    break;


}
}

void MainWindow::change_value(){
    if (timer->remainingTime()==0)
    timer->start(10);
    ui->progress->setValue(ui->progress->value()+step);

    if (ui->progress->orientation()==Qt::Horizontal){
    setFixedWidth(width() + step);
    }
    else {
    setFixedHeight(height() + step);
    }

    int value = ui->progress->value();
    ui->progress->setValue(value);
    next_step();

}

void MainWindow::start(){
   ui->start_button->setText("Стоп");
    if (timer->isActive()){
        timer->stop();
        ui->start_button->setText("Запуск");
    }
    else{
        timer->start(10);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}



