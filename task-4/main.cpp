#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
	string word;

	cout << "Please Enter a string: ";
	getline(cin, word);

	if (word == "") {
		cerr << "Please input a string, cannot be empty!";
	}

	if (word.length() == 1) {
		cout << "+=-=-=+" << endl;
		cout << "|  " << word << "  |" << endl;
		cout << "+=-=-=+" << endl;
	}
	else {
		for (char c : word) {
			cout << "+=-=-=" << endl;
			cout << "|  " << c << endl;
			cout << "+=-=-=" << endl;
		}
	}

	return 0;

}