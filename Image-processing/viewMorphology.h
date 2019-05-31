#pragma once
#include"viewTitle.h"
#include "controller.h"
#include "viewBottom.h"

class ViewMorphology : public ViewTitle, public ViewBottom
{
private:
	Controller& controller;
public:
	ViewMorphology(Controller& _controller);
	/**
	* Notification function of the view
	*/
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display() const;
};

