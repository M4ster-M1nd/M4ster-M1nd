#include "calculator.h"
#include "ui_calculator.h"

double num_first;

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect(ui->Button_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->Button_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->Button_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->Button_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->Button_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->Button_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->Button_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->Button_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->Button_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->Button_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->Button_neg,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->Button_perc,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->Button_div,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->Button_mult,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->Button_minus,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->Button_plus,SIGNAL(clicked()),this,SLOT(math()));

    ui->Button_div->setCheckable(true);
    ui->Button_mult->setCheckable(true);
    ui->Button_minus->setCheckable(true);
    ui->Button_plus->setCheckable(true);

}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::digits_numbers(){

   QPushButton *button = (QPushButton *) sender();

   double all_numbers;
   QString new_label;

   if(ui->result->text().contains(".") && button->text()=='0') {
       new_label = ui->result->text()+button->text();
   }
   else {
   all_numbers = (ui->result->text() + button->text()).toDouble();
   new_label = QString::number(all_numbers,'g', 16);
   }
   ui->result->setText(new_label);
}

void Calculator::operations(){

   QPushButton *button = (QPushButton *) sender();

   double all_numbers;
   QString new_label;
   if (button->text()=="+/-"){
    all_numbers = (ui->result->text()).toDouble();
    all_numbers = all_numbers*(-1);
    new_label = QString::number(all_numbers,'g', 16);
    ui->result->setText(new_label);
   } else if ((button->text()=="%")) {
       all_numbers = (ui->result->text()).toDouble();
       all_numbers = all_numbers*(0.01);
       new_label = QString::number(all_numbers,'g', 16);
       ui->result->setText(new_label);
   }

}

void Calculator::on_Button_dot_clicked()
{
    if (!(ui->result->text().contains('.')))
     ui->result->setText(ui->result->text()+".");
}

void Calculator::on_Button_clear_clicked()
{
    ui->result->setText("0");
    ui->Button_plus->setChecked(false);
    ui->Button_minus->setChecked(false);
    ui->Button_div->setChecked(false);
    ui->Button_mult->setChecked(false);

}

void Calculator::math(){
    QPushButton *button = (QPushButton *) sender();
    num_first=ui->result->text().toDouble();
    ui->result->setText("");
    button->setChecked(true);

}



void Calculator::on_Button_eq_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second=ui->result->text().toDouble();

    if(ui->Button_plus->isChecked()){
        labelNumber=num_first+num_second;
        new_label = QString::number(labelNumber,'g', 16);
        ui->result->setText(new_label);
        ui->Button_plus->setChecked(false);
    }
    else if (ui->Button_minus->isChecked()) {
        labelNumber=num_first-num_second;
        new_label = QString::number(labelNumber,'g', 16);
        ui->result->setText(new_label);
        ui->Button_minus->setChecked(false);

    }
    else if (ui->Button_div->isChecked()) {
        if (num_second==0){
            ui->result->setText("0");
        }
        labelNumber=num_first/num_second;
        new_label = QString::number(labelNumber,'g', 16);
        ui->result->setText(new_label);
        ui->Button_div->setChecked(false);

    }
    else if (ui->Button_mult->isChecked()) {
        labelNumber=num_first*num_second;
        new_label = QString::number(labelNumber,'g', 16);
        ui->result->setText(new_label);
        ui->Button_mult->setChecked(false);
    }
}
