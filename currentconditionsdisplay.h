#ifndef CURRENTCONDITIONSDISPLAY_H
#define CURRENTCONDITIONSDISPLAY_H

#include <QWidget>
#include <QLCDNumber>
#include "observer.h"
#include "DisplayElement.h"
#include "subject.h"

class CurrentConditionsDisplay : public QWidget, public Observer, public DisplayElement
{
    Q_OBJECT
private:
    float temperature;
    float humidity;
    float pressure;
    Subject *weatherData;
    QLCDNumber *lcdTemp;
    QLCDNumber *lcdHumid;
    QLCDNumber *lcdPres;
public:
    explicit CurrentConditionsDisplay(Subject*, QWidget *parent = nullptr);
    void display();
    void update(float,float,float);
};

#endif // CURRENTCONDITIONSDISPLAY_H
