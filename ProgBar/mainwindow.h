#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void change_value();
    void next_step();
    void start();
    void change_orientation();


private:
    Ui::MainWindow *ui;
    int step=1;
    QTimer *timer;
};
#endif // MAINWINDOW_H
