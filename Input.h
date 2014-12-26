#pragma once
#include "Board.h"
#include "Player.h"
class Input
{
private:
	int numPlayers;
public:
	Input();
	void playersInfo(Player *players);
	void boardInfo(int &boardWidth, int &boardHeight, int &markersWin);
	void InputTurns(Board &board, Player player, char &symbol);
	int getnumPlayers();
};
