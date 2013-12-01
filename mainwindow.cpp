#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stereoVision(new StereoVision)
{
    ui->setupUi(this);

    //Just for check

    Mat leftImage = imread("/home/haskis/Pictures/leftImage.jpg",CV_LOAD_IMAGE_GRAYSCALE);

    Mat rightImage = imread("/home/haskis/Pictures/rightImage.jpg",CV_LOAD_IMAGE_GRAYSCALE);

    stereoVision->changePatternSize(9,6);
    qDebug()<<stereoVision->addSampleToCalibration(leftImage,rightImage);

    imshow("a", leftImage);
    imshow("b", rightImage);

}

MainWindow::~MainWindow()
{
    delete ui;
}
