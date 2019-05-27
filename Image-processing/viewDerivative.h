#pragma once
#include "viewTitle.h"
#include "controller.h"
#include "animations.h"

class ViewDerivative : public ViewTitle
{
private:
	// Controller of the application
	Controller& controller;
public:
	ViewDerivative(Controller& _controller);
	/**
	* Notification function of the view
	*/
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display() const;
};

