#pragma once
#include "subject.h"
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "animations.h"

class Controller : public Subject
{
private:
	int currentScreen;
	cv::Mat image;
	cv::Mat current_image;
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

	/**
		* Print IMG from the user
	*/
	void printIMG(const std::string windowName) const;
	
	/**
		* MedianFiltrer using current image
	*/
	void MedianFilter();

};

