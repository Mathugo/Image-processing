#pragma once
#include "animations.h"
#include "controller.h"

class ViewBottom
{
private:
	Controller& controller;
public:
	ViewBottom(Controller& _controller);
	void display() const;
};

