#include "viewWelcome.h"


/**
* Constructor
* @param _controlller: controller of the application
*/
ViewWelcome::ViewWelcome(Controller& _controller): ViewTitle("Image Loading"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notify the observer
 */
void ViewWelcome::notify()
{
	if (controller.getScreen() == -1)
		display();
}

/**
 * Displays the view
 */
void ViewWelcome::display() const
{

	system("CLS");
	ViewTitle::display();
	printY("\t\t\t|--------------------------------------------------|");
	printY("\t\t\t| Welcome to a simple Image-processing using opencv|");
	printY("\t\t\t|--------------------------------------------------|\n\n");

	std::cout << KYEL << "You must choose a file to read : " << RST;

	std::string filename;
	std::cin >> filename;
	controller.readIMG(filename);
}