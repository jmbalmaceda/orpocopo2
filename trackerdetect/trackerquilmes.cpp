// Standard include files
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>

#include <string> 
#define THRESHOLD 5 //in pixels
using namespace cv;
using namespace std;
 
bool move(Rect2d r1, Rect2d r2)
{
	if (abs(r1.x-r2.x) > THRESHOLD) return true;
	if (abs(r1.y-r2.y) > THRESHOLD) return true;
	};
int main(int argc, char **argv)
{
	
	
    // Set up tracker. 
    // Instead of MIL, you can also use 
    // BOOSTING, KCF, TLD, MEDIANFLOW or GOTURN  
    Ptr<TrackerMIL> tracker = TrackerMIL::create();
 
	string video_filename = argv[1];
    // Read video
    VideoCapture video(video_filename);
     
    // Check video is open
    if(!video.isOpened())
    {
        cout << "Could not read video file" << endl;
        return 1;
    }
 
    // Read first frame. 
    Mat frame;
    video.read(frame);
 
    // Define an initial bounding box
   Rect2d bbox(287, 23, 86, 320);
 
    // Uncomment the line below if you 
    // want to choose the bounding box
   
   while (video.read(frame))
	{
		 imshow("Tracking", frame);
		int k = waitKey(0);
        if(k == 27) break;
		};
     bbox = selectROI(frame, false);
     
    // Initialize tracker with first frame and bounding box
    tracker->init(frame, bbox);
 
    while(video.read(frame))
    {
        // Update tracking results
        if (tracker->update(frame, bbox))
        { // Draw bounding box
        rectangle(frame, bbox, Scalar( 255, 0, 0 ), 2, 1 );
			};
 
       
 
        // Display result
        imshow("Tracking", frame);
        int k = waitKey(1);
        if(k == 27) break;
 
    }
 
    return 0; 
     
}
