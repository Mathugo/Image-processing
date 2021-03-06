#include "viewDerivative.h"



/**
* Constructor
* @param _controlller: controller of the application
*/
ViewDerivative::ViewDerivative(Controller& _controller) : controller(_controller), ViewTitle("Derivative"), ViewBottom(_controller)
{
	controller.addObserver(this);
}


/**
* Notify the observer
*/
void ViewDerivative::notify()
{
	if (controller.getScreen() == 2 && controller.getCurrentView() == menu || controller.getScreen() == 0 && controller.getCurrentView() == derivation)
	{
		display();
	}
	else if (controller.getScreen() == 1 && controller.getCurrentView() == derivation)
	{
		controller.Grad();
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 2 && controller.getCurrentView() == derivation)
	{
		controller.setCurrentView(menu);
		controller.setScreen(0);
	}
}
/**
	 * Displays the view and set current view to Filters
	 */
void ViewDerivative::display() const
{
	system("CLS");
	ViewTitle::display();
	printY("\t1 - Calcul of the gradient");
	printY("\t2 - Return to menu");
	controller.setCurrentView(derivation);
	ViewBottom::display();
	controller.insert();
}




