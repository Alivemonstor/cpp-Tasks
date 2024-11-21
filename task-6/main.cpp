#include "main.h"
#include <map>
#include <vector>
#include <iostream>

int main(int argc, char* argv[])
{
    const int RNG = random(0, 100);
    int amountOfGuesses = 0;
    bool hasGuessed = false;
    int userGuess = 0;

    std::cout << RNG << std::endl;

    std::map<int, std::string> mp;
    mp[50] = "freezing";
    mp[35] = "colder";
    mp[25] = "cold";
    mp[15] = "warm";
    mp[10] = "warmer";
    mp[5] = "hot";
    mp[3] = "hotter";
    mp[1] = "boiling";


    while (true) {
        std::cout << "Please enter a guess: ";
        std::cin >> userGuess;

        if (std::cin.fail() || userGuess > 100 || userGuess < 0) {
            std::cerr << "Please enter a valid number between 0-100." << std::endl;
        }
        else {
            int diff = abs(userGuess - RNG);

            amountOfGuesses++;
            
            if (diff == 0) {
                std::cout << "Well done! The number was:" << RNG << " It took you " << amountOfGuesses << " guesses.";
                return 0;
            }


            for (auto const& [key, val] : mp)
            {
                if (key >= diff)
                {
                    std::cout << val << std::endl;
                    break;
                }
            }
        }
    }
}