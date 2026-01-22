/*
* This program will search for a student in this room (efficiently AND inefficiently)!
*/

#include "CustomDynamicArray.h"
#include<algorithm>
#include<chrono>
#include<iomanip> //for std::scientific
#include <iostream>



class Car
{

};

int main()
{
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


	std::cin.get(); //forces user to enter a character before execution continues

	std::string theNameToSearchFor = "asdfadsfas";

	std::string filenameForStudentRoster = "studentRoster.csv";
	CustomDynamicArray students(filenameForStudentRoster);

	students.shuffle(); 

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

