// saurabh.cpp : Defines the entry point for the console application.
//

#include<opencv/cv.h>
#include<opencv/highgui.h>
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
//int i,j,k;
//String lol = "C:\\Users\\iis\\Desktop\\5.jpg";
string gohils1=argv[1];
//string gohils1="C:\\Users\\iis\\Desktop\\2.png";
//string gohils2="C:\\Users\\iis\\Desktop\\out\\2_out.png";
Mat x=imread(gohils1);
Mat sgohil;
cvtColor(x,x,CV_BGR2GRAY);
equalizeHist(x,x);
morphologyEx(x,x,CV_MOP_BLACKHAT,getStructuringElement(MORPH_RECT,Size(5,5),Point(2,2)),Point(-1,-1),2);
//equalizeHist(x,x);
//GaussianBlur(x,sgohil,Size(11,101),2);
medianBlur(x,sgohil,3);
//medianBlur(x,x,2);
morphologyEx(sgohil,sgohil,CV_MOP_CLOSE,getStructuringElement(MORPH_RECT,Size(15,2),Point(7,1)),Point(-1,-1),3);
Mat bnw = sgohil > 180;
erode(bnw,bnw,getStructuringElement(MORPH_RECT,Size(4,4),Point(2,2)),Point(-1,-1),2);
//morphologyEx(bnw,bnw,CV_MOP_CLOSE,getStructuringElement(MORPH_RECT,Size(10,10),Point(5,5)),Point(1,1));
//morphologyEx(x,x,CV_MOP_CLOSE,getStructuringElement(MORPH_RECT,Size(10,2),Point(1,1)),Point(1,1),2);
//morphologyEx(x,x,CV_MOP_CLOSE,getStructuringElement(MORPH_RECT,Size(10,2),Point(1,1)),Point(1,1),2);
//morphologyEx(x,x,CV_MOP_TOPHAT,getStructuringElement(MORPH_RECT,Size(3,3),Point(2,2)),Point(1,1),2);
//morphologyEx(x,x,CV_MOP_TOPHAT,getStructuringElement(MORPH_RECT,Size(3,3),Point(2,2)),Point(1,1),2);
//morphologyEx(x,x,CV_MOP_TOPHAT,getStructuringElement(MORPH_RECT,Size(3,3),Point(2,2)),Point(1,1),2);
//morphologyEx(x,x,CV_MOP_CLOSE,getStructuringElement(MORPH_RECT,Size(3,3),Point(2,2)),Point(1,1),2);
//morphologyEx(x,x,CV_MOP_TOPHAT,getStructuringElement(MORPH_RECT,Size(5,5),Point(2,2)),Point(1,1),2);
//Canny(x,x,100,1000);
/*char tmp[500];
for(i=lol.length();lol[i]!='.';i--);
for(j=0;j<i;j++)
tmp[j]=lol[j];
tmp[j++]='_';
tmp[j++]='o';
tmp[j++]='u';
tmp[j++]='t';
tmp[j++]='.';
k=j;
for(j=0;(j+i+1)<lol.length();j++)
tmp[k+j]=lol[i+1+j];
tmp[k+j]='\0';
cout << tmp;*/
imwrite("testout\\"+gohils1,bnw);
/*imshow("Mr. Saurabh",x);
imshow("Mr. Saurabhhhhhh",sgohil);
imshow("Black & White",bnw);*/
//waitKey(0);
//}
return 0;
}
