#ifndef STATISTICSDISPLAY_H
#define STATISTICSDISPLAY_H

#include <QWidget>
#include <QLCDNumber>

class StatisticsDisplay : public QWidget
{
    Q_OBJECT
private:
    float temp;
    float min_temp;
    float max_temp;
    QLCDNumber *lcdTemp;
    QLCDNumber *lcdMin;
    QLCDNumber *lcdMax;
public:
   explicit StatisticsDisplay(QWidget *parent = nullptr);
    void display();
private slots:
    void on_temp(float,float,float);
};

#endif // STATISTICSDISPLAY_H
