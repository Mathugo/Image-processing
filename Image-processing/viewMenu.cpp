#include "viewMenu.h"


/**
* Constructor
* @param _controlller: controller of the application
*/
ViewMenu::ViewMenu(Controller& _controller)
	: ViewTitle("Menu"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notify the observer
 */
void ViewMenu::notify()
{
	if (controller.getScreen() == 0)
		display();
	else if (controller.getScreen() == 5)
		displayIMG();
}

/**
 * Displays the view
 */
void ViewMenu::display() const
{
	system("CLS");
	ViewTitle::display();
	printY("\t1 - Filter");
	printY("\t2 - Derivation");
	printY("\t2 - Operations of mathematical morphology");
	printY("\t3 - Contour Detection");
	printY("\t4 - Segmentations of images");
	printBB("\t5 - Display your image");
	printRB("\t9 - Exit");
	std::cout << std::endl;

	int res;
	std::cin.clear();
	std::cin >> res;
	controller.setScreen(res);
}

void ViewMenu::displayIMG() const
{
	controller.printIMG("Your image");
	controller.setScreen(0);
}