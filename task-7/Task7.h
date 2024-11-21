#pragma once
#include <string>



class ShopItem {
public:
    std::string name;
    std::string type;
    int price;
    int damage;
    std::string role;
public:
	ShopItem() {
		name = "none";
		type = "none";
		price = 0;
		damage = 0;
		role = "none";
	}
    ShopItem (const std::string& inName, const std::string& inType, int inPrice, int inDamage, const std::string& inRole) {

        name = inName;
        type = inType;
        price = inPrice;
        damage = inDamage;
        role = inRole;
	}
};

class Player {
public:
    std::string Name;
    std::string ItemName = "none";
    int damage;
    std::string Role;
};


