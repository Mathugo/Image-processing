#include "filters.h"

Filters::Filters()
{
}


cv::Mat Filters::MedianFilter(cv::Mat image)
{
	// MAX_KERNEL_LENGTH -> Number of pixels around to median, must be small
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		medianBlur(image, dst, i);
	}
	return dst;
}

cv::Mat Filters::GaussianFilter(cv::Mat image)
{
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		cv::GaussianBlur(image, dst, cv::Size(i, i), 0, 0);
	}
	return dst;
}