/*
* This program will search for a student in this room (efficiently AND inefficiently)!
*/

#include "CustomDynamicArray.h"
#include <algorithm>
#include <chrono>
#include <iomanip> //for std::scientific
#include <iostream>


int main()
{
	//Car mycar;

	//std::cout << mycar;  //remember! this requires "operator overloading"

	///*simple timing demo*/
	//using namespace std::chrono; 
	//
	//auto starttime = std::chrono::high_resolution_clock::now(); 

	//
	///*question: how long does it take c++ to count to 1 billion?*/
	//for (int i = 0; i < 1'000'000; ++i)
	//{
	//	//do nothing (aren't you being mean to your computer ...)
	//}
	//auto stoptime = std::chrono::high_resolution_clock::now(); 

	//std::cout << "it took this many nanoseconds (billionths of a second): \n";

	//auto thetimeittook = (stoptime - starttime).count();

	//std::cout << std::fixed << std::setprecision(2); 
	//std::cout << std::scientific << (float)thetimeittook << "\n";

	//std::cin.get(); //forces user to enter a character before execution continues

	std::string theNameToSearchFor = "asdfadsfas";

	std::string filenameForStudentRoster = "studentRoster.csv";
	CustomDynamicArray students(filenameForStudentRoster);

	students.shuffle();

	std::cout << "Unsorted list of strings:\n";
	students.print();

	auto randomStudent = students.getRandomStringInList();

	std::cout << "\n";
	students.sortListAlphabetically();


	std::cout << "\n";

	if (students.sequentialSearch(randomStudent))
	{
		std::cout << "Student found via sequential search\n";
	}
	else
	{
		std::cout << "Student not found via sequential search\n";
	}

	if (students.binarySearch(randomStudent))
	{
		std::cout << "Student found via binary search\n";
	}
	else
	{
		std::cout << "Student not found via binary search\n\n";
	}
}

