#include "contour.h"



Contour::Contour()
{
}

void Contour::Canny(cv::Mat& image)
{
	cv::Mat src_gray;
	cv::Mat dst, detected_edges;
	int cannyThreshold = 100; // intensity of the detector

	const int ratio = 3;
	const int kernel_size = 3;

	dst.create(image.size(), image.type());
	cv::cvtColor(image, src_gray, cv::COLOR_BGR2GRAY); // convert to gray to see edges

	cv::blur(src_gray, detected_edges, cv::Size(3, 3)); // Reduction of noise

	cv::Canny(detected_edges, detected_edges, cannyThreshold, cannyThreshold*ratio, kernel_size);
	dst = cv::Scalar::all(0);
	image.copyTo(dst, detected_edges);

	image = dst;
}