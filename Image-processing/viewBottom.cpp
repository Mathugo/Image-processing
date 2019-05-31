#include "viewBottom.h"



ViewBottom::ViewBottom(Controller& _controller) : controller(_controller)
{
}

void ViewBottom::display() const
{
	std::cout << std::endl << std::endl;
	printY("\t|----------Image settings---------|");
	std::cout << std::endl;
	printBB("\t6 - Open an other image");
	printBB("\t7 - Display your image");
	printG("\t8 - Restore your image");
	printG("\t9 - Save current image");
	printRB("\t10 - Exit");
	std::cout << std::endl;

}

