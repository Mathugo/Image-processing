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
	if (idView >= -1 && idView <= 10)
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
* Insert number to select view
*/
void Controller::insert()
{
	int res;
	std::cin.clear();
	std::cin >> res;
	this->setScreen(res);
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
	std::cout << KYEL << "Please enter a name for your image : " << RST;
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
	filter.MedianFilter(currentImage);
	printIMG("Your image with the median filter");
}
/**
* Start GaussianFilter on currentImage
*/
void Controller::GaussianFilter()
{
	Filters filter;
	filter.GaussianFilter(currentImage);
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

void Controller::Erosion()
{
	Morphology morphology;
	morphology.erosion(currentImage);
	printIMG("Your image with erosion");
}

void Controller::Dilatation()
{
	Morphology morphology;
	morphology.dilatation(currentImage);
	printIMG("Your image with dilatation");
}

void Controller::Canny()
{
	Contour contour;
	contour.Canny(currentImage);
	printIMG("The contours");
}

void Controller::Thresholding()
{
	Segmentations seg;
	seg.thresholding(currentImage);
	printIMG("Your image with thresholding");
}
void Controller::Growth()
{
	Segmentations seg;
	seg.growth();
}
/**
* Detect images in the current folder (jpg and png)
*/
std::string Controller::detectIMAGE()
{
	std::string img = "";
	const std::string filename = "allfiles";
	std::string cmd = "dir /b >> " + filename;
	system(cmd.c_str());

	std::string content;

	std::ifstream file(filename, std::ios::in);
	if (file)
	{
		while (getline(file, content))
		{
			int size = content.size();
			if (content.size() >= 4)
			{
				bool test_jpg = content[size - 3] == 'j' && content[size - 2] == 'p' && content[size - 1] == 'g' || content[size - 3] == 'J' && content[size - 2] == 'P' && content[size - 1] == 'G';
				bool test_png = content[size - 3] == 'p' && content[size - 2] == 'n' && content[size - 1] == 'g' || content[size - 3] == 'P' && content[size - 2] == 'N' && content[size - 1] == 'G';

				if (test_jpg || test_png)
				{
					img = content + " " + img;
				}
			}
		}
		file.close();
		cmd = "ERASE " + filename;
		system(cmd.c_str());
		return img;
	}
	cmd = "ERASE " + filename;
	system(cmd.c_str());
	return "";

}