#include <stdio.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <vector>
#include <queue>
#include <fstream>
#include <stdio.h>


int main(int argc, char** argv)
{
    cv::Mat img;
    cv::HOGDescriptor hog;
    //auto tmp = cv::HOGDescriptor::getDefaultPeopleDetector
    hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
    printf("HI \n");
    return 0;
}
