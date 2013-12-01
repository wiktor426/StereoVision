#include "stereovision.h"




StereoVision::StereoVision()
{

}


bool StereoVision::addSampleToCalibration(Mat &leftImage, Mat &rightImage){

    //
    addedCalibrationSamplesCounter++;

    vector<Point2f> corners[2];

    bool result;

    result = findChessboardCorners(leftImage,
                                   patternSize,
                                   corners[0],
                                   CALIB_CB_ADAPTIVE_THRESH+CALIB_CB_NORMALIZE_IMAGE );
    if(result)
        result = findChessboardCorners(rightImage,
                                       patternSize,
                                       corners[1],
                                       CALIB_CB_ADAPTIVE_THRESH+CALIB_CB_NORMALIZE_IMAGE );

    //We accept only samples with full visibility of corners
    if(result)
        acceptedCalibrationSamplesCounter++;
    else
        return false;

    //If we found corners then we need to do some subpix corners interpolation

    cornerSubPix(leftImage, corners[0], Size(11, 11), Size(-1, -1),
                 TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.1));


    cornerSubPix(rightImage, corners[1], Size(11, 11), Size(-1, -1),

                 TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.1));

    //For Check
    drawChessboardCorners(leftImage,patternSize, corners[0], result);
    drawChessboardCorners(rightImage,patternSize, corners[1], result);
    //

    imagePoints[0].push_back(corners[0]);
    imagePoints[1].push_back(corners[1]);

    return true;

}
