#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "subject.h"
#include <QList>
#include <QTimer>
#include <ctime>
#include <iostream>


class WeatherData : public Subject
{
private:
    QList<Observer*> observers;
    float temperature;
    float humidity;
    float pressure;
    QTimer *timer;
public:
    WeatherData();
    void registerObserver(Observer*);
    void removeObserver(Observer*);
    void notifyObservers();
    void measurementsChanged();
    void setMeasurements(float, float, float);
private slots:
    void on_timer();
};

#endif // WEATHERDATA_H
