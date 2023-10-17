/********************************************************************************
** Form generated from reading UI file 'videoscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOSCREEN_H
#define UI_VIDEOSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videoScreen
{
public:

    void setupUi(QWidget *videoScreen)
    {
        if (videoScreen->objectName().isEmpty())
            videoScreen->setObjectName(QStringLiteral("videoScreen"));
        videoScreen->resize(400, 300);

        retranslateUi(videoScreen);

        QMetaObject::connectSlotsByName(videoScreen);
    } // setupUi

    void retranslateUi(QWidget *videoScreen)
    {
        videoScreen->setWindowTitle(QApplication::translate("videoScreen", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class videoScreen: public Ui_videoScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOSCREEN_H
