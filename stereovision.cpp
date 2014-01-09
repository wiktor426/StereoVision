#include "stereovision.h"

StereoVision::StereoVision()

{
    squareSize=0.05;
   // cameraMatrix[0] = Mat::eye(3, 3, CV_64F);
   // cameraMatrix[1] = Mat::eye(3, 3, CV_64F);
}


bool StereoVision::addSampleToCalibration(Mat &leftImage, Mat &rightImage){

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
    vector<Mat> rvecs[2], tvecs[2];

    //Calibrate first then second camera separately
    calibrateCamera(objectPoints,imagePoints[0],imageSize,cameraMatrix[0],distCoeffs[0],rvecs[0],tvecs[1]);
    calibrateCamera(objectPoints,imagePoints[1],imageSize,cameraMatrix[1],distCoeffs[1],rvecs[0],tvecs[1]);



    double rms = stereoCalibrate(objectPoints, imagePoints[0], imagePoints[1],
                        cameraMatrix[0], distCoeffs[0],
                        cameraMatrix[1], distCoeffs[1],
                        imageSize, R, T, E, F,
                        TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 100, 1e-5),
                        CV_CALIB_FIX_INTRINSIC);


    qDebug()<<"Rms"<<rms;

    //qDebug()<<"OBJECT POINTS";
    //for(unsigned int i=0;i<objectPoints.size();i++)
        //for(unsigned int j=0;j<objectPoints[i].size();j++)
          //  qDebug()<<"ObjectPoints.size "<<objectPoints.size()<<" ObjectPoints["<<i<<"] size "<< objectPoints[i].size()<<" value "<<j<<" :"
            //       <<objectPoints[i][j].x<<objectPoints[i][j].y<<objectPoints[i][j].z;


    // from Calibration Matrixes perform Rectification
    stereoRectify(cameraMatrix[0],distCoeffs[0],cameraMatrix[1],distCoeffs[1],imageSize,R,T,R1,R2,P1,P2,Q,CALIB_ZERO_DISPARITY,0,imageSize,0,0);
    bool isVerticalStereo = fabs(P2.at<double>(1, 3)) > fabs(P2.at<double>(0, 3));// check cameras mutual position
    qDebug()<< "is vertical="<<isVerticalStereo;
    initUndistortRectifyMap(cameraMatrix[0], distCoeffs[0], R1, P1, imageSize, CV_16SC2, rmap[0][0], rmap[0][1]);// computes undistortion and rectify maps for camera #1
    initUndistortRectifyMap(cameraMatrix[1], distCoeffs[1], R2, P2, imageSize, CV_16SC2, rmap[1][0], rmap[1][1]);// computes undistortion and rectify maps for camera #2

    qDebug()<<goodSamplesCounter;
    qDebug()<<samplesCounter;

return true;
}
bool StereoVision::rectifyStereoCameras(Mat &leftImage, Mat &rightImage,Mat &leftImage2, Mat &rightImage2){

    Mat disparityMap;
    Mat disparityMap2;
    remap(leftImage,leftImage2,rmap[0][0],rmap[0][1],INTER_LINEAR,BORDER_TRANSPARENT,0);// applies undistortion and rectify maps to input image from camera #1
    remap(rightImage,rightImage2,rmap[1][0],rmap[1][1],INTER_LINEAR,BORDER_TRANSPARENT,0);// applies undistortion and rectify maps to input image from camera #2

    sgbm.SADWindowSize = 3;
    sgbm.numberOfDisparities = 256;
    sgbm.preFilterCap = 4;
    sgbm.minDisparity = 0;
    sgbm.uniquenessRatio = 1;
    sgbm.speckleWindowSize = 150;
    sgbm.speckleRange = 2;
    sgbm.disp12MaxDiff = 10;
    sgbm.fullDP = true;
    sgbm.P1 = 600;
    sgbm.P2 = 2400;

    sgbm(leftImage2,rightImage2,disparityMap);
    normalize(disparityMap,disparityMap2,0,255,CV_MINMAX,CV_8U);
    imshow("Disparity",disparityMap2);
}

double StereoVision::getCameraValueAt(int x,int y, char camera) const {
    //Doesnt check if calibration was done or not

    if(x>3||x<0||y>3||y<0)
        return -1;\
    if(camera == 'L')
        return cameraMatrix[0].at<double>(x,y);
    if(camera == 'R')
        return cameraMatrix[1].at<double>(x,y);

    return -1;
}
void StereoVision::saveCalibration(std::string path){

  /*  QFile file(path);
      file.open(QIODevice::WriteOnly | QIODevice::Text);
      QTextStream out(&file);
      for(int i=0;i<3;i++){
          for(int j=0;j<3;j++){
              out<<cameraMatrix[0].at<double>(i,j)<<";";

          }
          out<<"\n";
      }


      // optional, as QFile destructor will already do it:
      file.close();*/
      cv::FileStorage file2(path, FileStorage::WRITE);
      file2<<"cameraMatrix0"<<cameraMatrix[0]<<"cameraMatrix1"<<cameraMatrix[1];
      file2.release();

}
void StereoVision::loadCalibration(std::string path){

  /*  if (path.isEmpty())
             return;
         else {

             QFile file(path);

             if (!file.open(QIODevice::ReadOnly)) {
                 //komunikat
                 return;
             }

          QTextStream in(&file);
             QString line = in.readLine();
            qDebug()<<line;

}*/
   cv::FileStorage file2(path, FileStorage::READ);
   file2["cameraMatrix0"]>> cameraMatrix[0];
   file2["cameraMatrix1"]>>cameraMatrix[1];


}
