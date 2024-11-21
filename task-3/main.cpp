#include <iostream>
#define ERROR_STRING_INPUT 2




int main(int argc, char* argv[])
{
    float number = 0.0f;
	std::string output = "Invalid input, please input a number!";


	std::cout << "Enter a number: ";
	std::cin >> number;

	if (std::cin.fail()) {
		std::cerr << output << std::endl;
		return ERROR_STRING_INPUT;
	}

	std::cout << "neg("<< number <<"): " << -number << std::endl;
	std::cout << "abs(" << number << "): " << abs(number) << std::endl;
	std::cout << "pow2(" << number << "): " << pow(number, 2) << std::endl;
	std::cout << "pow3(" << number << "): " << pow(number, 3) << std::endl;
	std::cout << "sqrt(" << number << "): " << sqrt(abs(number)) << std::endl;
	std::cout << "floor(" << number << "): " << floorf(number) << std::endl;
	std::cout << "ceil(" << number << "): " << ceilf(number) << std::endl;
	std::cout << "round(" << number << "): " << roundf(number) << std::endl;


    return 0;
}