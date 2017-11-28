/********************************************************************************
** Form generated from reading UI file 'fnuevoentrenamiento.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FNUEVOENTRENAMIENTO_H
#define UI_FNUEVOENTRENAMIENTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FnuevoEntrenamiento
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_3;
    QPushButton *siguiente1;
    QLabel *label;
    QLineEdit *iNombreEntrenamiento;
    QPushButton *cancelar;
    QPushButton *selVideo;
    QFrame *line;
    QLabel *label_2;
    QLabel *videoLabel;
    QWidget *page_4;
    QPushButton *siguiente2;
    QPushButton *iAgregarBg;
    QListView *iBGview;
    QWidget *page_3;
    QPushButton *salir;
    QPushButton *entrenar;
    QTextBrowser *iOutputConsole;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *iLargo;
    QLineEdit *iAncho;
    QLineEdit *iMuestras;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *iStages;

    void setupUi(QDialog *FnuevoEntrenamiento)
    {
        if (FnuevoEntrenamiento->objectName().isEmpty())
            FnuevoEntrenamiento->setObjectName(QStringLiteral("FnuevoEntrenamiento"));
        FnuevoEntrenamiento->resize(348, 302);
        stackedWidget = new QStackedWidget(FnuevoEntrenamiento);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 341, 301));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 150, 311, 101));
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setTextFormat(Qt::RichText);
        siguiente1 = new QPushButton(page);
        siguiente1->setObjectName(QStringLiteral("siguiente1"));
        siguiente1->setGeometry(QRect(250, 260, 80, 25));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 291, 31));
        iNombreEntrenamiento = new QLineEdit(page);
        iNombreEntrenamiento->setObjectName(QStringLiteral("iNombreEntrenamiento"));
        iNombreEntrenamiento->setGeometry(QRect(10, 130, 151, 25));
        cancelar = new QPushButton(page);
        cancelar->setObjectName(QStringLiteral("cancelar"));
        cancelar->setGeometry(QRect(160, 260, 80, 25));
        selVideo = new QPushButton(page);
        selVideo->setObjectName(QStringLiteral("selVideo"));
        selVideo->setGeometry(QRect(10, 40, 111, 25));
        line = new QFrame(page);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 160, 321, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 110, 161, 16));
        videoLabel = new QLabel(page);
        videoLabel->setObjectName(QStringLiteral("videoLabel"));
        videoLabel->setGeometry(QRect(10, 70, 331, 31));
        stackedWidget->addWidget(page);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        siguiente2 = new QPushButton(page_4);
        siguiente2->setObjectName(QStringLiteral("siguiente2"));
        siguiente2->setGeometry(QRect(250, 260, 80, 25));
        iAgregarBg = new QPushButton(page_4);
        iAgregarBg->setObjectName(QStringLiteral("iAgregarBg"));
        iAgregarBg->setGeometry(QRect(10, 20, 151, 25));
        iBGview = new QListView(page_4);
        iBGview->setObjectName(QStringLiteral("iBGview"));
        iBGview->setGeometry(QRect(10, 60, 311, 161));
        stackedWidget->addWidget(page_4);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        salir = new QPushButton(page_3);
        salir->setObjectName(QStringLiteral("salir"));
        salir->setGeometry(QRect(250, 260, 80, 25));
        entrenar = new QPushButton(page_3);
        entrenar->setObjectName(QStringLiteral("entrenar"));
        entrenar->setGeometry(QRect(250, 20, 80, 25));
        iOutputConsole = new QTextBrowser(page_3);
        iOutputConsole->setObjectName(QStringLiteral("iOutputConsole"));
        iOutputConsole->setGeometry(QRect(10, 80, 321, 171));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 20, 41, 17));
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 50, 54, 17));
        iLargo = new QLineEdit(page_3);
        iLargo->setObjectName(QStringLiteral("iLargo"));
        iLargo->setGeometry(QRect(80, 50, 31, 21));
        iAncho = new QLineEdit(page_3);
        iAncho->setObjectName(QStringLiteral("iAncho"));
        iAncho->setGeometry(QRect(80, 20, 31, 21));
        iMuestras = new QLineEdit(page_3);
        iMuestras->setObjectName(QStringLiteral("iMuestras"));
        iMuestras->setGeometry(QRect(180, 20, 41, 21));
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 20, 61, 17));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 50, 61, 17));
        iStages = new QLineEdit(page_3);
        iStages->setObjectName(QStringLiteral("iStages"));
        iStages->setGeometry(QRect(180, 50, 41, 21));
        stackedWidget->addWidget(page_3);

        retranslateUi(FnuevoEntrenamiento);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FnuevoEntrenamiento);
    } // setupUi

    void retranslateUi(QDialog *FnuevoEntrenamiento)
    {
        FnuevoEntrenamiento->setWindowTitle(QApplication::translate("FnuevoEntrenamiento", "Nuevo entrenamiento", Q_NULLPTR));
        label_3->setText(QApplication::translate("FnuevoEntrenamiento", "<html><head/><body><p>Al pulsar siguiente, se abrira el reproductor VLC <br/>para tomar muestras (frames) de entrenamiento, <br/>mediante la combinacion de teclas control+s.</p></body></html>", Q_NULLPTR));
        siguiente1->setText(QApplication::translate("FnuevoEntrenamiento", "Siguiente", Q_NULLPTR));
        label->setText(QApplication::translate("FnuevoEntrenamiento", "Seleccione el video para realizar el entrenamiento:", Q_NULLPTR));
        cancelar->setText(QApplication::translate("FnuevoEntrenamiento", "Cancelar", Q_NULLPTR));
        selVideo->setText(QApplication::translate("FnuevoEntrenamiento", "Seleccionar video", Q_NULLPTR));
        label_2->setText(QApplication::translate("FnuevoEntrenamiento", "Nombre de entrenamiento:", Q_NULLPTR));
        videoLabel->setText(QString());
        siguiente2->setText(QApplication::translate("FnuevoEntrenamiento", "Siguiente", Q_NULLPTR));
        iAgregarBg->setText(QApplication::translate("FnuevoEntrenamiento", "Agregar imagen de fondo", Q_NULLPTR));
        salir->setText(QApplication::translate("FnuevoEntrenamiento", "Salir", Q_NULLPTR));
        entrenar->setText(QApplication::translate("FnuevoEntrenamiento", "Entrenar", Q_NULLPTR));
        label_4->setText(QApplication::translate("FnuevoEntrenamiento", "Ancho:", Q_NULLPTR));
        label_5->setText(QApplication::translate("FnuevoEntrenamiento", "Largo:", Q_NULLPTR));
        iLargo->setText(QApplication::translate("FnuevoEntrenamiento", "24", Q_NULLPTR));
        iAncho->setText(QApplication::translate("FnuevoEntrenamiento", "24", Q_NULLPTR));
        iMuestras->setText(QString());
        label_6->setText(QApplication::translate("FnuevoEntrenamiento", "muestras:", Q_NULLPTR));
        label_7->setText(QApplication::translate("FnuevoEntrenamiento", "stages:", Q_NULLPTR));
        iStages->setText(QApplication::translate("FnuevoEntrenamiento", "8", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FnuevoEntrenamiento: public Ui_FnuevoEntrenamiento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FNUEVOENTRENAMIENTO_H
