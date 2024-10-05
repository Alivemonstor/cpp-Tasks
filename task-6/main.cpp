#include "main.h"
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    const int RNG = random(0, 100);
    int amountOfGuesses = 0;
    bool hasGuessed = false;
    int userGuess = 0;

    cout << RNG << endl;

    map<int, string> mp;
    mp[50] = "freezing";
    mp[35] = "colder";
    mp[25] = "cold";
    mp[15] = "warm";
    mp[10] = "warmer";
    mp[5] = "hot";
    mp[3] = "hotter";
    mp[1] = "boiling";


    while (true) {
        cout << "Please enter a guess: ";
        cin >> userGuess;

        if (cin.fail() || userGuess > 100 || userGuess < 0) {
            cerr << "Please enter a valid number between 0-100." << endl;
        }
        else {
            int diff = abs(userGuess - RNG);

            amountOfGuesses++;
            
            if (diff == 0) {
                cout << "Well done! The number was:" << RNG << " It took you " << amountOfGuesses << " guesses.";
                return 0;
            }


            for (auto const& [key, val] : mp)
            {
                if (key >= diff)
                {
                    cout << val << endl;
                    break;
                }
            }
        }
    }
}