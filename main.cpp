#include <iostream>
#include <ctime>
#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
using namespace std;
using namespace cv;
Scalar scalars[21] = {Scalar(128,0,0),Scalar(170,110,40),Scalar(0,128,128),Scalar(128,128,0),Scalar(0,0,128),
                      Scalar(0,0,0),Scalar(230,25,75),Scalar(245,130,48),Scalar(255,255,25),Scalar(210,245,60),Scalar(60,180,75),Scalar(70,240,240),Scalar(0,130,200),Scalar(145,30,180),
                      Scalar(240,50,230),Scalar(128,128,128),Scalar(250,190,190),Scalar(255,215,180),Scalar(255,255,200),Scalar(170,255,195),Scalar(230,190,255)};

int main() {
    std::cout << "Hello, World!" << std::endl;

    srand((unsigned)time(0));
    int row =100,col=100;
    Mat image(row,col,CV_8UC3, Scalar(255,255,255));
    int numFrames = 1800;//roughly a couple of minutes
    string windowName = "map Window"; //Name of the window
    namedWindow(windowName); // Create a window
    VideoWriter video("out.avi",CV_FOURCC('M','J','P','G'),10,Size(row,col));
    while(numFrames--)//suppose the inputMap will update automatically
    {
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++){

                int index = (rand()%21)+1;
                Scalar sca = scalars[index%21];
                Point pt1 = Point(i,j);
                Point pt2 = Point(i+1,j+1);
                rectangle(image,pt1,pt2,sca);
            }
        }
        imshow(windowName, image);
        video.write(image);// Show our image inside the created window.
        char key = (char)waitKey(25);
        if(key == 27) break; // press ESC on keyboard to exit
    }
    video.release();
    destroyWindow(windowName);
}
