#ifndef FMODIFICARENTRENAMIENTO_H
#define FMODIFICARENTRENAMIENTO_H

#include <QDialog>
#include <QStringListModel>
#include "data.h"

namespace Ui {
class FModificarEntrenamiento;
}

class FModificarEntrenamiento : public QDialog
{
    Q_OBJECT

public:
    explicit FModificarEntrenamiento(QWidget *parent = 0);
    ~FModificarEntrenamiento();

private slots:
    void on_nuevoRecorte_clicked();
    void cs();
    void on_nuevoRecorte_2_clicked();

private:
    Ui::FModificarEntrenamiento *ui;
    QStringListModel *tModel;
    QStringList tList;
    Data datos;
};

#endif // FMODIFICARENTRENAMIENTO_H
