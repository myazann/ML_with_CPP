#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//g++ opencv_deneme.cpp -o testoutput -std=c++11 `pkg-config --cflags --libs opencv4`

using namespace cv;

int main(){
    
    Mat image;

    image = imread("dog.jpg");
    
    if(!image.data ) 
    {
        std::cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }   

     
    cvtColor(image, image, COLOR_BGR2RGB);

    cv::Mat rgb[3];
    cv::split(image, rgb);
    
    std::cout << rgb[0].size() << '\n';

    return 0;   
}