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
	return m_name;
}

char Player::getPlayerSymbol(){
	return m_symbol;
}
