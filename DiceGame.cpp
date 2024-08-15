#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int dieRoll();
void printDice(int die1, int die2);
std::string firstThrow(int sum);
std::string pointThrow(int sum, int point);

int main() {
	time_t seed = time(nullptr);
	srand(seed);
    
    // TODO: Roll 2 dice
    int die1 = dieRoll();
    int die2 = dieRoll();
    int sum = die1 + die2;
    int point = sum;
    // TODO: print dice roll values
    printDice(die1, die2);
    std::string game = firstThrow(sum); // TODO: first throw check
    std::cout << "\nGame Status: " << game;
    while( game != "WIN" && game != "LOSE") {
        // TODO: Roll 2 dice
        die1 = dieRoll();
        die2 = dieRoll();
        sum = die1 + die2;
        // TODO: print dice roll values
        printDice(die1, die2);
        game = pointThrow(sum, point); // TODO: point throw check
        std::cout << "\nGame Status: " << game;
    }
    return 0; 
}
int dieRoll() {
    return rand() % 6 + 1;
}
void printDice(int die1, int die2) {
    std::cout << "\nDie1: " << die1;
    std::cout << "\nDie2: " << die2;
    std::cout << "\t\tSum: " << die1+die2 << "\n";
}
std::string firstThrow(int sum) {
    if(sum == 7 || sum == 11)
        return "WIN";
    else if(sum == 2 || sum == 3 || sum == 12)
        return "LOSE";
    else 
        return " Point: " + std::to_string(sum) + "\n";
}
std::string pointThrow(int sum, int point) {
    if(sum == 7)
        return "LOSE";
    else if(sum == point)
        return "WIN";
    else
        return "Keep rolling for Point: " + std::to_string(point) + "\n";
}
