#include "Input.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "Board.h"
using namespace std;

Input::Input()
{
	int num;
	cout << "***********   Welcome to Tic Tac Toe   ********\n\n";
	do{
		cout << "How many players are going to play? (2-5) ";
		cin >> num;
	} while (num < 1 || num > 5);
	numPlayers = num;
	cout << endl;
}

void Input::playersInfo(Player *players){
	string name;
	char symbol;
	for (int i = 0; i < numPlayers; i++){
		switch (i)
		{
		case 0:
			cout << "Enter first player's name: ";
			break;
		case 1:
			cout << "Enter second player's name: ";
			break;
		case 2:
			cout << "Enter third player's name: ";
			break;
		default:
			cout << "Enter" << i + 1 << "th player's name: ";
			break;
		}
		cin >> name;
		players[i].setPlayerName(name);

		cout << "Hello " << players[i].getPlayerName() << endl;
		do
		{
			cout << "What would you like your symbol to be? ";
			cin >> symbol;
			if(symbol == '.') cout << "'.' Is not allowed\n";
			
		} while (symbol == '.');

		//cout << "What would you like your symbol to be? ";
		//cin >> symbol;
		players[i].setPlayerSymbol(symbol);
		cout << endl;
	}
}

void Input::boardInfo(int &boardWidth, int &boardHeight, int &markersWin){
	cout << "How wide would you like your board to be? (3-10) ";
	cin >> boardWidth;
	cout << "How high would you like your board to be? (3-10) ";
	cin >> boardHeight;
	cout << "How many markers do you need to win? ";
	cin >> markersWin;
}

void Input::InputTurns(Board &board, Player player, char &symbol){
	//x = col,  y = row;
	int xcoord, ycoord;
	board.printBoard();
	cout << player.getPlayerName() << "'s Turn!\n";
	do
	{
		cout << "Enter (X,Y) coordinates: ";
		cin >> xcoord >> ycoord;
		symbol = player.getPlayerSymbol();
	} while (!board.modifyBoard(xcoord, ycoord, symbol));

}

int Input::getnumPlayers(){
	return numPlayers;
}
