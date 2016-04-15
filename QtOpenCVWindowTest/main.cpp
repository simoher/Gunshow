#include <QCoreApplication>
#include <video.h>
#include <QDebug>
int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);
	Video vid;
	vid.Record();
	qDebug() << "Recording ended.\n ";
	return a.exec();
}
