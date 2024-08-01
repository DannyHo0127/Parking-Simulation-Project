//Include iostream, fstream, cstdlib libraries
//Include the date and parking wars header files
#include <iostream>
#include "ParkingWars.h"
#include "Date.h"
#include <unistd.h>
#include <fstream>
#include <cstdlib>

//Include namespace std
using namespace std;

//Define runSimulation() in parkingWars header file that will print the intro 
//Then, it will call the function runMonthSimulation with a pointer parameter
void ParkingWars::runSimulation() {
	
	cout << "Welcome to Parking Wars!" << endl;
	cout <<"This program simulates an epic battle between Parking Services and" << endl;
	cout << "students in Politics High School." << endl;
	
	runMonthSimulation(datesToSimulate);
}

//Define the runMonthSimulation with pointer parameter
//This function will ask the user for the date and will allocate the private variable pointer
//This function will also define the private variable arraySize and simulate from the input date to the end of the month
void ParkingWars::runMonthSimulation(Date *startDatePtr) {
	//Create in month, day, and year to user inputs
   //Create string typeDay to know what day it is
	///Create an int engMonth to know when the end day of the specific month it is
	//Create in totalDay to see how many days are between user input and endMonth
	int month;
   int day;
   int year;
   string typeDay;
	int endMonth;
	int totalDays;

	//Print and ask user for a date to run the simulation
   cout << "Please enter the data you'd like to start the simulation in MM DD YYYY" << endl;
   cout << "format: ";
   cin >> month;
   cin >> day;
   cin >> year;
	
	//Make an if else statement that if month is 1,3,5,7,8,10,12, set endMonth to 28
	//Else if month is 4,6,9, or 12, set end month to 30
	//Else if, endmonth is 2, set endmonth to 28
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
         endMonth =  31;
   	}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
         endMonth = 30;
  		}
  		else if (month == 2) {
         endMonth = 28;
      }
   //Make a date object named dateObject with parameters of month, day, and year
   //This will set up private variables because it will be sent to the overloaded constructor
	//Set totalDays to endMonth minus day plus 1
	//I added one because I have to consider the day of the user's date like if the user enters a  Tuesday, I start on Tuesday
	//Set array size to totalDays
	Date dateObject(month, day, year);
	totalDays = endMonth - day + 1;
	arraySize = totalDays;
   
	//Make a for loop with int i is 0, i loop while less than totalDays, and increment i by 1
  	//Call dateObject setter of day use day plus i ad the parameter to go to each day until the end of the month
	//set typeDay to DateObject.getDayOfWeek() to get the day of the week
	//make and if statement that if typeDay is Saturday, set arraySize to itself minus 1
	//else if typeDay is Sunday, set arraySize to itself minus 1
	//The whole point of this for loop is to go through each day and remove all Sunday and Saturday elements from arraySize
	//When I postIncrement an object, it will skip Saturday and Sunday, which is why I have to do this
	for (int i = 0; i < totalDays; i++) {
		dateObject.setDay(day + i);
		typeDay = dateObject.getDayOfWeek();
		if (typeDay == "Saturday") {
      	arraySize -= 1;
   	}	 
		else if (typeDay == "Sunday") {
			arraySize -= 1;
		}
	}
	
	//Reset the dateObject by using the setter method with parameters of month, day, and year given by user
	//Reset typeDay to the original dateObject by calling getDayOfWeek of the original dateObject
	//Create a Date object array and set the size to arraySize
	dateObject.setDay(day);
	dateObject.setMonth(month);
	dateObject.setYear(year);
	typeDay = dateObject.getDayOfWeek();
	Date arrayDate[arraySize];	
	
	//Make an if else statement that if typeDay is Saturday. post increment the dateObject
	//Else if typeDay is Sunday, post increment the dateObject
	if (typeDay == "Saturday") {
      dateObject++;
	}
   else if (typeDay == "Sunday") {
      dateObject++;
   }
	
	//Dynamically allocate the startDattePtr
	startDatePtr = new Date[arraySize];	

	//Make a for loop with int i is 0, i loop while less than arraySize, and increment i by 1
	//set startDatePtr[i] to post increment of dateObject
	for (int i = 0; i < arraySize; i++) {
      startDatePtr[i] = dateObject++;
   }
	
	//Call the function updatedateArray with the pointer as the parameter
	updateDateArray(startDatePtr);
}

//Define the function updatedateArray with an array pointer from the header file of parkingWars
//This function will run the simulation of the weekdays between parking services and students
//This will print out results for each day of how many tickets parking services gave and how many students park without permit
//Then, it will print the who won, the results, and summary statement
//This function will also call writeToFile() that will write to a log.txt file of the results
void ParkingWars::updateDateArray(Date *newDatePtr) {
	//Create int parkWins and studentWins to record how many wins parking services and students has
	//Set both to 0
	//Make a string typeDay to output what weekday it is
	//Create bool dayResults to see 
	int parkWins = 0;
   int studentWins = 0;
   string typeDay;
   bool dayResults;
	
	//Set the private logFile and open log.txt
	//Create a seed of time0 to make random numbers each time we calculate tickets and parking
	logFile.open("log.txt");
	srand(time(0));
	
	//Make a for loop with int i is 0, i loop while less than arraySize, and increment i by 1
	//Set private variable pointerLocation to i
	//Set typeDay to the newDatePtr[i].getDayOfWeek() to get the day of the week it is
	//Print the simulation and the day of the week
	//then, print the month, day, and year for the simulation using newDatePtr[i].getMonth/Day/Year
	//Make an if statement that if the function runDaySimulation(newDatePtr), which will call the function and print calculations, returns true
	//increment studentWins and set dayResults to true
	//else mean parkingWars won, increment parkWins and set dayResults to true
	//The call the functiom writeToFile() with the pointer and dayResults as the parameter. This will write to the log.txt file
	//Each loop will update the log.txt file and write write the day, date, and who won 
	for (int i = 0; i < arraySize; i++) {
		pointerLocation = i;
		typeDay = newDatePtr[i].getDayOfWeek();
      cout << "Running simulation for " << typeDay << " ";
      cout << newDatePtr[i].getMonth() << "/" << newDatePtr[i].getDay() << "/" << newDatePtr[i].getYear() << endl;
		if (runDaySimulation(newDatePtr)) {
			++studentWins;
			dayResults = true;
		}
		else {
			++parkWins;
			dayResults = false;
		}
		writeToFile(newDatePtr, dayResults);
	}

	//Close the logFile
	logFile.close();

	//Print out summary for the start day of the simulation
	//Print out how many days students and parking won
	cout << "Summary for starting on " <<  newDatePtr[0].getMonth() << "/" << newDatePtr[0].getDay() << "/" << newDatePtr[0].getYear() << ":" << endl;
	cout << "Students won a total of " << studentWins << " days!" << endl;
	cout << "Parking won a total of " <<  parkWins << " days!" << endl;
}

//Define the bool runDaySimulation with a pointer parameter that will print numTickets, numParkings, and who won
//This function will also call calculateParkingTicketsGiven and calculateStudentsParkingWithoutPermi to get random numbers of parking and tickets
//Rhis function will return true of students won and false if parking won
bool ParkingWars::runDaySimulation(Date *datePtr) {
	//Create int numTickets and numParking and set both to 0
	int numTickets = 0;
	int numParking = 0;

	//Create a for loop with int i to 0, i loop while less than 10, increment i by 1
	//Set usleep(50000) to stop at 0.05 second intervals for each tick
	//set numTickets plus equal to the function calculateParkingTicketsGiven(), which will return a random number of tickets
	//set numParking plus equal to calculateStudentsParkingWithoutPermit(), which will return a random number of parking
	for (int i = 0; i < 10; i++) {
		usleep(50000);
		numTickets += calculateParkingTicketsGiven();
		numParking += calculateStudentsParkingWithoutPermit();
	}
	
	//Print out how many tickets parking services gave and how students parked
	cout << "Number of tickets given: " << numTickets << endl;
	cout << "Number of students parking without permits: " << numParking << endl;
	
	//Make an if statement that if numTickets is greater than numParking, means parking services won
	//Print parking services won and return false
	//Else mean students parked greater than or equal to tickets
	//Print students won and return true
	if (numTickets > numParking) {
		cout << "      Parking won!" << endl << endl;
		return false;
	}
	else {
		cout << "      Students won!" << endl << endl;
		return true;
	}
}

//Define the function calculateParkingTicketsGiven that will use the statistic in the directions to return a random number
int ParkingWars::calculateParkingTicketsGiven() {
	//Create int numTickets and int random number
	int numTickets = 0;
	int randomNumber = 0;
	
	//Set random Number to rand() from 1 to 100
	randomNumber = rand() % 100 + 1;
	
	//if RandomNumber is less than 35
	//set numTickets plus equal to 0
	//else if numTicket is less than or equal to 65, meaning from 36-65 because it didn't pass the first if statement
	//set numTickets to 9
	//else if numTickets is less than or equal to 95, meaning from 66-95 because it didn't pass the previous if statement
	//set numTickets to 1
	//else mean the randomNumber is 96-100, set numTickets to 12;
	if (randomNumber <= 35) {
		numTickets = 0;
	}
	else if (randomNumber <= 65) {
		numTickets = 9;
	}
	else if (randomNumber <= 95) {
		numTickets = 1;
	}
	else {
		numTickets = 12;
	}
	
	//Return numTickets
	return numTickets;
}

//Define the function calculateParkingTicketsGiven that will use the statistic in the directions to return a random number
int ParkingWars::calculateStudentsParkingWithoutPermit() {
	//Create int numParking and randomnumber and set it to 0
	int numParking = 0;
   int randomNumber = 0;
	
	//Set randomNumber to rand() from 1 to 100
	randomNumber = rand() % 100 + 1;
	
	//if randomNunber is less than or equal to 50, meaning from 1 to 50. set numParking to 3
	//Else if randomNumber is less than or equal to 85, meaning from 51-85 because it didn't pass the previous if statement
	//Set numParking to 1
	//else, means randomNumber is from 86-100, set nimParking to 6
	if (randomNumber <= 50) {
		numParking = 3;
	}
	else if (randomNumber <= 85) {
		numParking = 1;
	}
	else {
		numParking = 6;
	}
	
	//Return numParking
	return numParking;
}

//Define the function writeToFile with parameters of datePtr pointer, and bool studentsWon
void ParkingWars::writeToFile(Date *datePtr, bool studentsWon) {
	//Write to the logFile of datePti[pointerLocation].getDayOfWeek to get the day of the week
	//Use the getters of Day,month, and year with datePtr using pointerLocation to write MM/DD/YYYY in the log.txt file
	//Make an if statement if stuDentsWon, write Students won! to the log.txt file
	//Else write Parking won. to the log.txt file
	logFile << datePtr[pointerLocation].getDayOfWeek() << " ";
	logFile << datePtr[pointerLocation].getMonth() << "/" << datePtr[pointerLocation].getDay() << "/" << datePtr[pointerLocation].getYear() << ": ";
	if (studentsWon) {
		logFile << "Students won!" << endl;
	}
	else {
		logFile << "Parking won." << endl;
	}
	datePtr++;
}
