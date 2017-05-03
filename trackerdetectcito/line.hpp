#include<opencv2/imgproc.hpp>
using namespace cv;

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
