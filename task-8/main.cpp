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

vector<Items> itemSelection;

void SetItem(vector<Items>& inventory) {
	int itemSelect;

	cout << "Please Pick an item : " << endl;

	for (int i = 0; i < itemSelection.size(); i++)
	{
		cout << i << "." << itemSelection[i].name << endl;
	}

	cin >> itemSelect;


	while (!cin.good() || itemSelect > itemSelection.size() - 1){
		cerr << "Please enter a number." << endl;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please Pick an item : " << endl;

		for (int i = 0; i < itemSelection.size(); i++)
		{
			cout << i << "." << itemSelection[i].name << endl;
		}

		cin >> itemSelect;
	}

	//Picking inventory slot

	int itemSelectNew = 0;
	cin.clear();


	cout << "Please Pick an inventory slot: " << endl;

	for (int i = 0; i < inventory.size(); i++)
	{
		cout << i << "." << inventory[i].name << endl;
	}

	cin >> itemSelectNew;

	while (!cin.good() || itemSelectNew > inventory.size() - 1) {
		cerr << "Please enter a number." << endl;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please Pick an inventory slot: " << endl;

		for (int i = 0; i < inventory.size(); i++)
		{
			cout << i << "." << inventory[i].name << endl;
		}

		cin >> itemSelectNew;
	}

	if (inventory[itemSelectNew].name == itemSelection[itemSelect].name) {
		inventory[itemSelectNew].quantity += itemSelection[itemSelect].quantity;
	}
	else {
		inventory[itemSelectNew].name = itemSelection[itemSelect].name;
		inventory[itemSelectNew].description = itemSelection[itemSelect].description;
		inventory[itemSelectNew].quantity = itemSelection[itemSelect].quantity;
	}

	cin.clear();
}

void ShowAll(vector<Items>& inventory) {
	cout << "Here's what your inventory currently has: " << endl;

	for (int i = 0; i < inventory.size(); i++) {
		cout << "Slot " << i << ": " << inventory[i].name << endl;
	}

};

void View(vector<Items>& inventory) {
	int itemSelect;

	cout << "Please Pick an inventory slot : " << endl;

	for (int i = 0; i < inventory.size(); i++)
	{
		cout << i << "." << inventory[i].name << endl;
	}

	cin >> itemSelect;


	while (!cin.good() || itemSelect > inventory.size()-1) {
		cerr << "Please enter a slot number." << endl;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please Pick an inventory slot : " << endl;

		for (int i = 0; i < inventory.size(); i++)
		{
			cout << i << "." << inventory[i].name << endl;
		}

		cin >> itemSelect;
	}

	cout << "Name: " << inventory[itemSelect].name << endl;
	cout << "Description: " << inventory[itemSelect].description << endl;
	cout << "Quantity: " << inventory[itemSelect].quantity << endl;

};

void ShowAllItems(vector<Items>& inventory) {
	cout << "Here's what items you can pick from: " << endl;

	for (int i = 0; i < itemSelection.size(); i++) {
		cout << "Slot " << i << ": " << itemSelection[i].name << endl;
	}

};

void Help(vector<Items>& inventory) {
	cout << "Here are a list of all of the commands: " << endl;

	map<string, function<void(vector<Items>& inventory)>> func_list{
		{"help", Help},
		{"set", SetItem},
		{"show_all", ShowAll},
		{"view", View},
		{"items", ShowAllItems},
		{"exit", ShowAllItems},
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
		{"help", Help},
		{"set", SetItem},
		{"show_all", ShowAll},
		{"view", View},
		{"items", ShowAllItems},

	};

	vector<Items> inventory;
    int inventorySlots;

	cout << "How many inventory slots do you want?" << endl;
	cin >> inventorySlots;

	while(!cin.good() || inventorySlots > 16) 
	{
		cerr << "Please enter a number." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "How many inventory slots do you want?" << endl;
		cin >> inventorySlots;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < inventorySlots; i++) {
		inventory.push_back(AddItem("Empty", "None", 0));
	}

	while (true) 
	{
		string commandInput = {};
		cout << "What would you like to do? Type help for a list of all of the commands!\n";
		getline(cin, commandInput);

		if (commandInput == "exit") {
			break;
		};

		if (cin.fail() || func_list.find(commandInput) == func_list.end()) {
			cerr << "Please enter a valid command" << endl;
		}

		if (func_list.find(commandInput) != func_list.end()) {
			func_list[commandInput](inventory);
		}
	}

    return 0;
}