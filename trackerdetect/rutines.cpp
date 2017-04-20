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
