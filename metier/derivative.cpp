#include "derivative.h"



Derivative::Derivative()
{
}
void Derivative::grad(cv::Mat& image)
{
	
	printY("Please wait while the gradients of your image are being applied");
	printY("This might take a while depending on the size of your image");
	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y;
	cv::Mat src_gray;

	cv::cvtColor(image, src_gray, cv::COLOR_BGR2GRAY); // convert to grayscale to see the gradients
	
	image = src_gray;

	/// Gradient X
	cv::Sobel(image, grad_x, ddepth, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT);
	/// Gradient Y
	cv::Sobel(image, grad_y, ddepth, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT);

	convertScaleAbs(grad_x, abs_grad_x); //We convert our partial results back to CV_8U
	convertScaleAbs(grad_y, abs_grad_y);

	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst); // We add both gradients
		
	image = dst;
}