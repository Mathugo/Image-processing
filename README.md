# Image-processing
Simple image processing using opencv 

## Goals
This project is made with the MVC design pattern, finally they will be different options : 
 * Filtering :
   * median filter
   * gaussian filter
 * Derivation :
   * calculation of the gradient in an image (Sobel)
 * Operations of mathematical morphology :
   * dilatation
   * erosion
 * Contour Detection :
   * application of a contour detector "Canny"
 * Segmentations of images:
   * thresholding operations
   * regional growth segmentation
  
## Getting Started

These instructions will get you a copy of the project up and running on your local machine.

### Prerequisites

You will need [Visual Studio](https://visualstudio.microsoft.com/fr/) (Pro or community) at least 2015 and [opencv](https://opencv.org/releases/)

### Installing 

#### Windows 

Extract opencv
Modify the Windows environnement variables --> system variable --> Path ---> add the path of your opencv folder

#### Visual Studio

Put your project in Debug mode and x64

You have to add external library (opencv) and then link it : 
* Go to properties : C/C++ → General
* Copy the path your include opencv (ex : C:\opencv\build\include) in Additional include
Directories
* Go to C/C++ → Linker → General
* Copy the lib path of your opencv (ex C:\opencv\build\x64\vc15\lib) in Additonnal Library Directories
* Choose C/C++ → Linker → Input
* Additionnal depencencies → Edit :
* Enter : opencv_world320d_lib or opencv_world410d_lib if this doesn't work

## Authors
* **Math Hugo**

## Supervisions
*ESIREM* 
* **Charles Meunier**
* **Rahima Zaouche**
