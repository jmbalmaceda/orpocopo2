#include "fnuevoentrenamiento.h"
#include "ui_fnuevoentrenamiento.h"
#include <QFileDialog>
#include <fstream>
#include "utils.h"
#include "INIReader.h"
#include <iostream>
#include "mainwindow.h"
using namespace std;



int i=0;


FnuevoEntrenamiento::FnuevoEntrenamiento(QWidget *parent, Data* d ) :
    QDialog(parent),
    ui(new Ui::FnuevoEntrenamiento)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
    if (d!=NULL)
    {
       datos = *d;
    };

    process = new QProcess();

    connect(ui->cancelar,SIGNAL(clicked()),parent,SLOT(show()));
    connect(ui->cancelar,SIGNAL(clicked()),this,SLOT(hide()));
    connect(process, SIGNAL(readyReadStandardOutput()),this,SLOT(updateText()));

    connect(ui->siguiente2,SIGNAL(clicked()),this,SLOT(np()));

    //set model of listview BG's
    bgModel = new QStringListModel();
    ui->iBGview->setModel(bgModel);
    bgModel->setStringList(bgList);
}

FnuevoEntrenamiento::~FnuevoEntrenamiento()
{
    delete ui;
}

void FnuevoEntrenamiento::on_selVideo_clicked()
{
    datos.fileName = QFileDialog::getOpenFileName(this,
             tr("Abrir video"), "/home", tr("Archivos de video (*.*)"));
#ifdef _WIN32
    datos.fileName.replace("/","\\");
    cout << "reemplazo" << endl;
#endif
    ui->videoLabel->setText(datos.fileName);
}

void FnuevoEntrenamiento::next_page()
{
    i++;
    ui->stackedWidget->setCurrentIndex(i);
};

void FnuevoEntrenamiento::np()
{
    next_page();
};
void FnuevoEntrenamiento::on_siguiente1_clicked()
{

    datos.nameTraining = ui->iNombreEntrenamiento->text();

    if (datos.fileName!="" && datos.nameTraining!="")
    {
        QProcess mkprocess;
        QString commandmkdir;

#ifdef _WIN32
        commandmkdir.append("mkdir training\\");
#else
        commandmkdir.append("mkdir ./training/");
#endif
        commandmkdir.append(datos.nameTraining);

        QString mk1 = commandmkdir;


#ifdef _WIN32
        commandmkdir= "mkdir training\\";
#else
        commandmkdir= "mkdir ./training/";
#endif
        commandmkdir.append(datos.nameTraining);

#ifdef _WIN32
        commandmkdir.append("\\xml");
#else
        commandmkdir.append("/xml");
#endif
        QString mk2 = commandmkdir;

        commandmkdir=mk1;

#ifdef _WIN32
        commandmkdir.append("\\img");
#else
        commandmkdir.append("/img");
#endif
        QString mk3 = commandmkdir;

        commandmkdir=mk1; commandmkdir.append("; ");
        commandmkdir.append(mk2); commandmkdir.append("; ");
        commandmkdir.append(mk3);
        cout << "commands:" << commandmkdir.toStdString() << endl;
        system(commandmkdir.toStdString().c_str());

        INIReader reader("conf.ini");
        string vlcpath = reader.Get("paths", "vlc", "UNKNOWN");

        QString command=QString::fromStdString(vlcpath);
        command.append(" --snapshot-prefix  cap  --no-snapshot-preview --no-playlist-autostart --snapshot-sequential  ");
        command.append(" --snapshot-path ./training/");
        command.append(datos.nameTraining);
        command.append("/img/ ");
        command.append(datos.fileName);
        cout << "comando:" << command.toStdString() << endl;
        QProcess* vlc_process = new QProcess();
        QProcess* annotation_process = new QProcess();

       // connect(vlc_process,SIGNAL(finished(int)),this,SLOT(lauchOpenCvAnnotation(annotation_process,datos)));
        vlc_process->start(command.toStdString().c_str());
        vlc_process->waitForFinished(-1);

         connect(annotation_process,SIGNAL(finished(int)),this,SLOT(cs()));
        lauchOpenCvAnnotation(annotation_process,datos);
        next_page();
    }
}


void FnuevoEntrenamiento::updateText()
{
   QByteArray data = process->readAllStandardOutput();
   ui->iOutputConsole->append(QString(data));
}

void FnuevoEntrenamiento::on_entrenar_clicked()
{


   //eliminar entrenamiento previo
   QString command = "del cascade.xml";
   QString wk ="./training/";
   wk.append(datos.nameTraining);
   wk.append("/xml/");

   cout << "wk: " << wk.toStdString() << endl;
   cout << "command:" << command.toStdString() << endl;
   process->setWorkingDirectory(wk);
   process->start(command);
   process->waitForFinished();

   cout << "nsamples:" << datos.nSamples << endl;
   command = "opencv_createsamples -info ";
   command.append("annotations.txt");
   command.append(" -bg ");
   command.append(datos.bg_file);
   command.append(" -vec ");
   command.append(datos.nameTraining); command.append(".vec");
   command.append(" -num ");
   command.append(QString::number(datos.nSamples));
   command.append(" -h "); command.append(ui->iAncho->text());
   command.append(" -w "); command.append(ui->iLargo->text());
  cout << command.toStdString() << endl;

  wk = "./training/";
  wk.append(datos.nameTraining);

  process->setWorkingDirectory(wk);

     process->start(command);
    //ahora tengo que entrenar

  //opencv_traincascade -data training/monarca -vec vecs/monarca -bg bg/monarca.txt -numPos 500 -w 40 -h 40

//   command = "taskset -c 1,2,3 opencv_traincascade -data ";
   command = "opencv_traincascade -data ";

  command.append("./xml");

   command.append(" -vec ");
   command.append(datos.nameTraining); command.append(".vec");
   command.append(" -bg ");
   command.append("bg.txt");

   command.append(" -numPos ");
   command.append(QString::number(datos.nSamples-datos.nSamples/5)); //20 porciento
   command.append(" -numStages ");
   command.append(ui->iStages->text());
    command.append(" -h "); command.append(ui->iAncho->text());
    command.append(" -w "); command.append(ui->iLargo->text());
   process->waitForFinished();
   cout << "segundo comando:" << command.toStdString() << endl;

   process->setWorkingDirectory(wk);
   process->start(command);


 //  process->waitForFinished();
}

void FnuevoEntrenamiento::on_iAgregarBg_clicked()
{
    datos.fileName="";
    datos.fileName = QFileDialog::getOpenFileName(this,
             tr("Abrir video"), "/home", tr("Archivos de video (*.*)"));
    if (datos.fileName!="")
    {

      bgList << datos.fileName;
      bgModel->setStringList(bgList);
      datos.fileName="";
    };
}


void FnuevoEntrenamiento::crearBGFile(QString filename)
{
    //extrae de la lista de bg files y genera el archivo bg.txt para el entrenamiento
    ofstream file(filename.toStdString());

    for (QStringList::iterator it = bgList.begin();
          it != bgList.end(); ++it) {
         QString current = *it;

         int lastBarrel = current.lastIndexOf("/");
         QStringRef name(&current,lastBarrel+1,current.length()-lastBarrel-1);
         file << "./img/" << name.toString().toStdString() << endl;
     }

    file.close();
};



void FnuevoEntrenamiento::on_siguiente2_clicked()
{
    datos.bg_file= "./training/";
    datos.bg_file.append(datos.nameTraining);
    datos.bg_file.append("/bg.txt");
    crearBGFile(datos.bg_file);
    setMuestras(datos.nSamples);
     appendToFile("trainings.txt",datos.nameTraining.toStdString());
}

void FnuevoEntrenamiento::cs()
{
    datos.nSamples = countSamples(datos.annotations_file.toStdString());
};

void FnuevoEntrenamiento::setMuestras(int n)
{
    ui->iMuestras->setText(QString::number(n));
};
void FnuevoEntrenamiento::on_salir_clicked()
{
    exit(0);
}
