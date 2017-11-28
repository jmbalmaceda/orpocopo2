#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>

#include "DBConnection.h"


#include "rutines.h"
#include "tracker.h"
#include "detect_movement.h"
#include "index.h"
#include "INIReader.h"

using namespace cv;
using namespace std;

class RegBDFrame
{
	public:
	//dado un indice de persona, asociar las manos
	map<int, Point>* posMano;
	map<int, Point>* posCabeza;
	long int nFrame;
	
	RegBDFrame()
	{
		posMano = new map<int, Point>();
		posCabeza = new map<int, Point>();
		};
	void writeinBD(DBConnection &dbconn);
	//regDBFrame()
	
};

void RegBDFrame::writeinBD(DBConnection &dbconn)
	{
		
	
		map<int,Point>::iterator it = posCabeza->begin();
		
	

		while (it!=posCabeza->end())
		{
			
			int indice = it->first;
			Point cabeza = it->second;
			map<int,Point>::iterator itSearchMano = posMano->find(indice);
			
			if (itSearchMano!= posMano->end())
			{
				Point mano = itSearchMano->second;
				dbconn.insertPickUpInformation(nFrame,0,indice,cabeza.x,cabeza.y,0,1,mano.x,mano.y,1);
				} else
				{
					dbconn.insertPickUpInformation(nFrame,0,indice,cabeza.x,cabeza.y,0);
					};
			it++;
			};
		//dbconn.insertPickUpInformation(nFrame,0,objs[i].second,r.x,r.y,0);
		};
int main(int argc, char** argv)
{



	Index index;
	//Leer configuracion
	
	INIReader reader("confindio.ini");
	string username = reader.Get("detector", "name", "UNKNOWN");
	int minH= reader.GetInteger("detector","minH",-1);
	int minW= reader.GetInteger("detector","minW",-1);
	int maxH= reader.GetInteger("detector","maxH",-1);
	int maxW= reader.GetInteger("detector","maxW",-1);
	int offsety= reader.GetInteger("detector","offsetYCajaBlanca",-1);
	int minTimeDetect=reader.GetInteger("detector","minTimeDetect",-1);
	
	string cascadeClassifierFile= reader.Get("detector","cascadeClassifierFile","NULL");
	cout << "param:" << cascadeClassifierFile << endl;
	string cascadeClassifierFile2= reader.Get("detector","cascadeClassifierFile2","NULL");
	string cascadeClassifierFileMano= reader.Get("detector","cascadeClassifierMano","NULL");
	
	string cascadeClassifierFileBRec=reader.Get("detector","cascadeClassifierFileBRec","NULL");
		
	CascadeClassifier detectorBrazoRectangulo;
	detectorBrazoRectangulo.load(cascadeClassifierFileBRec);
	
	ConnectionData data;
	data.user = reader.Get("bd","user","NULL");
	data.password = reader.Get("bd","password","NULL");
	data.server = reader.Get("bd","server","NULL");
	data.database = reader.Get("bd","database","NULL");
	
	int ROIline=reader.GetInteger("detectorMano","ROILine",-1);
	string slinea1Gondola= reader.Get("gondola","linea1","NULL");
	string slinea2Gondola= reader.Get("gondola","linea2","NULL");
	string slinea3Gondola= reader.Get("gondola","linea3","NULL");
	
	//calculo la ROI de la gondola para el frame entero
	Line Linea1Gondola = str2line(slinea1Gondola);
	Line Linea2Gondola = str2line(slinea2Gondola);
	Line Linea3Gondola = str2line(slinea3Gondola);
	
	DBConnection dbconn(data);
	
	string fileName = argv[2];
	//ofstream file(fileName.c_str(), ios::out | ios::trunc);

  
	//creo traker
	Size minSize(minH,minW);
	Size maxSize(maxH,maxW);
	DetectionBasedTracker Detector = getDetectionBasedTracker(minSize,maxSize,minTimeDetect,cascadeClassifierFile);
	

/*
	Size minSizeMano(40,40);	
	Size maxSizeMano(80,80);
	DetectionBasedTracker DetectorMano = getDetectionBasedTracker(minSizeMano,maxSizeMano,0,cascadeClassifierFileMano);

	*/
//	MultiTracker mtracker("MEDIANFLOW");
    namedWindow("people detector", WINDOW_NORMAL | WINDOW_KEEPRATIO);
    
    string video_filename = argv[1];



    //Read from video file
    VideoCapture vc;
    Mat frame;
    Mat frameCPrev;
    Mat frameC;
    vc.open(video_filename.c_str());
    
    int ex = static_cast<int>(vc.get(CAP_PROP_FOURCC));
    Size S = Size((int) vc.get(CAP_PROP_FRAME_WIDTH), (int) vc.get(CAP_PROP_FRAME_HEIGHT));
    
    VideoWriter outputVideo;                                        // Open the output
    outputVideo.open("output.avi", ex, vc.get(CAP_PROP_FPS), S, true);

    if (!vc.isOpened()) throw runtime_error(string("can't open video file: " + video_filename));
    unsigned long int nFrame=0;
    
    
    //extraigo dimensiones
    vc >> frame;
    frameC = frame;
    Size s = frame.size();
    
    Rect roiFrame;
    roiFrame.x=0;
    roiFrame.y=0;
    roiFrame.width = s.width;
    roiFrame.height = s.height;
    
	vector<Point> vecpoli = getPolygon(roiFrame,Linea1Gondola,Linea3Gondola);
	
	DetectMovementInPolygon dmpoly(frame,vecpoli);
    
    Rect lastBrazo;
    lastBrazo.x=-1;
    
    for (;;)
    {
		nFrame++;
		frameCPrev=frameC;
		vc >> frame;
		frameC=frame.clone();
		
		if (frame.empty()) break;
		
		RegBDFrame* reg = new RegBDFrame();
		
		reg->nFrame=nFrame;
		Mat grayFrame;
		cvtColor(frame, grayFrame, COLOR_RGB2GRAY);
	
		Detector.process(grayFrame);
	
		vector<Object> objs;
        Detector.getObjects(objs);
       
            
		cout << "frame:" << nFrame << endl;
        for (int i = 0; i < objs.size(); i++) {
          //  	cout << "objeto " << objs[i].second << ":";
            	Rect r = objs[i].first;
            	int iExt = objs[i].second;
            	int iInt;
            	if (!index.get(iExt,iInt))
            	{
					index.put(iExt);
					iInt = index.size();
					};
				
				Point cabeza;
				cabeza.x = r.x;
				cabeza.y = r.y;
				reg->posCabeza->insert(pair<int, Point >(iInt, cabeza));
            //	cout << "interno:" << iInt << ", "  << "externo:" << iExt << endl;
            	
            //	cout <<  "(" << r.x << "," << r.y << ")" << endl;
				
				//inserto en la base de datos
            	//dbconn.insertPickUpInformation(nFrame,0,objs[i].second,r.x,r.y,0);
            	//dibujo
            	drawRectangle(frame,r,Scalar(0,255,0));
			}
       
       
              
               	

			//inserto en la base de datos
           	//dbconn.insertPickUpInformation(nFrame,0,objs[i].second,r.x,r.y,0);
           	//dibujo
           	
		
	outputVideo << frame;
   // delete reg;
   
		imshow("people detector", frame);
		int c = waitKey( vc.isOpened() ? 30 : 0 ) & 255;
		if ( c == 'q' || c == 'Q' || c == 27)
			break;
	}
   // dbconn.writeCache();
	frame.release();
    vc.release();
    destroyAllWindows();
    

    exit(0);
    return 0;
}
