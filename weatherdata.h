#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QList>
#include <QTimer>
#include <ctime>
#include <iostream>


class WeatherData : public QObject
{
    Q_OBJECT
private:
    float temperature;
    float humidity;
    float pressure;
    float min_temp;
    float max_temp;
    QTimer *timer;
public:
    WeatherData();
private slots:
    void on_timer();
signals:
    void update(float,float,float);
    void temp(float,float, float);
};

#endif // WEATHERDATA_H
