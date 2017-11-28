/********************************************************************************
** Form generated from reading UI file 'fmodificarentrenamiento.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FMODIFICARENTRENAMIENTO_H
#define UI_FMODIFICARENTRENAMIENTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FModificarEntrenamiento
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *nuevoRecorte;
    QPushButton *nuevoRecorte_2;
    QListView *listView;
    QWidget *page_2;

    void setupUi(QDialog *FModificarEntrenamiento)
    {
        if (FModificarEntrenamiento->objectName().isEmpty())
            FModificarEntrenamiento->setObjectName(QStringLiteral("FModificarEntrenamiento"));
        FModificarEntrenamiento->resize(338, 295);
        stackedWidget = new QStackedWidget(FModificarEntrenamiento);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 331, 291));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        nuevoRecorte = new QPushButton(page);
        nuevoRecorte->setObjectName(QStringLiteral("nuevoRecorte"));
        nuevoRecorte->setGeometry(QRect(190, 220, 131, 21));
        nuevoRecorte_2 = new QPushButton(page);
        nuevoRecorte_2->setObjectName(QStringLiteral("nuevoRecorte_2"));
        nuevoRecorte_2->setGeometry(QRect(190, 250, 131, 25));
        listView = new QListView(page);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(0, 0, 181, 271));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(FModificarEntrenamiento);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FModificarEntrenamiento);
    } // setupUi

    void retranslateUi(QDialog *FModificarEntrenamiento)
    {
        FModificarEntrenamiento->setWindowTitle(QApplication::translate("FModificarEntrenamiento", "Modificar Entrenamiento", Q_NULLPTR));
        nuevoRecorte->setText(QApplication::translate("FModificarEntrenamiento", "Nuevo recorte", Q_NULLPTR));
        nuevoRecorte_2->setText(QApplication::translate("FModificarEntrenamiento", "Nuevo entrenamiento", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FModificarEntrenamiento: public Ui_FModificarEntrenamiento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FMODIFICARENTRENAMIENTO_H
