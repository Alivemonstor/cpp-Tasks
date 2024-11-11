#include <iostream>
#include "Vector2.h"
#include <functional>
#include <sstream>
#include <map>
#include <vector>
#include <numbers>

using namespace std;

void Distance() {
	float distInput;
	Vector2 vector1;
	vector<Vector2> Vec;

	Vec.push_back(vector1);
	Vec.push_back(vector1);


	for (auto& val : Vec) {
		cout << "Please type X" << endl;
		cin >> distInput;

		while (!cin.good()) {
			cerr << "Please enter a number." << endl;

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please type x" << endl;

			cin >> distInput;
		}
		val.x = distInput;


		cout << "Please type Y" << endl;

		cin >> distInput;

		while (!cin.good()) {
			cerr << "Please enter a number." << endl;

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please type y" << endl;

			cin >> distInput;
		}

		val.y = distInput;

	}


	float calcDist = Vector2::Distance(Vec[0], Vec[1]);
	cout << calcDist << endl;

}

void FOVCheck() {
	float FOVInput;

	Vector2 vector1;
	vector<Vector2> Vec;

	Vec.push_back(vector1);
	Vec.push_back(vector1);


	for (auto& val : Vec) {
		cout << "Please type X" << endl;
		cin >> FOVInput;


		while (!cin.good()) {
			cerr << "Please enter a number." << endl;

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please type x" << endl;

			cin >> FOVInput;
		}


		val.x = FOVInput;
		cout << "[" << val.x << ", ]" << endl;

		cout << "Please type Y" << endl;

		cin >> FOVInput;

		while (!cin.good()) {
			cerr << "Please enter a number." << endl;

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please type y" << endl;

			cin >> FOVInput;
		}

		val.y = FOVInput;
		cout << "[" << val.x << "," << val.y << "]" << endl;

	}

	cout << "Please type FOV Direction" << endl;
	Vector2 FOVRDirection;


		cout << "Please type X" << endl;
		cin >> FOVInput;

		while (!cin.good()) {
			cerr << "Please enter a number." << endl;

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please type x" << endl;

			cin >> FOVInput;
		}
		FOVRDirection.x = FOVInput;


		cout << "Please type Y" << endl;

		cin >> FOVInput;

		while (!cin.good()) {
			cerr << "Please enter a number." << endl;

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please type y" << endl;

			cin >> FOVInput;
		}

		FOVRDirection.y = FOVInput;





	FOVRDirection.Normalize();


	Vector2 HowTo = Vec[0] - Vec[1];


	HowTo.Normalize();

	cout << HowTo.x << HowTo.y << endl;

	float FOV = acos(Vector2::Dot(FOVRDirection, HowTo));

	float finalAngle = FOV * 180 / numbers::pi_v<float>;


	if (finalAngle >= 0.0f + 45.0f || finalAngle  <= 180.0f - 45.0f) {
		cout << "this man got seen yk" << finalAngle << endl;
	}
	else {
		cout << "he aint see him" << finalAngle << endl;
	}
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

		if (cin.fail() || !commands.contains(commandInput)) {
			cerr << "Please enter a valid command";
		}
		else
		{
			commands[commandInput]();
		}
	}


    return 0;
}