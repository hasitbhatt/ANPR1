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
string gohils1,gohils2,tp,lol;
lol="_out";
gohils1="C:\\Users\\iis\\Documents\\Visual Studio 2008\\Projects\\saurabh\\Debug\\test1\\3266cnt";
gohils2=gohils1+lol+lol;
tp=".jpg";
Mat x;
/*
try{*/
x=imread(gohils1+tp);/*
if(!x.data)
	throw 1;
}
catch(int i)
{
if(i==1)
imread(gohils1+".png");
}*/
Mat sgohil;
Mat Sgohil;
cvtColor(x,x,CV_BGR2GRAY);

//x=255-x;
// Sgohil=x.clone();
//x.convertTo(Sgohil,CV_32F);
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
/*x/=32;
x=x^4;
x*=32;
x=255-x;*/
imshow("lkl",x);
Scalar s;
s=mean(x);
morphologyEx(x,x,CV_MOP_BLACKHAT,getStructuringElement(MORPH_RECT,Size(5,5),Point(2,2)),Point(-1,-1),2);
imshow("bi",x);
//sgohil=x;
//equalizeHist(x,x);
//GaussianBlur(x,sgohil,Size(11,101),2);
sgohil=x;
//bilateralFilter(x,sgohil,7,1,3);
//blur(x,sgohil,Size(2,1));
//medianBlur(x,sgohil,3);
//imshow("blur",sgohil);

morphologyEx(sgohil,sgohil,CV_MOP_CLOSE,getStructuringElement(MORPH_RECT,Size(17,4),Point(7,1)),Point(-1,-1),3);
imshow("ntuasdf",sgohil);
//Mat bnw = sgohil > 3*s[0]/2;
Mat bnw;
threshold(sgohil,bnw,0,255,THRESH_BINARY | THRESH_OTSU);
//cout<<s[0];
morphologyEx(bnw,bnw,CV_MOP_OPEN,getStructuringElement(MORPH_RECT,Size(5,25),Point(1,1)),Point(-1,-1),1);
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
imshow("Mr. Saurabh",x);
//imshow("Mr. Saurabhhhhhh",Sgohil);
imshow("Black & White",bnw);
waitKey(0);
//}
return 0;
}
