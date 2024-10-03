#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    string userInput;
    bool hasFound = true;

	cout << "Enter a string: ";

    getline(cin, userInput);

    for (char c : userInput)
    {
        if (!isalpha(c) && !isspace(c) && c != '.' && c != '!' && c != '?') {
            cerr << "This string contains a non alphabetical character";
            return 0;
        }
    }
    transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);
    cout << "Upper Case: " << userInput << endl;

    transform(userInput.begin(), userInput.end(), userInput.begin(), tolower);
    cout << "Lower Case: " << userInput << endl;

    cout << "Sentence Casing: ";
    for (char c : userInput)
    {

		if (isalpha(c) && hasFound)
		{
            cout << char(toupper(c));
			hasFound = false;
		}
		else
		{
			cout << c;
		}

        if (c == '.' || c == '!' || c == '?')
        {
            hasFound = true;
        }
	}
	cout << endl;

    cout << "Alternate Case: ";
    size_t index = 0;

    for (char c : userInput)
    {
        if (index % 2 == 0)
        {
            cout << char(isupper(c) ? tolower(c) : toupper(c));
        }
        else
        {
            cout << c;
        }

        if (isalpha(c)) {
            index++;
        }
    }


    return 0;
}