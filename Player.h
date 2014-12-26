#pragma once
#include <string>
using namespace std;
class Player
{
private:
	string name;
	char symbol;
public:
	Player();
	void setPlayerName(string);
	void setPlayerSymbol(char);
	string getPlayerName();
	char getPlayerSymbol();
};
