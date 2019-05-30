#include "filters.h"

Filters::Filters()
{
}


void Filters::MedianFilter(cv::Mat& image)
{
	printY("Please wait while the median filter is being applied on your image");
	printY("This might take a while depending on the size of your image");
	// MAX_KERNEL_LENGTH -> Number of pixels around to median, must be small
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		medianBlur(image, dst, i);
	}
	image = dst;
}

void Filters::GaussianFilter(cv::Mat& image)
{
	printY("Please wait while the gaussian filter is being applied on your image");
	printY("This might take a while depending on the size of your image");
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		cv::GaussianBlur(image, dst, cv::Size(i, i), 0, 0);
	}
	image = dst;

}