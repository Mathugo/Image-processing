#pragma once
#include "viewTitle.h"
#include "controller.h"
#include "animations.h"

class ViewFilters : public ViewTitle
{
private:
	// Controller of the application
	Controller& controller;
public:
	ViewFilters(Controller& _controller);

	/**
		 * Notification function of the view
		 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display() const;

};

