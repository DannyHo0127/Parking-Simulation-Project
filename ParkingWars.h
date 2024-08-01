//Danny Ho 
//CPSC 1070-010
//3/4/2023

//Declare header guards for parkingwars
//Include fstream and string library
#ifndef PARKINGWARS_H
#define PARKINGWARS_H
#include "Date.h"
#include <fstream>
#include <string>

//Declare a class name ParkingWars
class ParkingWars {
	public:
	//In public, provide all the function this project will need
	//Declare runSimulation to run the parking simulation
	//Declare runMonthSimulation with a pointer parameter, which will define th arraySize and  allocate the pointer
	//Declare void updateDateArray that will allocate the pointer
	//Declare bool runDaySimulation that will simulate a day and return true or false depending on who wins
	//Declare int calculateParkingTicketsGiven and calculateStudentsParkingWithoutPermit to calculate number of tickets and parking each day
	//Declare writeToFile(Date *datePtr, bool studentsWon) to write to log.txt file about the results
	void runSimulation();
	void runMonthSimulation(Date *startDatePtr);
	void updateDateArray(Date *newDatePtr);  
	bool runDaySimulation(Date *datePtr);
	int calculateParkingTicketsGiven();  
	int calculateStudentsParkingWithoutPermit(); 
	void writeToFile(Date *datePtr, bool studentsWon);
	private:
	//Declare an output stream object logFile, since more than one function needs to access the logFile for my code
	//Create int arraySize
	//Create in pointerLocation for the logfile, since logFile updates each day(in a loop)  and needs to know the pointer location
	//Create a Date pointer name datesToSimulate
	ofstream logFile;
	int arraySize;
	int pointerLocation;
	Date *datesToSimulate;
};

#endif

