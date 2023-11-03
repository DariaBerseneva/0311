#include "weatherdata.h"

WeatherData::WeatherData()
{
    timer = new QTimer(this);
    timer->setInterval(2000);
    timer->start();

    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void WeatherData::on_timer()
{
    temperature = std::rand() % 60 - 30;
    humidity =  std::rand() % 100 + 700;
    pressure = std::rand() % 101;
    emit update(temperature,humidity,pressure);

    temperature = std::rand() % 60 - 30;
    min_temp = std::rand() % 60 - 30;
    max_temp = std::rand() % 60 - 30;
    emit temp(temperature, min_temp, max_temp);
}
