#include "mainwindow.h"
#include "ui_mainwindow.h"
#define USDollar 73.20
#define Euro 86.85

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(convert()));
    ui->textEdit->setAlignment(Qt::AlignHCenter);
    ui->textEdit_2->setAlignment(Qt::AlignHCenter);
    ui->val1->addItems({"RUB","USD","EUR"});
    ui->val2->addItems({"RUB","USD","EUR"});


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::convert(){



   double numbers;
   QString new_label;

   if (ui->val1->currentText()=="RUB"){
       if (ui->val2->currentText()=="RUB"){
           numbers=ui->textEdit->toPlainText().toDouble();
           new_label = QString::number(numbers,'f', 2);
           ui->textEdit_2->setText(new_label);
       }
       if (ui->val2->currentText()=="USD"){
            numbers=ui->textEdit->toPlainText().toDouble()/USDollar;
            new_label = QString::number(numbers,'f', 2);
            ui->textEdit_2->setText(new_label);
       }
       if (ui->val2->currentText()=="EUR"){
           numbers=ui->textEdit->toPlainText().toDouble()/Euro;
           new_label = QString::number(numbers,'f', 2);
           ui->textEdit_2->setText(new_label);

       }
   }
   if (ui->val1->currentText()=="USD"){
       if (ui->val2->currentData()=="USD"){
           numbers=ui->textEdit->toPlainText().toDouble();
           new_label = QString::number(numbers,'f', 2);
           ui->textEdit_2->setText(new_label);
       }
       if (ui->val2->currentText()=="RUB"){
           numbers=ui->textEdit->toPlainText().toDouble()*USDollar;
           new_label = QString::number(numbers,'f', 2);
           ui->textEdit_2->setText(new_label);
       }
       if (ui->val2->currentText()=="EUR"){
           numbers=ui->textEdit->toPlainText().toDouble()/Euro*USDollar;
           new_label = QString::number(numbers,'f', 2);
           ui->textEdit_2->setText(new_label);

       }
   }
   if (ui->val1->currentText()=="EUR"){
       if (ui->val2->currentData()=="EUR"){
           numbers=ui->textEdit->toPlainText().toDouble();
           new_label = QString::number(numbers,'f', 2);
           ui->textEdit_2->setText(new_label);

       }
       if (ui->val2->currentText()=="RUB"){
           numbers=ui->textEdit->toPlainText().toDouble()*Euro;
           new_label = QString::number(numbers,'f', 2);
           ui->textEdit_2->setText(new_label);

       }
       if (ui->val2->currentText()=="USD"){
           numbers=ui->textEdit->toPlainText().toDouble()/USDollar*Euro;
           new_label = QString::number(numbers,'f', 2);
           ui->textEdit_2->setText(new_label);

       }

   }
    ui->textEdit_2->setAlignment(Qt::AlignHCenter);
}

