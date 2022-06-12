/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *video;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *connect;
    QPushButton *disconnect;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *left;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *front;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *right;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Ltranslate;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *stop;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *Rtranslate;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *LturnRound;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *behind;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *RturnRound;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *FPS;
    QHBoxLayout *horizontalLayout_5;
    QLabel *distance;
    QLCDNumber *lcdNumber;
    QLabel *cm;
    QSpacerItem *horizontalSpacer_15;
    QTextBrowser *textBrowser;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *autodrive;
    QHBoxLayout *horizontalLayout_7;
    QLabel *speed;
    QLCDNumber *lcdNumber_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *add;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *decrease;
    QSpacerItem *horizontalSpacer_14;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(747, 471);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        video = new QLabel(widget);
        video->setObjectName(QString::fromUtf8("video"));
        sizePolicy.setHeightForWidth(video->sizePolicy().hasHeightForWidth());
        video->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(16);
        video->setFont(font);
        video->setScaledContents(false);
        video->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(video, 0, 0, 2, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 500, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        connect = new QPushButton(widget);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\345\201\234\347\225\231\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(44 , 137 , 255);\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton"
                        ":pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));

        verticalLayout_3->addWidget(connect);

        disconnect = new QPushButton(widget);
        disconnect->setObjectName(QString::fromUtf8("disconnect"));
        disconnect->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\345\201\234\347\225\231\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(44 , 137 , 255);\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton"
                        ":pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));

        verticalLayout_3->addWidget(disconnect);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        left = new QPushButton(widget);
        left->setObjectName(QString::fromUtf8("left"));
        left->setEnabled(true);
        left->setAutoFillBackground(true);
        left->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"   // background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217"
                        "\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));
        left->setIconSize(QSize(50, 50));

        horizontalLayout_4->addWidget(left);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        front = new QPushButton(widget);
        front->setObjectName(QString::fromUtf8("front"));
        front->setLayoutDirection(Qt::LeftToRight);
        front->setAutoFillBackground(true);
        front->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"   // background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217"
                        "\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));
        front->setIconSize(QSize(48, 50));

        horizontalLayout_4->addWidget(front);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        right = new QPushButton(widget);
        right->setObjectName(QString::fromUtf8("right"));
        right->setAutoFillBackground(true);
        right->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"   // background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217"
                        "\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));
        right->setIconSize(QSize(50, 50));

        horizontalLayout_4->addWidget(right);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        Ltranslate = new QPushButton(widget);
        Ltranslate->setObjectName(QString::fromUtf8("Ltranslate"));
        Ltranslate->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"   // background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217"
                        "\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));

        horizontalLayout->addWidget(Ltranslate);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        stop = new QPushButton(widget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"   // background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217"
                        "\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));

        horizontalLayout->addWidget(stop);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        Rtranslate = new QPushButton(widget);
        Rtranslate->setObjectName(QString::fromUtf8("Rtranslate"));
        Rtranslate->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"   // background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217"
                        "\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));

        horizontalLayout->addWidget(Rtranslate);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        LturnRound = new QPushButton(widget);
        LturnRound->setObjectName(QString::fromUtf8("LturnRound"));
        LturnRound->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"   // background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217"
                        "\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));

        horizontalLayout_3->addWidget(LturnRound);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        behind = new QPushButton(widget);
        behind->setObjectName(QString::fromUtf8("behind"));
        behind->setAutoFillBackground(true);
        behind->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"   // background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217"
                        "\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));
        behind->setIconSize(QSize(48, 50));

        horizontalLayout_3->addWidget(behind);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_12);

        RturnRound = new QPushButton(widget);
        RturnRound->setObjectName(QString::fromUtf8("RturnRound"));
        RturnRound->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"   // background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217"
                        "\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));

        horizontalLayout_3->addWidget(RturnRound);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QLabel\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(250 , 200 , 100);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:2px;\n"
"}\n"
""));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        FPS = new QLabel(widget);
        FPS->setObjectName(QString::fromUtf8("FPS"));
        FPS->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QLabel\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:black;\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
""));
        FPS->setScaledContents(true);
        FPS->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(FPS);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        distance = new QLabel(widget);
        distance->setObjectName(QString::fromUtf8("distance"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(distance->sizePolicy().hasHeightForWidth());
        distance->setSizePolicy(sizePolicy2);
        distance->setMinimumSize(QSize(50, 10));
        distance->setStyleSheet(QString::fromUtf8("  /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;"));

        horizontalLayout_5->addWidget(distance);

        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lcdNumber->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(20);
        lcdNumber->setFont(font1);

        horizontalLayout_5->addWidget(lcdNumber);

        cm = new QLabel(widget);
        cm->setObjectName(QString::fromUtf8("cm"));
        cm->setStyleSheet(QString::fromUtf8("  /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;"));

        horizontalLayout_5->addWidget(cm);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_15);

        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMinimumSize(QSize(100, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(12);
        textBrowser->setFont(font2);

        horizontalLayout_5->addWidget(textBrowser);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_16);

        autodrive = new QPushButton(widget);
        autodrive->setObjectName(QString::fromUtf8("autodrive"));
        autodrive->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\345\201\234\347\225\231\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(44 , 137 , 255);\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton"
                        ":pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));

        horizontalLayout_5->addWidget(autodrive);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        speed = new QLabel(widget);
        speed->setObjectName(QString::fromUtf8("speed"));
        sizePolicy2.setHeightForWidth(speed->sizePolicy().hasHeightForWidth());
        speed->setSizePolicy(sizePolicy2);
        speed->setMinimumSize(QSize(50, 10));
        speed->setStyleSheet(QString::fromUtf8("  /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;"));

        horizontalLayout_7->addWidget(speed);

        lcdNumber_3 = new QLCDNumber(widget);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lcdNumber_3->setPalette(palette1);
        lcdNumber_3->setFont(font1);

        horizontalLayout_7->addWidget(lcdNumber_3);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("  /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;"));

        horizontalLayout_7->addWidget(label_6);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_13);

        add = new QPushButton(widget);
        add->setObjectName(QString::fromUtf8("add"));
        add->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\345\201\234\347\225\231\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(44 , 137 , 255);\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton"
                        ":pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));

        horizontalLayout_7->addWidget(add);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_17);

        decrease = new QPushButton(widget);
        decrease->setObjectName(QString::fromUtf8("decrease"));
        decrease->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\345\201\234\347\225\231\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(44 , 137 , 255);\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton"
                        ":pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"/*\346\214\211\351\222\256disabled\346\200\201*/\n"
"QPushButton:disabled\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(128,128,128);\n"
"}"));

        horizontalLayout_7->addWidget(decrease);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_14);


        verticalLayout_2->addLayout(horizontalLayout_7);


        gridLayout_2->addLayout(verticalLayout_2, 1, 1, 1, 1);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 747, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        video->setText(QString());
        connect->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\350\247\206\351\242\221", nullptr));
        disconnect->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\346\216\245\346\224\266", nullptr));
        left->setText(QString());
        front->setText(QString());
        right->setText(QString());
        Ltranslate->setText(QString());
        stop->setText(QString());
        Rtranslate->setText(QString());
        LturnRound->setText(QString());
        behind->setText(QString());
        RturnRound->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\270\247\346\225\260", nullptr));
        FPS->setText(QString());
        distance->setText(QCoreApplication::translate("MainWindow", "\351\232\234\347\242\215\347\211\251\350\267\235\347\246\273:", nullptr));
        cm->setText(QCoreApplication::translate("MainWindow", "CM", nullptr));
        autodrive->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\345\276\252\350\277\271", nullptr));
        speed->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "\345\212\240\351\200\237", nullptr));
        decrease->setText(QCoreApplication::translate("MainWindow", "\345\207\217\351\200\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
