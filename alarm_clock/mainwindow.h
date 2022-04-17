#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>
#include <QDir>
#include <QSoundEffect>

#define HOUR 3600000
#define MINUTE 60000
#define SECOUND 1000

#include <QMainWindow>

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
  QTimer *timer = new QTimer(this);
  QTime time = QTime::currentTime();
  QTime alarmTime;
  QTime storedAlarm;
  QSoundEffect effect;
  int hourShift=0,minShift=0,secShift=0;

private slots:
  void timerSlot();
  void alarmChecked(bool checked);
  void timeChecked(bool checked);
  void lcdDisplay();
  void syncClicked();
  void hourPlusClicked();
  void hourMinusClicked();
  void minPlusClicked();
  void minMinusClicked();
  void secPlusClicked();
  void secMinusClicked();
  void on_pushKillAlarm_clicked();
  void on_alarmBox_stateChanged();
};
#endif // MAINWINDOW_H
