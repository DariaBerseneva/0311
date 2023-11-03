#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    weatherData = new WeatherData();
    statisticsDisplay = new StatisticsDisplay();
    statisticsDisplay->setGeometry(50,50, 600,800);
    statisticsDisplay->show();

    connect(weatherData, SIGNAL(temp(float,float,float)), statisticsDisplay, SLOT(on_temp(float,float,float)));

    currentDisplay = new CurrentConditionsDisplay();
    currentDisplay->setGeometry(400,50, 600,800);
    currentDisplay->show();

    connect(weatherData, SIGNAL(update(float,float,float)), currentDisplay, SLOT(on_update(float,float,float)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

