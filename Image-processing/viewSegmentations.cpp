#include "viewSegmentations.h"


/**
* Constructor
* @param _controlller: controller of the application
*/
ViewSegmentations::ViewSegmentations(Controller& _controller) : controller(_controller), ViewTitle("Segmentations of Image"), ViewBottom(_controller)
{
	controller.addObserver(this);
}



/**
 * Notify the observer
 */
void ViewSegmentations::notify()
{
	if (controller.getScreen() == 5 && controller.getCurrentView() == menu || controller.getScreen() == 0 && controller.getCurrentView() == seg)
	{
		display();
	}
	else if (controller.getScreen() == 1 && controller.getCurrentView() == seg)
	{
		controller.Thresholding();
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 2 && controller.getCurrentView() == seg)
	{
		controller.Growth();
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 3 && controller.getCurrentView() == seg)
	{
		controller.setCurrentView(menu);
		controller.setScreen(0);
	}
}

/**
* Displays the view and set current view to Filters
*/
void ViewSegmentations::display() const
{
	system("CLS");
	ViewTitle::display();
	printY("\t1 - Thresholding operations");
	printY("\t2 - Regional growth segmentation");
	printY("\t3 - Return to menu");

	controller.setCurrentView(seg);

	ViewBottom::display();
	controller.insert();
}