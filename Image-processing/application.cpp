#include "application.h"



Application::Application() : controller(), viewWelcome(controller), viewMenu(controller), viewFilters(controller), viewDerivation(controller), viewMorphology(controller), viewContour(controller), viewSegmentations(controller)
{
}

void Application::run()
{
	controller.notify();
}