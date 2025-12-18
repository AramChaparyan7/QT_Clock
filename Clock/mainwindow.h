#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "AnalogClock.h"
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    AnalogClock* clock;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
