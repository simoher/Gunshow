
#include "video.h"
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/highgui.h>

#include <QString>
#include <QDebug>

using namespace cv;

Video::Video(QObject *parent)
	: QObject(parent) {
	cam = new VideoCapture(0);
	if (!cam->isOpened())
		qDebug() << "Cannot open Camera";
	else
		qDebug() << "Camera open.";
}

void Video::Record() {

	qDebug() << "Record\n";
	double dWidth =
	    cam->get(CV_CAP_PROP_FRAME_WIDTH); // get the width of frames of the video
	double dHeight = cam->get(
	    CV_CAP_PROP_FRAME_HEIGHT); // get the height of frames of the video
	Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));
	qDebug() << "Frame Size = " << dWidth << "x" << dHeight << "\n";

	qDebug() << "Recording.\n";
	Mat frame;
	qDebug() << "Made frame.\n";
	cam->read(frame); // get a new frame from camera
	if (frame.data) {
		qDebug("Image has data !");
		QString Path = "/ EmbeddedOS0.jpg";
		QByteArray ba = Path.toLocal8Bit();
		const char *PathChar = ba.data();
		imwrite(PathChar, frame);
	}
}
