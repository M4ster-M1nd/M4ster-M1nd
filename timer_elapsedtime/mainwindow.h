#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QElapsedTimer>
#include <QDir>
#include <QSoundEffect>

#define DAY 86400000
#define HOUR 3600000
#define MINUTE 60000
#define SECOUND 1000

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
  void on_start_stop_Button_clicked();

  void timer_slot();


private:
  Ui::MainWindow *ui;
  QTimer *timer;
  //QElapsedTimer *el_timer;
  long stored_time=0;
  int time_conversion();
  QSoundEffect beep;


};
#endif // MAINWINDOW_H
