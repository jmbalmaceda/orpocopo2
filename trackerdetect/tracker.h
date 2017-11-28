#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect/detection_based_tracker.hpp>


using namespace cv;
using namespace std;

typedef std::pair<cv::Rect, int> Object;

class CascadeDetectorAdapter: public DetectionBasedTracker::IDetector
{
public:
    CascadeDetectorAdapter(cv::Ptr<cv::CascadeClassifier> detector,Size minS, Size maxS, int n_intersecs);

    void detect(const cv::Mat &Image, std::vector<cv::Rect> &objects);

    virtual ~CascadeDetectorAdapter()
    {};

private:
    CascadeDetectorAdapter();
    Size minSize;
    Size maxSize;
    int n_intersecs;
    cv::Ptr<cv::CascadeClassifier> Detector;
};

DetectionBasedTracker getDetectionBasedTracker(Size minS, Size maxS, int minTimeDetection, int nIntersecs, string cascadeClassifierFile);
