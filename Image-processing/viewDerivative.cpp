#include "viewDerivative.h"



/**
* Constructor
* @param _controlller: controller of the application
*/
ViewDerivative::ViewDerivative(Controller& _controller) : controller(_controller), ViewTitle("Derivative")
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
	printBB("\t2 - Menu");
	controller.setCurrentView(derivation);

	int res;
	std::cin.clear();
	std::cin >> res;
	
	controller.setScreen(res);
}




