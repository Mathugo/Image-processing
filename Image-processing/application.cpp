#include "application.h"



Application::Application() : controller(), viewWelcome(controller), viewMenu(controller), viewFilters(controller)
{
}

void Application::run()
{
	controller.notify();
}