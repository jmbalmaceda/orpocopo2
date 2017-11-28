#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fnuevoentrenamiento.h>
#include <fmodificarentrenamiento.h>
#include "data.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{


public:
    Data datos;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSalir_triggered();

    void on_actionAbrir_video_triggered();

    void on_nuevoEntrenamiento_clicked();

    void on_modificarEntrenamiento_clicked();

private:
     Q_OBJECT
    Ui::MainWindow *ui;
    FnuevoEntrenamiento* fNuevoEntrenamiento;
    FModificarEntrenamiento* fModificarEntrenamiento;

};

#endif // MAINWINDOW_H
