#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void turnOffTraffiLight();
    void turnOnTrafficLight();

    void startGreenTimer();
    void startYellowTimer();
    void startRedTimer();
    void startSecondYellowTimer();

private:
    Ui::MainWindow *ui;
    QTimer *_greenTimer;
    QTimer *_yellowTimer;
    QTimer *_redTimer;
    QTimer *_secondYellowTimer;
};

#endif // MAINWINDOW_HPP
