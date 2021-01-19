#include "opencv2/opencv.hpp"
#include "mylib.h"

using namespace cv;

Mat detection_contour(Mat image_in ){
 Mat frame_out,frame_gray;
cvtColor(image_in,frame_gray,CV_BGR2GRAY);
frame_out.create(image_in.rows,image_in.cols,CV_8UC1);
for (int i=1;i<image_in.rows;i++){
			for (int j=1;j<image_in.cols;j++){
short temp;
temp = (-1)*(short)frame_gray.at<uchar>(i,j-1)+(-1)*(short)frame_gray.at<uchar>(i-1,j)+(-1)*(char)frame_gray.at<uchar>(i,j+1)+(-1)*(short)frame_gray.at<uchar>(i+1,j)+4*(short)frame_gray.at<uchar>(i,j);

frame_out.at<uchar>(i,j)=(uchar)abs(temp);

		if(frame_out.at<uchar>(i,j)>23) frame_out.at<uchar>(i,j)=255;
		else { frame_out.at<uchar>(i,j)=0;
			}

			}
		}
return frame_out;
}

Mat seuillage_rouge_jaune ( Mat image_in){

float nr;


for (int i=1;i<image_in.rows;i++){
            for (int j=1;j<image_in.cols;j++){
                uchar r,v,b;
                b=image_in.at<Vec3b>(i,j)[0];
                v=image_in.at<Vec3b>(i,j)[1];
                r=image_in.at<Vec3b>(i,j)[2];
		
			nr=r/sqrt((r*r)+(b*b)+(v*v));  
			if(nr>0.7){
                		image_in.at<Vec3b>(i,j)[0]=0;
               			 image_in.at<Vec3b>(i,j)[1]=r;
                		image_in.at<Vec3b>(i,j)[2]=r;
         		 }
      			  else{
         		   image_in.at<Vec3b>(i,j)[0]=b;
           		 image_in.at<Vec3b>(i,j)[1]=v;
           		 image_in.at<Vec3b>(i,j)[2]=r;
       		
		}
	}
			
}
return image_in;

}

Mat seuillage_vert_cyan(cv::Mat image_in){
Mat frame_out,frame_gray;
cvtColor(image_in,frame_gray,CV_BGR2GRAY);
frame_out.create(image_in.rows,image_in.cols,CV_8UC1);
float nr;

for (int i=1;i<image_in.rows;i++){
            for (int j=1;j<image_in.cols;j++){
                uchar r,v,b;
                b=image_in.at<Vec3b>(i,j)[0];
                v=image_in.at<Vec3b>(i,j)[1];
                r=image_in.at<Vec3b>(i,j)[2];
		
			nr=v/sqrt((r*r)+(b*b)+(v*v));  
			if(nr>0.7){
                		image_in.at<Vec3b>(i,j)[0]=v;
               			 image_in.at<Vec3b>(i,j)[1]=v;
                		image_in.at<Vec3b>(i,j)[2]=0;
         		 }
      			  else{
         		   image_in.at<Vec3b>(i,j)[0]=b;
           		 image_in.at<Vec3b>(i,j)[1]=v;
           		 image_in.at<Vec3b>(i,j)[2]=r;
       		
		}
	}
			
}
return image_in;



}

Mat seuillage_bleu_violet(cv::Mat image_in){
float nr;


for (int i=1;i<image_in.rows;i++){
            for (int j=1;j<image_in.cols;j++){
                uchar r,v,b;
                b=image_in.at<Vec3b>(i,j)[0];
                v=image_in.at<Vec3b>(i,j)[1];
                r=image_in.at<Vec3b>(i,j)[2];
		
			nr=b/sqrt((r*r)+(b*b)+(v*v));  
			if(nr>0.7){
                		image_in.at<Vec3b>(i,j)[0]=b;
               			 image_in.at<Vec3b>(i,j)[1]=0;
                		image_in.at<Vec3b>(i,j)[2]=b;
         		 }
      			  else{
         		   image_in.at<Vec3b>(i,j)[0]=b;
           		 image_in.at<Vec3b>(i,j)[1]=v;
           		 image_in.at<Vec3b>(i,j)[2]=r;
       		
		}
	}
			
}
return image_in;
}

Mat gaussien(Mat image_in){
Mat frame_copy;
cvtColor(image_in,image_in,CV_BGR2GRAY);
frame_copy.create(image_in.rows,image_in.cols,CV_8UC1);
for (int i=150;i<500;i++){
            for (int j=2;j<frame_copy.cols;j++){
short temp;

				temp = (short)(1/2)*image_in.at<uchar>(i,j-1)+(short)(1/2)*image_in.at<uchar>(i,j+1);
   frame_copy.at<uchar>(i,j)=(uchar)temp;

}
}

return frame_copy;
}


Mat noir_blanc(Mat image_in){
cvtColor(image_in,image_in,CV_BGR2GRAY);
return image_in;
}
