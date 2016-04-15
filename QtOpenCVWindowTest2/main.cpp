// main.cpp

#include <QApplication>
#include "frmtracker.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	frmTracker w;
	w.show();
	
	return a.exec();
}
