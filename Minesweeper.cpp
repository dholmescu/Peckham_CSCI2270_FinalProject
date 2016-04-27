#include "Minesweeper.h"
#include <random>

MineSweeperGame::MineSweeperGame(int rowsNumber, int collumsNumber, int mines)
{
	activeBoard = new minefeild;
	activerows = rowsNumber;
	activecollums = collumsNumber;
	active = 1;
	activeBoard->board.resize(rowsNumber);
	for (int i = 0; i < rowsNumber; i++) {
		//std::cout << i << std::endl;
		activeBoard->board[i].row.resize(collumsNumber);
		for (int y = 0; y < collumsNumber; y++) {
			activeBoard->board[i].row[y].symbol='O';
		}
	}
	laymines(mines);
	setnearbyall();
}

MineSweeperGame::MineSweeperGame()
{
	int newrows = 0;
	int newcollums = 0;
	int newmines = 0;
	std::cout << "number of rows: ";
	//std::cin.ignore();
	std::cin >> newrows;
	std::cout << "number of columns: ";
	//std::cin.ignore();
	std::cin >> newcollums;
	std::cout << "number of mines: ";
	//std::cin.ignore();
	std::cin >> newmines;
	activeBoard = new minefeild;
	activerows = newrows;
	activecollums = newcollums;
	active = 1;
	activeBoard->board.resize(newrows);
	for (int i = 0; i < newrows; i++) {
		//std::cout << i << std::endl;
		activeBoard->board[i].row.resize(newcollums);
		for (int y = 0; y < newcollums; y++) {
			activeBoard->board[i].row[y].symbol = 'O';
		}
	}
	laymines(newmines);
	setnearbyall();
}

MineSweeperGame::~MineSweeperGame()
{
}

void MineSweeperGame::flagsquare(int x,int y)
{
	activeBoard->board[y].row[x].symbol = 'X';
}

void MineSweeperGame::cheaksquare(int x,int y)
{
	if (activeBoard->board[x].row[y].symbol == 'X') {
		std::cout << "square flagged" << std::endl;
		return;
	}
	else if (activeBoard->board[x].row[y].mine) {
		//std::cout << "boom" << std::endl;
		GameOver();
		return;
	}
	else if ((activeBoard->board[x].row[y].nearby == 0) && (activeBoard->board[x].row[y].symbol == 'O')) {
		//if std::cout << x << y << std::endl;
		cords temp(x, y);
		activeBoard->board[x].row[y].symbol = ' ';
		if (x == 0) {
			if (y == 0) {
				cheaksquare(temp.x++, temp.y++);
				cheaksquare(temp.x++, temp.y);
				cheaksquare(temp.x, temp.y++);
			}
			else if (y == activerows - 1) {
				cheaksquare(temp.x++, temp.y);
				cheaksquare(temp.x++, temp.y--);
				cheaksquare(temp.x, temp.y--);
			}
			else {
				cheaksquare(temp.x++, temp.y++);
				cheaksquare(temp.x++, temp.y);
				cheaksquare(temp.x++, temp.y--);
				cheaksquare(temp.x, temp.y++);
				cheaksquare(temp.x, temp.y--);
			}
		}
		else if (x == activecollums - 1) {
			if (y == 0) {
				cheaksquare(temp.x, temp.y++);
				cheaksquare(temp.x--, temp.y++);
				cheaksquare(temp.x--, temp.y);
			}
			else if (y = activerows - 1) {
				cheaksquare(temp.x, temp.y--);
				cheaksquare(temp.x--, temp.y);
				cheaksquare(temp.x--, temp.y--);
			}
			else {
				cheaksquare(temp.x, temp.y++);
				cheaksquare(temp.x, temp.y--);
				cheaksquare(temp.x--, temp.y++);
				cheaksquare(temp.x--, temp.y);
				cheaksquare(temp.x--, temp.y--);
			}
		}
		else {
			if (y == 0) {
				cheaksquare(temp.x++, temp.y++);
				cheaksquare(temp.x++, temp.y);
				cheaksquare(temp.x, temp.y++);
				cheaksquare(temp.x--, temp.y++);
				cheaksquare(temp.x--, temp.y);
			}
			else if (y == activerows - 1) {
				cheaksquare(temp.x++, temp.y);
				cheaksquare(temp.x++, temp.y--);
				cheaksquare(temp.x, temp.y--);
				cheaksquare(temp.x--, temp.y);
				cheaksquare(temp.x--, temp.y--);
			}
			else {
				cheaksquare(temp.x++, temp.y++);
				cheaksquare(temp.x++, temp.y);
				cheaksquare(temp.x++, temp.y--);
				cheaksquare(temp.x, temp.y++);
				cheaksquare(temp.x, temp.y--);
				cheaksquare(temp.x--, temp.y++);
				cheaksquare(temp.x--, temp.y);
				cheaksquare(temp.x--, temp.y--);
			}
		}
	}
	else if(!activeBoard->board[x].row[y].symbol == ' '){
		activeBoard->board[x].row[y].symbol = '0' + activeBoard->board[x].row[y].nearby;
	}
}

void MineSweeperGame::printBoard()
{
	for (int x = 0; x < activerows; x++) {
		for (int y = 0; y < activecollums; y++) {
			std::cout<<activeBoard->board[x].row[y].symbol;
		}
		std::cout << std::endl;
	}
}

cords MineSweeperGame::requestcords()
{
	cords tmp;
	std::cout << "x:";
	while (!(std::cin >> tmp.x) && tmp.x < activecollums&&tmp.x >= 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Must be a integer between 0 and" << activecollums - 1 << std::endl << "Try again:";
	}
	std::cout << "y:";
	while (!(std::cin >> tmp.y) && tmp.y < activerows&&tmp.y >= 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Must be an integer between 0 and" << activerows - 1 << std::endl << "Try again:";
	}
	return tmp;
}

void MineSweeperGame::showall()
{
	for (int x = 0; x < activerows; x++) {
		for (int y = 0; y < activecollums; y++) {
			if (activeBoard->board[x].row[y].mine == 1) {
				activeBoard->board[x].row[y].symbol = 'X';
			}
			else if (!(activeBoard->board[x].row[y].nearby == 0)) {
				activeBoard->board[x].row[y].symbol = '0'+ activeBoard->board[x].row[y].nearby;
			}
			else {
				activeBoard->board[x].row[y].symbol = ' ';
			}
		}
	}
	//printBoard();
	//system("PAUSE");
}

void MineSweeperGame::setnearby(int x, int y)
{
	int count = 0;
	//possibility* target = &activeBoard->board[y].row[x];
	//std::cout << x << "," << y << std::endl;
	if (x == 0) {
		if (y == 0) {
			if (activeBoard->board[y + 1].row[x].mine == 1) {
				count++;
			}
			if (activeBoard->board[y + 1].row[x + 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y].row[x + 1].mine == 1) {
				count++;
			}
		}
		else if(y==activerows-1){
			if (activeBoard->board[y - 1].row[x].mine == 1) {
				count++;
			}
			if (activeBoard->board[y].row[x + 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y - 1].row[x + 1].mine == 1) {
				count++;
			}
		}
		else {
			if (activeBoard->board[y - 1].row[x].mine == 1) {
				count++;
			}
			if (activeBoard->board[y + 1].row[x].mine == 1) {
				count++;
			}
			if (activeBoard->board[y + 1].row[x + 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y].row[x + 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y - 1].row[x + 1].mine == 1) {
				count++;
			}
		}
	}
	else if (x==activecollums-1) {
		if (y == 0) {
			if (activeBoard->board[y].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y + 1].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y + 1].row[x].mine == 1) {
				count++;
			}
		}
		else if(y==activerows-1){
			if (activeBoard->board[y - 1].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y - 1].row[x].mine == 1) {
				count++;
			}
		}
		else {
			if (activeBoard->board[y - 1].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y + 1].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y - 1].row[x].mine == 1) {
				count++;
			}
			if (activeBoard->board[y + 1].row[x].mine == 1) {
				count++;
			}
		}
	}
	else {
		if (y == 0) {
			if (activeBoard->board[y].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y + 1].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y + 1].row[x].mine == 1) {
				count++;
			}
			if (activeBoard->board[y + 1].row[x + 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y].row[x + 1].mine) {
				count++;
			}
		}
		else if (y == activerows - 1) {
			if (activeBoard->board[y - 1].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y - 1].row[x].mine == 1) {
				count++;
			}
			if (activeBoard->board[y].row[x + 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y - 1].row[x + 1].mine == 1) {
				count++;
			}
		}
		else {
			if (activeBoard->board[y - 1].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y + 1].row[x - 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y - 1].row[x].mine == 1) {
				count++;
			}
			if (activeBoard->board[y + 1].row[x].mine == 1) {
				count++;
			}
			if (activeBoard->board[y + 1].row[x + 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y].row[x + 1].mine == 1) {
				count++;
			}
			if (activeBoard->board[y - 1].row[x + 1].mine == 1) {
				count++;
			}
		}
	}
	//std::cout << count << std::endl;
	activeBoard->board[y].row[x].nearby = count;
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
				if (!activeBoard->board[i].row[y].mine) {
					randomnumber = rand() % 100;
					if (randomnumber == 1) {
						activeBoard->board[i].row[y].mine = 1;
						minecount--;
					}
				}
			}
		}
	}
}

void MineSweeperGame::GameOver()
{
	std::cout << "Game Over" << std::endl;
	active = 0;
}