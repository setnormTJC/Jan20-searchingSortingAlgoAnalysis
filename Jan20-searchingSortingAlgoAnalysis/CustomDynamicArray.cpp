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
	std::uniform_int_distribution<int> distribution(0, listOfStrings.size() - 1);

	for (int i = 0; i < listOfStrings.size(); ++i)
	{
		int randomIndex = distribution(rng); 

		if (randomIndex < 0 || randomIndex > listOfStrings.size() - 1)
		{
			std::cout << "Out of bounds\n";
			__debugbreak(); 
		}

		std::swap(listOfStrings[i], listOfStrings[randomIndex]);
	}
}

void CustomDynamicArray::print()
{
	for (const std::string& currentString : listOfStrings)
	{
		std::cout << currentString << "\n";
	} //Heisenbug
}

std::string CustomDynamicArray::getRandomStringInList()
{
	std::mt19937 rng(std::random_device{}()); //this syntax is CRAZY (let's just use "abstraction")
	std::uniform_int_distribution<int> distribution(0, listOfStrings.size() - 1);
	int randomIndex = distribution(rng); 

	int otherRandomIndex = rand() % listOfStrings.size(); //this is a SIMPLER (but less "good") version 
															//of the 3 lines directly above

	std::string randomString = CustomDynamicArray::listOfStrings[distribution(rng)];

	return randomString; //fix me!
}

bool CustomDynamicArray::sequentialSearch(const std::string& targetString)
{

	std::cout << "We are looking for: " << targetString << "\n";

	for (int i = 0; i < listOfStrings.size(); ++i)
	{
		if (listOfStrings[i] == targetString) //the droid we're looking for
		{
			return true; //found
		}
	}

	return false; 
}

int CustomDynamicArray::binarySearch(const std::string& target)
{
	bool found = false;
	int first = 0;
	int last = static_cast<int>(listOfStrings.size()) - 1;
	int middle = 0;

	//
	if (first <= last && !found)
	{
		middle = static_cast<int>(floor((first + last / 2)));

		if (listOfStrings[middle] == target)
			found = true;
		else if (listOfStrings[middle] < target)
			last = middle - 1;
		else if (listOfStrings[middle] > target)
			first = middle + 1;
	}

	if (found)
		return middle;
	else
		return -1;
}