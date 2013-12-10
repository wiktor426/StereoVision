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
    Mat leftImage2;
    Mat rightImage2;
    //Just for check
    QString url= "/home/wiktor/Pictures/Calibration/";
   for(int i=1; i<9;i++){
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
    stereoVision->rectifyStereoCameras(leftImage,rightImage,leftImage2,rightImage2);
  //  drawChessboardCorners(leftImage,Size(9,6), stereoVision->imagePoints[0][4], true);
   // drawChessboardCorners(rightImage,Size(9,6), stereoVision->imagePoints[1][4], true);
//     drawChessboardCorners(leftImage2,Size(9,6), stereoVision->imagePoints[0][4], true);
  //  drawChessboardCorners(rightImage2,Size(9,6), stereoVision->imagePoints[1][4], true);
    imshow("A",leftImage);
    imshow("B",rightImage);
    imshow("C",leftImage2);
    imshow("D",rightImage2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
