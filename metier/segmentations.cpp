#include "segmentations.h"



Segmentations::Segmentations()
{
}
void Segmentations::enter()
{
	int enter;
	
	system("cls");
	printY("\nPlease enter the type you want");
	printY("0: Binary");
	printY("1: Binary Inverted");
	printY("2: Truncate");
	printY("3: To Zero");
	printY("4: To Zero Inverted\n");

	std::cin.clear();
	std::cin >> enter;

	if (enter >= 0 && enter <= 4)
	{
		threshold_type = enter;
	}
	else
	{
		printRB("Bad value entered, default is 3");
	}
	printY("\nPlease enter a thresholding value between 0 and 255");

	std::cin.clear();
	std::cin >> enter;

	if (enter >= 0 && enter <= 255)
	{
		threshold_value = enter;
	}
	else
	{
		printRB("Bad value entered, default is 100");
		threshold_value = 100;
	}


}
void Segmentations::thresholding(cv::Mat& image)
{
	cv::Mat src_gray;
	/// Convert the image to Gray
	cvtColor(image, src_gray, cv::COLOR_BGR2GRAY);
	enter();
	threshold(src_gray, dst, threshold_value, max_BINARY_value, threshold_type);
	image = dst;
}
void Segmentations::growth()
{

}