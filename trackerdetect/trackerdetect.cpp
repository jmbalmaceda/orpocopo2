#include <iostream>
#include <fstream>
#include <string>

#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>

#include "DBConnection.h"

#include "ini.cpp"
#include "rutines.h"
#include "tracker.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

	//Leer configuracion
	INI::Parser p = readIni("conf.ini");
   
	int minH=stoi(p.top()["minH"]);
	int minW=stoi(p.top()["minW"]);
	int maxH=stoi(p.top()["maxH"]);
	int maxW=stoi(p.top()["maxW"]);
	int minTimeDetect=stoi(p.top()["minTimeDetect"]);
	string cascadeClassifierFile=p.top()["cascadeClassifierFile"];
	string cascadeClassifierFile2=p.top()["cascadeClassifierFile2"];
	string cascadeClassifierFileMano=p.top()["cascadeClassifierFileMano"];
	
	ConnectionData data;
	data.user = p.top()["user"];
	data.password = p.top()["password"];
	data.server = p.top()["server"];
	data.database = p.top()["database"];
	
	int ROIline=stoi(p.top()["ROIline"]);
	
	
	DBConnection dbconn(data);
	
	string fileName = argv[2];
	ofstream file(fileName.c_str(), ios::out | ios::trunc);

  
	//creo traker
	Size minSize(minH,minW);
	Size maxSize(maxH,maxW);
	DetectionBasedTracker Detector = getDetectionBasedTracker(minSize,maxSize,minTimeDetect,cascadeClassifierFile);
	
	//tracker persona completa
	Size minSize2(60,90);	
	Size maxSize2(150,150);
	DetectionBasedTracker Detector2 = getDetectionBasedTracker(minSize2,maxSize2,minTimeDetect,cascadeClassifierFile2);


	Size minSizeMano(24,24);	
	Size maxSizeMano(70,70);
	DetectionBasedTracker DetectorMano = getDetectionBasedTracker(minSizeMano,maxSizeMano,minTimeDetect,cascadeClassifierFileMano);
	
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
    for (;;)
    {
		nFrame++;
		framePrevC=frameC.clone();
		vc >> frame;
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
            	cout << "(" << r.x << "," << r.y << ")" << endl;
				//inserto en la base de datos
            	//dbconn.insertPickUpInformation(nFrame,0,objs[i].second,r.x,r.y,0);
            	//dibujo
            	drawRectangle(frame,r,Scalar(0,255,0));
			}
       
       
              
               	
		Detector2.process(grayFrame);
	
		vector<Object> objs2;
        Detector2.getObjects(objs2);
        
        DetectorMano.process(grayFrame);
        vector<Object> manos;
        DetectorMano.getObjects(manos);
        
      // cout << "CAJAS AZULES:" << endl;
        for (int i = 0; i < objs2.size(); i++) {
  
           	Rect r = objs2[i].first;
		//	cout << "(x,y):" << r.x << "," << r.y << endl;
		//	cout << "(w,h):" << r.width << "," << r.height << endl;
			if (intersection(r,ROIline))
			{
				cout << "interseccion con zona de interes" << endl;
				//tengo que recortar y aplicar detector de mano
				Rect roi;
				roi.x = max(0,r.x-24);
				roi.width = min(r.width+24,frame.size().width);
				roi.y = max(0,r.y-24);
				roi.height = min(r.height+80,frame.size().height);
				
				Mat crop = frameC(roi);
				Mat cropprev = framePrevC(roi);
				if (movement(crop,cropprev))
				{
					cout << "cacona" << endl;
					};
				//ahora tengo que aplicar detector de mano
				//si alguna mano esta intersecada con la roi actual, dibujo el rectangulo
				
				for (int m=0;m < manos.size();m++)
				{
						Rect mano = manos[i].first;
						if ((mano & roi).area()>0)
						{
							drawRectangle(frame,mano,Scalar(0,0,255));
							};
					};
				
				imshow("crop", crop);
				
				};
			//inserto en la base de datos
           	//dbconn.insertPickUpInformation(nFrame,0,objs[i].second,r.x,r.y,0);
           	//dibujo
           	drawRectangle(frame,r,Scalar(255,0,0));
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
