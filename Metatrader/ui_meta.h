/********************************************************************************
** Form generated from reading UI file 'meta.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_META_H
#define UI_META_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "showwindow.h"

QT_BEGIN_NAMESPACE

class Ui_Meta
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    ShowWindow *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Meta)
    {
        if (Meta->objectName().isEmpty())
            Meta->setObjectName(QString::fromUtf8("Meta"));
        Meta->resize(771, 504);
        centralWidget = new QWidget(Meta);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new ShowWindow(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        Meta->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Meta);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 771, 21));
        Meta->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Meta);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Meta->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Meta);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Meta->setStatusBar(statusBar);

        retranslateUi(Meta);

        QMetaObject::connectSlotsByName(Meta);
    } // setupUi

    void retranslateUi(QMainWindow *Meta)
    {
        Meta->setWindowTitle(QApplication::translate("Meta", "Meta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Meta: public Ui_Meta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_META_H
