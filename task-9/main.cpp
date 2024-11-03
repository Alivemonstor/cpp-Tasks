#include <iostream>
#include "Vector2.h"
#include <functional>
#include <sstream>
#include <map>

using namespace std;

void Distance() {
	float distInput;
	Vector2 vector1;
	Vector2 vector2;

	cout << "Please type x" << endl;
	cin >> distInput;

	while (!cin.good()) {
		cerr << "Please enter a number." << endl;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please type x" << endl;

		cin >> distInput;
	}

	vector1.x = distInput;

	cout << "Please type y" << endl;

	cin >> distInput;

	while (!cin.good()) {
		cerr << "Please enter a number." << endl;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please type y" << endl;

		cin >> distInput;
	}

	vector1.y = distInput;

	cout << "Please type x" << endl;
	cin >> distInput;

	while (!cin.good()) {
		cerr << "Please enter a number." << endl;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please type x" << endl;

		cin >> distInput;
	}

	vector2.x = distInput;

	cout << "Please type y" << endl;

	cin >> distInput;

	while (!cin.good()) {
		cerr << "Please enter a number." << endl;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please type y" << endl;

		cin >> distInput;
	}

	vector2.y = distInput;


	float calcDist = Vector2::Distance(vector1, vector2);
	cout << calcDist << endl;

}

void FOVCheck() {

}

int main(int argc, char* argv[])
{
    map<string, function<void()>> commands{
        {"distance", Distance},
        {"fov", FOVCheck},
    };

	auto help = [&commands](){
		cout << "Heres a list of all of the commands:" << endl;

		for (auto const& [key, val] : commands)
		{
			cout << key << endl;
		}
	};

	auto exit = [&commands](){
			cout << "Exiting" << endl;

			return 0;
	};

	commands.emplace("exit", exit);
	commands.emplace("help", help);

	while (true) {
		cin.clear();

		string commandInput;
		cout << "What mode would you like to choose, type help to see the commands!" << endl;
		cin >> commandInput;

		if (cin.fail() || !commands[commandInput]) {
			cerr << "Please enter a valid command";
		}
		else
		{
			commands[commandInput]();
		}
	}


    return 0;
}