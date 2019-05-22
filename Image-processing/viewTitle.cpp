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
	printG("[ "+title+" ]");
}
