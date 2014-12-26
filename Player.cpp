#include "Player.h"


Player::Player()
{
	this->name = "unknown";
}

void Player::setPlayerName(string name){
	this->name = name;
}

void Player::setPlayerSymbol(char symbol){
	this->symbol = symbol;
}

string Player::getPlayerName(){
	return name;
}

char Player::getPlayerSymbol(){
	return symbol;
}
