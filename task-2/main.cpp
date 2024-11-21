#include <iostream> 
#include <windows.h>



int main(int argc, char* argv[])
{
    std::string PlayerName;
	std::string PlayerUsername;
	std::string PlayerClan;
    unsigned int PlayerXP;
	unsigned int CurrentLevel;


    std::cout << "Enter your name: ";
    std::cin >> PlayerName; 
	std::cout << "Enter your username: ";
	std::cin >> PlayerUsername;
	std::cout << "Enter your clan: ";
	std::cin >> PlayerClan;
	std::cout << "Enter your XP: ";
	std::cin >> PlayerXP;
	CurrentLevel = PlayerXP / 100; // 100 xp per level getting it down to single number to see level

	std::cout << "Your name is: " << PlayerName << " and your in-game-name is [" << PlayerClan << "]" << PlayerUsername << std::endl;
	std::cout << "and your level is " << CurrentLevel << std::endl;
	std::cout << "You need " << ((CurrentLevel+1) * 100) - PlayerXP << " more XP to level up" << std::endl;


    return 0;
}