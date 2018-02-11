/********************************************************************************
** Form generated from reading UI file 'impedancecheck_test.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPEDANCECHECK_TEST_H
#define UI_IMPEDANCECHECK_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImpedanceCheck_testClass
{
public:
    QSlider *m_slider;
    QLabel *labelFramesize;

    void setupUi(QWidget *ImpedanceCheck_testClass)
    {
        if (ImpedanceCheck_testClass->objectName().isEmpty())
            ImpedanceCheck_testClass->setObjectName(QStringLiteral("ImpedanceCheck_testClass"));
        ImpedanceCheck_testClass->resize(1598, 967);
        m_slider = new QSlider(ImpedanceCheck_testClass);
        m_slider->setObjectName(QStringLiteral("m_slider"));
        m_slider->setGeometry(QRect(80, 100, 160, 22));
        m_slider->setOrientation(Qt::Horizontal);
        labelFramesize = new QLabel(ImpedanceCheck_testClass);
        labelFramesize->setObjectName(QStringLiteral("labelFramesize"));
        labelFramesize->setGeometry(QRect(80, 220, 47, 13));

        retranslateUi(ImpedanceCheck_testClass);

        QMetaObject::connectSlotsByName(ImpedanceCheck_testClass);
    } // setupUi

    void retranslateUi(QWidget *ImpedanceCheck_testClass)
    {
        ImpedanceCheck_testClass->setWindowTitle(QApplication::translate("ImpedanceCheck_testClass", "ImpedanceCheck_test", Q_NULLPTR));
        labelFramesize->setText(QApplication::translate("ImpedanceCheck_testClass", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImpedanceCheck_testClass: public Ui_ImpedanceCheck_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPEDANCECHECK_TEST_H
