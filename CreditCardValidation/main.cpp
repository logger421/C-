#include <iostream>

const std::string EXIT = "quit";

/* 
* function to check if given input string is a number 
*/
bool is_number(const std::string toCheck);

int main() {
    std::cout << "Welcome to check if my credit card number is valid program!\n";
    std::cout << "Please enter your credit card number:(or type \"quit\" to exit) ";
    std::string credit_card_number;
    std::cin >> credit_card_number;

    while(true) {

        if(credit_card_number == EXIT) {
            std::cout << "Exiting from program...\n";
            break;
        }

        if(!is_number(credit_card_number)) {
            std::cout << "Given number is not a credit card number\n";
            std::cout << "please enter a number: ";
            std::cin >> credit_card_number;
            continue;
        }
        
    }
    std::cout << "See you next time!\n";
}


bool is_number(const std::string toCheck) {
    for(char const &c : toCheck)
        if(!std::isdigit(c))
            return false;
    return true;
}