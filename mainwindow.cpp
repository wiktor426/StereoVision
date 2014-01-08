#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stereoVision(new StereoVision),
    calibrationStatus(false)

{
    ui->setupUi(this);
    connect (this,SIGNAL(calibrationDone()),this,SLOT(showParameters()));

    stereoVision->setPatternSize(ui->spinBoxPatternSizeX->value(),
                                 ui->spinBoxPatternSizeY->value());

  //  drawChessboardCorners(leftImage,Size(9,6), stereoVision->imagePoints[0][4], true);
   // drawChessboardCorners(rightImage,Size(9,6), stereoVision->imagePoints[1][4], true);
//     drawChessboardCorners(leftImage2,Size(9,6), stereoVision->imagePoints[0][4], true);
  //  drawChessboardCorners(rightImage2,Size(9,6), stereoVision->imagePoints[1][4], true);
//    imshow("A",leftImage);
//    imshow("B",rightImage);
//    imshow("C",leftImage2);
//    imshow("D",rightImage2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCalibrate_clicked()
{
    QString url= ui->lineEditCalibrationData->text();

   for(int i=1; i<9;i++){
        QString left=url+"left0"+QString::number(i)+".jpg";
        QString right=url+"right0"+QString::number(i)+".jpg";

        String leftS=left.toStdString();
        String rightS=right.toStdString();

        qDebug()<<left<<right;

        leftImage = imread(leftS,CV_LOAD_IMAGE_GRAYSCALE);
        rightImage = imread(rightS,CV_LOAD_IMAGE_GRAYSCALE);
        //For later changes--------------------------
        if(i==1){
            stereoVision->setImageSize(leftImage.size());
        }
        //-------------------------------------------
        stereoVision->addSampleToCalibration(leftImage,rightImage);
    }

    stereoVision->setImageSize(leftImage.size());
    calibrationStatus = stereoVision->calibrateStereoCameras();
    emit calibrationDone();
}


void MainWindow::showParameters(){
    qDebug()<<"showParameters";
    ui->labelA1_1->setText(QString::number(stereoVision->getCameraValueAt(0,0,'L')));
    ui->labelA1_2->setText(QString::number(stereoVision->getCameraValueAt(0,1,'L')));
    ui->labelA1_3->setText(QString::number(stereoVision->getCameraValueAt(0,2,'L')));

    ui->labelA2_1->setText(QString::number(stereoVision->getCameraValueAt(1,0,'L')));
    ui->labelA2_2->setText(QString::number(stereoVision->getCameraValueAt(1,1,'L')));
    ui->labelA2_3->setText(QString::number(stereoVision->getCameraValueAt(1,2,'L')));

    ui->labelA3_1->setText(QString::number(stereoVision->getCameraValueAt(2,0,'L')));
    ui->labelA3_2->setText(QString::number(stereoVision->getCameraValueAt(2,1,'L')));
    ui->labelA3_3->setText(QString::number(stereoVision->getCameraValueAt(2,2,'L')));

    ui->labelB1_1->setText(QString::number(stereoVision->getCameraValueAt(0,0,'R')));
    ui->labelB1_2->setText(QString::number(stereoVision->getCameraValueAt(0,1,'R')));
    ui->labelB1_3->setText(QString::number(stereoVision->getCameraValueAt(0,2,'R')));

    ui->labelB2_1->setText(QString::number(stereoVision->getCameraValueAt(1,0,'R')));
    ui->labelB2_2->setText(QString::number(stereoVision->getCameraValueAt(1,1,'R')));
    ui->labelB2_3->setText(QString::number(stereoVision->getCameraValueAt(1,2,'R')));

    ui->labelB3_1->setText(QString::number(stereoVision->getCameraValueAt(2,0,'R')));
    ui->labelB3_2->setText(QString::number(stereoVision->getCameraValueAt(2,1,'R')));
    ui->labelB3_3->setText(QString::number(stereoVision->getCameraValueAt(2,2,'R')));
}

void MainWindow::on_pushButtonRectify_clicked()
{
    if(calibrationStatus == true){
        String leftS=ui->lineEditLeftImage->text().toStdString();
        String rightS= ui->lineEditRightImage->text().toStdString();

        leftImage = imread(leftS,CV_LOAD_IMAGE_GRAYSCALE);
        rightImage = imread(rightS,CV_LOAD_IMAGE_GRAYSCALE);

        stereoVision->rectifyStereoCameras(leftImage,rightImage,leftImage2,rightImage2);


       // undistortPoints( stereoVision->imagePoints[0][4], stereoVision->imagePoints[0][4],stereoVision->cameraMatrix[0], stereoVision->distCoeffs[0],noArray(),stereoVision->cameraMatrix[0]);
       // undistortPoints( stereoVision->imagePoints[1][4], stereoVision->imagePoints[1][4],stereoVision->cameraMatrix[1], stereoVision->distCoeffs[1],noArray(),stereoVision->cameraMatrix[1]);
       // drawChessboardCorners(leftImage2, Size(9,6), stereoVision->imagePoints[0][4], true);
       // drawChessboardCorners(rightImage2, Size(9,6), stereoVision->imagePoints[1][4], true);

       // imshow("leftAfter",leftImage2);
       // imshow("rightAfter",rightImage2);
    }

    else
        qDebug()<<"Calibration is needed to proceed";
}

