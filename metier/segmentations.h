#pragma once
#include "..\Image-processing\animations.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class Segmentations
{
private:
	int threshold_value = 0;
	int threshold_type = 3;
	int const max_BINARY_value = 255;
	cv::Mat dst;
public:
	Segmentations();
	void thresholding(cv::Mat& image);
	void enter();
	void growth();
};

