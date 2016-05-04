#include <iostream>
#include <vector>

struct possibility {
	char symbol;
	bool mine;
	int nearby;
};

struct rows {
	std::vector<possibility> row;
};

struct minefeild {
	std::vector<rows> board;
};

struct cords {
	int x;
	int y;
	cords() {

	}
	cords(int xin, int yin) {
		x = xin;
		y = yin;
	}
};

class MineSweeperGame {
public:
		MineSweeperGame(int rows, int collums, int mines);
		MineSweeperGame();
		~MineSweeperGame();
		void flagsquare(int x,int y);
		void checksquare(int x,int y);
		void printBoard();
		cords requestcords();
		bool active;
		void showall();
		//x is collums, y is rows
private:
		minefeild* activeBoard;
		int activerows;
		int activecollums;
		void setnearby(int x, int y);
		void setnearbyall();
		void laymines(int minenumber);
		void GameOver();
};
