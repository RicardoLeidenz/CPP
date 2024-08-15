
/*
Ricardo Leidenz
Project: Simple Withdrawing System
*/
#include <iostream>
#include <string>


bool Withdraw(double &balance, int transaction);
int BankTransaction(std:: string purchase); 

int main()
{
    double balance = 100.00;
    std::string purchase = "Enter the amount of the item to purchase: ";

    std::cout << "Initial Balance: " << balance << std::endl;

    if( ! Withdraw(balance, BankTransaction(purchase) ) )
        std::cout << "Account Overdrawn - You're in the red\n";
    else
        std::cout << "You're still in the black\n";


    std::cout << "Final Balance: " << balance << std::endl;
    
    return 0;
}
bool Withdraw(double &balance, int transaction){
	balance -= transaction;
	if (balance >= 0) return true;
	else return false;
}
int BankTransaction(std::string purchase){
	int ammount;
	std :: cout << purchase;
	std :: cin >> ammount;
	return ammount;
}
