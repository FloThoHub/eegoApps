#define EEGO_SDK_BIND_STATIC // How to bind

#include "impedancecheck_test.h"
#include <QtWidgets/QApplication>
#include <QLabel>
#include <qlayout.h>
#include <iostream>

int main(int argc, char *argv[])
{
	QCoreApplication::addLibraryPath(".");
    QApplication a(argc, argv);
	
    ImpedanceCheck_test w;

    return a.exec();
	
}


