#include <string>

using namespace std;

enum status { WIN, DRAW, CONTINUE};

class ticTacToe
{
	public:
		void play();

		void displayBoard() const;
		void displayBoard(int r, int c, char p);
		void displayStats();

		bool isValidMove(int x, int y) const;

		bool getXOMove(char moveSymbol);
		bool getXOMoveAI(char moveSymbol);

		status gameStatus();
		bool boardEmpty();
		int winConvert();

		void reStart();

		ticTacToe(); //constuctor

	private:
		bool againstAI;
		char board[3][3];
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