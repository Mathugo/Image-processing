#pragma once
#include "animations.h"
#include "controller.h"
#include "viewTitle.h"

class ViewWelcome : public ViewTitle
{
private:
	// Controller of the application
	Controller& controller;
public:
	ViewWelcome(Controller& controller);

	/**
		 * Notification function of the view
		 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display() const;

};


