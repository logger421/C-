#include <iostream>

const std::string EXIT = "quit";

/* 
* function to check if given input string is a number 
*/
bool is_number(const std::string& toCheck);
/*
* function to check if credit card number is valid based on
* Luhn algorithm
*/
bool check_if_valid(const std::string& ccNumber);


// 3379513561108795 - valid
// 3479513561108795 - invalid

int main() {
    std::cout << "Welcome to check if my credit card number is valid program!\n";
    std::cout << "Please enter your credit card number:\n(or type \"quit\" to exit)\n: ";
    std::string credit_card_number;
    std::cin >> credit_card_number;

    while(true) {

        if( credit_card_number == EXIT || credit_card_number == "q" ) {
            std::cout << "Exiting from program...\n";
            break;
        }

        if( !is_number(credit_card_number) ) {
            std::cout << "Given number is not a credit card number\n";
            std::cout << "please enter a number:\n: ";
            std::cin >> credit_card_number;
            continue;
        }
        
        if( is_number(credit_card_number) ) {
            check_if_valid(credit_card_number) ? std::cout << "Your credit card number is valid\n" : std::cout << 
            "Your credit card number isn't valid\n";
            std::getchar();
            std::getchar();
            std::cout << "Please enter your credit card number:\n(or type \"quit\" to exit)\n: ";
            std::cin >> credit_card_number;
            continue;
        }
    }
    std::cout << "See you next time!\n";
}


bool is_number(const std::string& toCheck) {
    for(char const &c : toCheck)
        if(!std::isdigit(c))
            return false;
    return true;
}

bool check_if_valid(const std::string& ccNumber) {
    int len = ccNumber.length();
    int evenSum = 0;
    int oddSum = 0;
    int digit = 0;

    // multiply even positions by 2
    for( int i = 0; i < len; i++ ) {
        digit = (ccNumber[i] - 48);
        if( i % 2 == 0) {
            digit*=2;
            if( digit > 9 ) 
            digit = digit/10 + digit%10;
            evenSum += digit;
        } else {
            oddSum+=digit;
        }
    }
    return (evenSum + oddSum) % 10 == 0;
}