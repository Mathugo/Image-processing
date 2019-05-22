#pragma once
#include <string>
#include "observer.h"
#include <iostream>
#include "animations.h"


class ViewTitle : public Observer
{
private:
	//Title of the view
	std::string title;
public:

	/**
	 * Constructor
	 * @param _title: title of the view
	 */
	ViewTitle(const std::string& _title);

	/**
	 * Clears console
	 */
	void clear() const;

	/**
	 * Displays generic dialog
	 */
	virtual void display() const;
};

