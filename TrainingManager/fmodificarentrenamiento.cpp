#include "fmodificarentrenamiento.h"
#include "ui_fmodificarentrenamiento.h"
#include "utils.h"
#include <QProcess>
#include "fnuevoentrenamiento.h"
#include <iostream>
using namespace std;

FModificarEntrenamiento::FModificarEntrenamiento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FModificarEntrenamiento)
{
    ui->setupUi(this);

    tModel = new QStringListModel();
    ui->listView->setModel(tModel);

    readFileLines2List("trainings.txt",tList);
    tModel->setStringList(tList);
}

FModificarEntrenamiento::~FModificarEntrenamiento()
{
    delete ui;
}

void FModificarEntrenamiento::on_nuevoRecorte_clicked()
{

    QModelIndex index = ui->listView->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();

    datos.nameTraining = itemText;
    cout << itemText.toStdString() << endl;

    QProcess* annotation_process = new QProcess();

    lauchOpenCvAnnotation(annotation_process,datos);
}

void FModificarEntrenamiento::on_nuevoRecorte_2_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();

    datos.nameTraining = itemText;

    datos.bg_file= "./training/";
    datos.bg_file.append(datos.nameTraining);
    datos.bg_file.append("/bg.txt");

    datos.annotations_file="./training/";
    datos.annotations_file.append(datos.nameTraining);
    datos.annotations_file.append("/annotations.txt");

    datos.nSamples = countSamples(datos.annotations_file.toStdString());

    FnuevoEntrenamiento* fn = new FnuevoEntrenamiento(this,&datos);
    fn->setMuestras(datos.nSamples);
    fn->next_page();
    fn->next_page();
    fn->show();
    this->hide();
}

void FModificarEntrenamiento::cs()
{
    datos.nSamples = countSamples(datos.annotations_file.toStdString());
};
