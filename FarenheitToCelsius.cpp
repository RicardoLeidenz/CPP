/*
Ricardo Leidenz
Project: Given fahrenheit convert to celsius
*/
#include <iostream>
#include <string>

int main()
{
    double fahrenheit = 0.0;
    std :: cout << "Enter FAHRENHEIT: ";
    std :: cin >> fahrenheit;
    fahrenheit = (fahrenheit - 32) * 5/9;
    std :: cout << "Celsius: " << fahrenheit;
    return 0;
}
