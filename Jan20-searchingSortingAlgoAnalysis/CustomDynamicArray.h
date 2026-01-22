#pragma once
#include <vector>
#include <string>


/*This class is a "wrapper" around std::vector (the C++ standard library dynamic array implementation*/
class CustomDynamicArray
{
private: 
	std::vector<std::string> listOfStrings; //what are the contents of this guy at the moment? 

public: 
	CustomDynamicArray() = delete; //what is the name of this "special" constructor (one which takes 0 args.)

	CustomDynamicArray(const std::string& filename);//

	void shuffle(); 

	void print(); 

	std::string getRandomStringInList(); 

	/*This algorithm might be described as naive and brute-force*/
	bool sequentialSearch(const std::string& targetString);
};

