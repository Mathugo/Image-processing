#pragma once
#include "controller.h"
#include <iostream>
#include "viewTitle.h"

class ViewMenu : public ViewTitle
{
private:
	// Controller of the application
	Controller& controller;
public:
	ViewMenu(Controller& controller);

	/**
		 * Notification function of the view
		 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display();

};