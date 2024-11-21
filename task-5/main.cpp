#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>


int main(int argc, char* argv[])
{
    std::string userInput;
    bool hasFound = true;

    std::cout << "Enter a string: ";

    std::getline(std::cin, userInput);

    for (char c : userInput)
    {
        if (!isalpha(static_cast<unsigned char>(c)) && !isspace(static_cast<unsigned char>(c)) && c != '.' && c != '!' && c != '?') {
            std::cerr << "This string contains a non alphabetical character";
            return 0;
        }
    }
    transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);
    std::cout << "Upper Case: " << userInput << std::endl;

    transform(userInput.begin(), userInput.end(), userInput.begin(), tolower);
    std::cout << "Lower Case: " << userInput << std::endl;

    std::cout << "Sentence Casing: ";
    for (char c : userInput)
    {

		if (isalpha(static_cast<unsigned char>(c)) && hasFound)
		{
            std::cout << char(toupper(c));
			hasFound = false;
		}
		else
		{
            std::cout << c;
		}

        if (c == '.' || c == '!' || c == '?')
        {
            hasFound = true;
        }
	}
    std::cout << std::endl;

    std::cout << "Alternate Case: ";
    size_t index = 0;

    for (char c : userInput)
    {
        if (index % 2 == 0)
        {
            std::cout << char(isupper(static_cast<unsigned char>(c)) ? tolower(c) : toupper(c));
        }
        else
        {
            std::cout << c;
        }

        if (isalpha(static_cast<unsigned char>(c))) {
            index++;
        }
    }


    return 0;
}