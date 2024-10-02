#include <iostream>
#define ERROR_STRING_INPUT 2
using namespace std;




int main(int argc, char* argv[])
{
    float number = 0.0f;
	string output = "Invalid input, please input a number!";


	cout << "Enter a number: ";
	cin >> number;

	if (cin.fail()) {
		cerr << output << endl;
		return ERROR_STRING_INPUT;
	}

	cout << "neg("<< number <<"): " << -number << endl;
	cout << "abs(" << number << "): " << abs(number) << endl;
	cout << "pow2(" << number << "): " << pow(number, 2) << endl;
	cout << "pow3(" << number << "): " << pow(number, 3) << endl;
	cout << "sqrt(" << number << "): " << sqrt(abs(number)) << endl;
	cout << "floor(" << number << "): " << floorf(number) << endl;
	cout << "ceil(" << number << "): " << ceilf(number) << endl;
	cout << "round(" << number << "): " << roundf(number) << endl;


    return 0;
}