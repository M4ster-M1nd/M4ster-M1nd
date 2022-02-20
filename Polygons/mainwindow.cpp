#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
       setAttribute(Qt::WA_TranslucentBackground);
       */
       time=0;
       timer= new QTimer(this);
       connect(timer, SIGNAL (timeout()), this, SLOT (timer_slot()) );
       timer->start(30);

       polygon<<QPoint(x1,y1)<<QPoint(x2,y2)<<QPoint(x3,y3)<<QPoint(x4,y4)<<QPoint(x5,y5);

    QPalette palit(this->palette());
    palit.setColor(QPalette::Window,Qt::darkRed);

    this->setPalette(palit);

    this->resize(minimumSize());


    QScreen *screen = QGuiApplication::primaryScreen();

    m_screenGeometry.setX(screen->availableGeometry().center().x()/2);
    m_screenGeometry.setY(screen->availableGeometry().center().y()/2);
    this->setGeometry(m_screenGeometry);
    m_screenGeometry = screen->availableGeometry();
    this->setMinimumSize(screen->availableGeometry().center().x(),screen->availableGeometry().center().y());
    this->setMaximumSize(m_screenGeometry.size());


    direction.setHeight(8);
    direction.setWidth(4);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::timer_slot() {


  if(this->width() == this->maximumWidth() || this->width()==minimumWidth() || this->height() == maximumHeight() || this->height() == minimumHeight())
    {

      move*=-1;
      direction.setHeight(direction.height()*(-1));
      direction.setWidth(direction.width()*(-1));

    }

      for (int i=0;i<polygon.length();++i)
      {
          switch (i) {
            case 0:
              polygon[i].setX(polygon[i].x()-(2*move));
              polygon[i].setY(polygon[i].y()-(4*move));
              break;
            case 1:
              polygon[i].setX(polygon[i].x()+(2*move));
              polygon[i].setY(polygon[i].y()-(16*move));
              break;
            case 2:
              polygon[i].setX(polygon[i].x()+(8*move));
              polygon[i].setY(polygon[i].y()+(4*move));
              break;
            case 3:
              polygon[i].setX(polygon[i].x()+(4*move));
              polygon[i].setY(polygon[i].y()+(8*move));
              break;
            case 4:
              polygon[i].setX(polygon[i].x()-(4*move));
              polygon[i].setY(polygon[i].y()+(8*move));
              break;

            default:
              break;
            }



      }
      this->setGeometry((this->geometry().x()-(direction.width()/2)),(this->geometry().y()-(direction.height()/2)),this->geometry().width(),this->geometry().height());
      this->resize(this->size()+direction);
    init();

}

void MainWindow::init()
{

    QRegion mask(polygon);
    this->setMask(mask);
}



