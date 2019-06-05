#pragma once
#include "..\Image-processing\animations.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class Contour
{
public:
	Contour();
	void Canny(cv::Mat& image);
};

