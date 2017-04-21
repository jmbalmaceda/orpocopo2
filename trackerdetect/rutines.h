
#include "ini.cpp"

using namespace cv;
using namespace std;

void drawRectangle(Mat &img, Rect &r,Scalar color);

bool intersection(Rect &r, int yline);

INI::Parser readIni(string fileName);


