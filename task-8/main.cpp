#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>

using namespace std;


class Item {
public:
	string name;
	string description;
	int quantity;
public:
	Item(const string& inName, const string& inDescription, const int& inQuantity)
		: name(inName)
		, description(inDescription)
		, quantity(inQuantity)
	{}
};


vector<Item> itemSelection;

void SetItem(vector<Item>& inventory) {
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

void ShowAll(vector<Item>& inventory) {
	cout << "Here's what your inventory currently has: " << endl;

	for (int i = 0; i < inventory.size(); i++) {
		cout << "Slot " << i << ": " << inventory[i].name << endl;
	}

};

void View(vector<Item>& inventory) {
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

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Name: " << inventory[itemSelect].name << endl;
	cout << "Description: " << inventory[itemSelect].description << endl;
	cout << "Quantity: " << inventory[itemSelect].quantity << endl;

};

void ShowAllItems(vector<Item>& inventory) {
	cout << "Here's what Item you can pick from: " << endl;

	for (int i = 0; i < itemSelection.size(); i++) {
		cout << "Slot " << i << ": " << itemSelection[i].name << endl;
	}

};

void Clear(vector<Item>& inventory) {
	cout << "Clearing the inventory" << endl;

	int inventorySlots = inventory.size();


	inventory.clear();

	for (int i = 0; i < inventorySlots; i++) {
		inventory.push_back(Item("Empty", "None", 0));
	}
};

void Restart(vector<Item>& inventory) {
	cout << "Restarting" << endl;
	inventory.clear();

	int inventorySlots;

	cout << "How many inventory slots do you want?" << endl;
	cin >> inventorySlots;

	while (!cin.good() || inventorySlots > 16)
	{
		cerr << "Please enter a number." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "How many inventory slots do you want?" << endl;
		cin >> inventorySlots;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < inventorySlots; i++) {
		inventory.push_back(Item("Empty", "None", 0));
	}
};

void SearchItem(vector<Item>& inventory) {
	string input;

	cout << "What do you want to search for?" << endl;
	cin >> input;

	while (!cin.good() || input.empty())
	{
		cerr << "Please enter a string." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "What do you want to search for?" << endl;
		cin >> input;
	}

	for (int i = 0; i < itemSelection.size(); i++)
	{
		string string = itemSelection[i].name;
		if (string.find(input) != string::npos) {
			cout << i << ". " << itemSelection[i].name << endl;
		}
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
};

int main(int argc, char* argv[])
{
	itemSelection.push_back(Item("Empty", "None", 0));
	itemSelection.push_back(Item("Shield", "A strong shield", 1));
	itemSelection.push_back(Item("Potion", "A strength potion", 1));
	itemSelection.push_back(Item("Gloves", "Leather Gloves", 1));

	map<string, function<void(vector<Item>& inventory)>> func_list{
		{"set", SetItem},
		{"show_all", ShowAll},
		{"view", View},
		{"items", ShowAllItems},
		{"clear", Clear},
		{"restart", Restart},
		{"search" , SearchItem},
	};

	auto help = [&func_list](vector<Item>& inventory)
	{
		cout << "Heres a list of all of the commands:" << endl;
		
		for (auto const& [key, val] : func_list)
		{
			cout << key << endl;
		}
	};

	func_list.emplace("help", help);

	vector<Item> inventory;
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
		inventory.push_back(Item("Empty", "None", 0));
	}

	while (true) 
	{
		cin.clear();

		string commandInput = {};
		cout << "What would you like to do? Type help for a list of all of the commands!\n";
		cin >> commandInput;

		if (commandInput == "exit") {
			cout << "Exiting" << endl;
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