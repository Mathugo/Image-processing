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
	cv::Mat image = cv::imread(filename);
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