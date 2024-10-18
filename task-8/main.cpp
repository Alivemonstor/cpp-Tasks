#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Inventory {
	public:
		string itemName;
		string itemDescription;
		int itemQuantity;
};
int main(int argc, char* argv[])
{
    int inventorySlots;

	cout << "How many inventory slots do you want?" << endl;
	cin >> inventorySlots;

	if (!isdigit(inventorySlots)) {
		cerr << "Please enter a number." << endl;
	}

	vector<string> inventory(inventorySlots);




    return 0;
}