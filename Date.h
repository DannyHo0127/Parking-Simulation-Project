//Danny Ho 
//CPSC 1070-010
//3/4/2023

//Include header guards for Date header file
//Include string library because one functionr returns a string
#ifndef DATE_H
#define DATE_H
#include <string>

//Include using namespace std
using namespace std;

//Declare a class named Date
class Date {
	public:
	//Declare all functions, constructors, accesscors, and mutators in public
	//Declare a Date default constructor and overloaded constructor to fine private variables
	Date();
	Date(int, int, int);
	
	//Declare accessors for month, day, and year so that user can access private variables
	int getMonth();          
	int getDay();
	int getYear();
	
	//Declar mutators for month, day, and year so that user can set private variables
	void setMonth(int);
	void setDay(int);
	void setYear(int);

	//Declare function string getDayOfWeek, which calls MysteryMachine to get the day of the week
	string getDayOfWeek();
	
	//Declare overloaded operators for plus, minus, pre increment, post increment, pre decrement, and post decrement
	Date operator+(int days);  
	Date operator-(int days);
	Date operator++(void);     
	Date operator++(int);      
	Date operator--(void);     
	Date operator--(int);      
	
	private:
	//Declare private variable month, day, and year
	int month;
	int day;
	int year;
};
#endif
