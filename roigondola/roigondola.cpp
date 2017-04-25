#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <fstream>
#include <list>
using namespace std;
using namespace cv;

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

class Data
{
	public:
		void insertLineH(Line l);
		void writeFile(string fileName);
	private:
		list<Line> horizontales;
	};

Line::Line(Point p1,Point p2)
{
	point1=p1;
	point2=p2;
	};

void Data::insertLineH(Line l)
{
	horizontales.push_front(l);
	};
	
void Data::writeFile(string fileName)
{
	ofstream file(fileName, ios::out | ios::trunc);
	
	list<Line>::iterator it = horizontales.begin();
	file << "[horizontales]" << endl;
	while (it!=horizontales.end())
	{
		Line l = *it;

		file << l.getP1() << ";" << l.getP2() <<  endl;
		it++;
		};
	
	file.close();
	};
bool clickp1=false;
bool lineasVerticales=false;
Point p1,p2;
Mat img;
Data data;
Point Line::getP1()
{
	return point1;
	};
Point Line::getP2()
{
	return point2;
	};
	
void drawLine(Mat &img, Point p1, Point p2)
{
	line(img,p1,p2,Scalar(0,0,255));
	};
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == EVENT_LBUTTONDOWN )
     {
			if (!clickp1)
			{
				p1.x=x;
				p1.y=y;
				cout << "primer punto" << endl;
				clickp1=true;
				} else
				{
					p2.x=x;
					p2.y=y;
					
					Line l(p1,p2);
					cout << "inserto linea" << endl;
					drawLine(img,p1,p2);
					     imshow("My Window", img);
					data.insertLineH(l);
					clickp1=false;
					};
          cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_RBUTTONDOWN )
     {
          cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_MBUTTONDOWN )
     {
          cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if ( event == EVENT_MOUSEMOVE )
     {
          cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;

     }
}


int main(int argc, char** argv)
{

     // Read image from file 
     string imgFile = argv[1];
     img = imread(imgFile);

     //if fail to read the image
     if ( img.empty() ) 
     { 
          cout << "Error loading the image" << endl;
          return -1; 
     }

     //Create a window
     namedWindow("My Window", 1);

     //set the callback function for any mouse event
     setMouseCallback("My Window", CallBackFunc, NULL);

     //show the image
     
     imshow("My Window", img);

     // Wait until user press some key
     int c= waitKey(0);
   //  cout << "Dibuje lineas verticales" << endl;
   //  lineasVerticales=true;
   //  c= waitKey(0);
     
	 data.writeFile("rois.conf");
     return 0;

}
