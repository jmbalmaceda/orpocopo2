/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *nuevoEntrenamiento;
    QPushButton *modificarEntrenamiento;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(383, 283);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        nuevoEntrenamiento = new QPushButton(centralWidget);
        nuevoEntrenamiento->setObjectName(QStringLiteral("nuevoEntrenamiento"));
        nuevoEntrenamiento->setGeometry(QRect(120, 80, 151, 25));
        modificarEntrenamiento = new QPushButton(centralWidget);
        modificarEntrenamiento->setObjectName(QStringLiteral("modificarEntrenamiento"));
        modificarEntrenamiento->setGeometry(QRect(120, 120, 151, 25));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Training Manager", Q_NULLPTR));
        nuevoEntrenamiento->setText(QApplication::translate("MainWindow", "Nuevo entrenamiento", Q_NULLPTR));
        modificarEntrenamiento->setText(QApplication::translate("MainWindow", "Modificar entrenamiento", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
