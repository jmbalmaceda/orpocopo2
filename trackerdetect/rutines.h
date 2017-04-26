
#include "ini.cpp"
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

class Line
{
	public:
		Line(Point p1, Point p2);
		
		Point getP1();
		Point getP2();
	private:
		Point point1;
		Point point2;
	};

void drawRectangle(Mat &img, Rect &r,Scalar color);

bool intersection(Rect &r, int yline);

INI::Parser readIni(string fileName);

bool isGrayImage( Mat img );
bool movement(Mat imgprev, Mat img);

Line str2line(string s);

Point* getPolygon(Rect r, Line l1, Line l2);

	
bool intersectionLines(Line l1, Line l2,
                      Point2f &r);

