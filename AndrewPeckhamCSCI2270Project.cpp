#include "Minesweeper.h"
using namespace std;

int main() {
	int newrows=5;
	int newcollums=5;
	int newmines=5;
	cords cordin;
	MineSweeperGame* currentGame=new MineSweeperGame(newrows,newcollums,newmines);
	//cout << "First Game created" << endl;
	int menuchoice = 0;
	while (menuchoice!=5) {
		if (currentGame->active) {
			currentGame->printBoard();
			cout << "1. Flag Space" << endl <<
				"2. Select Space" << endl <<
				"3. Reprint Board" << endl <<
				"4. New Game" << endl <<
				"5. Exit" << endl;
			cin >> menuchoice;
			//cin.ignore();
			if (menuchoice == 1) {
				//Flag
				cordin = currentGame->requestcords();
				currentGame->flagsquare(cordin.x, cordin.y);
			}
			else if (menuchoice == 2) {
				//select
				cordin = currentGame->requestcords();
				currentGame->cheaksquare(cordin.x, cordin.y);
			}
			else if (menuchoice == 3) {
				//print
				//returns to top of loop
			}
			else if (menuchoice == 4) {
				//new game
				//returns to top of loop and triggers other part of if.
				currentGame->active = 0;
			}
			else if (menuchoice == 5) {
				cout << "Thank You for Playing" << endl;
				return 0;
			}
			else if (menuchoice == 100) {
				//exists for error cheaking
				currentGame->showall();
			}
			else {
				cin.ignore();
				cout << "ERROR: invalid input";
			}
		}
		else {
			delete currentGame;
			currentGame = new MineSweeperGame();
		}
	}
	return 0;
}