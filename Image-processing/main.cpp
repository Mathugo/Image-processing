#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	/*
 Cr�ation de l�objet image et lecture de l�image � partir du
 r�pertoire associ� en utilisant la m�thode imread()
 */
	Mat image = imread("C:/photo.jpg");
	// V�rifier si l�image existe bien dans le r�pertoire
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	// Affichage de l�image dans une fen�tre (Image)
	string windowName = "Image";
	namedWindow(windowName);
	imshow(windowName, image);
	waitKey(0);
	destroyWindow(windowName);
	return 0;
}