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
	if (controller.getScreen() == 0 && controller.getCurrentView() == menu)
	{
		display();
	}
	else if (controller.getScreen() == 6 && controller.getCurrentView() == menu)
	{
		controller.restoreIMG();
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 7 && controller.getCurrentView() == menu)
	{
		controller.saveIMG();
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 8 && controller.getCurrentView() == menu)
	{
		controller.printIMG("Your image");
		controller.setScreen(0);
	}
}

/**
 * Displays the view and set current view to Menu
 */
void ViewMenu::display() const
{
	system("CLS");
	ViewTitle::display();
	printY("\t1 - Filters");
	printY("\t2 - Derivation");
	printY("\t3 - Operations of mathematical morphology");
	printY("\t4 - Contour Detection");
	printY("\t5 - Segmentations of images");
	printBB("\t6 - Restore your image");
	printBB("\t7 - Save current image");
	printBB("\t8 - Display your image");
	printRB("\t9 - Exit");
	std::cout << std::endl;
	controller.setCurrentView(menu);
	int res;
	std::cin.clear();
	std::cin >> res;
	
	controller.setScreen(res);
}

