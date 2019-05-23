#include "animations.h"


void SetColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
	/*
	1: Blue
	2 : Green
	3 : Cyan
	4 : Red
	5 : Purple
	6 : Yellow(Dark)
	7 : Default white
	8 : Gray / Grey
	9 : Bright blue
	10 : Brigth green
	11 : Bright cyan
	12 : Bright red
	13 : Pink / Magenta
	14 : Yellow
	15 : Bright white
	- Numbers after 15 are background colors -
	*/
}
void printY(const std::string buffer)
{
	std::cout << KYEL << buffer << RST << std::endl;
}
void printRB(const std::string buffer)
{
	std::cout << KBOLD << KRED << buffer << RST << std::endl;
}
void printG(const std::string buffer)
{
	std::cout << KBOLD << KGRN << buffer << RST << std::endl;
}
void printB(const std::string buffer)
{
	std::cout << KBLU << buffer << RST << std::endl;
}
void printBB(const std::string buffer)
{
	std::cout << KBOLD << KBLU << buffer << RST << std::endl;

}
