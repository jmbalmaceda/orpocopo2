#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>

#include "DBConnection.h"

#include "ini.cpp"
#include "rutines.h"
#include "tracker.h"
#include "detect_movement.h"
#include "index.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

	Index index;
	//Leer configuracion
	INI::Parser p = readIni("conf.ini");
   
	int minH=stoi(p.top()["minH"]);
	int minW=stoi(p.top()["minW"]);
	int maxH=stoi(p.top()["maxH"]);
	int maxW=stoi(p.top()["maxW"]);
	int minTimeDetect=stoi(p.top()["minTimeDetect"]);
	string cascadeClassifierFile=p.top()["cascadeClassifierFile"];

	ConnectionData data;
	data.user = p.top()["user"];
	data.password = p.top()["password"];
	data.server = p.top()["server"];
	data.database = p.top()["database"];
	
	int ROIline=stoi(p.top()["ROIline"]);
	string slinea1Gondola=p.top()["linea1"];
	string slinea2Gondola=p.top()["linea2"];
	
	
	//calculo la ROI de la gondola para el frame entero
	Line Linea1Gondola = str2line(slinea1Gondola);
	Line Linea2Gondola = str2line(slinea2Gondola);
	
	DBConnection dbconn(data);
	
	string fileName = argv[2];
	ofstream file(fileName.c_str(), ios::out | ios::trunc);

  
	//creo traker
	Size minSize(minH,minW);
	Size maxSize(maxH,maxW);
	DetectionBasedTracker Detector = getDetectionBasedTracker(minSize,maxSize,minTimeDetect,cascadeClassifierFile);
	
	
//	MultiTracker mtracker("MEDIANFLOW");
    namedWindow("people detector", WINDOW_NORMAL | WINDOW_KEEPRATIO);
    
    string video_filename = argv[1];

    //Read from video file
    VideoCapture vc;
    Mat frame;
    Mat framePrevC;
    Mat frameC;
    vc.open(video_filename.c_str());
    if (!vc.isOpened()) throw runtime_error(string("can't open video file: " + video_filename));
    unsigned long int nFrame=0;
    
    
    //extraigo dimensiones
    vc >> frame;
    Size s = frame.size();
    
    Rect roiFrame;
    roiFrame.x=0;
    roiFrame.y=0;
    roiFrame.width = s.width;
    roiFrame.height = s.height;
    
	vector<Point> vecpoli = getPolygon(roiFrame,Linea1Gondola,Linea2Gondola);
	
	DetectMovementInPolygon dmpoly(frame,vecpoli);
    
    for (;;)
    {
		nFrame++;
		framePrevC=frameC.clone();
		vc >> frame;
	
		/*
		Point* pts = new Point[4];
		
		//Point p1,p2,p3,p4;
		pts[0].x=100;
		pts[0].y=100;
		pts[1].x=200;
		pts[1].y=200;
		pts[2].x=100;
		pts[2].y=400;
		pts[3].x=120;
		pts[3].y=100;
		
		fillConvexPoly(frame, pts, 4, Scalar(0,0,255),16,0);
				*/
		frameC=frame.clone();
		if (frame.empty()) break;
		
		Mat grayFrame;
		cvtColor(frame, grayFrame, COLOR_RGB2GRAY);
	
		Detector.process(grayFrame);
	
		vector<Object> objs;
        Detector.getObjects(objs);
       
            
		cout << "frame:" << nFrame << endl;
        for (int i = 0; i < objs.size(); i++) {
            	cout << "objeto " << objs[i].second << ":";
            	Rect r = objs[i].first;
            	int iExt = objs[i].second;
            	int iInt;
            	if (!index.get(iExt,iInt))
            	{
					index.put(iExt);
					iInt = index.size();
					};
            	
            	cout << "interno:" << iInt << ", "  << "externo:" << iExt << endl;
            	
            	cout <<  "(" << r.x << "," << r.y << ")" << endl;
				
				//inserto en la base de datos
            	//dbconn.insertPickUpInformation(nFrame,0,objs[i].second,r.x,r.y,0);
            	//dibujo
            	drawRectangle(frame,r,Scalar(0,255,0));
			}
       
       
              
               	

        
		imshow("people detector", frame);
		int c = waitKey( vc.isOpened() ? 30 : 0 ) & 255;
		if ( c == 'q' || c == 'Q' || c == 27)
			break;
	}
   
	frame.release();
    vc.release();
    
    destroyAllWindows();
    
    file.close();
    exit(0);
    return 0;
}
