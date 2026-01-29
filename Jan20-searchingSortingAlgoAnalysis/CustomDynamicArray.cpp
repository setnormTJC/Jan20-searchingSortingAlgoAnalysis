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



std::string CustomDynamicArray::binarySearch(const std::string& target, int startPosition, int endPosition)
{
	if (!std::is_sorted(listOfStrings.begin(), listOfStrings.end()))
	{
		std::cout << "Hey bro, that array ain't sorted ...\n";
		return "";
	}
	//assert(std::is_sorted(names.begin(), names.end()); //givin' me LIP!

	if (startPosition > endPosition)
	{
		return "Not found";
	}

	const int middle = floor((startPosition + endPosition) / 2); //like linoleum? 

	if (listOfStrings[middle] == target)
	{
		return "Found it at index " + std::to_string(middle); //added "to_string" after class 
	}

	//log2(50) = x; 2^x = 50; log2(1000) = x -> 10 

	if (listOfStrings[middle] > target) //is else preferable here??
	{
		return binarySearch(target, startPosition, middle - 1);
	}

	if (listOfStrings[middle] < target)
	{
		return binarySearch( target, middle + 1, endPosition);
	}
}


