#include "viewMenu.h"


/**
* Constructor
* @param _controlller: controller of the application
*/
ViewMenu::ViewMenu(Controller& _controller)
	: ViewTitle("Menu"), ViewBottom(_controller), controller(_controller)
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
	else if (controller.getScreen() == 6)
	{
		controller.setScreen(-1);
	}
	else if (controller.getScreen() == 7)
	{
		controller.printIMG("Your image");
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 8)
	{
		controller.restoreIMG();
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 9)
	{
		controller.saveIMG();
		controller.setScreen(0);
	}
}

/**
 * Displays the view and set current view to Menu
 */
void ViewMenu::display() const
{
	clear();
	ViewTitle::display();
	printY("\t1 - Filters");
	printY("\t2 - Derivation");
	printY("\t3 - Operations of mathematical morphology");
	printY("\t4 - Contour Detection");
	printY("\t5 - Segmentations of images");

	ViewBottom::display();
	controller.setCurrentView(menu);
	controller.insert();

}

