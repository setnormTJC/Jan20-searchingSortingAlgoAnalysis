#include "CustomDynamicArray.h"


#include<fstream>
#include <iostream>

CustomDynamicArray::CustomDynamicArray(const std::string& filename)
{
	std::ifstream fin(filename); 

	if (!fin)
	{
		std::cout << "Could not find the file named " << filename << "\n";
		__debugbreak();
	}

	std::string currentStudentName; 
	while (std::getline(fin, currentStudentName))
	{
		std::cout << currentStudentName << "\n";
	}

}
