#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
    string user_string;

    cout << "Please Enter a string: ";
    getline(cin, user_string);

    if (user_string.empty())
    {
        cerr << "Please input a string, cannot be empty!";
    }

    stringstream side_lines;
    stringstream middle_line;

    for (size_t index = 0; index < user_string.size(); index++)
    {

        side_lines << "+=-=-=";

        if (index != 0)
        {
            middle_line << "  ";
        }

        middle_line << "|  " << user_string[index];
    }

    side_lines << "+" << endl;
    middle_line << "  |" << endl;

    cout << side_lines.str();
    cout << middle_line.str();
    cout << side_lines.str();
    return 0;
}