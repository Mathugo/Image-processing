#include "application.h"



Application::Application() : controller(), viewWelcome(controller), viewMenu(controller)
{
}

void Application::run()
{
	controller.notify();
}