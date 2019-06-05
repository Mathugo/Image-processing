#include "morphology.h"



Morphology::Morphology(cv::Mat& _image) : image(_image)
{
}

void Morphology::dilatation()
{
	enter(dilation_size, dilation_type);

	if (dilation_elem == 0) { dilation_type = cv::MORPH_RECT; }
	else if (dilation_elem == 1) { dilation_type = cv::MORPH_CROSS; }
	else if (dilation_elem == 2) { dilation_type = cv::MORPH_ELLIPSE; }

	cv::Mat element = cv::getStructuringElement(dilation_type,
	cv::Size(2 * dilation_size + 1, 2 * dilation_size + 1),
	cv::Point(dilation_size, dilation_size));

	/// Apply the dilation operation
	printY("Please wait while dilatation is being applied");
	printY("This might take a while depending on the size of your image");

	dilate(image, dst, element);
	image = dst;
}

void Morphology::enter(int& erosion_size, int& erosion_type)
{
	int enter;

	// Element:\n 0: Rect \n 1: Cross \n 2: Ellipse"
	system("cls");

	printY("\nPlease enter the type you want");
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

	printY("\nPlease enter the level of the filter you want");
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

void Morphology::erosion()
{
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
	erode(image, dst, element);

	image = dst;
	
}
