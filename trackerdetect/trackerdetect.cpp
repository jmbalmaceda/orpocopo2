#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

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
	INI::Parser p = readIni("conf.ini");
   
	int minH=stoi(p.top()["minH"]);
	int minW=stoi(p.top()["minW"]);
	int maxH=stoi(p.top()["maxH"]);
	int maxW=stoi(p.top()["maxW"]);
	int minTimeDetect=stoi(p.top()["minTimeDetect"]);
	string cascadeClassifierFile=p.top()["cascadeClassifierFile"];
	string cascadeClassifierFile2=p.top()["cascadeClassifierFile2"];
	string cascadeClassifierFileMano=p.top()["cascadeClassifierFileMano"];
	
	string cascadeClassifierFileBRec=p.top()["cascadeClassifierFileBRec"];
	string cascadeClassifierFileBVer=p.top()["cascadeClassifierFileBVer"];
	string cascadeClassifierFileBHor=p.top()["cascadeClassifierFileBHor"];
	
	CascadeClassifier detectorBrazoVertical;
	detectorBrazoVertical.load(cascadeClassifierFileBVer);
		
	CascadeClassifier detectorBrazoRectangulo;
	detectorBrazoRectangulo.load(cascadeClassifierFileBRec);
	
	CascadeClassifier detectorBrazoHorizontal;
	detectorBrazoHorizontal.load(cascadeClassifierFileBHor);

	ConnectionData data;
	data.user = p.top()["user"];
	data.password = p.top()["password"];
	data.server = p.top()["server"];
	data.database = p.top()["database"];
	
	int ROIline=stoi(p.top()["ROIline"]);
	string slinea1Gondola=p.top()["linea1"];
	string slinea2Gondola=p.top()["linea2"];
	string slinea3Gondola=p.top()["linea3"];
	
	//calculo la ROI de la gondola para el frame entero
	Line Linea1Gondola = str2line(slinea1Gondola);
	Line Linea2Gondola = str2line(slinea2Gondola);
	Line Linea3Gondola = str2line(slinea3Gondola);
	
	DBConnection dbconn(data);
	
	string fileName = argv[2];
	ofstream file(fileName.c_str(), ios::out | ios::trunc);

  
	//creo traker
	Size minSize(minH,minW);
	Size maxSize(maxH,maxW);
	DetectionBasedTracker Detector = getDetectionBasedTracker(minSize,maxSize,minTimeDetect,cascadeClassifierFile);
	
	//tracker persona completa
	Size minSize2(120,120);	
	Size maxSize2(200,200);
	DetectionBasedTracker DetectorPersona = getDetectionBasedTracker(minSize2,maxSize2,0,cascadeClassifierFile2);


	Size minSizeMano(40,40);	
	Size maxSizeMano(80,80);
	DetectionBasedTracker DetectorMano = getDetectionBasedTracker(minSizeMano,maxSizeMano,0,cascadeClassifierFileMano);
	
	Size minSizeBVer(40,86);	
	Size maxSizeBVer(60,100);
	DetectionBasedTracker DetectorBVer = getDetectionBasedTracker(minSizeBVer,maxSizeBVer,0,cascadeClassifierFileBVer);
	
//	MultiTracker mtracker("MEDIANFLOW");
    namedWindow("people detector", WINDOW_NORMAL | WINDOW_KEEPRATIO);
    
    string video_filename = argv[1];

    //Read from video file
    VideoCapture vc;
    Mat frame;
    Mat frameCPrev;
    Mat frameC;
    vc.open(video_filename.c_str());
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
       
       
              
               	
		DetectorPersona.process(grayFrame);
		vector<Object> objsPersona;
        DetectorPersona.getObjects(objsPersona);
        
        
      // cout << "CAJAS AZULES:" << endl;
        for (int i = 0; i < objsPersona.size(); i++) {
  
           	Rect r = objsPersona[i].first;
           	Object objr;
			if (intersection(r,ROIline) && intersection(r,objs,objr))
			{
			//	cout << "interseccion con zona de interes" << endl;
				//tengo que recortar y aplicar detector de mano
			
				Rect roi;
				roi = ROIExtended(r,s);
				
				vector<Rect> brazosRec;
				detectorBrazoRectangulo.detectMultiScale(frame, brazosRec, 1.1, 50, 0 | 1, Size(40,40), Size(70,70));
				
				for (int m=0; m< brazosRec.size();m++)
				{
					Rect brazo = brazosRec[m];
					if (intersection(brazo,320))
					{
						drawRectangle(frame,brazo,Scalar(0,255,255));
						lastBrazo = brazo;
						if (dmpoly.movement(frameC,frameCPrev,roi))
						{
						if (brazo.x<= 217) cout << "MANO en GONDOLA 1" << endl;
						if (brazo.x > 217) cout << "MANO en GONDOLA 2" << endl;
						cout << brazo << endl;
						
						int indiceExt = objr.second;
						int indiceInt;
						index.get(indiceExt,indiceInt);
						
						Point mano;
						mano.x=brazo.x;
						mano.y=brazo.y;
						
						reg->posMano->insert(pair<int, Point >(indiceInt, mano));
						};
					};
				}
				
		
				//cout << "ROI:" << roi << endl;
				vector<Point> vecpoli = getPolygon(roi,Linea1Gondola,Linea2Gondola);
				
				drawRectangle(frame,r,Scalar(255,0,0));
				};
			//inserto en la base de datos
           	//dbconn.insertPickUpInformation(nFrame,0,objs[i].second,r.x,r.y,0);
           	//dibujo
           	
		}
    reg->writeinBD(dbconn);

   // delete reg;
   
		imshow("people detector", frame);
		int c = waitKey( vc.isOpened() ? 30 : 0 ) & 255;
		if ( c == 'q' || c == 'Q' || c == 27)
			break;
	}
    dbconn.writeCache();
	frame.release();
    vc.release();
    
    destroyAllWindows();
    
    file.close();
    exit(0);
    return 0;
}
