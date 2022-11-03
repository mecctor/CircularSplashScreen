#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
protected:
    void setProgressValue(int);
    void timerEvent(QTimerEvent *event)override;
private:
    Ui::MainWindow *ui;
    int m_timerId;
};
#endif // MAINWINDOW_H
