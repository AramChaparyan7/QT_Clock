#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    clock = new AnalogClock(this);
    setMinimumHeight(400);
    setMinimumWidth(400);
    setCentralWidget(clock);
}

MainWindow::~MainWindow() {}
