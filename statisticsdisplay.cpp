#include "statisticsdisplay.h"

StatisticsDisplay::StatisticsDisplay(QWidget *parent) : QWidget(parent)
{
    lcdTemp = new QLCDNumber(this);
    lcdTemp->setGeometry(100,100, 300, 50);
    lcdTemp->show();

    lcdMin = new QLCDNumber(this);
    lcdMin->setGeometry(100,200, 300, 50);
    lcdMin->show();

    lcdMax = new QLCDNumber(this);
    lcdMax->setGeometry(100,300, 300, 50);
    lcdMax->show();
}

void StatisticsDisplay::display()
{
    lcdTemp->display(temp);
    lcdMin->display(min_temp);
    lcdMax->display(max_temp);
}

void StatisticsDisplay::on_temp(float t, float min, float max)
{
    this->temp= t;
    this->min_temp = min;
    this->max_temp = max;
    this->display();
}
