/********************************************************************************
** Form generated from reading UI file 'frmtracker.ui'
**
** Created: Thu Nov 22 18:50:04 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMTRACKER_H
#define UI_FRMTRACKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_frmTracker
{
public:
    QLabel *lblOriginal;
    QLabel *lblProcessed;
    QPlainTextEdit *txtXYRadius;
    QPushButton *btnPauseOrResume;

    void setupUi(QDialog *frmTracker)
    {
        if (frmTracker->objectName().isEmpty())
            frmTracker->setObjectName(QString::fromUtf8("frmTracker"));
        frmTracker->resize(1286, 662);
        lblOriginal = new QLabel(frmTracker);
        lblOriginal->setObjectName(QString::fromUtf8("lblOriginal"));
        lblOriginal->setGeometry(QRect(2, 2, 640, 480));
        QFont font;
        font.setPointSize(10);
        lblOriginal->setFont(font);
        lblOriginal->setAutoFillBackground(true);
        lblOriginal->setFrameShape(QFrame::Box);
        lblProcessed = new QLabel(frmTracker);
        lblProcessed->setObjectName(QString::fromUtf8("lblProcessed"));
        lblProcessed->setGeometry(QRect(644, 2, 640, 480));
        lblProcessed->setFont(font);
        lblProcessed->setAutoFillBackground(true);
        lblProcessed->setFrameShape(QFrame::Box);
        txtXYRadius = new QPlainTextEdit(frmTracker);
        txtXYRadius->setObjectName(QString::fromUtf8("txtXYRadius"));
        txtXYRadius->setGeometry(QRect(288, 484, 995, 175));
        QPalette palette;
        QBrush brush(QColor(212, 208, 200, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        txtXYRadius->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier New"));
        font1.setPointSize(10);
        txtXYRadius->setFont(font1);
        txtXYRadius->setReadOnly(true);
        btnPauseOrResume = new QPushButton(frmTracker);
        btnPauseOrResume->setObjectName(QString::fromUtf8("btnPauseOrResume"));
        btnPauseOrResume->setGeometry(QRect(78, 542, 123, 35));
        QFont font2;
        font2.setPointSize(12);
        btnPauseOrResume->setFont(font2);

        retranslateUi(frmTracker);

        QMetaObject::connectSlotsByName(frmTracker);
    } // setupUi

    void retranslateUi(QDialog *frmTracker)
    {
        frmTracker->setWindowTitle(QApplication::translate("frmTracker", "frmTracker", 0));
        lblOriginal->setText(QString());
        lblProcessed->setText(QString());
        btnPauseOrResume->setText(QApplication::translate("frmTracker", "pause", 0));
    } // retranslateUi

};

namespace Ui {
    class frmTracker: public Ui_frmTracker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMTRACKER_H
