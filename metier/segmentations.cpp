#include "segmentations.h"



Segmentations::Segmentations()
{
}
void Segmentations::enter()
{
	int enter;
	
	system("cls");
	printY("\nPlease enter the type you want");
	printY("0: Binary");
	printY("1: Binary Inverted");
	printY("2: Truncate");
	printY("3: To Zero");
	printY("4: To Zero Inverted\n");

	std::cin.clear();
	std::cin >> enter;

	if (enter >= 0 && enter <= 4)
	{
		threshold_type = enter;
	}
	else
	{
		printRB("Bad value entered, default is 3");
	}
	printY("\nPlease enter a thresholding value between 0 and 255");

	std::cin.clear();
	std::cin >> enter;

	if (enter >= 0 && enter <= 255)
	{
		threshold_value = enter;
	}
	else
	{
		printRB("Bad value entered, default is 100");
		threshold_value = 100;
	}


}

void Segmentations::thresholding(cv::Mat& image)
{
	cv::Mat src_gray;
	/// Convert the image to Gray
	cvtColor(image, src_gray, cv::COLOR_BGR2GRAY);
	enter();
	threshold(src_gray, dst, threshold_value, max_BINARY_value, threshold_type);
	image = dst;
}

void Segmentations::growth(cv::Mat& image)
{
	printY("Please wait while the region growing segmentation is being applied on your image");
	printY("This might take a while depending on the size of your image");

	printY("[*] Converting image to white and black ...");

	// Change the background from white to black, since that will help later to extract
	// better results during the use of Distance Transform
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			if (image.at<cv::Vec3b>(i, j) == cv::Vec3b(255, 255, 255))
			{
				image.at<cv::Vec3b>(i, j)[0] = 0;
				image.at<cv::Vec3b>(i, j)[1] = 0;
				image.at<cv::Vec3b>(i, j)[2] = 0;
			}
		}
	}
	printG("[*] Done");
	printY("[*] Putting laplacian filtering ...");

	// Create a kernel that we will use to sharpen our image
	cv::Mat kernel = (cv::Mat_<float>(3, 3) <<
		1, 1, 1,
		1, -8, 1,
		1, 1, 1); // an approximation of second derivative, a quite strong kernel

	 // do the laplacian filtering as it is
	// well, we need to convert everything in something more deeper then CV_8U
	// because the kernel has some negative values,
	// and we can expect in general to have a Laplacian image with negative values
	// BUT a 8bits unsigned int (the one we are working with) can contain values from 0 to 255
	// so the possible negative number will be truncated
	cv::Mat imgLaplacian;
	filter2D(image, imgLaplacian, CV_32F, kernel);
	cv::Mat sharp;
	image.convertTo(sharp, CV_32F);
	cv::Mat imgResult = sharp - imgLaplacian;
	// convert back to 8bits gray scale
	imgResult.convertTo(imgResult, CV_8UC3);
	imgLaplacian.convertTo(imgLaplacian, CV_8UC3);

	printG("[*] Done");
	printY("[*] Creating binary image ...");

	// Create binary image from source image
	cv::Mat bw;
	cvtColor(imgResult, bw, cv::COLOR_BGR2GRAY);
	threshold(bw, bw, 40, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);


	// Perform the distance transform algorithm
	cv::Mat dist;
	distanceTransform(bw, dist, cv::DIST_L2, 3);
	// Normalize the distance image for range = {0.0, 1.0}
	// so we can visualize and threshold it
	normalize(dist, dist, 0, 1.0, cv::NORM_MINMAX);
	printG("[*] Done");
	// Threshold to obtain the peaks
	// This will be the markers for the foreground objects

	printY("[*] Dilating and thresholding ... ");

	threshold(dist, dist, 0.4, 1.0, cv::THRESH_BINARY);
	// Dilate a bit the dist image
	cv::Mat kernel1 = cv::Mat::ones(3, 3, CV_8U);
	dilate(dist, dist, kernel1);

	cv::Mat dist_8u;
	dist.convertTo(dist_8u, CV_8U);

	printG("[*] Done");

	printY("[*] Putting markers to detect contours ...");

	// Find total markers
	std::vector<std::vector<cv::Point> > contours;
	findContours(dist_8u, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	// Create the marker image for the watershed algorithm
	cv::Mat markers = cv::Mat::zeros(dist.size(), CV_32S);
	// Draw the foreground markers
	for (size_t i = 0; i < contours.size(); i++)
	{
		drawContours(markers, contours, static_cast<int>(i), cv::Scalar(static_cast<int>(i) + 1), -1);
	}
	// Draw the background marker
	circle(markers, cv::Point(5, 5), 3, cv::Scalar(255), -1);


	cv::Mat mark;
	markers.convertTo(mark, CV_8U);
	bitwise_not(mark, mark);
	//    imshow("Markers_v2", mark); // uncomment this if you want to see how the mark
	// image looks like at that point
	// Generate random colors
	std::vector<cv::Vec3b> colors;
	for (size_t i = 0; i < contours.size(); i++)
	{
		int b = cv::theRNG().uniform(0, 256);
		int g = cv::theRNG().uniform(0, 256);
		int r = cv::theRNG().uniform(0, 256);
		colors.push_back(cv::Vec3b((uchar)b, (uchar)g, (uchar)r));
	}

	printG("[*] Done");

	// Create the result image
	dst = cv::Mat::zeros(markers.size(), CV_8UC3);
	// Fill labeled objects with random colors
	for (int i = 0; i < markers.rows; i++)
	{
		for (int j = 0; j < markers.cols; j++)
		{
			int index = markers.at<int>(i, j);
			if (index > 0 && index <= static_cast<int>(contours.size()))
			{
				dst.at<cv::Vec3b>(i, j) = colors[index - 1];
			}
		}
	}

	image = dst;

}