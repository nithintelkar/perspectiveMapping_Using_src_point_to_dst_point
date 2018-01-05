#include <iostream>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
using namespace std;
int main()
{
	//load original image
	IplImage* src= cvLoadImage("Birds_Eye.jpg",-1);
	cvShowImage("src",src);
	IplImage* dst = cvCreateImage(cvGetSize(src),src->depth,src->nChannels);

	CvPoint2D32f srcPoint[4];
	CvPoint2D32f dstPoint[4];
	cvZero(dst);
	
	//
	//srcPoint[0].x=0; srcPoint[0].y=0;
	//srcPoint[1].x=src->width - 1; srcPoint[1].y=0;
	//srcPoint[2].x=0; srcPoint[2].y=src->height - 1;
	//srcPoint[3].x=src->width - 1; srcPoint[3].y=src->height - 1;
	
	srcPoint[0].x=0; srcPoint[0].y=0;
	srcPoint[1].x=640; srcPoint[1].y=0;
	srcPoint[2].x=0; srcPoint[2].y=180;
	srcPoint[3].x=640; srcPoint[3].y=180;
	
	dstPoint[0].x=262; dstPoint[0].y=0;
	dstPoint[1].x=756; dstPoint[1].y=0;
	dstPoint[2].x=462; dstPoint[2].y=865;
	dstPoint[3].x=543; dstPoint[3].y=865;
	
	CvMat *h=cvCreateMat( 3, 3, CV_64FC1 );
	cvGetPerspectiveTransform(srcPoint,dstPoint,h);
	cvWarpPerspective(src,dst,h,CV_INTER_LINEAR | CV_WARP_INVERSE_MAP | CV_WARP_FILL_OUTLIERS,cvScalarAll(0));
	cvNamedWindow("dst",-1);
	cvShowImage("dst",dst);
	cvSaveImage("nit.jpg",dst);
	cvWaitKey();
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	cvDestroyWindow( "src" );
    cvDestroyWindow( "dst" );
	return 0;


}