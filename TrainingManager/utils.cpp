#include <fstream>
#include "utils.h"
#include <QProcess>
#include <iostream>
using namespace std;

#ifndef UTILS
using namespace std;

int countSamples(string filename)
{
    int count=0;
    ifstream input(filename);

    string line;
    getline(input,line);

    while (!input.eof())
    {

        int pos = line.find(' ');
                string number = line.substr(pos,2);
        count += stoi(number);

        getline(input,line);
        };
    return count;
   }

void appendToFile(string filename, string text)
{
    ofstream file(filename, ofstream::app);

    file << text << endl;

    file.close();
};


void readFileLines2List(string filename, QStringList& list)
{

      ifstream file(filename, ifstream::in);
      while (!file.eof())
      {
        string line;
        getline(file,line);
        list << QString::fromStdString(line);
      };
};

void lauchOpenCvAnnotation(QProcess* annotation_process, Data& datos)
{
    datos.annotations_file="./training/";
    datos.annotations_file.append(datos.nameTraining);
    datos.annotations_file.append("/annotations.txt");

    QString working_dir="./training/";
    working_dir.append(datos.nameTraining);
    working_dir.append("/");
    annotation_process->setWorkingDirectory(working_dir);
    QString command;

    command = "opencv_annotation -i=./img -a=annotations.txt";


    annotation_process->start(command);
    cout << "annotations_file:" << datos.annotations_file.toStdString() << endl;


    cout << "count samples:" << datos.nSamples << endl;

};
#endif
