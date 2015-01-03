#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;
class Player
{
private:
	string m_name;
	char m_symbol;
public:
	Player();
	void setPlayerName(string);
	void setPlayerSymbol(char);
	string getPlayerName();
	char getPlayerSymbol();
};
#endif
