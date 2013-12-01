#ifndef STEREOVISION_H
#define STEREOVISION_H

#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;

class StereoVision
{

public:
    StereoVision();
    bool addSampleToCalibration(Mat &leftImage, Mat &rightImage);

    void changePatternSize(Size x){ patternSize =x;}
    void changePatternSize(int x, int y){ patternSize = Size(x,y);}
private:

    //Calibration Begin

    int addedCalibrationSamplesCounter;
    int acceptedCalibrationSamplesCounter;

    vector<vector<Point2f> > imagePoints[2];
    vector<vector<Point3f> > objectPoints;

    Size patternSize; //Number of inner corners per a chessboard row and column for (8x8) board it's (7x7)

};

#endif // STEREOVISION_H
