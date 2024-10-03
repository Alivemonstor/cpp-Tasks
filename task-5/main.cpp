#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    string userInput;

    getline(cin, userInput);

    for (char c : userInput)
    {
        if (!isalpha(c) && !isspace(c) && c != '.') {
            cerr << "This string contains a non alphabetical character";
            return 0;
        }
    }
    transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);
    cout << "Upper Case: " << userInput << endl;

    transform(userInput.begin(), userInput.end(), userInput.begin(), tolower);
    cout << "Lower Case: " << userInput << endl;

    cout << "Sentence Casing: ";



    return 0;
}