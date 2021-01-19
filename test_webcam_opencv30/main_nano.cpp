
#include "opencv2/opencv.hpp"
#include "mylib.h"


using namespace cv;


std::string gstreamer_pipeline (int capture_width, int capture_height, int display_width, int display_height, int framerate, int flip_method) {
    return "nvarguscamerasrc ! video/x-raw(memory:NVMM), width=(int)" + std::to_string(capture_width) + ", height=(int)" +
           std::to_string(capture_height) + ", format=(string)NV12, framerate=(fraction)" + std::to_string(framerate) +
           "/1 ! nvvidconv flip-method=" + std::to_string(flip_method) + " ! video/x-raw, width=(int)" + std::to_string(display_width) + ", height=(int)" +
           std::to_string(display_height) + ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
}


int main(int, char**)

{ 

 int capture_width = 1280 ;
    int capture_height = 720 ;
    int display_width = 1280 ;
    int display_height = 720 ;
    int framerate = 60 ;
    int flip_method = 0 ;

    std::string pipeline = gstreamer_pipeline(capture_width,
	capture_height,
	display_width,
	display_height,
	framerate,
	flip_method);
    std::cout << "Using pipeline: \n\t" << pipeline << "\n";

cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER);
	//VideoCapture cap(); // open the default camera
	if(!cap.isOpened())  // check if we succeeded
		return -1;
	





	while(1){
char c=(char)waitKey(25);

	    Mat frame,frame_out,frame_grayt;
	    // Capture frame-by-frame
	    cap >> frame;
	

	    // If the frame is empty, break immediately
	    if (frame.empty())
	      break;
// ----------------------------Détection de contour----------------------------------------------
if(c=='d') {
while(1){
  cap >> frame;
 if (frame.empty())
	      break;
frame = detection_contour(frame);
imshow("Detection de contour", frame);
char c=(char)waitKey(25);
if(c==8) break;
}
}
// ----------------------------------Rouge en Jaune----------------------------------------------
if(c=='j'){ 
while(1){
  cap >> frame;
 if (frame.empty())
	      break;
frame = seuillage_rouge_jaune (frame);
imshow("Seuillage couleur", frame);
char c=(char)waitKey(25);
if(c==8) break;
}
}

// ----------------------------------Vert en Cyan----------------------------------------------
	if(c=='c'){ 
			while(1){
 		 	cap >> frame;
 			if (frame.empty())
	     	 	break;
			frame = seuillage_vert_cyan(frame);
			imshow("Cyan", frame);
			char c=(char)waitKey(25);
			if(c==8) break;
			}
		}
// ----------------------------------Bleu en Violet----------------------------------------------
	if(c=='v'){ 
			while(1){
 		 	cap >> frame;
 			if (frame.empty())
	     	 	break;
			frame = seuillage_bleu_violet(frame);
			imshow("Violet", frame);
			char c=(char)waitKey(25);
			if(c==8) break;
			}
		}
// ----------------------------------Noir et blanc----------------------------------------------

if(c=='n'){ 
while(1){
  cap >> frame;
 if (frame.empty())
	      break;
frame = noir_blanc(frame);
imshow("Noir et blanc", frame);
char c=(char)waitKey(25);
if(c==8) break;
}
}

if(c=='g'){ 
while(1){
Mat out;
  cap >> frame;
 if (frame.empty())
	      break;
out = gaussien( frame,5,5);
imshow("Gaussien", out);
char c=(char)waitKey(25);
if(c==8) break;
}
}



else{ imshow("Frame", frame);}

	    // Display the resulting frame

	    // Press  ESC on keyboard to exit
	    
	    if(c==27)
	      break;
	  }

	  // When everything done, release the video capture object
	  cap.release();

	  // Closes all the frames
	  destroyAllWindows();

	  return 0;
}
