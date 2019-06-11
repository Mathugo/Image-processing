#pragma once
#include "animations.h"
#include "controller.h"

class ViewBottom 
{
private:

	Controller& controller;
public:
	/**
	* Constructor
	* @param _controlller: controller of the application
	*/
	ViewBottom(Controller& _controller);
	
	/**
	 * Displays the view
	 */
	virtual void display() const;
};

