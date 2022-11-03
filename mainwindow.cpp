#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setProgressValue(90);
    m_timerId = startTimer(15);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect *effect  = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(20);
    effect->setXOffset(0);
    effect->setYOffset(0);
    effect->setColor(QColor(0,0,0,100));
    ui->circularBg->setGraphicsEffect(effect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setProgressValue(int value)
{
    QString Qss = "QFrame{"
            "border-radius:150px;"
            "background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:{STOP1} rgba(255, 0, 127, 0), stop:{STOP2} rgba(85, 170, 255, 255))"
        "}";

    auto progress = (100 - value) / 100.0;
    QString stop1;
    auto stop2 = QString::number(progress);
    if((progress ) < 0.001 )//为了保证 stop:的值 在 0-1.0之间
    {
        stop1 = "0.000";
        stop2 = "0.0001";
    }
    else
        stop1 = QString::number(progress - 0.001);


    Qss.replace("{STOP1}",stop1).replace("{STOP2}",stop2);
    ui->circularProgress->setStyleSheet(Qss);
}

void MainWindow::timerEvent(QTimerEvent *event)
{

    if(event->timerId() == m_timerId)
    {
        static int counter = 0;
        if (counter >= 100)
        {
             setProgressValue(counter);;
        }
        else
            setProgressValue(counter);
        if(counter % 10 == 0)
        {
            QString htmlText = R"(<p><span style=" font-size:68pt;">{value}</span><span style=" font-size:58pt; vertical-align:super;">%</span></p>)";
            htmlText.replace("{value}",QString::number(counter));
            ui->labelPercentage->setText(htmlText);
        }
        if(counter > 100)
        {
            close();
        }
        counter = counter +  1.2;
    }
}

