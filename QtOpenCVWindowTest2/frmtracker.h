// frmtracker.h

#ifndef FRMTRACKER_H
#define FRMTRACKER_H

#include <QDialog>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////
namespace Ui {
	class frmTracker;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
class frmTracker : public QDialog {
	Q_OBJECT
	
public slots:
	void processFrameAndUpdateGUI();
	
public:
	explicit frmTracker(QWidget *parent = 0);
	~frmTracker();
	
private slots:
	void on_btnPauseOrResume_clicked();
	
private:
	Ui::frmTracker *ui;
	
	cv::VideoCapture capWebcam;
	cv::Mat matOriginal;
	cv::Mat matProcessed;
	
	QImage qimgOriginal;
	QImage qimgProcessed;
	
	std::vector<cv::Vec3f> vecCircles;
	std::vector<cv::Vec3f>::iterator itrCircles;
	
	QTimer* qtimer;
	
};

#endif // FRMTRACKER_H
