#pragma once
#include "controller.h"
#include "viewMenu.h"

class Application  
{
private:
	Controller controller;
	ViewMenu viewMenu;
	
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

