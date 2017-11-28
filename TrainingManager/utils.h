#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <QStringList>
#include <QProcess>
#include "data.h"
using namespace std;

void readFileLines2List(string filename, QStringList& list);
void appendToFile(string filename, string text);
int countSamples(string filename);
void lauchOpenCvAnnotation(QProcess* annotation_process, Data& datos);
#endif // UTILS_H
