#pragma once
#include "..\Image-processing\animations.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class Morphology
{
private:
	cv::Mat dst;
	cv::Mat image;

	int erosion_type;
	int erosion_size = 0;
	int const max_elem = 2;
	int const max_kernel_size = 21;
	int erosion_elem = 0;

	int dilation_type;
	int dilation_elem = 0;
	int dilation_size = 0;
public:
	Morphology(cv::Mat& _image);
	void dilatation();
	void erosion();
	void enter(int& erosion_size, int& erosion_type);

};
