#pragma once
#include <string.h>
#include "..\Image-processing\animations.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class Filters
{
private:
	int MAX_KERNEL_LENGTH = 31;	 
	cv::Mat dst;

public:
	Filters();
	cv::Mat GaussianFilter(cv::Mat image);
	cv::Mat MedianFilter(cv::Mat image);
};

