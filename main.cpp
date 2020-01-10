#include <iostream>
#include <ctime>
#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <string>
#include <fstream>
using namespace std;
using namespace cv;
Scalar scalars[21] = {Scalar(128,0,0),Scalar(170,110,40),Scalar(0,128,128),Scalar(128,128,0),Scalar(0,0,128),
                      Scalar(0,0,0),Scalar(230,25,75),Scalar(245,130,48),Scalar(255,255,25),Scalar(210,245,60),Scalar(60,180,75),Scalar(70,240,240),Scalar(0,130,200),Scalar(145,30,180),
                      Scalar(240,50,230),Scalar(128,128,128),Scalar(250,190,190),Scalar(255,215,180),Scalar(255,255,200),Scalar(170,255,195),Scalar(230,190,255)};

int main() {
    int FLOATPRICITION = 100;
    int SIZEUNIT = 25;




    int row =1000,col=1000;
    col = max(row,col);
    Mat image(row,col,CV_8UC3, Scalar(255,255,255));
    string windowName = "map Window"; //Name of the window
    namedWindow(windowName); // Create a window
    VideoWriter video("out.avi",CV_FOURCC('M','J','P','G'),10,Size(row,col));

    fstream infile;
    string word, filename;

    // filename of the file
    filename = "out.txt";

    // opening file
    infile.open(filename.c_str());

    // extracting words from the file
    while (infile >> word)
    {
        if(word.compare("EOM")==0){
            imshow(windowName, image);

            video.write(image);
            continue;
        }
        stringstream stringstream1(word);
        int x = 0, y=0;
        stringstream1 >> x;
        infile>>word;
        stringstream stringstream2(word);
        stringstream2>>y;
        infile>>word;
        // displaying content
        cout << x<<" "<<y<<" "<<word << endl;
        Point pt1 = Point(x,y);
        Point pt2 = Point(x+SIZEUNIT,y+SIZEUNIT);
        if(word.at(0)=='a' || word.at(0)=='A'){
            Scalar sca = scalars[0];

            rectangle(image,pt1,pt2,sca,-1);
        } else{
            Scalar sca = scalars[1];
            circle(image,pt1,SIZEUNIT,sca,-1);
        }
    }
    video.release();
    destroyWindow(windowName);

/*
    int row =1000,col=1000;
    col = max(row,col);
    Mat image(row,col,CV_8UC3, Scalar(255,255,255));
    int numFrames = 100;//roughly a couple of minutes
    string windowName = "map Window"; //Name of the window
    namedWindow(windowName); // Create a window
    VideoWriter video("out.avi",CV_FOURCC('M','J','P','G'),10,Size(row,col));
    while(numFrames--)//suppose the inputMap will update automatically
    {
        for(int i=0;i<row;i+=100) {
            for(int j=0;j<col;j+=100){
                int index = (rand()%21)+1;
                Scalar sca = scalars[index%21];
                Point pt1 = Point(i,j);
                Point pt2 = Point(i+100,j+100);
                rectangle(image,pt1,pt2,sca,-1);
            }
        }
        imshow(windowName, image);

        video.write(image);// Show our image inside the created window.
        cout<<"sleep"<<endl;

cout<<"wake up"<<endl;
//        char key = (char)waitKey(250000);
//        if(key == 27) break; // press ESC on keyboard to exit
    }
    video.release();
    destroyWindow(windowName);*/
}
