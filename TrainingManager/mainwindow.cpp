#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fnuevoentrenamiento.h"
#include "fmodificarentrenamiento.h"

#include <QFileDialog>
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fNuevoEntrenamiento = new FnuevoEntrenamiento(this);
    fModificarEntrenamiento = new FModificarEntrenamiento(this);

    connect(ui->nuevoEntrenamiento,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->nuevoEntrenamiento,SIGNAL(clicked()),fNuevoEntrenamiento,SLOT(show()));


    connect(ui->modificarEntrenamiento,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->modificarEntrenamiento,SIGNAL(clicked()),fModificarEntrenamiento,SLOT(show()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSalir_triggered()
{
    exit(0);
}

void MainWindow::on_actionAbrir_video_triggered()
{

}

void MainWindow::on_nuevoEntrenamiento_clicked()
{

}

void MainWindow::on_modificarEntrenamiento_clicked()
{

}
