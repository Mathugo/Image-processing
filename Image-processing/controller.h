#pragma once
#include "subject.h"
#include <opencv2/opencv.hpp>
#include "animations.h"

class Controller : public Subject
{
private:
	int currentScreen;
public:
	/**
 * Constructor
 */
	Controller();

	/**
	 * Defines the new screen to display
	 * @param value : id of the new screen to display
	 */
	void setScreen(const int& idView);

	/**
	 * Returns the id of the current displayed screen
	 */
	int getScreen() const;
	/**
		* Read IMG from the user
	*/
	void readIMG(const std::string filename);

};

