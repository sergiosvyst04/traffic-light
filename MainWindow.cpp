#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->start, &QPushButton::clicked, this, &MainWindow::turnOnTrafficLight);
    connect(ui->stop, &QPushButton::clicked, this, &MainWindow::turnOffTraffiLight);

}

void MainWindow::turnOnTrafficLight()
{
    ui->red->setChecked(true);

    //    ui->green->click();
    _yellowTimer = new QTimer(this);
    _redTimer = new QTimer(this);
    _greenTimer = new QTimer(this);
    _secondYellowTimer = new QTimer(this);

    _yellowTimer->setSingleShot(true);
    _redTimer->setSingleShot(true);
    _greenTimer->setSingleShot(true);
    _secondYellowTimer->setSingleShot(true);


    connect(ui->start, &QPushButton::pressed, this, &MainWindow::startRedTimer);
    connect(_redTimer, &QTimer::timeout, this, &MainWindow::startYellowTimer);
    connect(_yellowTimer, &QTimer::timeout, this, &MainWindow::startGreenTimer);
    connect(_greenTimer, &QTimer::timeout, this, &MainWindow::startSecondYellowTimer);
    connect(_secondYellowTimer, &QTimer::timeout, this, &MainWindow::startRedTimer);
}

void MainWindow::startGreenTimer()
{
    _greenTimer->start(2000);
    connect(_greenTimer, &QTimer::timeout, ui->yellow, &QRadioButton::click);
}

void MainWindow::startSecondYellowTimer()
{
    _secondYellowTimer->start(1000);
    connect(_secondYellowTimer, &QTimer::timeout, ui->red, &QRadioButton::click);
}

void MainWindow::startRedTimer()
{
    _redTimer->start(5000);
    connect(_redTimer, &QTimer::timeout, ui->yellow, &QRadioButton::click);
}

void MainWindow::startYellowTimer()
{
    _yellowTimer->start(1000);
    connect(_yellowTimer, &QTimer::timeout, ui->green, &QRadioButton::click);
}



void MainWindow::turnOffTraffiLight()
{
    ui->green->setAutoExclusive(false);
    ui->green->setChecked(false);
    ui->green->setAutoExclusive(true);

    ui->yellow->setAutoExclusive(false);
    ui->yellow->setChecked(false);
    ui->yellow->setAutoExclusive(true);

    ui->red->setAutoExclusive(false);
    ui->red->setChecked(false);
    ui->red->setAutoExclusive(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}
