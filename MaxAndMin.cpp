/*
Ricardo Leidenz
Prtoject: Max and min numbers.
Summary: The program asks for 3 numbers, and outputs the largest and the smallest.
*/

#include <iostream>

using namespace std;

int LargestNumber(int, int, int);
int SmallestNumber(int, int, int);

int main() 
{
   int num1,num2,num3;
   
   std :: cin >> num1;
   std :: cin >> num2;
   std :: cin >> num3;
   
   std :: cout << "largest: " << LargestNumber(num1,num2,num3) << endl;
   std :: cout << "smallest: " << SmallestNumber(num1,num2,num3) << endl;

   return 0;
}

int LargestNumber(int num1, int num2, int num3){
   if ((num1 >= num2) && (num1 >= num3)) return num1;
   else if ((num2 >= num1) && (num2 >= num3)) return num2;
   else if ((num3 >= num1) && (num3 >= num2)) return num3;
}
int SmallestNumber(int num1, int num2, int num3){
   if ((num1 <= num2) && (num1 <= num3)) return num1;
   else if ((num2 <= num1) && (num2 <= num3)) return num2;
   else if ((num3 <= num1) && (num3 <= num2)) return num3;
}
