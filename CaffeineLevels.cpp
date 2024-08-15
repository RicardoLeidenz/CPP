/*
Project: Caffeine levels.
Summary: Given caffeine amount (in mg) as input, output the caffeine level after 6, 12, and 24 hours.
*/
#include <iostream>
#include <iomanip>


int main() 
{
   double caffeineMg = 0.0;
   std :: cout << "Enter caffeine amount in mg: ";
   std :: cin >> caffeineMg;
   std :: cout << "After 6 hours: " << std :: fixed << std :: setprecision(2) << (caffeineMg / 2) << " mg" << std :: endl;
   std :: cout << "After 12 hours: " << std :: fixed << std :: setprecision(2) << (caffeineMg / 4)<< " mg" << std :: endl;
   std :: cout << "After 24 hours: " << std :: fixed << std :: setprecision(2) << (caffeineMg / 16) << " mg" << std :: endl;

   return 0;
}

