/********************************************************************************
** Form generated from reading UI file 'analyzetool.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYZETOOL_H
#define UI_ANALYZETOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnalyzeTool
{
public:
    QWidget *centralwidget;
    QPushButton *btnOpenMap;
    QTextEdit *txtOutput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AnalyzeTool)
    {
        if (AnalyzeTool->objectName().isEmpty())
            AnalyzeTool->setObjectName("AnalyzeTool");
        AnalyzeTool->resize(1283, 607);
        centralwidget = new QWidget(AnalyzeTool);
        centralwidget->setObjectName("centralwidget");
        btnOpenMap = new QPushButton(centralwidget);
        btnOpenMap->setObjectName("btnOpenMap");
        btnOpenMap->setGeometry(QRect(10, 10, 80, 24));
        txtOutput = new QTextEdit(centralwidget);
        txtOutput->setObjectName("txtOutput");
        txtOutput->setGeometry(QRect(10, 40, 551, 71));
        AnalyzeTool->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AnalyzeTool);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1283, 21));
        AnalyzeTool->setMenuBar(menubar);
        statusbar = new QStatusBar(AnalyzeTool);
        statusbar->setObjectName("statusbar");
        AnalyzeTool->setStatusBar(statusbar);

        retranslateUi(AnalyzeTool);

        QMetaObject::connectSlotsByName(AnalyzeTool);
    } // setupUi

    void retranslateUi(QMainWindow *AnalyzeTool)
    {
        AnalyzeTool->setWindowTitle(QCoreApplication::translate("AnalyzeTool", "AnalyzeTool", nullptr));
        btnOpenMap->setText(QCoreApplication::translate("AnalyzeTool", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnalyzeTool: public Ui_AnalyzeTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYZETOOL_H
