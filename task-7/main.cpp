#include <iostream>
#include <vector>

using namespace std;

class ShopItem {
    public:
        string Name;
        string Type;
        int price;
        int damage;
        string Role;
};

ShopItem CreateShopItem(string name, string type, int price, int damage, string role) {
    ShopItem shopItem;

    shopItem.Name = name;
    shopItem.Type = type;
    shopItem.price = price;
    shopItem.damage = damage;
    shopItem.Role = role;

    return shopItem;
}

class Player {
    public:
        string Name;
        string ItemName = "none";
        int damage;
        string Role;
};


int main(int argc, char* argv[])
{
    const int amountOfPlayers = 3;
    int coinAmount = 100;
    int tempSelect = 0;

    vector<Player> curPlayers;

    Player Player1;
    curPlayers.push_back(Player1);
    curPlayers.push_back(Player1);
    curPlayers.push_back(Player1);

    for (int i = 0; i < amountOfPlayers; i++) {
        cout << "Player #" << i+1 << " enter your name: ";
        cin >> curPlayers[i].Name;
    }
    

    for (int i = 0; i < curPlayers.size(); i++) {
        cout << "Welcome " << curPlayers[i].Name<< endl;
    }

    cout << "Welcome to the shop, at the moment you all have " << coinAmount << " coins." << endl;

    // Creating the shop

    vector<ShopItem> shopVec;
    ShopItem shop;

    shop = CreateShopItem("Great Sword", "Sword", 40, 100, "Knight");
    shopVec.push_back(shop);

    shop = CreateShopItem("Scimitar", "Sword", 35, 75, "Knight");
    shopVec.push_back(shop);

    shop = CreateShopItem("Dagger", "Sword", 10, 35, "Knight");
    shopVec.push_back(shop);

    shop = CreateShopItem("Longbow", "Bow", 20, 55, "Archer");
    shopVec.push_back(shop);

    shop = CreateShopItem("Crossbow", "Bow", 40, 100, "Archer");
    shopVec.push_back(shop);

    shop = CreateShopItem("Rusty spear", "Spear", 10, 35, "Spearman");
    shopVec.push_back(shop);

    shop = CreateShopItem("Iron spear", "Spear", 20, 65, "Spearman");
    shopVec.push_back(shop);

    for (int i = 0; i < curPlayers.size(); i++) {

        for (int b = 0; b < shopVec.size(); b++) {
            cout << b << ". " << shopVec[b].Name << "[" << shopVec[b].price << " coins, " << shopVec[b].damage << " damage]" << endl;
        }

        while (curPlayers[i].ItemName == "none") {
            cout << "You have " << coinAmount << " coins" << endl;
            cout << curPlayers[i].Name << " Please enter the weapon you would like to buy: ";
            cin >> tempSelect;

            if (tempSelect <= shopVec.size()-1 && tempSelect >= 0 && coinAmount >= shopVec[tempSelect].price) {
                curPlayers[i].ItemName = shopVec[tempSelect].Name;
                curPlayers[i].Role = shopVec[tempSelect].Role;
                curPlayers[i].damage = shopVec[tempSelect].damage;
                coinAmount -= shopVec[tempSelect].price;
                shopVec.erase(shopVec.begin()+tempSelect);
                cout << curPlayers[i].Name << " You are now a " << curPlayers[i].Role << " with a " << curPlayers[i].ItemName << " and you do " << curPlayers[i].damage << " damage" << endl;
            }
            else {
                cerr << "This is not a valid shop item or you cannot afford it" << endl;
            }
        }
    }

    return 0;
}