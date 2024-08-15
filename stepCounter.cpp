/*
Ricardo Leidenz
Assignment: Max and min numbers.
Summary: Program asks the user to input the last 3 step counts from the last trhee workouts, and outputs the total miles and which day had the most and least steps.
*/

#include <iostream>
#include <iomanip>
//Function Declarations
double StepsToMiles(int, int, int);
int LargestNumber(int, int, int);
int SmallestNumber(int, int, int);

int main() 
{
   	int stepsDay1, stepsDay2, stepsDay3;
   	std :: cout << "Please input the step count for your last 3 workouts: ";
   	std :: cout << "\nDay one : ";
   	std :: cin >> stepsDay1;
   	std :: cout << "\nDay two : ";
   	std :: cin >> stepsDay2;
   	std :: cout << "\nDay three : ";
   	std :: cin >> stepsDay3;
   	
   	double milesWalked = StepsToMiles(stepsDay1, stepsDay2, stepsDay3); // we call the function to get the total miles 

	std :: cout << "\nYou walked a total of " << std :: fixed << std :: setprecision(2) << milesWalked << " miles in your last three workouts." << std :: endl;
   	std :: cout << "The most steps you've had in a day is: " << LargestNumber(stepsDay1, stepsDay2, stepsDay3) << " steps." << std :: endl; // We call the "LargestNumber" function to get the largest stepcount
   	std :: cout << "The least steps you've had in a day is: " << SmallestNumber(stepsDay1, stepsDay2, stepsDay3) << " steps." << std :: endl; // We call the "SmallestNumber" function to get the smallest stepcount

   return 0;
}

// Function Definitions

double StepsToMiles(int userSteps1, int userSteps2, int userSteps3) //We add the three numbers and divide them by 2000.00 to get the ammount of miles walked
{
   	double miles = (userSteps1 + userSteps2 + userSteps3) / 2000.00;
   	return miles;
}

int LargestNumber(int num1, int num2, int num3) //We compare the three numbers and return the largest
{
   	if ((num1 >= num2) && (num1 >= num3)) return num1;
   	else if ((num2 >= num1) && (num2 >= num3)) return num2;
   	else if ((num3 >= num1) && (num3 >= num2)) return num3;
}

int SmallestNumber(int num1, int num2, int num3) //We compare the three numbers and return the smallest
{
   	if ((num1 <= num2) && (num1 <= num3)) return num1;
   	else if ((num2 <= num1) && (num2 <= num3)) return num2;
   	else if ((num3 <= num1) && (num3 <= num2)) return num3;
}
