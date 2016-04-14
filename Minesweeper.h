#include <iostream>
#include <vector>

struct possibility {
	char symbol;
	bool mine;
	int nearby;
};

struct minefeild {
	std::vector<std::vector<possibility>> board;
};

class MineSweeperGame {
public:
		MineSweeperGame(int rows, int collums, int mines);
		~MineSweeperGame();
		void flagsquare(int x,int y);
		void cheaksquare(int x,int y);
		void printBoard();
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