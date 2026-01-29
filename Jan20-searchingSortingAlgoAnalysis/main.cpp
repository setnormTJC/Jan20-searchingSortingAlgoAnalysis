/*
* This program will search for a student in this room (efficiently AND inefficiently)!
*/

#include "CustomDynamicArray.h"
#include<algorithm> //included so we have access to std::is_sorted (among other functions) 
#include<chrono>
#include<iomanip> //for std::scientific
#include <iostream>




int main()
{
	std::vector<int> sortedNums = { 1, 2, 3, -123123 };


	std::cout << "Is the following list sorted??\n";
	for (int i = 0; i < sortedNums.size(); ++i)
	{
		std::cout << sortedNums[i] << " ";
	}

	std::cout << "\n";

	std::cout << std::boolalpha;
	std::cout << std::is_sorted(sortedNums.begin(), sortedNums.end()) << "\n"; //true


	//Car myCar; 

	//std::cout << myCar;  //remember! this requires "operator overloading"

	/*Simple timing demo*/
	//using namespace std::chrono; 
	
	auto startTime = std::chrono::high_resolution_clock::now(); 

	/*Question: how long does it take C++ to count to 1 billion?*/
	for (int i = 0; i < 1'000'000; ++i)
	{
		//do nothing (aren't you being MEAN to your computer ...)
	}
	auto stopTime = std::chrono::high_resolution_clock::now(); 

	std::cout << "It took this many nanoseconds (billionths of a second): \n";
	

	auto theTimeItTook = (stopTime - startTime).count();

	std::cout << std::fixed << std::setprecision(2); 
	std::cout << std::scientific << (float)theTimeItTook << "\n";

	//std::cin.get(); //forces user to enter a character before execution continues

	std::string theNameToSearchFor; //CHANGE ME!!!!!!!!!!!!!!!!!!!!!!!!!

	std::string filenameForStudentRoster = "studentRoster.csv";
	CustomDynamicArray students(filenameForStudentRoster);

	students.shuffle(); ///DANGER WILL ROBINSON!!!!!!!!

	/*Let's do a selection search for a random name in this list*/
	students.print(); 


	auto randomStudent = students.getRandomStringInList(); 

	std::cout << "\n\n\n";
	if (students.sequentialSearch(randomStudent) == true)//searches IN SEQUENCE
	{
		std::cout << "FOUND that student\n";
	}

	else
	{
		std::cout << "NOT found\n";
	}
}

