#include <iostream>
#include <vector>

using namespace std;

class TheShop {
    public:
        string iName;
        string iType;
        int price;
        int damage;
        string cRole;
};

class CurrentPlayers {
    public:
        string pName = "larry";
        int selectedWeapon = 8;
};


int main(int argc, char* argv[])
{
    const int amountOfPlayers = 3;
    int coinAmount = 100;

    vector<CurrentPlayers> curPlayers;

    CurrentPlayers Player1;
    CurrentPlayers Player2;
    CurrentPlayers Player3;
    curPlayers.push_back(Player1);
    curPlayers.push_back(Player2);
    curPlayers.push_back(Player3);

    for (int i = 0; i < amountOfPlayers; i++) {
        cout << "Player #" << i+1 << " enter your name: ";
        cin >> curPlayers[i].pName;
    }
    

    for (int i = 0; i < curPlayers.size(); i++) {
        cout << "Welcome " << curPlayers[i].pName<< endl;
    }

    cout << "Welcome to the shop, at the moment you all have " << coinAmount << " coins.Spend wisely!" << endl;

    // Creating the shop

    vector<TheShop> shopVec;

    TheShop shopItem1;
    shopItem1.iName = "Great Sword";
    shopItem1.iType = "Sword";
    shopItem1.price = 40;
    shopItem1.damage = 100;
    shopItem1.cRole = "Knight";
    shopVec.push_back(shopItem1);

    TheShop shopItem2;
    shopItem2.iName = "Scimitar";
    shopItem2.iType = "Sword";
    shopItem2.price = 35;
    shopItem2.damage = 75;
    shopItem2.cRole = "Knight";
    shopVec.push_back(shopItem2);

    TheShop shopItem3;
    shopItem3.iName = "Dagger";
    shopItem3.iType = "Sword";
    shopItem3.price = 10;
    shopItem3.damage = 35;
    shopItem3.cRole = "Knight";
    shopVec.push_back(shopItem3);


    TheShop shopItem4;
    shopItem4.iName = "Longbow";
    shopItem4.iType = "Bow";
    shopItem4.price = 20;
    shopItem4.damage = 55;
    shopItem4.cRole = "Archer";
    shopVec.push_back(shopItem4);

    TheShop shopItem5;
    shopItem5.iName = "Crossbow";
    shopItem5.iType = "Bow";
    shopItem5.price = 40;
    shopItem5.damage = 100;
    shopItem5.cRole = "Archer";
    shopVec.push_back(shopItem5);

    TheShop shopItem6;
    shopItem6.iName = "Rusty spear";
    shopItem6.iType = "Spear";
    shopItem6.price = 10;
    shopItem6.damage = 35;
    shopItem6.cRole = "Spearman";
    shopVec.push_back(shopItem6);

    TheShop shopItem7;
    shopItem7.iName = "Iron spear";
    shopItem7.iType = "Spear";
    shopItem7.price = 20;
    shopItem7.damage = 65;
    shopItem7.cRole = "Spearman";
    shopVec.push_back(shopItem7);

    for (int i = 0; i < shopVec.size(); i++) {
        cout << i << ". " << shopVec[i].iName << "[" << shopVec[i].price << " coins, " << shopVec[i].damage << " damage]" << endl;
    }

    //for (int i = 0; i < curPlayers.size(); i++) {
    //    while (curPlayers[i].selectedWeapon == 8) {

    //    }
    //}

    return 0;
}