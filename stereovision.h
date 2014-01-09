#ifndef STEREOVISION_H
#define STEREOVISION_H

#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>


using namespace cv;

class StereoVision
{

public:
    StereoVision();
    bool addSampleToCalibration(Mat &leftImage, Mat &rightImage);
    bool calibrateStereoCameras();
    bool rectifyStereoCameras(Mat &leftImage, Mat &rightImage,Mat &leftImage2, Mat &rightImage2);

    void setPatternSize(Size x){ patternSize =x;}
    void setPatternSize(int x, int y){ patternSize = Size(x,y);}
    void setImageSize(Size x) { imageSize= x;}

    vector<vector<Point2f> > imagePoints[2];
    vector<vector<Point3f> > objectPoints;
    double getCameraValueAt(int x,int y, char camera) const;  // camera='L','R' -Left,Right
    void saveCalibration(std::string path);
    void loadCalibration(std::string path);
public:

    //Calibration Begin

    int samplesCounter;
    int goodSamplesCounter;
    int minSamples;
    float squareSize; //size of calibration pattern

    Size patternSize; //Number of inner corners per a chessboard row and column for (8x8) board it's (7x7)
    Size imageSize;
    Mat cameraMatrix[2], distCoeffs[2];
    Mat R, T, E, F,R1,R2,P1,P2,Q,rmap[2][2];
    StereoSGBM sgbm;
};

#endif // STEREOVISION_H
