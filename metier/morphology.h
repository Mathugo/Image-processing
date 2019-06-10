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
	int erosion_type;
	int erosion_size = 0;
	int erosion_elem = 0;

	int dilation_type;
	int dilation_elem = 0;
	int dilation_size = 0;
public:

	Morphology();
	void dilatation(cv::Mat& image);
	void erosion(cv::Mat& image);
	void enter(int& size, int& type);

};
