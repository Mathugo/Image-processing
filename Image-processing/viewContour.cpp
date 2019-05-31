#include "viewContour.h"


/**
* Constructor
* @param _controlller: controller of the application
*/
ViewContour::ViewContour(Controller& _controller) : controller(_controller), ViewTitle("Contour detection"), ViewBottom(_controller)
{
	controller.addObserver(this);
}
/**
* Notify the observer
*/
void ViewContour::notify()
{
	if (controller.getScreen() == 4 && controller.getCurrentView() == menu || controller.getScreen() == 0 && controller.getCurrentView() == contour)
	{
		display();
	}
	else if (controller.getScreen() == 1 && controller.getCurrentView() == contour)
	{
		controller.Canny();
	}
	else if (controller.getScreen() == 2 && controller.getCurrentView() == contour)
	{
		controller.setCurrentView(menu);
		controller.setScreen(0);
	}
}

/**
 * Displays the view and set current view to Filters
*/
void ViewContour::display() const
{
	system("CLS");
	ViewTitle::display();
	printY("\t1 - Canny");
	printY("\t2 - Return to menu");
	controller.setCurrentView(contour);
	ViewBottom::display();
	controller.insert();
}