#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	/*
 Création de l’objet image et lecture de l’image à partir du
 répertoire associé en utilisant la méthode imread()
 */
	Mat image = imread("C:/photo.jpg");
	// Vérifier si l’image existe bien dans le répertoire
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	// Affichage de l’image dans une fenêtre (Image)
	string windowName = "Image";
	namedWindow(windowName);
	imshow(windowName, image);
	waitKey(0);
	destroyWindow(windowName);
	return 0;
}