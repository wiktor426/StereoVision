/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonCalibrate;
    QPushButton *pushButtonRectify;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelPatternSize;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *labelX;
    QSpinBox *spinBoxPatternSizeX;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelY;
    QSpinBox *spinBoxPatternSizeY;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelCalibrationSource;
    QLineEdit *lineEditCalibrationData;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelB1_1;
    QLabel *labelB1_2;
    QLabel *labelB1_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelB2_1;
    QLabel *labelB2_2;
    QLabel *labelB2_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelB3_1;
    QLabel *labelB3_2;
    QLabel *labelB3_3;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelA1_1;
    QLabel *labelA1_2;
    QLabel *labelA1_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelA2_1;
    QLabel *labelA2_2;
    QLabel *labelA2_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelA3_1;
    QLabel *labelA3_2;
    QLabel *labelA3_3;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_9;
    QLabel *labelLeftImage;
    QLabel *labelRightImage;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *lineEditLeftImage;
    QLineEdit *lineEditRightImage;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(503, 338);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonCalibrate = new QPushButton(centralWidget);
        pushButtonCalibrate->setObjectName(QStringLiteral("pushButtonCalibrate"));
        pushButtonCalibrate->setGeometry(QRect(400, 10, 80, 23));
        pushButtonRectify = new QPushButton(centralWidget);
        pushButtonRectify->setObjectName(QStringLiteral("pushButtonRectify"));
        pushButtonRectify->setGeometry(QRect(330, 210, 80, 23));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 50, 198, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelPatternSize = new QLabel(layoutWidget);
        labelPatternSize->setObjectName(QStringLiteral("labelPatternSize"));

        verticalLayout_3->addWidget(labelPatternSize);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_3);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelX = new QLabel(layoutWidget);
        labelX->setObjectName(QStringLiteral("labelX"));

        verticalLayout->addWidget(labelX);

        spinBoxPatternSizeX = new QSpinBox(layoutWidget);
        spinBoxPatternSizeX->setObjectName(QStringLiteral("spinBoxPatternSizeX"));
        spinBoxPatternSizeX->setValue(9);

        verticalLayout->addWidget(spinBoxPatternSizeX);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelY = new QLabel(layoutWidget);
        labelY->setObjectName(QStringLiteral("labelY"));

        verticalLayout_2->addWidget(labelY);

        spinBoxPatternSizeY = new QSpinBox(layoutWidget);
        spinBoxPatternSizeY->setObjectName(QStringLiteral("spinBoxPatternSizeY"));
        spinBoxPatternSizeY->setValue(6);

        verticalLayout_2->addWidget(spinBoxPatternSizeY);


        horizontalLayout->addLayout(verticalLayout_2);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 10, 391, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelCalibrationSource = new QLabel(layoutWidget1);
        labelCalibrationSource->setObjectName(QStringLiteral("labelCalibrationSource"));

        horizontalLayout_2->addWidget(labelCalibrationSource);

        lineEditCalibrationData = new QLineEdit(layoutWidget1);
        lineEditCalibrationData->setObjectName(QStringLiteral("lineEditCalibrationData"));

        horizontalLayout_2->addWidget(lineEditCalibrationData);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(140, 140, 83, 88));
        verticalLayout_6 = new QVBoxLayout(layoutWidget2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_6->addWidget(label_5);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelB1_1 = new QLabel(layoutWidget2);
        labelB1_1->setObjectName(QStringLiteral("labelB1_1"));

        horizontalLayout_6->addWidget(labelB1_1);

        labelB1_2 = new QLabel(layoutWidget2);
        labelB1_2->setObjectName(QStringLiteral("labelB1_2"));

        horizontalLayout_6->addWidget(labelB1_2);

        labelB1_3 = new QLabel(layoutWidget2);
        labelB1_3->setObjectName(QStringLiteral("labelB1_3"));

        horizontalLayout_6->addWidget(labelB1_3);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelB2_1 = new QLabel(layoutWidget2);
        labelB2_1->setObjectName(QStringLiteral("labelB2_1"));

        horizontalLayout_7->addWidget(labelB2_1);

        labelB2_2 = new QLabel(layoutWidget2);
        labelB2_2->setObjectName(QStringLiteral("labelB2_2"));

        horizontalLayout_7->addWidget(labelB2_2);

        labelB2_3 = new QLabel(layoutWidget2);
        labelB2_3->setObjectName(QStringLiteral("labelB2_3"));

        horizontalLayout_7->addWidget(labelB2_3);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelB3_1 = new QLabel(layoutWidget2);
        labelB3_1->setObjectName(QStringLiteral("labelB3_1"));

        horizontalLayout_8->addWidget(labelB3_1);

        labelB3_2 = new QLabel(layoutWidget2);
        labelB3_2->setObjectName(QStringLiteral("labelB3_2"));

        horizontalLayout_8->addWidget(labelB3_2);

        labelB3_3 = new QLabel(layoutWidget2);
        labelB3_3->setObjectName(QStringLiteral("labelB3_3"));

        horizontalLayout_8->addWidget(labelB3_3);


        verticalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout_6->addLayout(verticalLayout_5);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(50, 140, 83, 88));
        verticalLayout_7 = new QVBoxLayout(layoutWidget3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_7->addWidget(label_7);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelA1_1 = new QLabel(layoutWidget3);
        labelA1_1->setObjectName(QStringLiteral("labelA1_1"));

        horizontalLayout_3->addWidget(labelA1_1);

        labelA1_2 = new QLabel(layoutWidget3);
        labelA1_2->setObjectName(QStringLiteral("labelA1_2"));

        horizontalLayout_3->addWidget(labelA1_2);

        labelA1_3 = new QLabel(layoutWidget3);
        labelA1_3->setObjectName(QStringLiteral("labelA1_3"));

        horizontalLayout_3->addWidget(labelA1_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelA2_1 = new QLabel(layoutWidget3);
        labelA2_1->setObjectName(QStringLiteral("labelA2_1"));

        horizontalLayout_4->addWidget(labelA2_1);

        labelA2_2 = new QLabel(layoutWidget3);
        labelA2_2->setObjectName(QStringLiteral("labelA2_2"));

        horizontalLayout_4->addWidget(labelA2_2);

        labelA2_3 = new QLabel(layoutWidget3);
        labelA2_3->setObjectName(QStringLiteral("labelA2_3"));

        horizontalLayout_4->addWidget(labelA2_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelA3_1 = new QLabel(layoutWidget3);
        labelA3_1->setObjectName(QStringLiteral("labelA3_1"));

        horizontalLayout_5->addWidget(labelA3_1);

        labelA3_2 = new QLabel(layoutWidget3);
        labelA3_2->setObjectName(QStringLiteral("labelA3_2"));

        horizontalLayout_5->addWidget(labelA3_2);

        labelA3_3 = new QLabel(layoutWidget3);
        labelA3_3->setObjectName(QStringLiteral("labelA3_3"));

        horizontalLayout_5->addWidget(labelA3_3);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_4);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(270, 140, 207, 56));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        labelLeftImage = new QLabel(layoutWidget4);
        labelLeftImage->setObjectName(QStringLiteral("labelLeftImage"));

        verticalLayout_9->addWidget(labelLeftImage);

        labelRightImage = new QLabel(layoutWidget4);
        labelRightImage->setObjectName(QStringLiteral("labelRightImage"));

        verticalLayout_9->addWidget(labelRightImage);


        horizontalLayout_9->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        lineEditLeftImage = new QLineEdit(layoutWidget4);
        lineEditLeftImage->setObjectName(QStringLiteral("lineEditLeftImage"));

        verticalLayout_8->addWidget(lineEditLeftImage);

        lineEditRightImage = new QLineEdit(layoutWidget4);
        lineEditRightImage->setObjectName(QStringLiteral("lineEditRightImage"));

        verticalLayout_8->addWidget(lineEditRightImage);


        horizontalLayout_9->addLayout(verticalLayout_8);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        pushButtonCalibrate->raise();
        pushButtonRectify->raise();
        layoutWidget->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 503, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButtonCalibrate->setText(QApplication::translate("MainWindow", "Calibrate", 0));
        pushButtonRectify->setText(QApplication::translate("MainWindow", "Rectyfy", 0));
        labelPatternSize->setText(QApplication::translate("MainWindow", "Pattern Size", 0));
        label->setText(QString());
        labelX->setText(QApplication::translate("MainWindow", "X", 0));
        labelY->setText(QApplication::translate("MainWindow", "Y", 0));
        labelCalibrationSource->setText(QApplication::translate("MainWindow", "Calibration Data ", 0));
        lineEditCalibrationData->setText(QApplication::translate("MainWindow", "/home/haskis/Pictures/Projects/Calibration/", 0));
        label_5->setText(QApplication::translate("MainWindow", "Cam 2 Matrix", 0));
        labelB1_1->setText(QApplication::translate("MainWindow", "1", 0));
        labelB1_2->setText(QApplication::translate("MainWindow", "1", 0));
        labelB1_3->setText(QApplication::translate("MainWindow", "1", 0));
        labelB2_1->setText(QApplication::translate("MainWindow", "1", 0));
        labelB2_2->setText(QApplication::translate("MainWindow", "1", 0));
        labelB2_3->setText(QApplication::translate("MainWindow", "1", 0));
        labelB3_1->setText(QApplication::translate("MainWindow", "1", 0));
        labelB3_2->setText(QApplication::translate("MainWindow", "1", 0));
        labelB3_3->setText(QApplication::translate("MainWindow", "1", 0));
        label_7->setText(QApplication::translate("MainWindow", "Cam 1 Matrix", 0));
        labelA1_1->setText(QApplication::translate("MainWindow", "1", 0));
        labelA1_2->setText(QApplication::translate("MainWindow", "1", 0));
        labelA1_3->setText(QApplication::translate("MainWindow", "1", 0));
        labelA2_1->setText(QApplication::translate("MainWindow", "1", 0));
        labelA2_2->setText(QApplication::translate("MainWindow", "1", 0));
        labelA2_3->setText(QApplication::translate("MainWindow", "1", 0));
        labelA3_1->setText(QApplication::translate("MainWindow", "1", 0));
        labelA3_2->setText(QApplication::translate("MainWindow", "1", 0));
        labelA3_3->setText(QApplication::translate("MainWindow", "1", 0));
        labelLeftImage->setText(QApplication::translate("MainWindow", "Left Image", 0));
        labelRightImage->setText(QApplication::translate("MainWindow", "Right Image", 0));
        lineEditLeftImage->setText(QApplication::translate("MainWindow", "/home/haskis/Pictures/Projects/Calibration/left01.jpg", 0));
        lineEditRightImage->setText(QApplication::translate("MainWindow", "/home/haskis/Pictures/Projects/Calibration/left02.jpg", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
