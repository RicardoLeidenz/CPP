/*
Ricardo Leidenz
Project: House real estate summary.
Summary: The program takes two inputs, current price and last month's price (both integers). 
Then, outputs a summary listing the price, the change since last month, and the estimated monthly mortgag
*/
#include <iostream>

int main() 
{
   int currentPrice = 0;
   int lastMonthsPrice = 0;
   
   /* Type your code here. */
   std :: cout << "Enter house's current price: ";
   std :: cin >> currentPrice;
   std :: cout << "Enter house's last months price: ";
   std :: cin >> lastMonthsPrice;
   std :: cout << "This house is $" << currentPrice << ". The change is $" << (currentPrice -lastMonthsPrice) << " since last month." << std :: endl;
   std :: cout << "The estimated monthly mortgage is $" << ((currentPrice *0.051)/12) << "." << std :: endl;
   
   return 0;
}

