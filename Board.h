#ifndef BOARD_H
#define BOARD_H
class Board
{
private:
	int boardWide;
	int boardHigh;
	char Data[20][20];
public:
	Board();
	void setBoardSize(int wide, int high);
	int getBoardWide();
	int getBoardHigh();
	char getBoardData(int x, int y);
	void initBoard();
	void printBoard();
	bool modifyBoard(int x, int y, char c);
	bool hasWon(int markersWin, char playerSymb);
};
#endif
