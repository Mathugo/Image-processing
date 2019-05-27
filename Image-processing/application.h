#pragma once
#include "controller.h"
#include "viewMenu.h"
#include "viewWelcome.h"
#include "viewFilters.h"
#include "viewDerivative.h"
#include "viewMorphology.h"

class Application  
{
private:
	Controller controller;
	ViewMenu viewMenu;
	ViewWelcome viewWelcome;
	ViewFilters viewFilters;
	ViewDerivative viewDerivation;
	ViewMorphology viewMorphology;

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

