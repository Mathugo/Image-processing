#include "viewBottom.h"



ViewBottom::ViewBottom(Controller& _controller) : controller(_controller)
{
}

void ViewBottom::display() const
{
	printY("\t6 - Open an other image");
	printY("\t7 - Display your image");
	printG("\t8 - Restore your image");
	printG("\t9 - Save current image");
	printRB("\t10 - Exit");
	std::cout << std::endl;

}

