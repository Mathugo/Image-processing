#pragma once
#include "..\Image-processing\animations.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class Derivative
{
private:
	cv::Mat dst;
	int scale = 1; // default values
	int delta = 0;
	int ddepth = CV_16S; //  The depth of the output image. We set it to CV_16S to avoid overflow.
public:
	Derivative();
	void grad(cv::Mat& image);
};

