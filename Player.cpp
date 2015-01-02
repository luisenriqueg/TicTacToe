#include "Player.h"


Player::Player()
{
	m_name = "unknown";
}

void Player::setPlayerName(string name){
	m_name = name;
}

void Player::setPlayerSymbol(char symbol){
	m_symbol = symbol;
}

string Player::getPlayerName(){
	return name;
}

char Player::getPlayerSymbol(){
	return symbol;
}
