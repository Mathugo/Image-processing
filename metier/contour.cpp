#include "contour.h"



Contour::Contour()
{
}

void Contour::Canny(cv::Mat& image)
{
	
	//int thresh = 100;
	//cv::RNG rng(12345);

	//cv::Mat src_gray;

	//cv::cvtColor(image, src_gray, cv::COLOR_BGR2GRAY); // convert to gray scale

	//cv::blur(src_gray, src_gray, cv::Size(3, 3));
	/*
	cv::Mat canny_output;
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;

	/// Detect edges using canny
	cv::Canny(src_gray, canny_output, thresh, thresh * 2, 3);
	/// Find contours
	findContours(canny_output, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

	/// Draw contours
	cv::Mat drawing = cv::Mat::zeros(canny_output.size(), CV_8UC3);

	for (int i = 0; i < contours.size(); i++)
	{
		cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, cv::Point());
	}
	*/

//	image = canny_output;
	//image = src_gray;

}