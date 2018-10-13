#include "opencv2/opencv.hpp"
#include <iostream>

int main() {
    cv::VideoCapture cap(0);
    // if something fails
    if(!cap.isOpened())
    {
        std::cout << "Something went wrong or got crashed" << std::endl;
        return 0;
    }
    // infinte for loop
    cv::Mat edges;
    cv::Mat frame;

    for(;;)
    {
        /*
         * CANNY EDGES ALGORITHM
         * https://docs.opencv.org/2.4/modules/core/doc/intro.html
         * */
        cap >> frame; // Get a new frame from camera
        if(frame.empty()) break;

        // addapting the new edges image to a gray color for
        //  a better matrix handing-> from rgb to a 0-255 gray varaition color
        cv::cvtColor(frame, edges, cv::COLOR_BGR2GRAY);

        // cv::GaussianBlur(imputarray, outputarray, kernel_size, sigmaX, sigmaY);
        cv::GaussianBlur(edges, edges, cv::Size(7,7), 1.5, 1.5);

        // cv::Canny(imputArray, outputArray, threshold1, threshold2, apertureSize, L2gradient);
        cv::Canny(edges, edges, 0, 30, 3);

        // cv::cvtColor(frame, edges, cv::COLOR_BGR2GRAY);
        cv::imshow("FRAMES!", frame);
        cv::imshow("CANNY EDGES!", edges);

        std::cout << "Were streaming" << std::endl;

        // closing the window
        if(cv::waitKey(10) == 27) break; // Capturing ESC
    }
    // the  camera will be deintialized automaticalliy in VideCaptures destrutor
    // cap.close();
    return 0;
}