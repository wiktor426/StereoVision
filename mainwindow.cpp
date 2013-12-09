#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stereoVision(new StereoVision)

{
    ui->setupUi(this);

    stereoVision->setPatternSize(9,6);
    Mat leftImage;
    Mat rightImage;
    //Just for check
    QString url= "/home/haskis/Pictures/Calibration/";
    for(int i=1; i<6;i++){
        QString left=url+"left0"+QString::number(i)+".jpg";
        QString right=url+"right0"+QString::number(i)+".jpg";
        String leftS=left.toStdString();
        String rightS=right.toStdString();
        qDebug()<<left<<right;

        leftImage = imread(leftS,CV_LOAD_IMAGE_GRAYSCALE);

        rightImage = imread(rightS,CV_LOAD_IMAGE_GRAYSCALE);

        stereoVision->addSampleToCalibration(leftImage,rightImage);
    }
    stereoVision->setImageSize(leftImage.size());
    stereoVision->calibrateStereoCameras();

    drawChessboardCorners(leftImage,Size(9,6), stereoVision->imagePoints[0][4], true);
    drawChessboardCorners(rightImage,Size(9,6), stereoVision->imagePoints[1][4], true);
    imshow("a",rightImage);
    imshow("B",leftImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}
