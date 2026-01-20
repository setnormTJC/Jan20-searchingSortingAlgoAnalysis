/*
* This program will search for a student in this room (efficiently AND inefficiently)!
*/

#include "CustomDynamicArray.h"
#include<algorithm>
#include <iostream>


int main()
{

	std::string theNameToSearchFor = "asdfadsfas";

	std::string filenameForStudentRoster = "studentRoster.csv";
	CustomDynamicArray students(filenameForStudentRoster);

	students.shuffle(); 

	students.print(); 
}

