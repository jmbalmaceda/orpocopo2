#ifndef FNUEVOENTRENAMIENTO_H
#define FNUEVOENTRENAMIENTO_H

#include <QDialog>
#include <QProcess>
#include <QStringListModel>
#include "data.h"

namespace Ui {
class FnuevoEntrenamiento;
}

class FnuevoEntrenamiento : public QDialog
{

   Q_OBJECT
public:
    explicit FnuevoEntrenamiento(QWidget *parent = 0, Data* d = NULL);
    ~FnuevoEntrenamiento();
    void next_page();
    void setMuestras(int n);

private slots:
    void on_selVideo_clicked();

    void on_siguiente1_clicked();
    void updateText();
    void on_entrenar_clicked();
    void on_iAgregarBg_clicked();
    void np();
    void on_siguiente2_clicked();
    void cs();
    void on_salir_clicked();

private:

    Ui::FnuevoEntrenamiento *ui;
    QProcess *process;
    QStringListModel *bgModel;
    QStringList bgList;
    Data datos;
    void crearBGFile(QString directory);
};

#endif // FNUEVOENTRENAMIENTO_H
