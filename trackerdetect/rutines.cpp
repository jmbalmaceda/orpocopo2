#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include "ini.cpp"


using namespace cv;
using namespace std;

class Line
{
	public:
		Line(Point p1, Point p2)
		{
				point1=p1;
				point2=p2;
			};
		
		Point getP1();
		Point getP2();
	private:
		Point point1;
		Point point2;
	};
	
Point Line::getP1()
{
	return point1;
	};
Point Line::getP2()
{
	return point2;
	};



void drawRectangle(Mat &img, Rect &r,Scalar color)
{
	r.x += cvRound(r.width*0.1);
	r.width = cvRound(r.width*0.8);
	r.y += cvRound(r.height*0.07);
	r.height = cvRound(r.height*0.8);
	rectangle(img, r.tl(), r.br(), color, 3);
	};
	

INI::Parser readIni(string fileName)
{
	std::stringstream stream;
	string ss;
	ifstream iniFile;
	iniFile.open(fileName,ios::in);
	while (!iniFile.eof())
	{
		getline(iniFile,ss);
		stream << ss << '\n';
		};

  INI::Parser p(stream);
  std::stringstream out;
  p.dump(out);

  return p;
}

bool intersection(Rect &r, int yline)
{
	
	return (yline >= r.y) && (yline <= r.y+r.height);
	};

bool intersectionLines(Line l1, Line l2,
                      Point2f &r)
{
	Point2f o1 = l1.getP1();
	Point2f o2 = l1.getP2();
	Point2f p1 = l2.getP1();
	Point2f p2 = l2.getP2();
	
    Point2f x = o2 - o1;
    Point2f d1 = p1 - o1;
    Point2f d2 = p2 - o2;

    float cross = d1.x*d2.y - d1.y*d2.x;
    if (abs(cross) < /*EPS*/1e-8)
        return false;

    double t1 = (x.x * d2.y - x.y * d2.x)/cross;
    r = o1 + d1 * t1;
    return true;
}

bool isGrayImage( Mat img ) // returns true if the given 3 channel image is B = G = R
{
    Mat dst;
    Mat bgr[3];
    split( img, bgr );
    absdiff( bgr[0], bgr[1], dst );

    if(countNonZero( dst ))
        return false;

    absdiff( bgr[0], bgr[2], dst );
    return !countNonZero( dst );
}

bool movement(Mat imgprev, Mat img)
{
	
	Mat motion;

	absdiff(imgprev, img, motion);
	threshold(motion, motion, 40, 255, cv::THRESH_BINARY);
	//erode(motion, motion, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3)));
	
	imshow("movement", motion);
	return !isGrayImage(motion);
	};

Point str2point(string s)
{
	int pos = s.find(".");
	
	 string sp1 = s.substr (0,pos);
	   
	};


Point* getPolygon(Rect r, Line l1, Line l2)
{
	Point* vec = new Point[4];
	
	
	//construyo las lineas verticales desde el rectanculo r
	Point2f lr1p1;
	lr1p1.x=r.x;
	lr1p1.y=r.y;
	
	Point2f lr1p2;
	lr1p2.x=r.x;
	lr1p2.y=r.y+r.height;
	
	Line lr1(lr1p1,lr1p1);
	
	Point2f lr2p1;
	lr2p1.x=r.x+r.width;
	lr2p1.y=r.y;
	
	Point2f lr2p2;
	lr2p2.x=r.x+r.width;
	lr2p2.y=r.y+r.height;
	
	Line lr2(lr2p2,lr2p2);
	
	//obtengo los cuatro puntos del poligono
	
	Point2f p1,p2,p3,p4;
	
	intersectionLines(lr1,l1,p1);
	intersectionLines(lr1,l2,p2);
	intersectionLines(lr2,l1,p3);
	intersectionLines(lr2,l2,p4);
	
	vec[0]=p1;
	vec[1]=p2;
	vec[2]=p3;
	vec[3]=p4;
	
	return vec;
	};
	




