#include <iostream>
#include <string>
#include "Player.h"
#include "Board.h"
#include "Input.h"
using  namespace std;
int main(){

	const int maxNumPlayers = 10;
	Player players[maxNumPlayers];

	Input inputGame; //Welcome and get numofplayers
	
	inputGame.playersInfo(players); //Names & Symbols
	
	bool isOver = false;  //Allow infinite plays/matches
	bool isWon = false;   //know which player wins the round
	char symbol;
	Player player; //current player
	while (!isOver){ //Play another match
		int boardWidth = 3, boardHeight = 3, markersWin = 3;
		//Ask boardsize and number of marks to win:
		inputGame.boardInfo(boardWidth, boardHeight, markersWin);

		Board board;
		board.setBoardSize(boardWidth, boardHeight);
		board.initBoard(); //Initialize board with it size, blank = '.'

		int numOfPlayers = inputGame.getnumPlayers();
		while (!isWon){
			for (int i = 0; i < numOfPlayers; i++){
				//player currently playing: (i: turn)
				player = players[i];
				symbol = player.getPlayerSymbol();
				//x = col,  y = row;
				inputGame.InputTurns(board, player, symbol);

				//isWon = hasWon(board, markersWin, symbol);

				isWon = board.hasWon(markersWin, symbol);

				if (isWon){
					cout << "Congratulations " << player.getPlayerName() << " you win!\n";
					char yesno;
					do
					{
						board.printBoard();
						cout << "Want to keep playing? (Y/N) ";
						cin >> yesno;
					} while (yesno != 'Y' && yesno != 'N');
					isOver = yesno == 'Y' ? false : true;
					break;
				}
			}
		}
		if (!isOver) isWon = false;
	}
	return 0;
}
