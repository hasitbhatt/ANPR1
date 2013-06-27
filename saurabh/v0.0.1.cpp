// saurabh.cpp : Defines the entry point for the console application.
//

#include<opencv/cv.h>
#include<opencv/highgui.h>
using namespace std;
using namespace cv;

int qweamain(int argc, char* argv[])
{
Scalar t;
string gohils1,gohils2,tp,lol;
//lol="_out_";
gohils1=argv[1];
//gohils1="C:\\Users\\iis\\Documents\\Visual Studio 2008\\Projects\\saurabh\\Debug\\test1\\20";
//tp=".png";
//gohils2=gohils1+lol;

Mat x=imread(gohils1+tp);
Mat y,z;

cvtColor(x,x,CV_BGR2GRAY);
equalizeHist(x,x);
//dilate(x,y,getStructuringElement(MORPH_RECT,Size(5,5),Point(2,2)),Point(-1,-1),5);
morphologyEx(x,y,CV_MOP_CLOSE,getStructuringElement(MORPH_RECT,Size(5,7),Point(2,2)),Point(-1,-1),2);
//imshow("lol",y);
z=y-x;
//morphologyEx(z,z,CV_MOP_BLACKHAT,getStructuringElement(MORPH_RECT,Size(5,5),Point(2,2)),Point(-1,-1),2);
//imshow(":P",z);
//z^=4;
//t=mean(z);
Mat bw;
threshold(z,bw,0,255,THRESH_BINARY | THRESH_OTSU);
morphologyEx(bw,bw,CV_MOP_CLOSE,getStructuringElement(MORPH_RECT,Size(16,4),Point(1,1)),Point(-1,-1),1);
//morphologyEx(bw,bw,CV_MOP_OPEN,getStructuringElement(MORPH_RECT,Size(4,12),Point(1,1)),Point(-1,-1),1);
//imshow(":PpP",z);

//z.convertTo(z,CV_32F);
//z= (z>3*t[0]/2);
//imshow(":PP",bw);
//int a,b;
//bw.at(10,10);
//cout<<a<<"  "<<b;
//imwrite(gohils2+tp,z);
imwrite("testout\\"+gohils1,bw);
waitKey();
return 0;
}