#include "controller.h"


/**
* Constructor
* currentScreen set to -1 to display viewWelcome
*/
Controller::Controller() : Subject(), currentScreen(-1)
{

}

/**
 * Defines the current screen to display
 * @param value : id of the screen to display
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

void Controller::readIMG(const std::string filename)
{
	/*
Création de l’objet image et lecture de l’image à partir du
répertoire associé en utilisant la méthode imread()
*/
	image = cv::imread(filename);
	current_image = image;
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
	imshow(windowName, current_image);      
	cv::waitKey(0);      
	cv::destroyWindow(windowName);
}

void Controller::MedianFilter()
{
	cv::Mat dst;
	int MAX_KERNEL_LENGTH = 30; // Number of pixels around to median 

	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		medianBlur(image, dst, i);
	}
	printIMG("Your image with the median filter");
}