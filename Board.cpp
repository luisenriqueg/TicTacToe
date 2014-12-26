#include "Board.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

Board::Board()
{
	this->boardWide = 3;
	this->boardHigh = 3;
}

void Board::setBoardSize(int boardWide, int boardHigh){
	this->boardWide = boardWide;
	this->boardHigh = boardHigh;
}

int Board::getBoardWide(){
	return boardWide;
}

int Board::getBoardHigh(){
	return boardHigh;
}

char Board::getBoardData(int x, int y){
	return Data[x][y];
}

void Board::initBoard(){
	for (int row = 0; row < boardHigh; row++){
		for (int col = 0; col < boardWide; col++){
			Data[row][col] = '.';
		}
	}
}

void Board::printBoard(){
	cout << endl;
	cout << endl;
	for (int row = 0; row < boardHigh+1; row++){
		cout << "    ";
		for (int col = 0; col < boardWide+1; col++){
			if (row == 0 && col != boardWide)
				cout << " | " << col + 1;
			if (col == 0 && row != 0)
				cout << row <<"| ";
			if (row == 0 && col == boardWide)
				cout << " |";
			if (col > 0 && col < boardWide + 1 && row > 0 && row < boardHigh + 1)
				cout << Data[row - 1][col - 1] << " | ";
		}
		cout << endl << "    ";
		//4 characters each iteration: " | n" + " |" = 4*boardWide+2
		for (int col = 0; col < 4*boardWide; col++){
			cout << "-";
		} cout << "--";
		cout << endl;
	}
	cout << endl;
}

bool Board::modifyBoard(int x, int y, char c){
	//x = col,  y = row;
	if (Data[y-1][x-1] == '.'){
		Data[y-1][x-1] = c;
		return true;
	}
	else{
		cout << "\nAlready chosen or input is invalid\n";
		return false;
	}
}

bool Board::hasWon(int markersWin, char playerSymb){

	bool winner = false;
	char data;
	for (int i = 0; i < boardHigh; i++){
		for (int j = 0; j < boardWide; j++){
			data = Data[i][j];
			//Horizontal Check:
			int cont = 1;
			if (data == playerSymb && (j + markersWin < boardWide)){
				while (playerSymb == Data[i][j+cont]){
					cont++;
				}
			}
			if (cont == markersWin) return true; //winner = true;

			//Vertical Check:
			cont = 1;
			if (data == playerSymb && (i + markersWin < boardHigh)){
				while (playerSymb == Data[i+cont][j]){
					cont++;
				}
			}
			if (cont == markersWin) return true; //winner = true;

			//TopRight to BottomLeft:
			cont = 1;
			if (data == playerSymb && (i + markersWin < boardHigh) && (j + markersWin < boardWide)){
				while (playerSymb == Data[i+cont][j+cont]){
					cont++;
				}
			}
			if (cont == markersWin) return true; //winner = true;

			//TopLeft to BottomRight:
			cont = 1;
			if (data == playerSymb && (i + markersWin < boardHigh) && (j - cont >= 0)){
				while (playerSymb == Data[i+cont][j-cont]){
					cont++;
				}
			}
			if (cont == markersWin) return true; //winner = true;
		}
		//if (winner) break;
	}
	return winner;
}
