#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void digits_numbers();
    void on_Button_dot_clicked();
    void operations();
    void on_Button_clear_clicked();
    void math();
    void on_Button_eq_clicked();
};

#endif // CALCULATOR_H
