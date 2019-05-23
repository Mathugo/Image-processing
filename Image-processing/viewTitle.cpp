#include "viewTitle.h"


/**
 * Constructor
 * @param _title: Title of the view
 */
ViewTitle::ViewTitle(const std::string& _title)
	:title(_title)
{

}

/**
 * Clears console
 */
void ViewTitle::clear() const
{
	system("CLS");
}

/**
 * Displays the view
 */
void ViewTitle::display() const
{
	printY("[ "+title+" ]");
	std::cout << std::endl << std::endl;
}

/**
* Return the title to check diferent views
*/
std::string ViewTitle::getTitle() const
{
	return title;
}
