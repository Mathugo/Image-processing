#pragma once
#include "controller.h"
#include "animations.h"
#include "viewTitle.h"
#include "viewBottom.h"

class ViewSegmentations : public ViewTitle, public ViewBottom
{
private:
	// Controller of the application
	Controller& controller;
public:
	ViewSegmentations(Controller& _controller);
	/**
	* Notification function of the view
	*/
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display() const;
};



