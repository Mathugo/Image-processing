#pragma once
#include "controller.h"
#include "viewMenu.h"
#include "viewWelcome.h"

class Application  
{
private:
	Controller controller;
	ViewMenu viewMenu;
	ViewWelcome viewWelcome;
	
public:
	/**
	 * Constructor
	 */
	Application();

	/**
	 * Runs the application
	 */
	void run();
};

