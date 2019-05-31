#include "viewMorphology.h"
/**
* Constructor
* @param _controlller: controller of the application
*/
ViewMorphology::ViewMorphology(Controller& _controller) : controller(_controller), ViewTitle("Morphology"), ViewBottom(_controller)
{
	controller.addObserver(this);
}



/**
* Notify the observer
*/
void ViewMorphology::notify()
{
	if (controller.getScreen() == 3 && controller.getCurrentView() == menu || controller.getScreen() == 0 && controller.getCurrentView() == morphology)
	{
		display();
	}
	else if (controller.getScreen() == 1 && controller.getCurrentView() == morphology)
	{
		controller.Erosion();
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 2 && controller.getCurrentView() == morphology)
	{
		controller.Dilatation();
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 3 && controller.getCurrentView() == morphology)
	{
		controller.setCurrentView(menu);
		controller.setScreen(0);
	}
}
/**
 * Displays the view and set current view to Filters
*/
void ViewMorphology::display() const
{
	system("CLS");
	ViewTitle::display();
	printY("\t1 - Dilatation");
	printY("\t2 - Erosion");
	printY("\t3 - Return to menu");
	controller.setCurrentView(morphology);
	ViewBottom::display();
	controller.insert();
}