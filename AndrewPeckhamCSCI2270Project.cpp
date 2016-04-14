#include "Minesweeper.h"
using namespace std;

int main() {
	int newrows=10;
	int newcollums=10;
	int newmines=1;
	MineSweeperGame* currentGame=new MineSweeperGame(newrows,newcollums,newmines);
	int menuchoice = 0;
	while (menuchoice!=5) {
		cout << "1. Flag Space" << endl <<
			"2. Select Space" << endl <<
			"3. Reprint Board" << endl <<
			"4. New Game" << endl <<
			"5. Exit";
		cin.ignore();
		cin >> menuchoice;
		if (menuchoice = 1) {
			
		}
		else if (menuchoice = 2) {

		}
		else if (menuchoice = 3) {

		}
		else if (menuchoice = 4) {
			delete currentGame;
			std::cout << "number of rows: ";
			std::cin.ignore();
			std::cin >> newrows;
			std::cout << std::endl << "number of collums: ";
			std::cin.ignore();
			std::cin >> newcollums;
			std::cout << std::endl << "number of mines: ";
			std::cin.ignore();
			std::cin >> newmines;
			currentGame = new MineSweeperGame(newrows, newcollums, newmines);
		}
		else if (menuchoice = 5) {
			cout << "Thank You for Playing" << endl;
		}
		else {
			cin.ignore();
			cout << "ERROR: invalid input";
		}
	}
}