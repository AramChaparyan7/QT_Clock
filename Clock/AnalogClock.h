#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QPainter>

class AnalogClock : public QWidget {
    Q_OBJECT

public:
    QTimer* timer;
    AnalogClock(QWidget* parent = nullptr);
protected:
    void paintEvent(QPaintEvent* event) override;
};


#endif // ANALOGCLOCK_H
