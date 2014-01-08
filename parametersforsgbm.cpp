#include "parametersforsgbm.h"
#include "ui_parametersforsgbm.h"

ParametersForSGBM::ParametersForSGBM(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParametersForSGBM)
{
    ui->setupUi(this);
    SADWindowSize = 5;
    numberOfDisparities = 192;
    preFilterCap = 4;
    minDisparity = -64;
    uniquenessRatio = 1;
    speckleWindowSize = 150;
    speckleRange = 2;
    disp12MaxDiff = 10;
    fullDP = false;
    P1 = 600;
    P2 = 2400;
}

ParametersForSGBM::~ParametersForSGBM()
{
    delete ui;
}

void ParametersForSGBM::on_horizontalSlider_7_valueChanged(int value)
{

}
