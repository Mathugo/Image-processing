#pragma once
#include "viewTitle.h"
#include "controller.h"
#include "animations.h"
#include "viewBottom.h"

class ViewFilters : public ViewTitle, public ViewBottom
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

