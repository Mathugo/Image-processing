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
Cr�ation de l�objet image et lecture de l�image � partir du
r�pertoire associ� en utilisant la m�thode imread()
*/
	cv::Mat image = cv::imread(filename);
	// V�rifier si l�image existe bien dans le r�pertoire
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
	// Affichage de l�image dans une fen�tre (Image)
}