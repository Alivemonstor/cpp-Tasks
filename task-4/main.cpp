#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
    while (true) {
        std::string user_string;

        std::cout << "Please Enter a string: ";
        std::getline(std::cin, user_string);

        if (user_string.empty())
        {
            std::cerr << "Please input a string, cannot be empty!" << std::endl;
        }

        std::stringstream side_lines;
        std::stringstream middle_line;

        for (size_t index = 0; index < user_string.size(); index++)
        {

            side_lines << "+=-=-=";

            if (index != 0)
            {
                middle_line << "  ";
            }

            middle_line << "|  " << user_string[index];
        }

        side_lines << "+" << std::endl;
        middle_line << "  |" << std::endl;

        if (!user_string.empty())
        {
            std::cout << side_lines.str();
            std::cout << middle_line.str();
            std::cout << side_lines.str();
        }
    }
}