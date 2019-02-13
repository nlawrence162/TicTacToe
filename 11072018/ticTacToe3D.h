#include <string>

using namespace std;

enum status;

class ticTacToe3D
{
	public:
		void play();

		void displayBoard() const;
		void displayBoard(int d, int r, int c, char p);
		void displayStats();

		bool isValidMove(int dimention, int row, int col) const;

		bool getXOMove(char moveSymbol);
		bool getXOMoveAI(char moveSymbol);

		status gameStatus();
		bool boardEmpty();
		int winConvert();

		void reStart();

		ticTacToe3D(); //constuctor

	private:
		bool againstAI;
		char board[3][3][3];
		int noOfMoves;
		struct playerStats
		{
			string name;
			char playerSymbol;
			int wins;
		};
		playerStats player1;
		playerStats player2;
		playerStats computer;
};
