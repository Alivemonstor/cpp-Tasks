#include <iostream> 
#include <windows.h>

using namespace std;


int main(int argc, char* argv[])
{
    string PlayerName;
	string PlayerUsername;
    string PlayerClan;
    unsigned int PlayerXP;
	unsigned int CurrentLevel;


    cout << "Enter your name: ";
    cin >> PlayerName; 
	cout << "Enter your username: ";
	cin >> PlayerUsername;
	cout << "Enter your clan: ";
	cin >> PlayerClan;
	cout << "Enter your XP: ";
	cin >> PlayerXP;

	CurrentLevel = PlayerXP / 100; // 100 xp per level getting it down to single number to see level

	cout << "Your name is: " << PlayerName << " and your in-game-name is [" << PlayerClan << "]" << PlayerUsername << endl;
	cout << "and your level is " << CurrentLevel << endl;
	cout << "You need " << ((CurrentLevel+1) * 100) - PlayerXP << " more XP to level up" << endl;


    return 0;
}