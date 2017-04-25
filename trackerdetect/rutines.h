
#include "ini.cpp"
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

class Line;

void drawRectangle(Mat &img, Rect &r,Scalar color);

bool intersection(Rect &r, int yline);
bool intersection(Rect &r1, Rect &r2)
{
	
	};
INI::Parser readIni(string fileName);

bool isGrayImage( Mat img );
bool movement(Mat imgprev, Mat img);

Point str2point(string s);

Point* getPolygon(Rect r, Line l1, Line l2);

	
bool intersectionLines(Line l1, Line l2,
                      Point2f &r);

