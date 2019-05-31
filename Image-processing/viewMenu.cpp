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
	else if (controller.getScreen() == 7 && controller.getCurrentView() == menu)
	{
		controller.printIMG("Your image");
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 8 && controller.getCurrentView() == menu)
	{
		controller.restoreIMG();
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 9 && controller.getCurrentView() == menu)
	{
		controller.saveIMG();
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 9 && controller.getCurrentView() == menu)
	{
		controller.setScreen(-1);
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

	// FAIRE BOTOM AVEC LES SETTINGS IMAGE VIEW
	printY("\t6 - Open an other image");
	printY("\t7 - Display your image");
	printG("\t8 - Restore your image");
	printG("\t9 - Save current image");
	printRB("\t10 - Exit");
	std::cout << std::endl;
	controller.setCurrentView(menu);
	int res;
	std::cin.clear();
	std::cin >> res;
	
	controller.setScreen(res);
}

