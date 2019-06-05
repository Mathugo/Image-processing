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
	
public:
	Morphology();
	void dilatation(cv::Mat& image);
	void erosion(cv::Mat& image);
	void enter(int& erosion_size, int& erosion_type);

};
