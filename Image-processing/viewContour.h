#pragma once
#include "viewTitle.h"
#include "controller.h"
#include "animations.h"

class ViewContour : public ViewTitle
{
private:
	/**
* Constructor
* @param _controlller: controller of the application
*/
	Controller& controller;
public:
	ViewContour(Controller& _controller);

	/**
	* Notification function of the view
	*/
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display() const;
};

