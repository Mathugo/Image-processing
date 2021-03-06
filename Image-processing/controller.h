#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "subject.h"

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "animations.h"
#include "filters.h"
#include "derivative.h"
#include "morphology.h"
#include "contour.h"
#include "segmentations.h"

typedef enum views views;
enum views
{
	menu, filters, derivation, morphology, contour, seg
};

class Controller : public Subject
{
private:
	int currentScreen;
	views currentview;
	cv::Mat image;
	cv::Mat currentImage;
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
	* Returns the current view
	*/
	views getCurrentView() const;
	/**
	* Set the current view
	*/
	void setCurrentView(views _currentview);
	/**
	* Insert number to select view	
	*/
	void insert();
	/**
		* Read IMG from the user
	*/
	void readIMG(const std::string filename);

	/**
	* Print IMG from the user
	*/
	void printIMG(const std::string windowName) const;

	/**
	* Save the current image
	*/
	void saveIMG() const;

	/**
	* Restore your current image at its original format
	*/
	void restoreIMG();

	/**
	* All operation to the current image
	*/
	void MedianFilter();
	void GaussianFilter();
	void Grad();
	void Erosion();
	void Dilatation();
	void Canny();
	void Thresholding();
	void Growth();

	/**
	* Detect image in the current folder (jpg and png)
	*/
	std::string detectIMAGE();
};

