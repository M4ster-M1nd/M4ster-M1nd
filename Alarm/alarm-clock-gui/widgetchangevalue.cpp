#include "widgetchangevalue.h"
#include "ui_widgetchangevalue.h"

WidgetChangeValue::WidgetChangeValue(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::WidgetChangeValue)
{
    ui->setupUi(this);

    this->setFrameShape(QFrame::Box);
    this->setFrameShadow(QFrame::Sunken);
    timer.setInterval(timerInterval);
    connect(ui->toolButtonInc, SIGNAL(clicked()), this, SLOT(toolButtonInc_clicked()));
    connect(ui->toolButtonInc, SIGNAL(pressed()), this, SLOT(toolButtonInc_pressed()));
    connect(ui->toolButtonInc, SIGNAL(released()), this, SLOT(toolButtonInc_released()));

    connect(ui->toolButtonDec, SIGNAL(clicked()), this, SLOT(toolButtonDec_clicked()));
    connect(ui->toolButtonDec, SIGNAL(pressed()), this, SLOT(toolButtonDec_pressed()));
    connect(ui->toolButtonDec, SIGNAL(released()), this, SLOT(toolButtonDec_released()));

    connect(&timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
}

WidgetChangeValue::~WidgetChangeValue()
{
    delete ui;
}

QString WidgetChangeValue::title() const {return ui->label->text();}

void WidgetChangeValue::setTitle(QString title) {ui->label->setText(title);}

void WidgetChangeValue::toolButtonInc_clicked(){
    emit buttonPressed(1);
}

void WidgetChangeValue::toolButtonDec_clicked(){
    emit buttonPressed(-1);
}

void WidgetChangeValue::toolButtonInc_pressed(){
    valueToSend = 1;
    timerStart();
}

void WidgetChangeValue::toolButtonInc_released(){
    timer.stop();
}

void WidgetChangeValue::toolButtonDec_pressed(){
    valueToSend = -1;
    timerStart();
}

void WidgetChangeValue::toolButtonDec_released(){
    timer.stop();
}

void WidgetChangeValue::timer_timeout(){
    if (waitCyclesCounter > 0) {
        --waitCyclesCounter;
        return;
    }
    emit buttonPressed(valueToSend);
}
