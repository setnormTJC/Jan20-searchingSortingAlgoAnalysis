#include "CustomDynamicArray.h"


#include<algorithm>
#include<fstream>
#include <iostream>
#include<random> 

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
		//std::cout << currentStudentName << "\n";
		listOfStrings.push_back(currentStudentName);
	}

}

void CustomDynamicArray::shuffle()
{
	std::mt19937 rng(std::random_device{}()); //this syntax is CRAZY (let's just use "abstraction")

	std::uniform_int_distribution<int> distribution(0, listOfStrings.size());

	for (int i = 0; i < listOfStrings.size(); ++i)
	{
		int randomIndex = distribution(rng); 
		std::swap(listOfStrings[i], listOfStrings[randomIndex]);
	}
}

void CustomDynamicArray::print()
{
	for (const std::string& currentString : listOfStrings)
	{
		std::cout << currentString << "\n";
	}
}


