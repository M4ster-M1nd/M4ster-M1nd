#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#define MOVEMENT 5

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->button_no->setGeometry(160,100,80,26);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mouseMoveEvent(QMouseEvent* event){
    qDebug()<<event->pos();
    QPoint posOnCentralWidget = event->pos() - ui->centralwidget->pos();
    int x = posOnCentralWidget.x();
    int y = posOnCentralWidget.y();

    QRect no_geometry = ui->button_no->geometry();

    move_button(x,y,no_geometry);

    QMainWindow::mouseMoveEvent(event);
}

void MainWindow::move_button(int x,int y,QRect geo){

    QRect r = geo.marginsAdded(QMargins(10, 10, 10, 10));
    if (!r.contains(QPoint(x, y)))
        return;

    int new_x,new_y;

    new_x=ui->button_no->x();
    new_y=ui->button_no->y();
    if ((x>=new_x+geo.width())&&(x-new_x<90)) {
    new_x-=MOVEMENT;
    }
    if ((y>=new_y+geo.height())&&(y-new_y<36)) {
    new_y-=MOVEMENT;
    }
    if ((x<new_x)&&(new_x-x<20)) {
    new_x+=MOVEMENT;
    }
    if ((y<new_y)&&(new_y-y<36)) {
    new_y+=MOVEMENT;
    }
    if ((new_x<20)||(new_y<20)||(new_x>780)||(new_y>580)) {
        new_x=160;
        new_y=100;
    }
    ui->button_no->setGeometry(new_x,new_y,geo.width(),geo.height());

    r = geo.marginsAdded(QMargins(70,20,70,20));
    if ((r.contains(ui->button_yes->geometry()))||(r.contains(ui->label->geometry()))){
        ui->button_no->setGeometry(160,100,geo.width(),geo.height());

    }
}


