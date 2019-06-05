#pragma once
#include <string.h>
#include "..\Image-processing\animations.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#define MAX_KERNEL_LENGTH 31

class Filters
{
private:
	cv::Mat dst;

public:
	Filters();
	void GaussianFilter(cv::Mat& image);
	void MedianFilter(cv::Mat& image);
};

