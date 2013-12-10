#include "stereovision.h"




StereoVision::StereoVision()

{
    squareSize=0.05;
    cameraMatrix[0] = Mat::eye(3, 3, CV_64F);
    cameraMatrix[1] = Mat::eye(3, 3, CV_64F);
}


bool StereoVision::addSampleToCalibration(Mat &leftImage, Mat &rightImage){


    //
    samplesCounter++;

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
        goodSamplesCounter++;
    else
        return false;

    //If we found corners then we need to do some subpix corners interpolation

    cornerSubPix(leftImage, corners[0], Size(11, 11), Size(-1, -1),
                 TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.1));


    cornerSubPix(rightImage, corners[1], Size(11, 11), Size(-1, -1),

                 TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.1));

    //For Check
    //

    imagePoints[0].push_back(corners[0]);
    imagePoints[1].push_back(corners[1]);

    return true;

}

bool StereoVision::calibrateStereoCameras(){

    if(goodSamplesCounter<minSamples){
        return false;
    }

    //Assign values to objectPoints in object coordinate space
    for(int i = 0; i <goodSamplesCounter ; i++ ){
        objectPoints.push_back(vector<Point3f>());
        {
            for(int j = 0; j < patternSize.height; j++ )
                for(int k = 0; k < patternSize.width; k++ )
                    objectPoints[i].push_back(Point3f(float(j*squareSize), float(k*squareSize), 0));
        }
    }

    //For Check
  //  for(int i=0;i<objectPoints.size();i++)
    //    for(int j=0;j<objectPoints[i].size();j++)
      //      qDebug()<<objectPoints[i][j].x<<objectPoints[i][j].y<<objectPoints[i][j].z;
    //

    double rms = stereoCalibrate(objectPoints, imagePoints[0], imagePoints[1],
                        cameraMatrix[0], distCoeffs[0],
                        cameraMatrix[1], distCoeffs[1],
                        imageSize, R, T, E, F,
                        TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 100, 1e-5),
                        CALIB_FIX_ASPECT_RATIO +
                        CALIB_ZERO_TANGENT_DIST +
                        CALIB_SAME_FOCAL_LENGTH +
                        CALIB_RATIONAL_MODEL +
                        CALIB_FIX_K3 + CALIB_FIX_K4 + CALIB_FIX_K5);

   // setIdentity(cameraMatrix[0]);
    //For check
    qDebug()<<rms;

    qDebug()<<"OBJECT POINTS";
    for(int i=0;i<objectPoints.size();i++)
        for(int j=0;j<objectPoints[i].size();j++)
            qDebug()<<"ObjectPoints.size "<<objectPoints.size()<<" ObjectPoints["<<i<<"] size "<< objectPoints[i].size()<<" value "<<j<<" :"
                   <<objectPoints[i][j].x<<objectPoints[i][j].y<<objectPoints[i][j].z;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            qDebug()<<cameraMatrix[0].at<double>(i,j) ;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            qDebug()<<cameraMatrix[1].at<double>(i,j);
    //
    qDebug()<<goodSamplesCounter;
    qDebug()<<samplesCounter;
    undistortPoints( imagePoints[0][4], imagePoints[0][4],cameraMatrix[0], distCoeffs[0],noArray(),cameraMatrix[0]);
    undistortPoints( imagePoints[1][4], imagePoints[1][4],cameraMatrix[1], distCoeffs[1]);


return true;
}
bool StereoVision::rectifyStereoCameras(Mat &leftImage, Mat &rightImage,Mat &leftImage2, Mat &rightImage2){
    Mat rmap[2][2];
    // from Calibration Matrixes perform Rectification
    stereoRectify(cameraMatrix[0],distCoeffs[0],cameraMatrix[1],distCoeffs[1],imageSize,R,T,R1,R2,P1,P2,Q,CALIB_ZERO_DISPARITY,0,imageSize,0,0);
    bool isVerticalStereo = fabs(P2.at<double>(1, 3)) > fabs(P2.at<double>(0, 3));// sprawdza wzajemne położenie kamer
    qDebug()<< "is vertical= lol"<<isVerticalStereo;


    initUndistortRectifyMap(cameraMatrix[0], distCoeffs[0], R1, P1, imageSize, CV_16SC2, rmap[0][0], rmap[0][1]);//mapa 1
    initUndistortRectifyMap(cameraMatrix[1], distCoeffs[1], R2, P2, imageSize, CV_16SC2, rmap[1][0], rmap[1][1]);
    remap(leftImage,leftImage2,rmap[0][0],rmap[0][1],INTER_LINEAR,BORDER_TRANSPARENT,0);
    remap(rightImage,rightImage2,rmap[1][0],rmap[1][1],INTER_LINEAR,BORDER_TRANSPARENT,0);
}
