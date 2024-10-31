#pragma once
#include <string>

using namespace std;


class ShopItem {
public:
    string name;
    string type;
    int price;
    int damage;
    string role;
public:
	ShopItem() {
		name = "none";
		type = "none";
		price = 0;
		damage = 0;
		role = "none";
	}
    ShopItem (const string& inName, const string& inType, int inPrice, int inDamage, const string& inRole) {

        name = inName;
        type = inType;
        price = inPrice;
        damage = inDamage;
        role = inRole;
	}
};

class Player {
public:
    string Name;
    string ItemName = "none";
    int damage;
    string Role;
};


