#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <fstream>
#include <list>
using namespace std;
using namespace cv;


class Poligono
{
	public:
		void insertPoint(Point p);
		void setName(string n);
		void write(ofstream &file);
	private:
		list<Point> puntos;
		string name;
	};

void Poligono::setName(string n)
{
	name = n;
	};
	
void Poligono::write(ofstream &file)
{
	
	list<Point>::iterator it = puntos.begin();
	file << name << ":";
	while (it!=puntos.end())
	{
		Point p = *it;
		file << p << ";";
		it++;
	};
	file << endl;
};
void Poligono::insertPoint(Point p)
{
	puntos.push_front(p);
	};
	
class Data
{
	public:
		void insertPoligono(Poligono p);
		void writeFile(string fileName);
	private:
		list<Poligono> poligonos;
	};


void Data::insertPoligono(Poligono p)
{
	poligonos.push_front(p);
	};
	
void Data::writeFile(string fileName)
{
	ofstream file(fileName, ios::out | ios::trunc);
	
	list<Poligono>::iterator it = poligonos.begin();
	
	while (it!=poligonos.end())
	{
		Poligono p = *it;
		p.write(file);
		it++;
	};
	
	file.close();
	};
bool lineasVerticales=false;
Mat img;
Point pprev(-1,-1);
Data data;
Poligono* poli;
	
void drawLine(Mat &img, Point p1, Point p2)
{
	line(img,p1,p2,Scalar(0,0,255));
	};
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == EVENT_LBUTTONDOWN )
     {
		Point p;
		p.x=x;
		p.y=y;
		
		poli->insertPoint(p);
		if (pprev.x!=-1)
		{
			drawLine(img,pprev,p);
			imshow("My Window", img);
			};
		pprev=p;
	
	
      
     }
     
     /*
     
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

     }*/
}


int main(int argc, char** argv)
{

     // Read image from file 
     string imgFile = argv[1];
     img = imread(imgFile);

	 poli = new Poligono();
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
     int c=0;
     while (c!='q')
     {
		c= waitKey(0);
		cout << "nombre ROI:" << endl;
		string name;
		cin >> name;
		poli->setName(name);
		data.insertPoligono(*poli);
		pprev.x=-1;
		poli = new Poligono();	
     }
      
	 data.writeFile("rois.conf");
     return 0;

}
