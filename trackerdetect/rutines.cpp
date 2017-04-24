#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>

#include "ini.cpp"

using namespace cv;
using namespace std;


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
