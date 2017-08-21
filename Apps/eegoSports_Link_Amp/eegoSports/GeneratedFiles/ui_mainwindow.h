/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionQuit_2;
    QAction *actionLoad_Configuration;
    QAction *actionSave_Configuration;
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPlainTextEdit *channelLabels;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QComboBox *samplingRate;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QPushButton *linkButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(285, 284);
        actionQuit_2 = new QAction(MainWindowClass);
        actionQuit_2->setObjectName(QString::fromUtf8("actionQuit_2"));
        actionLoad_Configuration = new QAction(MainWindowClass);
        actionLoad_Configuration->setObjectName(QString::fromUtf8("actionLoad_Configuration"));
        actionSave_Configuration = new QAction(MainWindowClass);
        actionSave_Configuration->setObjectName(QString::fromUtf8("actionSave_Configuration"));
        actionQuit = new QAction(MainWindowClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        channelLabels = new QPlainTextEdit(groupBox_2);
        channelLabels->setObjectName(QString::fromUtf8("channelLabels"));

        gridLayout->addWidget(channelLabels, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 3, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        samplingRate = new QComboBox(groupBox);
        samplingRate->setObjectName(QString::fromUtf8("samplingRate"));

        formLayout->setWidget(0, QFormLayout::FieldRole, samplingRate);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);


        gridLayout_2->addWidget(groupBox, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 134, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 1);

        linkButton = new QPushButton(centralWidget);
        linkButton->setObjectName(QString::fromUtf8("linkButton"));

        gridLayout_2->addWidget(linkButton, 2, 1, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 285, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad_Configuration);
        menuFile->addAction(actionSave_Configuration);
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindowClass);

        samplingRate->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "eegoSports Connector", 0, QApplication::UnicodeUTF8));
        actionQuit_2->setText(QApplication::translate("MainWindowClass", "Quit", 0, QApplication::UnicodeUTF8));
        actionLoad_Configuration->setText(QApplication::translate("MainWindowClass", "Load Configuration", 0, QApplication::UnicodeUTF8));
        actionSave_Configuration->setText(QApplication::translate("MainWindowClass", "Save Configuration", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindowClass", "Quit", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindowClass", "Channel Labels", 0, QApplication::UnicodeUTF8));
        channelLabels->setPlainText(QApplication::translate("MainWindowClass", "Fp1\n"
"Afz\n"
"Fp2\n"
"F7\n"
"F3\n"
"Fz\n"
"F4\n"
"F8\n"
"FC5\n"
"FC1\n"
"FC2\n"
"FC6\n"
"FCC1h\n"
"T7\n"
"C3\n"
"Cz\n"
"C4\n"
"T8\n"
"FCC2h\n"
"CP5\n"
"CP1\n"
"CP2\n"
"CP6\n"
"P7\n"
"P3\n"
"Pz\n"
"P4\n"
"P8\n"
"POz\n"
"O1\n"
"O2\n"
"CPz\n"
"FCC3h\n"
"AF3\n"
"AF4\n"
"FCC4h\n"
"F5\n"
"F1\n"
"F2\n"
"F6\n"
"FC3\n"
"FCz\n"
"FC4\n"
"C5\n"
"C1\n"
"C2\n"
"C6\n"
"CP3\n"
"CP4\n"
"P5\n"
"P1\n"
"P2\n"
"P6\n"
"CCP1h\n"
"PO3\n"
"PO4\n"
"CCP2h\n"
"FT7\n"
"FT8\n"
"TP7\n"
"TP8\n"
"CCP3h\n"
"CCP4h\n"
"Oz", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindowClass", "Device Settings", 0, QApplication::UnicodeUTF8));
        samplingRate->clear();
        samplingRate->insertItems(0, QStringList()
         << QApplication::translate("MainWindowClass", "500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "512", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "1000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "1024", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "2000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "2048", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "4000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "4960", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "8000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "8192", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "16000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "16384", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        samplingRate->setToolTip(QApplication::translate("MainWindowClass", "Sampling rate to use.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindowClass", "Sampling Rate", 0, QApplication::UnicodeUTF8));
        linkButton->setText(QApplication::translate("MainWindowClass", "Link", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
