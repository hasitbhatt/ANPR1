// saurabh.cpp : Defines the entry point for the console application.
//

#include<opencv/cv.h>
#include<opencv/highgui.h>
using namespace std;
using namespace cv;

int qewmain(int argc, char* argv[])
{
//int i,j,k;
//String lol = "C:\\Users\\iis\\Desktop\\5.jpg";
string gohils1=argv[1];
//string gohils2="C:\\Users\\iis\\Desktop\\out\\6_out.png";

Mat x=imread(gohils1);

Mat sgohil;
Mat Sgohil;
cvtColor(x,x,CV_BGR2GRAY);

// Sgohil=x.clone();
x.convertTo(Sgohil,CV_32F);
/*Sgohil= (Sgohil+1);
cv::log(Sgohil,Sgohil);
Sgohil*=0.109;
double min,max;
Point p1,p2;
minMaxLoc(Sgohil,&min,&max,&p1,&p2);
   cout<<min<<" "<<max;
Sgohil.convertTo(x,CV_8U,255.0/(max-min));
*/
equalizeHist(x,x);
//imshow("lkl",x);
Scalar s;
s=mean(x);
morphologyEx(x,x,CV_MOP_BLACKHAT,getStructuringElement(MORPH_RECT,Size(5,5),Point(2,2)),Point(-1,-1),2);
//imshow("bi",x);
//imwrite(gohils2,x);
//equalizeHist(x,x);
//GaussianBlur(x,sgohil,Size(11,101),2);
//sgohil=x;
//bilateralFilter(x,sgohil,7,1,3);
blur(x,sgohil,Size(2,1));
//medianBlur(x,sgohil,3);
//imshow("blur",sgohil);

morphologyEx(sgohil,sgohil,CV_MOP_CLOSE,getStructuringElement(MORPH_RECT,Size(17,2),Point(7,1)),Point(-1,-1),3);
//imshow("ntuasdf",sgohil);
Mat bnw = sgohil > 3.0/2*s[0];
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
// imwrite(gohils2,bnw);
//imshow("Mr. Saurabh",x);
//imshow("Mr. Saurabhhhhhh",Sgohil);
//imshow("Black & White",bnw);
imwrite("gohils1\\"+gohils1,bnw);
waitKey(0);
//}
return 0;
}
