#ifndef PARAMETERSFORSGBM_H
#define PARAMETERSFORSGBM_H

#include <QWidget>

namespace Ui {
class ParametersForSGBM;
}

class ParametersForSGBM : public QWidget
{
    Q_OBJECT

public:
    explicit ParametersForSGBM(QWidget *parent = 0);
    ~ParametersForSGBM();

private slots:
    void on_horizontalSlider_7_valueChanged(int value);

private:
    Ui::ParametersForSGBM *ui;

    int SADWindowSize;
    int numberOfDisparities;
    int preFilterCap;
    int minDisparity;
    int uniquenessRatio;
    int speckleWindowSize;
    int speckleRange;
    int disp12MaxDiff;
    int fullDP;
    int P1;
    int P2;
};

#endif // PARAMETERSFORSGBM_H
