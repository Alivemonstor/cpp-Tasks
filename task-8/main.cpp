#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>

using namespace std;


class Items {
	public:
		string name = "Empty";
		string description = "Nothing";
		int quantity = 0;
};


Items AddItem(string name, string desc, int quant) {
	Items invItem;

	invItem.name = name;
	invItem.description = desc;
	invItem.quantity = quant;

	return invItem;
}

vector<Items> itemSelection;

void setItem(vector<Items>& inventory) {
	int itemSelect;

	cout << "Please Pick an item : " << endl;

	for (int i = 0; i < itemSelection.size(); i++)
	{
		cout << itemSelection[i].name << endl;
	}

	cin >> itemSelect;

	if (cin.fail()) {
		cerr << "Please enter a number" << endl;
		cin.ignore(numeric_limits<streamsize>::max());
		return;
	}
}



void help(vector<Items>& inventory) {
	cout << "Here are a list of all of the commands: " << endl;

	map<string, function<void(vector<Items>& inventory)>> func_list{
		{"help", help},
		{"AddItem", setItem},
	};

	for (auto const& [key, val] : func_list)
	{
		cout << key << endl;
	}
};




int main(int argc, char* argv[])
{
	itemSelection.push_back(AddItem("Shield", "A strong shield", 1));
	itemSelection.push_back(AddItem("Potion", "A strength potion", 1));
	itemSelection.push_back(AddItem("Gloves", "Leather Gloves", 1));

	map<string, function<void(vector<Items>& inventory)>> func_list{
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

	while (true) {
		commandInput = "";
		cout << "What would you like to do? Type help for a list of all of the commands!" << endl;
		cin >> commandInput;

		if (cin.fail() || func_list.find(commandInput) == func_list.end()) {
			cerr << "Please enter a valid command" << endl;
		}

		if (func_list.find(commandInput) != func_list.end()) {
			func_list[commandInput](inventory);
		}
	}


    return 0;
}