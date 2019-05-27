#include "controller.h"


/**
* Constructor
* currentScreen set to -1 to display viewWelcome
*/
Controller::Controller() : Subject(), currentScreen(-1), currentview(menu)
{
}

/**
 * Defines the current screen to display
 * @param idView : id of the screen to display
 */
void Controller::setScreen(const int& idView)
{
	if (idView >= -1 && idView <= 9)
		currentScreen = idView;
	notify();
}
int Controller::getScreen() const
{
	return currentScreen;
}

/**
 * Defines the current view to display
 * @param _currentview: type of view to display
 */
void Controller::setCurrentView(views _currentview)
{
	currentview = _currentview;
}

views Controller::getCurrentView() const
{
	return currentview;
}
/**
* Read IMG from the user
* @param filename: name of the file to read
*/
void Controller::readIMG(const std::string filename)
{
	/*
Création de l’objet image et lecture de l’image à partir du
répertoire associé en utilisant la méthode imread()
*/
	image = cv::imread(filename);
	currentImage = image;
	// Vérifier si l’image existe bien dans le répertoire
	if (image.empty())
	{
		printRB("Unable to load " + filename+ " please retry");
		Sleep(1000);
		setScreen(-1);
	}
	else
	{
		printG("Successfully loaded " + filename);
		Sleep(1000);
		setScreen(0);
	}
	// Affichage de l’image dans une fenêtre (Image)
}

/**
 * Print current image
 * @param windowName: Name of the windows 
 */
void Controller::printIMG(const std::string windowName) const
{
	cv::namedWindow(windowName,cv::WINDOW_NORMAL);      
	imshow(windowName, currentImage);      
	cv::waitKey(0);      
	cv::destroyWindow(windowName);
}

/**
* Save the current image
*/
void Controller::saveIMG() const
{
	std::string filename;
	printY("Please enter a name for your image : ");
	std::cin >> filename;
	imwrite(filename, currentImage);
}

/**
* Restore your current image at its original format
*/
void Controller::restoreIMG()
{
	currentImage = image;
}
/**
* Start MedianFilter on currentImage
*/
void Controller::MedianFilter()
{
	Filters filter;
	currentImage = filter.MedianFilter(currentImage);
	printIMG("Your image with the median filter");
}
/**
* Start GaussianFilter on currentImage
*/
void Controller::GaussianFilter()
{
	Filters filter;
	currentImage = filter.GaussianFilter(currentImage);
	printIMG("Your image with the gaussian filter");
}
/**
* Start gradient on currentImage
*/
void Controller::Grad()
{
	Derivative derivate;
	derivate.grad(currentImage);
	printIMG("Your image with gradients");
}