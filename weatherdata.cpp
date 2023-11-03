#include "weatherdata.h"

WeatherData::WeatherData()
{
    timer = new QTimer(this);
    timer->setInterval(2000);
    timer->start();

    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void WeatherData::registerObserver(Observer *o)
{
    observers.append(o);
}

void WeatherData::removeObserver(Observer *o)
{
    auto iter = observers.begin();
    while (iter != observers.end()) {
        if (*iter == o) {
        iter = observers.erase(iter);
        }
        else {
            iter++;
        }
    }
}

void WeatherData::notifyObservers()
{
    for (auto iter : observers) {
        ((Observer*)iter)->update(temperature, humidity, pressure);
    }
}

void WeatherData::measurementsChanged() {
    notifyObservers();
}

void WeatherData::setMeasurements(float, float, float) {
    this->temperature = temperature;
    this->humidity = humidity;
    this->pressure = pressure;
    measurementsChanged();
}

void WeatherData::on_timer()
{
    temperature = std::rand() % 60 - 30;
    humidity = std::rand() % 60 - 30;
    pressure = std::rand() % 60 - 30;
    measurementsChanged();
}
