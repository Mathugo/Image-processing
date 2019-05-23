#include "viewFilters.h"



ViewFilters::ViewFilters(Controller& _controller) : ViewTitle("Filters"), controller(_controller)
{
	controller.addObserver(this);
}


/**
 * Notify the observer
 */
void ViewFilters::notify()
{
	if (controller.getScreen() == 1 && controller.getCurrentView() == menu || controller.getScreen() == 0 && controller.getCurrentView() == filters)
	{
		display();
	}
	else if (controller.getScreen() == 1 && controller.getCurrentView() == filters)
	{
		controller.MedianFilter();
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 2 && controller.getCurrentView() == filters)
	{
		controller.GaussianFilter();
		controller.setScreen(0);
	}
	else if (controller.getScreen() == 3 && controller.getCurrentView() == filters)
	{
		controller.setCurrentView(menu);
		controller.setScreen(0);
	}
}

/**
	 * Displays the view and set current view to Filters
	 */
void ViewFilters::display() const
{
	clear();
	ViewTitle::display();
	printY("\t1 - Median Filter");
	printY("\t2 - Gaussian Filter");
	printY("\t3 - Return to menu");

	controller.setCurrentView(filters);
	std::cout << std::endl;
	int res;
	std::cin.clear();
	std::cin >> res;
	controller.setScreen(res);
}