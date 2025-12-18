#include <AnalogClock.h>

AnalogClock::AnalogClock(QWidget* parent) : QWidget(parent){
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&QWidget::update));
    timer->start(16);
}


void AnalogClock::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.fillRect(rect(), "#D3D3D3");
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(width()/2, height()/2);
    painter.rotate(-90);
    painter.setPen(QPen((Qt::black), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setBrush(Qt::gray);
    double radius = 0.45 * qMin(width(), height());
    painter.drawEllipse(-radius, - radius, 2*radius, 2*radius);



    for(int i = 1; i <= 12; ++i) {
        painter.save();
        painter.rotate(i * 30);
        painter.setPen(QPen((Qt::black), 2));
        painter.drawLine(radius*8/9, 0, radius, 0);
        painter.translate(radius*7/9, 0);
        painter.rotate(-(i * 30) + 90);
        QFont font("GeneralFont", radius/9);
        painter.setFont(font);
        QRect rect(-radius/9, -radius/9, 2*radius/9, 2*radius/9);
        painter.drawText(rect, Qt::AlignCenter, QString::number(i));
        painter.restore();
    }

    QTime time = QTime::currentTime();
    double secondsAngle = (time.second() + time.msec() / 1000.0) * 6;
    double minutesAngle = time.minute() * 6 + time.second() * 0.1;
    double hoursAngle = time.hour() % 12 * 30 + time.minute() * 0.5 + time.second() * 0.5 / 60;

    painter.setPen(QPen((Qt::red), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.save();
    painter.rotate(secondsAngle);
    painter.drawLine(0, 0, radius*8/9, 0);
    painter.restore();

    painter.setPen(QPen((Qt::white), 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.save();
    painter.rotate(minutesAngle);
    painter.drawLine(0, 0, radius*7/9, 0);
    painter.restore();

    painter.setPen(QPen((Qt::white), 7, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.save();
    painter.rotate(hoursAngle);
    painter.drawLine(0, 0, radius*5/9, 0);
    painter.restore();

    painter.setBrush(Qt::black);
    painter.drawEllipse(-5, -5, 10, 10);
}
