#pragma once
#include"viewTitle.h"
#include "controller.h"

class ViewMorphology : public ViewTitle
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

