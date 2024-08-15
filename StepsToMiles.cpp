/*
Ricardo Leidenz
Project: Step Counter.
Summary: Program whose input is the number of steps, and whose output is the miles walked.
*/

#include <iostream>
#include <iomanip>

double StepsToMiles(int userSteps);

int main() 
{
   int userSteps;
   std :: cin >> userSteps;
   double milesWalked = StepsToMiles(userSteps);
   std :: cout << std :: fixed << std :: setprecision(2) << milesWalked << std :: endl;

   return 0;
}

double StepsToMiles(int userSteps){
   double miles = userSteps / 2000.00;
   return miles;
}
