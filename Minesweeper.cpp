#include "Minesweeper.h"
#include <random>

MineSweeperGame::MineSweeperGame(int rowsNumber, int collumsNumber, int mines)
{
	activeBoard = new minefeild;
	activerows = rowsNumber;
	activecollums = collumsNumber;
	for (int i = 0; i < rowsNumber; i++) {
		for (int y = 0; y < collumsNumber; y++) {
			activeBoard->board[i][y].symbol='O';
		}
	}
	laymines(mines);
}

MineSweeperGame::~MineSweeperGame()
{
}

void MineSweeperGame::flagsquare(int x,int y)
{

}

void MineSweeperGame::cheaksquare(int x,int y)
{
	if (activeBoard->board[x][y].mine) {
		GameOver();
		return;
	}
	else if (activeBoard->board[x][y].nearby = 0) {

	}
	else {

	}
}

void MineSweeperGame::printBoard()
{
	for (int i = 0; i < activerows; i++) {
		for (int y = 0; y < activecollums; y++) {
			std::cout<<activeBoard->board[i][y].symbol;
		}
		std::cout << std::endl;
	}
}

void MineSweeperGame::setnearby(int x, int y)
{
	int count = 0;
	possibility* target = &activeBoard->board[y][x];
	if (x = 0) {
		if (y = 0) {
			if (activeBoard->board[y + 1][x].mine) {
				count + 1;
			}
			if (activeBoard->board[y + 1][x + 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y][x + 1].mine) {
				count + 1;
			}
		}
		else if(y=activerows-1){
			if (activeBoard->board[y - 1][x].mine) {
				count + 1;
			}
			if (activeBoard->board[y][x + 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y - 1][x + 1].mine) {
				count + 1;
			}
		}
		else {
			if (activeBoard->board[y - 1][x].mine) {
				count + 1;
			}
			if (activeBoard->board[y + 1][x].mine) {
				count + 1;
			}
			if (activeBoard->board[y + 1][x + 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y][x + 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y - 1][x + 1].mine) {
				count + 1;
			}
		}
	}
	else if (x=activecollums-1) {
		if (y = 0) {
			if (activeBoard->board[y][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y + 1][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y + 1][x].mine) {
				count + 1;
			}
		}
		else if(y=activerows-1){
			if (activeBoard->board[y - 1][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y - 1][x].mine) {
				count + 1;
			}
		}
		else {
			if (activeBoard->board[y - 1][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y + 1][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y - 1][x].mine) {
				count + 1;
			}
			if (activeBoard->board[y + 1][x].mine) {
				count + 1;
			}
		}
	}
	else {
		if (y = 0) {
			if (activeBoard->board[y][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y + 1][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y + 1][x].mine) {
				count + 1;
			}
			if (activeBoard->board[y + 1][x + 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y][x + 1].mine) {
				count + 1;
			}
		}
		else if (y = activerows - 1) {
			if (activeBoard->board[y - 1][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y - 1][x].mine) {
				count + 1;
			}
			if (activeBoard->board[y][x + 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y - 1][x + 1].mine) {
				count + 1;
			}
		}
		else {
			if (activeBoard->board[y - 1][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y + 1][x - 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y - 1][x].mine) {
				count + 1;
			}
			if (activeBoard->board[y + 1][x].mine) {
				count + 1;
			}
			if (activeBoard->board[y + 1][x + 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y][x + 1].mine) {
				count + 1;
			}
			if (activeBoard->board[y - 1][x + 1].mine) {
				count + 1;
			}
		}
	}
	target->nearby = count;
}

void MineSweeperGame::setnearbyall()
{
	for (int i = 0; i < activerows; i++) {
		for (int y = 0; y < activecollums; y++) {
			setnearby(y,i);
		}
	}
}

void MineSweeperGame::laymines(int minenumber)
{
	int randomnumber;
	int minecount = minenumber;
	while (minecount > 0) {
		for (int i = 0; i < activerows; i++) {
			for (int y = 0; y < activecollums; y++) {
				if (!activeBoard->board[i][y].mine) {
					randomnumber = rand() % 100;
					if (randomnumber == 100) {
						activeBoard->board[i][y].mine = 1;
						minecount--;
					}
				}
			}
		}
	}
}

void MineSweeperGame::GameOver()
{
	std::cout << "Game Over" << std::endl <<
		"please start a new game";
}
