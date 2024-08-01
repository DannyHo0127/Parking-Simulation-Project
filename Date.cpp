//Danny Ho 
//CPSC 1070-010
//3/4/2023

//Include Date header file, string because of MysterMachine, and header file for MysteryMachine to get day of the week
#include "Date.h"
#include <string>
#include "MysteryMachine.h"

//Include namespace std
using namespace std;

//Create a date default constructor that set the private variables of month, day, and year to January 1, 2000
Date::Date() {
	month = 1;
	day = 1;
	year = 2000;
}

//Create a date overload constructors that has parameters of int month, int day, and int year.
//Set the private class variables equal to the parameters. Use this-> because the private variable names are the same as parameters
Date::Date(int month, int day, int year) {
	this->month = month;
	this->day = day;
	this->year = year;
}

//Define the accessor getMonth() that return the private variable month
int Date::getMonth() {
	return month;
}

//Define the accessor getDay() that returns the private variable day
int Date::getDay() {
   return day;
}

//Define the accessor getYear() that returns the private variable year
int Date::getYear() {
   return year;
}

//Define the mutator setMonth that takes in an int as the parameter
//Set class private variable month to parameter
void Date::setMonth(int month) {
	this->month = month;
}

//Define the mutator setDay that takes in an int as a parameter
//Set class variable day equal to the parameter
void Date::setDay(int day) {
   this->day = day;
}

//Define the mutator setYear that takes in an int as a parameter
//Set the class private variable year equal to the parameter
void Date::setYear(int year) {
   this->year = year;
}

//Define the function getDayOfWeek, which calls MysteryMachine
//Make a string named typeDay
//set typeDay equal to getDayOfWeek from the MysteryMachine header file, use *this as the parameter
//This will take in the current class and set typeDay to a day of the week, retu7rn typeDay
string Date::getDayOfWeek() {
	string typeDay;

	typeDay = MysteryMachine::getDayOfWeek(*this);

	return typeDay;
}

//Define the overloaded operator plus with the parameter days
//Make a for loop with int i is 0, i loop while less than days, increment i
//in the for loop post increment days and create a string typeDay that calls MysteryMachine to get Day of the week
//If typeDay is Saturday, add private variable day by 2,
//if typeDay is Sunday, add private variable day by 1
//Make an if else statement that if month is 1, 3, 5, 7, 8, 10, 12 and if day is greater than 31,
//set day equal to day minus 31 and increment month
//else if month is 4, 6, 9, or 11, and if day is greater than 30,
//Set day equal to day minus 30 and increment month
//Else if month is 2, and if day is greater than 28.
//Set day equal to day minus 28 and increment month by 1
//Make an if statement that if month is greater than 12, set month equal to month minus 12 and increment year by 1
Date Date::operator+(int days) {

	for (int i = 0; i < days; i++) {
		day++;
		string typeDay = MysteryMachine::getDayOfWeek(*this);

   	if (typeDay == "Saturday") {
      	day += 2;
   	}
   	else if (typeDay == "Sunday") {
      	day += 1;
   	}

		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
     		if (day > 31) {
         	day = day - 31;
         	++month;
      	}
   	}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
      	if (day > 30) {
         	day = day - 30;
         	++month;
      	}
  		}
  		else if (month == 2) {
      	if (day > 28) {
         	day = day - 28;
         	++month;
      	}
  		}
   	if (month > 12) {
      	month = month - 12;
      	++year;
   	}
	}


	return *this;
}

//Define the overloaded operator minus with the parameter days
//Make a for loop with int i is 0, i loop while less than days, increment i
//in the for loop post increment days and create a string typeDay that calls MysteryMachine to get Day of the week
//If typeDay is Saturday, minus private variable day by 1
//if typeDay is Sunday, minus private variable day by 2
//Make an if else statement that if month is 1, 3, 5, 7, 8, 10, 12 and if day is less than 1
//set day equal to 31 and decrement month
//else if month is 4, 6, 9, or 11, and if day is less than 1,
//Set day equal 30 and decrement month
//Else if month is 2, and if day is less than 1.
//Set day equal to 28 and decrement month by 1
//Make an if statement that if month is less than 1, set month equal to 12 and decrement year by 1
Date Date::operator-(int days) {
	 for (int i = 0; i < days; i++) {
      day--;
      string typeDay = MysteryMachine::getDayOfWeek(*this);

      if (typeDay == "Saturday") {
         day -= 1;
      }
      else if (typeDay == "Sunday") {
         day -= 2;
      }

      if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
         if (day < 1) {
            day = 31;
            --month;
         }
      }
      else if (month == 4 || month == 6 || month == 9 || month == 11) {
         if (day < 1) {
            day = 30;
            --month;
         }
      }
      else if (month == 2) {
         if (day < 1) {
            day = 28;
            --month;
         }
      }
      if (month < 1) {
         month = 12;
         --year;
      }
   }
   return *this;
}

//Define the overloaded operator for preincrement
//In the overloaded preincrement operator, post increment days and create a string typeDay that calls MysteryMachine to get Day of the week
//If typeDay is Saturday, add private variable day by 2,
//if typeDay is Sunday, add private variable day by 1
//Make an if else statement that if month is 1, 3, 5, 7, 8, 10, 12 and if day is greater than 31,
//set day equal to day minus 31 and increment month
//else if month is 4, 6, 9, or 11, and if day is greater than 30,
//Set day equal to day minus 30 and increment month
//Else if month is 2, and if day is greater than 28.
//Set day equal to day minus 28 and increment month by 1
//Make an if statement that if month is greater than 12, set month equal to month minus 12 and increment year by 1
Date Date::operator++(void) {
   day++;
	string typeDay = MysteryMachine::getDayOfWeek(*this);

	if (typeDay == "Saturday") {
		day += 2;
	}
	else if (typeDay == "Sunday") {
		day += 1;
	}

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
   	if (day > 31) {
      	day = day - 31;
         ++month;
      }
   }

  else if (month == 4 || month == 6 || month == 9 || month == 11) {
      if (day > 30) {
         day = day - 30;
         ++month;
      }
  }
  else if (month == 2) {
      if (day > 28) {
         day = day - 28;
         ++month;
      }
  }
      
	if (month > 12) {
   	month = month - 12;
      ++year;
   }

	return *this;
}

//Define the overloaded operator postfix increment
//Create a date object named temp equal to the instance of the class
//preincrement the instance of the class use ++(*this)
//Return the temp object
Date Date::operator++(int) {
	Date temp = *this;
	
	++(*this);

	return temp;
}

//Define the overloaded operator for predecrement
//In the overloaded operator for pre decrement, post decrement days and create a string typeDay that calls MysteryMachine to get Day of the week
//If typeDay is Saturday, minus private variable day by 1
//if typeDay is Sunday, minus private variable day by 2
//Make an if else statement that if month is 1, 3, 5, 7, 8, 10, 12 and if day is less than 1
//set day equal to 31 and decrement month
//else if month is 4, 6, 9, or 11, and if day is less than 1,
//Set day equal 30 and decrement month
//Else if month is 2, and if day is less than 1.
//Set day equal to 28 and decrement month by 1
//Make an if statement that if month is less than 1, set month equal to 12 and decrement year by 1
Date Date::operator--(void) {
   day--;
	string typeDay = MysteryMachine::getDayOfWeek(*this);

      if (typeDay == "Saturday") {
         day -= 1;
      }
      else if (typeDay == "Sunday") {
         day -= 2;
      }

      if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
         if (day < 1) {
            day = 30;
            --month;
         }
      }
      else if (month == 4 || month == 6 || month == 9 || month == 11) {
         if (day < 1) {
            day = 29;
            --month;
         }
      }
      else if (month == 2) {
         if (day < 1) {
            day = 27;
            --month;
         }
      }
      if (month < 1) {
         month = 12;
         --year;
      }

   return *this;
}

//Define the overloaded operaor for post decrement
//Create a date object named temp
//Set temp equal to the instance of this class and predecrement the instance of this class
//Then, return the object temp
Date Date::operator--(int) {
	Date temp = *this;

   --(*this);

   return temp;
}

