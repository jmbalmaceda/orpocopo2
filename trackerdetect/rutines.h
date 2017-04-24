
#include "ini.cpp"

using namespace cv;
using namespace std;

void drawRectangle(Mat &img, Rect &r,Scalar color);

bool intersection(Rect &r, int yline);
bool intersection(Rect &r1, Rect &r2)
{
	
	};
INI::Parser readIni(string fileName);

bool isGrayImage( Mat img );
bool movement(Mat imgprev, Mat img);
