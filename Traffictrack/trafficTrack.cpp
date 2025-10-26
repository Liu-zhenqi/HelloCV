#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
//103,85,148,179,255,255red
//65,132,127,120,255,255green


Mat img,imgGray,imgHSV,mask;
vector<vector<int>> myColors{ {103,85,148,179,255,255}, // red
								{65,132,127,120,255,255} };//green
vector<Scalar> myColorsValues{{0,0,255},
                                    {0,255,0}};
vector<string> myText{"Red",
                      "green"};
vector<Rect> getContours(Mat image) {


	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size()),Substitute(1);


	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		//cout <<"area" <<area << endl;
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			//cout << conPoly[i].size() << endl;
            if (area > 30000&&conPoly[i].size()==8)
		{
			boundRect[i] = boundingRect(conPoly[i]);
			//drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			//rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
            Substitute[0]=boundRect[i];
		}
            
	}
return Substitute;
}
void findColor(Mat img)
{
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
    vector<vector<int>> newPoints;

	for (int i = 0; i < myColors.size(); i++)
	{
		Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
		Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);
        
		imshow(to_string(i), mask);
		vector<Rect> myRect = getContours(mask);
        if(myRect[0].x !=0)
        {
            rectangle(img, myRect[0].tl(), myRect[0].br(), myColorsValues[i], 5);
            putText(img,myText[i],Point(80,200),FONT_HERSHEY_SCRIPT_COMPLEX,7.5,myColorsValues[i],5);
        
	}
}
}
int main()
{
    string path ="opencv小测试/TrafficLight.mp4";
    VideoCapture cap(path);
    VideoWriter writer("result.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 20, Size(1920,1080));
    while(true)
    {
        cap.read(img);
        findColor(img);
        imshow("Image", img);
        writer.write(img);
        waitKey(20);
        //cout<<"size"<<size(img);//1920 x 1080
        
    }
    writer.release();
    cv::destroyAllWindows();
    return 0;
}
