#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    weatherData = new WeatherData();
    currentDisplay = new CurrentConditionsDisplay(weatherData, this);
    currentDisplay->setGeometry(50,50, 600,800);
    currentDisplay->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

