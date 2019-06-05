#include "morphology.h"



Morphology::Morphology()
{
}

void Morphology::dilatation(cv::Mat& image)
{

}
void Morphology::enter(int& erosion_size)
{
	int level;
	std::cin.clear();
	std::cin >> level;

	if (1 <= level && level <= 3)
	{
		if (level == 1)
			erosion_size = 25;
		else if (level == 2)
			erosion_size = 50;
		else if (level == 3)
			erosion_size = 75;
	}
	else
	{
		enter(erosion_size);
	}
}

void Morphology::erosion(cv::Mat& image)
{
	cv::Mat erosion_dst, dilation_dst;
	
	int erosion_type;
	int erosion_size = 0;
	int const max_elem = 2;
	int const max_kernel_size = 21;
	int erosion_elem = 0;

	// Element:\n 0: Rect \n 1: Cross \n 2: Ellipse"
	printY("Erosion element : "+std::to_string(erosion_elem));
	printY("Erosion size : " + std::to_string(erosion_size));
	printY("\nPlease enter the level of erosion you want");
	printY("1 : LOW\t2 : MEDIUM\t3 : HIGH");

	enter(erosion_size);
	
	if (erosion_elem == 0) { erosion_type = cv::MORPH_RECT; }
	else if (erosion_elem == 1) { erosion_type = cv::MORPH_CROSS; }
	else if (erosion_elem == 2) { erosion_type = cv::MORPH_ELLIPSE; }

	cv::Mat element = cv::getStructuringElement(erosion_type, // KERNEL 
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));

	/// Apply the erosion operation
	erode(image, erosion_dst, element);

	image = erosion_dst;
	
}
