#pragma once
#include "viewTitle.h"
#include "controller.h"
#include "animations.h"
#include "viewBottom.h"

class ViewContour : public ViewTitle, public ViewBottom
{
private:

	Controller& controller;
public:
	/**
* Constructor
* @param _controlller: controller of the application
*/
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

