#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stereovision.h>
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonCalibrate_clicked();

    void showParameters();
    void on_pushButtonRectify_clicked();


    void on_saveButton_clicked();

    void on_loadButton_clicked();

signals:
    void calibrationDone();

private:
    Ui::MainWindow *ui;

    StereoVision *stereoVision;

    cv::Mat leftImage;
    cv::Mat rightImage;


    cv::Mat leftImage2;
    cv::Mat rightImage2;
    bool calibrationStatus;
};

#endif // MAINWINDOW_H
