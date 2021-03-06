#pragma once
#include "viewTitle.h"
#include "controller.h"
#include "animations.h"
#include "viewBottom.h"

class ViewDerivative : public ViewTitle, public ViewBottom
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

