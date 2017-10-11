/********************************************************************************
** Form generated from reading UI file 'aeroForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AEROFORM_H
#define UI_AEROFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aeroForm
{
public:
    QWidget *centralwidget;
    QPushButton *startButton;
    QPushButton *browseButton;
    QLineEdit *pathSection;
    QLabel *infoLabel;

    void setupUi(QMainWindow *aeroForm)
    {
        if (aeroForm->objectName().isEmpty())
            aeroForm->setObjectName(QString::fromUtf8("aeroForm"));
        aeroForm->resize(521, 209);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aeroForm->sizePolicy().hasHeightForWidth());
        aeroForm->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(aeroForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setEnabled(false);
        startButton->setGeometry(QRect(290, 170, 221, 32));
        browseButton = new QPushButton(centralwidget);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        browseButton->setGeometry(QRect(400, 90, 110, 41));
        pathSection = new QLineEdit(centralwidget);
        pathSection->setObjectName(QString::fromUtf8("pathSection"));
        pathSection->setGeometry(QRect(10, 100, 391, 21));
        infoLabel = new QLabel(centralwidget);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        infoLabel->setGeometry(QRect(10, 80, 261, 16));
        aeroForm->setCentralWidget(centralwidget);

        retranslateUi(aeroForm);

        QMetaObject::connectSlotsByName(aeroForm);
    } // setupUi

    void retranslateUi(QMainWindow *aeroForm)
    {
        aeroForm->setWindowTitle(QApplication::translate("aeroForm", "AeroUber - a flight scheduling software", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        startButton->setToolTip(QApplication::translate("aeroForm", "<html><head/><body><p>Start scheduling flights from requests in request file.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        startButton->setText(QApplication::translate("aeroForm", "Start scheduling", 0, QApplication::UnicodeUTF8));
        browseButton->setText(QApplication::translate("aeroForm", "browseButton", 0, QApplication::UnicodeUTF8));
        infoLabel->setText(QApplication::translate("aeroForm", "Open the request file:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class aeroForm: public Ui_aeroForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AEROFORM_H
