#pragma once
#include "controller.h"
#include "viewMenu.h"
#include "viewWelcome.h"
#include "viewFilters.h"
#include "viewDerivative.h"
#include "viewMorphology.h"
#include "viewContour.h"
#include "viewSegmentations.h"

class Application  
{
private:
	Controller controller;
	ViewMenu viewMenu;
	ViewWelcome viewWelcome;
	ViewFilters viewFilters;
	ViewDerivative viewDerivation;
	ViewMorphology viewMorphology;
	ViewContour viewContour;
	ViewSegmentations viewSegmentations;

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

