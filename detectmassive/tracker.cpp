#include "tracker.h"

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect/detection_based_tracker.hpp>



using namespace cv;
using namespace std;

typedef std::pair<cv::Rect, int> Object;

CascadeDetectorAdapter::CascadeDetectorAdapter(cv::Ptr<cv::CascadeClassifier> detector,Size minS,Size maxS):
        IDetector(),
        Detector(detector)
{
    CV_Assert(detector);
	minSize=minS;
	maxSize=maxS;
}

void CascadeDetectorAdapter::detect(const cv::Mat &Image, std::vector<cv::Rect> &objects)
{
    // Detector->detectMultiScale(Image, objects, scaleFactor, minNeighbours, 0, minObjSize, maxObjSize);
	Detector->detectMultiScale(Image, objects, scaleFactor, 20, 0,  minSize, maxSize);
   }


DetectionBasedTracker getDetectionBasedTracker(Size minS, Size maxS, int minTimeDetection, string cascadeClassifierFile)
{
	Ptr<CascadeClassifier> cascade = makePtr<CascadeClassifier>(cascadeClassifierFile);
	Ptr<DetectionBasedTracker::IDetector> MainDetector = makePtr<CascadeDetectorAdapter>(cascade,minS,maxS);
	cascade = makePtr<CascadeClassifier>(cascadeClassifierFile);
	Ptr<DetectionBasedTracker::IDetector> TrackingDetector = makePtr<CascadeDetectorAdapter>(cascade,minS,maxS);
	DetectionBasedTracker::Parameters params;
	params.minDetectionPeriod = minTimeDetection;
	DetectionBasedTracker Detector(MainDetector, TrackingDetector, params);
	
	return Detector;
	};

