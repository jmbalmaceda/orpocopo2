#include <vector>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv; 

class DetectMovementInPolygon
{
	public:
		DetectMovementInPolygon(Mat frameI, vector<Point> poly);
		bool movement(Mat frame,vector<Point> subPoly);
		Mat appyMask(Mat frame);
		void createMask(Size s, vector<Point> poly);
		bool movement(Mat frame,Rect roi, int nFrame);
	private:
		vector<Point> roiPolygonal;
		Mat framePrev;
		Mat mask;
		int nFramePrev;
		
};
