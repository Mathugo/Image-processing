#include "controller.h"



Controller::Controller() : Subject(), currentScreen(0)
{

}

/**
 * Defines the current screen to display
 * @param value : id of the screen to display
 */
void Controller::setScreen(const int& idView)
{
	if (idView >= 0 && idView <= 9)
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
	std::cv::Mat image = imread(filename);
	// V�rifier si l�image existe bien dans le r�pertoire
	if (image.empty())
	{
		return -1;
	}
	// Affichage de l�image dans une fen�tre (Image)
}