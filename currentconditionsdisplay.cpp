#include "currentconditionsdisplay.h"

CurrentConditionsDisplay::CurrentConditionsDisplay(QWidget *parent) : QWidget(parent)
{
    lcdTemp = new QLCDNumber(this);
    lcdTemp->setGeometry(100,100, 300, 50);
    lcdTemp->show();

    lcdHumid = new QLCDNumber(this);
    lcdHumid->setGeometry(100,200, 300, 50);
    lcdHumid->show();

    lcdPres = new QLCDNumber(this);
    lcdPres->setGeometry(100,300, 300, 50);
    lcdPres->show();
}

void CurrentConditionsDisplay::display()
{
    lcdTemp->display(temperature);
    lcdHumid->display(humidity);
    lcdPres->display(pressure);
}

void CurrentConditionsDisplay::on_update(float t, float h, float p)
{
    this->temperature = t;
    this->humidity = h;
    this->pressure = p;
    this->display();
}

