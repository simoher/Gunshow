#ifndef VIDEO_H
#define VIDEO_H

#include <QString>
#include <QObject>
#include <vector>

#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/highgui.h>

using namespace cv;

class Video : public QObject {
private:
	VideoCapture *cam;

public:
	explicit Video(QObject *parent = 0);
	void Record();
};

#endif // VIDEO_H
