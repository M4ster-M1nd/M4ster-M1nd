#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPainterPath>
#include <QTimer>
#include <QScreen>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    //int direction=-1;
    QTimer *timer;
    QPolygon polygon;
    float time;
    QRect m_screenGeometry;
    QSize direction;
    int move=1;
    QTransform transform;


private slots:
    void timer_slot();
protected:
   // virtual void paintEvent(QPaintEvent* event);
    void init();
    int x1=10,x2=200,x3=450,x4=100,x5=10;
    int y1=20,y2=60,y3=250,y4=500,y5=200;
    QVector<int> ve_x;
    QVector<int> ve_y;

};
#endif // MAINWINDOW_H
