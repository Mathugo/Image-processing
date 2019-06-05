#include "morphology.h"



Morphology::Morphology()
{
}

void Morphology::dilatation(cv::Mat& image)
{

}

void Morphology::enter(int& erosion_size, int& erosion_type)
{
	int enter;

	// Element:\n 0: Rect \n 1: Cross \n 2: Ellipse"
	system("cls");

	printY("\nPlease enter the type of erosion you want");
	printY("0: Rect");
	printY("1: Cross");
	printY("2: Ellipse\n");

	std::cin.clear();
	std::cin >> enter;

	if (1 <= enter && enter <= 3)
	{
		if (enter == 1)
			erosion_type = 0;
		else if (enter == 2)
			erosion_type = 1;
		else if (enter == 3)
			erosion_type = 2;
	}
	else
	{
		printRB("Bad type entered, defaut is 0");
		erosion_type = 0;
	}

	system("cls");

	printY("\nPlease enter the level of erosion you want");
	printY("1 - LOW");
	printY("2 - MEDIUM");
	printY("3 - HIGH\n");

	std::cin.clear();
	std::cin >> enter;
	if (1 <= enter && enter <= 3)
	{
		if (enter == 1)
			erosion_size = 25;
		else if (enter == 2)
			erosion_size = 50;
		else if (enter == 3)
			erosion_size = 75;
	}
	else
	{
		printRB("Bad level entered, defaut is MEDIUM");
		erosion_size = 50;
	}

	system("cls");

}

void Morphology::erosion(cv::Mat& image)
{
	cv::Mat erosion_dst, dilation_dst;
	
	int erosion_type;
	int erosion_size = 0;
	int const max_elem = 2;
	int const max_kernel_size = 21;
	int erosion_elem = 0;

	enter(erosion_size, erosion_type);
	
	if (erosion_elem == 0) { erosion_type = cv::MORPH_RECT; }
	else if (erosion_elem == 1) { erosion_type = cv::MORPH_CROSS; }
	else if (erosion_elem == 2) { erosion_type = cv::MORPH_ELLIPSE; }

	cv::Mat element = cv::getStructuringElement(erosion_type, // KERNEL 
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));

	/// Apply the erosion operation
	printY("Please wait while erosion is being applied");
	printY("This might take a while depending on the size of your image");
	erode(image, erosion_dst, element);

	image = erosion_dst;
	
}
