#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>

using namespace std;


class Items {
	public:
		string name;
		string description;
		int quantity;
};

Items AddItem(string name, string desc, int quant) {
	Items invItem;

	invItem.name = name;
	invItem.description = desc;
	invItem.quantity = quant;

	return invItem;
}

void setItem(vector<Items>& inventory) {

}

void help() {
	cout << "Here are a list of all of the commands: " << endl;


};

int main(int argc, char* argv[])
{

	map<string, function<void(vector<Items>& inventory)>> func_list {
		{"help", help},
		{"AddItem", setItem},
	};

	vector<Items> inventory;
	vector<Items> itemShop;

    int inventorySlots;
	string commandInput;

	cout << "How many inventory slots do you want?" << endl;
	cin >> inventorySlots;

	if (cin.fail() || inventorySlots > 16) {
		cerr << "Please enter a number." << endl;
	}


	cout << "What would you like to do? Type help for a list of all of the commands!" << endl;
	cin >> commandInput;

	if (cin.fail() || func_list.find(commandInput) == func_list.end()) {
		cerr << "Please enter a valid command" << endl;
	}



    return 0;
}