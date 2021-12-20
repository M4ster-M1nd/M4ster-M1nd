#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QRect>
#include <QMargins>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void mouseMoveEvent(QMouseEvent* event);
private slots:
    void move_button(int x,int y,QRect geo);


private:
    Ui::MainWindow *ui;
    QString position;
    void overlay();
};
#endif // MAINWINDOW_H

