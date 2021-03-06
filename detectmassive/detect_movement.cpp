#include <vector>
#include <opencv2/imgproc.hpp>
#include <opencv2/video.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include "detect_movement.h"
#include "rutines.h"

using namespace std;
using namespace cv;

bool DetectMovementInPolygon::movement(Mat frameActual, Mat framePrev, Rect roi)
{
	Mat frameAMasked= appyMask(frameActual);
	Mat framePMasked = appyMask(framePrev);
	//imshow("appymask",frameMasked);
	bool cond=false;
		//aplico mascara en frame
		//recorto con roi frame actual y frame previo
		//cout << "recortara:" << roi << endl;
		Mat cropprev = framePMasked(roi);
		Mat crop = frameAMasked(roi);
		//cout << "recorto" << endl;
		cond = movementFrame(cropprev,crop);
		//if (cond) imshow("crop",crop);
		return cond;
	
	};

Mat DetectMovementInPolygon::appyMask(Mat frame)
{
	Mat frameMasked;
	frame.copyTo(frameMasked, mask);
	return frameMasked;
	};
	
void DetectMovementInPolygon::createMask(Size s, vector<Point> poly)
{
	Mat m(s, CV_8UC1);
	m = Scalar(0,0,0);
	fillConvexPoly(m, poly, Scalar(255,255,255));
	mask=m;
	
	
	
	};
DetectMovementInPolygon::DetectMovementInPolygon(Mat frameI, vector<Point> poly)
{
	roiPolygonal = poly;
	
	Size s = frameI.size();
	//crear mascara con el poligono
	createMask(s,poly);
	framePrev = appyMask(frameI);
	};
