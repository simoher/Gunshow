// frmtracker.cpp

#include "frmtracker.h"
#include "ui_frmtracker.h"

#include <QtCore>

// constructor ////////////////////////////////////////////////////////////////////////////////////
frmTracker::frmTracker(QWidget *parent) : QDialog(parent), ui(new Ui::frmTracker) {
	ui->setupUi(this);
	
	capWebcam.open(0);
	
	if(capWebcam.isOpened() == false) {
		ui->txtXYRadius->appendPlainText("error: capWebcam not accessed successfully");
		return;
	}
	
	qtimer = new QTimer(this);
	connect(qtimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
	qtimer->start(20);
}

// destructor /////////////////////////////////////////////////////////////////////////////////////
frmTracker::~frmTracker() {
	delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void frmTracker::processFrameAndUpdateGUI() {
	capWebcam.read(matOriginal);
	
	if(matOriginal.empty() == true) return;
	
	cv::inRange(matOriginal, cv::Scalar(0, 0, 175), cv::Scalar(100, 100, 256), matProcessed);
	cv::GaussianBlur(matProcessed, matProcessed, cv::Size(9, 9), 1.5);
	cv::HoughCircles(matProcessed, vecCircles, CV_HOUGH_GRADIENT, 2, matProcessed.rows / 4, 100, 50, 10, 400);
	
	for(itrCircles = vecCircles.begin(); itrCircles != vecCircles.end(); itrCircles++) {
		ui->txtXYRadius->appendPlainText(QString("ball position x =") + QString::number((*itrCircles)[0]).rightJustified(4, ' ') +
																		 QString(", y =") + QString::number((*itrCircles)[1]).rightJustified(4, ' ') +
																		 QString(", radius =") + QString::number((*itrCircles)[2], 'f', 3).rightJustified(7, ' '));
		
		cv::circle(matOriginal, cv::Point((int)(*itrCircles)[0], (int)(*itrCircles)[1]), 3, cv::Scalar(0, 255, 0), CV_FILLED);
		cv::circle(matOriginal, cv::Point((int)(*itrCircles)[0], (int)(*itrCircles)[1]), (int)(*itrCircles)[2], cv::Scalar(0, 0, 255), 3);
	}
	cv::cvtColor(matOriginal, matOriginal, CV_BGR2RGB);
	
	QImage qimgOriginal((uchar*)matOriginal.data, matOriginal.cols, matOriginal.rows, matOriginal.step, QImage::Format_RGB888);
	QImage qimgProcessed((uchar*)matProcessed.data, matProcessed.cols, matOriginal.rows, matProcessed.step, QImage::Format_Indexed8);
	
	ui->lblOriginal->setPixmap(QPixmap::fromImage(qimgOriginal));
	ui->lblProcessed->setPixmap(QPixmap::fromImage(qimgProcessed));
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void frmTracker::on_btnPauseOrResume_clicked() {
	if(qtimer->isActive() == true) {
		qtimer->stop();
		ui->btnPauseOrResume->setText("resume");
	} else {
		qtimer->start(20);
		ui->btnPauseOrResume->setText("pause");
	}
}
