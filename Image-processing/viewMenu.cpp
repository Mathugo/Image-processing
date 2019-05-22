#include "viewMenu.h"



ViewMenu::ViewMenu(Controller& _controller)
	: ViewTitle("Menu"), controller(_controller)
{
	controller.addObserver(this);
}

void ViewMenu::notify()
{
	if (controller.getScreen() == 0)
		display();
}


void ViewMenu::display()
{
	system("CLS");
	ViewTitle::display();
	printY("\t1. Filter");
	printY("\t2. Derivation");
	printY("\t2. Operations of mathematical morphology");
	printY("\t3. Contour Detection");
	printY("\t4. Segmentations of images");
	printRB("\t9. Quitter");
	std::cout << std::endl;

	int res;
	std::cin.clear();
	std::cin >> res;
	controller.setScreen(res);
}