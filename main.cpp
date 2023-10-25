#include <iostream>
#include <string>
#include "SLLString.h"

int main()
{
    /*
	SLLString str("Hello world!");
	SLLString newStr;

	newStr = str;
	newStr += SLLString("CS@BC");
	newStr[6] = 'W';

	std::cout << newStr << std::endl;			// Hello World! CS@BC
	std::cout << newStr.length() << std::endl;	//18

	int loc = newStr.findSubstring("World");
	std::cout << loc << std::endl;				// 6

	newStr.erase('l');							//erase the letter l
	std::cout << newStr << std::endl;			// Heo Word! CS@BC

	newStr.erase('C');
	std::cout << newStr << std::endl;			// Heo Word! S@B

	return 0;
     */

    SLLString str("deez");
    SLLString newStr;
    newStr = str;
    newStr += SLLString("nutz");
    //std::cout << "&str: " << &str << std::endl;
    //std::cout << "&newStr: " << &newStr << std::endl;
    //std::cout << "str: " << str << std::endl;
    /*std::cout << "Calling newStr[6] = 'W': " << std::endl;
    newStr[6] = 'W';
    std::cout << "newStr: " << newStr << std::endl;
    std::cout << "newStr length: " << newStr.length() << std::endl;

    std::string searchString;
    while (searchString != "1") {
        std::cout << "What are you looking for? ";
        std::getline(std::cin, searchString);
        int loc = newStr.findSubstring(searchString);
        std::cout << loc << std::endl;
    }*/
    std::cout << "Bogey on Radar" << std::endl;
    newStr.erase('d');							//erase the letter l
    std::cout << newStr << std::endl;
    newStr.erase('e');							//erase the letter l
    std::cout << newStr << std::endl;
}