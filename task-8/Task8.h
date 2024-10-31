#pragma once
#include <string>

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