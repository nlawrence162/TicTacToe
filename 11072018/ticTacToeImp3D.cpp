/*
nathandiditagain.exe
11/9/2018
desc: might not be finished when submitted.
*/

#include <windows.h>
#include <conio.h>

#include <iostream>
#include <iomanip>

#include <random>
#include <ctime>

#include "ticTacToe3D.h"

using namespace std;

HANDLE hConsole3D = GetStdHandle(STD_OUTPUT_HANDLE);
enum status { WIN, DRAW, CONTINUE };

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#define SPACE 32
#define ENTER 13
#define BACK 8
#define ESC 27

#define MINUS 45
#define PLUS 61

void ticTacToe3D::play()
{
	bool done = false;
	char player = 'X';

	//ai or nah
	int c = 1;
	while (c != -1)
	{
		if (c != 0 && c != 224)
		{
			system("cls");
			if (againstAI)
			{
				SetConsoleTextAttribute(hConsole3D, 7);
				cout << "|-vs Computer-| ";
				SetConsoleTextAttribute(hConsole3D, 8);
				cout << "|--- P v P ---|\n";
				SetConsoleTextAttribute(hConsole3D, 7);
				cout << "|-  _______  -| ";
				SetConsoleTextAttribute(hConsole3D, 8);
				cout << "|-  \\        -|\n";
				SetConsoleTextAttribute(hConsole3D, 7);
				cout << "|- |   | | | -| ";
				SetConsoleTextAttribute(hConsole3D, 8);
				cout << "|-  \\ \\      -|\n";
				SetConsoleTextAttribute(hConsole3D, 7);
				cout << "|- |_______| -| ";
				SetConsoleTextAttribute(hConsole3D, 8);
				cout << "|-   \\ \\     -|\n";
				SetConsoleTextAttribute(hConsole3D, 7);
				cout << "|-    /|\\    -| ";
				SetConsoleTextAttribute(hConsole3D, 8);
				cout << "|-   -\\-\\-   -|\n";
				SetConsoleTextAttribute(hConsole3D, 7);
				cout << "|-           -| ";
				SetConsoleTextAttribute(hConsole3D, 8);
				cout << "|-      \\    -|\n";
				if (player1.name == "~") {
					SetConsoleTextAttribute(hConsole3D, 10);
					cout << "          <-       ->";
				}
				SetConsoleTextAttribute(hConsole3D, 7);
			}
			else
			{
				SetConsoleTextAttribute(hConsole3D, 8);
				cout << "|-vs Computer-| ";
				SetConsoleTextAttribute(hConsole3D, 7);
				cout << "|--- P v P ---|\n";
				SetConsoleTextAttribute(hConsole3D, 8);
				cout << "|-  _______  -| ";
				SetConsoleTextAttribute(hConsole3D, 7);
				cout << "|-  \\        -|\n";
				SetConsoleTextAttribute(hConsole3D, 8);
				cout << "|- |   | | | -| ";
				SetConsoleTextAttribute(hConsole3D, 7);
				cout << "|-  \\ \\      -|\n";
				SetConsoleTextAttribute(hConsole3D, 8);
				cout << "|- |_______| -| ";
				SetConsoleTextAttribute(hConsole3D, 7);
				cout << "|-   \\ \\     -|\n";
				SetConsoleTextAttribute(hConsole3D, 8);
				cout << "|-    /|\\    -| ";
				SetConsoleTextAttribute(hConsole3D, 7);
				cout << "|-   -\\-\\-   -|\n";
				SetConsoleTextAttribute(hConsole3D, 8);
				cout << "|-           -| ";
				SetConsoleTextAttribute(hConsole3D, 7);
				cout << "|-      \\    -|\n";
				if (player1.name == "~") {
					SetConsoleTextAttribute(hConsole3D, 10);
					cout << "          <-       ->";
				}
				SetConsoleTextAttribute(hConsole3D, 7);
			}
		}

		c = 0;

		switch ((c = _getch())) {
		case KEY_LEFT:
		case KEY_RIGHT:
			if (againstAI)
				againstAI = false;
			else
				againstAI = true;
			break;
		case SPACE:
		case ENTER:
			c = -1;
		default:
			break;
		}

	}

	system("cls");

	//get player names, choose x/o main loop.
	if (againstAI)
	{
		system("cls");
		if (player1.name == "~") //GET NAME FIRST TIME
		{
			cout << "What is your name?\n > ";
			getline(cin, player1.name);
			c = 1;
			while (c != -1)
			{
				if (c != 0 && c != 224)
				{
					system("cls");
					cout << player1.name << ", pick your symbol:\n";
					if (player == 'X')
					{
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << " \\  /  ";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << "  /--\\  \n";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << "  \\/   ";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << " /    \\ \n";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << "  /\\   ";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << " \\    / \n";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << " /  \\  ";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << "  \\--/  \n";
						SetConsoleTextAttribute(hConsole3D, 7);

					}
					else
					{
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << " \\  /  ";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << "  /--\\  \n";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << "  \\/   ";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << " /    \\ \n";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << "  /\\   ";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << " \\    / \n";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << " /  \\  ";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << "  \\--/  \n";
					}
				}

				c = 0;

				switch ((c = _getch())) {
				case KEY_LEFT:
				case KEY_RIGHT:
					if (player == 'X')
						player = 'O';
					else
						player = 'X';
					break;
				case SPACE:
				case ENTER:
					c = -1;
				default:
					break;
				}
			}
			player1.playerSymbol = player;
		}

		player = player1.playerSymbol;

		if (player == 'X')
			computer.playerSymbol = 'O';
		else
			computer.playerSymbol = 'X';

		player = 'X'; //X starts first

		while (!done)
		{
			if (player == player1.playerSymbol)
				done = getXOMove(player);
			else
				done = getXOMoveAI(player);

			if (player == 'X')
				player = 'O';
			else
				player = 'X';
		}
	}
	else
	{
		system("cls");
		if (player1.name == "~")
		{
			cout << "Player 1, what is your name?\n > ";
			getline(cin, player1.name);
			cout << endl;

			if (player2.name == "~")
			{
				cout << "Player 2, what is your name?\n > ";
				getline(cin, player2.name);
			}

			c = 1;
			while (c != -1)
			{
				if (c != 0 && c != 224)
				{
					system("cls");
					cout << player1.name << ", pick your symbol:\n";
					if (player == 'X')
					{
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << " \\  /  ";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << "  /--\\  \n";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << "  \\/   ";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << " /    \\ \n";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << "  /\\   ";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << " \\    / \n";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << " /  \\  ";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << "  \\--/  \n";
						SetConsoleTextAttribute(hConsole3D, 7);

					}
					else
					{
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << " \\  /  ";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << "  /--\\  \n";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << "  \\/   ";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << " /    \\ \n";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << "  /\\   ";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << " \\    / \n";
						SetConsoleTextAttribute(hConsole3D, 8);
						cout << " /  \\  ";
						SetConsoleTextAttribute(hConsole3D, 7);
						cout << "  \\--/  \n";
					}
				}
				c = 0;

				switch ((c = _getch())) {
				case KEY_LEFT:
				case KEY_RIGHT:
					if (player == 'X')
						player = 'O';
					else
						player = 'X';
					break;
				case SPACE:
				case ENTER:
					c = -1;
				default:
					break;
				}
			}
			player1.playerSymbol = player;
		}
		if (player2.name == "~")
		{
			cout << "Player 2, what is your name?\n > ";
			getline(cin, player2.name);
		}

		player = player1.playerSymbol;

		if (player == 'X')
			player2.playerSymbol = 'O';
		else
			player2.playerSymbol = 'X';

		player = 'X'; //X starts first

		while (!done)
		{
			done = getXOMove(player);

			if (player == 'X')
				player = 'O';
			else
				player = 'X';
		}
	}
	cin.clear();
	cin.ignore();
}

void ticTacToe3D::displayBoard() const
{
	cout << "               \n";

	for (int dimention = 0; dimention < 3; dimention++)
	{
		for (int row = 0; row < 3; row++)
		{
			cout << " ";

			for (int col = 0; col < 3; col++)
			{
				if (board[dimention][row][col] == 'x' || board[dimention][row][col] == 'o')
					SetConsoleTextAttribute(hConsole3D, 6);
				cout << setw(3) << (char)toupper(board[dimention][row][col]);
				SetConsoleTextAttribute(hConsole3D, 7);

				if (col != 2)
					cout << "  |";
			}

			cout << endl;

			if (row != 2)
				cout << "   ___|_____|___\n      |     |   \n";
		}
		cout << "\n";
	}

	cout << "\n";
}

void ticTacToe3D::displayBoard(int d, int r, int c, char p)
{
	cout << "               \n";

	for (int dimention = 0; dimention < 3; dimention++)
	{
		for (int row = 0; row < 3; row++)
		{
			cout << " ";

			for (int col = 0; col < 3; col++)
			{
				if (dimention == d && row == r && col == c) {
					if (board[dimention][row][col] == ' ')
						SetConsoleTextAttribute(hConsole3D, 10);
					else
						SetConsoleTextAttribute(hConsole3D, 12);
					cout << setw(3) << p;
					SetConsoleTextAttribute(hConsole3D, 7);
				}
				else
					cout << setw(3) << board[dimention][row][col];

				if (col != 2)
					cout << "  |";
			}

			cout << endl;

			if (row != 2)
				cout << "   ___|_____|___\n      |     |   \n";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool ticTacToe3D::isValidMove(int dimention, int row, int col) const
{
	if (0 <= dimention && dimention <= 2 && 0 <= row && row <= 2 && 0 <= col && col <= 2 && board[dimention][row][col] == ' ')
		return true;
	else
		return false;
}

bool ticTacToe3D::getXOMove(char playerSymbol)
{
	int dimention = 0;
	int row = 0;
	int col = 0;
	int c = 1;
	int temp = 0;
	c = 1;

	while (c != -1)
	{
		if (c != 0 && c != 224) {
			system("cls");
			displayBoard(dimention, row, col, playerSymbol);
		}
		if (c == -2)
		{
			system("cls");
			displayBoard(dimention, row, col, playerSymbol);
			SetConsoleTextAttribute(hConsole3D, 12);
			cout << "\n\nYou can't do that. -.-";
			SetConsoleTextAttribute(hConsole3D, 7);
		}
		c = 0;

		switch ((c = _getch())) {
		case KEY_RIGHT:
			if (col < 2)
				col++;
			else
				col = 0;
			break;
		case KEY_LEFT:
			if (col > 0)
				col--;
			else
				col = 2;
			break;
		case KEY_DOWN:
			if (row < 2)
				row++;
			else
			{
				row = 0;
				if (dimention < 2)
					dimention++;
				else
					dimention = 0;
				break;
			}
			break;
		case KEY_UP:
			if (row > 0)
				row--;
			else
			{
				row = 2;
				if (dimention > 0)
					dimention--;
				else
					dimention = 2;
				break;
			}
			break;
		case SPACE:
		case ENTER:
			if (isValidMove(dimention, row, col))
				c = -1;
			else
				c = -2;
		default:
			break;
		}
	}

	noOfMoves++;
	board[dimention][row][col] = playerSymbol;

	status gStatus = gameStatus();

	if (gStatus == WIN)
	{
		winConvert();
		system("cls");
		string temp = (playerSymbol == player1.playerSymbol) ? player1.name : player2.name;
		playerSymbol == player1.playerSymbol ? player1.wins++ : player2.wins++;
		displayBoard();
		cout << temp << " wins!" << endl;
		return true;
	}
	else if (gStatus == DRAW)
	{
		system("cls");
		displayBoard();
		cout << "This game is a draw!\n";
		return true;
	}
	else
		return false;
}

bool ticTacToe3D::getXOMoveAI(char playerSymbol)
{
	int dimention, row, col;
	srand(time(NULL));

	if (!boardEmpty())
	{
		dimention = 1;
		row = 1;
		col = 1;
	}
	else
	{
		dimention = rand() % 3;
		row = rand() % 3;
		col = rand() % 3;
	}

	for (int d = 0; d < 3; d++)
	{
		for (int r = 0; r < 3; r++) //check to block opponet
		{
			for (int c = 0; c < 3; c++)
			{
				if (board[d][r][c] == ' ')
				{
					board[d][r][c] = player1.playerSymbol;
					if (gameStatus() == WIN)
					{
						dimention = d;
						row = r;
						col = c;
					}
					board[d][r][c] = ' ';
				}
			}
		}
	}
	for (int d = 0; d < 3; d++)
	{
		for (int r = 0; r < 3; r++) //check for win. overides blocking opponent
		{
			for (int c = 0; c < 3; c++)
			{
				if (board[d][r][c] == ' ')
				{
					board[d][r][c] = playerSymbol; //lol copy paste modify for the win
					if (gameStatus() == WIN)
					{
						dimention = d;
						row = r;
						col = c;
					}
					board[d][r][c] = ' ';
				}
			}
		}
	}
	while (!isValidMove(dimention, row, col)) //otherwise
	{
		dimention = rand() % 3;
		row = rand() % 3;
		col = rand() % 3;
	}

	noOfMoves++;

	board[dimention][row][col] = playerSymbol;

	status gStatus = gameStatus();

	if (gStatus == WIN)
	{
		winConvert();
		system("cls");
		computer.wins++;
		displayBoard();
		cout << computer.name << " wins!" << endl;
		return true;
	}
	else if (gStatus == DRAW)
	{
		system("cls");
		displayBoard();
		cout << "This game is a draw!\n";
		return true;
	}
	else
		return false;
}

status ticTacToe3D::gameStatus()
{
	for (int d = 0; d < 3; d++) //top down
	{
		//rowes
		for (int row = 0; row < 3; row++)
			if (board[d][row][0] != ' ' && (board[d][row][0] == board[d][row][1]) && (board[d][row][1] == board[d][row][2]))
				return WIN;

		//col
		for (int col = 0; col < 3; col++)
			if (board[d][0][col] != ' ' && (board[d][0][col] == board[d][1][col]) && (board[d][1][col] == board[d][2][col]))
				return WIN;

		//digoneals
		if (board[d][0][0] != ' ' && (board[d][0][0] == board[d][1][1]) && (board[d][1][1] == board[d][2][2]))
			return WIN;

		if (board[d][2][0] != ' ' && (board[d][2][0] == board[d][1][1]) && (board[d][1][1] == board[d][0][2]))
			return WIN;
	}
	for (int d = 0; d < 3; d++) //right to left
	{
		//converted rows
		for (int row = 0; row < 3; row++)
			if (board[row][0][d] != ' ' && (board[row][0][d] == board[row][1][d]) && (board[row][1][d] == board[row][2][d]))
				return WIN;

		//converted cols
		for (int col = 0; col < 3; col++)
			if (board[0][col][d] != ' ' && (board[0][col][d] == board[1][col][d]) && (board[1][col][d] == board[2][col][d]))
				return WIN;

		if (board[0][0][d] != ' ' && (board[0][0][d] == board[1][1][d]) && (board[1][1][d] == board[2][2][d]))
			return WIN;

		if (board[2][0][d] != ' ' && (board[2][0][d] == board[1][1][d]) && (board[1][1][d] == board[0][2][d]))
			return WIN;
	}
	for (int d = 0; d < 3; d++) //forward to back
	{
		//converted rows
		for (int row = 0; row < 3; row++)
			if (board[0][d][row] != ' ' && (board[0][d][row] == board[1][d][row]) && (board[1][d][row] == board[2][d][row]))
				return WIN;

		//converted cols
		for (int col = 0; col < 3; col++)
			if (board[col][d][0] != ' ' && (board[col][d][0] == board[col][d][1]) && (board[col][d][1] == board[col][d][2]))
				return WIN;

		if (board[0][d][0] != ' ' && (board[0][d][0] == board[1][d][1]) && (board[1][d][1] == board[2][d][2]))
			return WIN;

		if (board[0][d][2] != ' ' && (board[0][d][2] == board[1][d][1]) && (board[1][d][1] == board[2][d][0]))
			return WIN;
	}
	//dimentional "diagonals"
	if (board[0][0][0] != ' ' && (board[0][0][0] == board[1][1][1]) && (board[1][1][1] == board[2][2][2]))
		return WIN;

	if (board[2][2][0] != ' ' && (board[2][2][0] == board[1][1][1]) && (board[1][1][1] == board[0][0][2]))
		return WIN;

	if (board[2][0][0] != ' ' && (board[2][0][0] == board[1][1][1]) && (board[1][1][1] == board[0][2][2]))
		return WIN;

	if (board[0][2][0] != ' ' && (board[0][2][0] == board[1][1][1]) && (board[1][1][1] == board[2][0][2]))
		return WIN;
	

	if (noOfMoves < 27)
		return CONTINUE;

	return DRAW;
}

int ticTacToe3D::winConvert()
{
	//dimentions "rows"
	for (int d = 0; d < 3; d++)
	{
		for (int row = 0; row < 3; row++)
			if (board[d][row][0] != ' ' && (board[d][row][0] == board[d][row][1]) && (board[d][row][1] == board[d][row][2]))
			{
				board[d][row][0] = tolower(board[d][row][0]);
				board[d][row][1] = tolower(board[d][row][1]);
				board[d][row][2] = tolower(board[d][row][2]);
				return 0;
			}

		for (int col = 0; col < 3; col++)
			if (board[d][0][col] != ' ' && (board[d][0][col] == board[d][1][col]) && (board[d][1][col] == board[d][2][col]))
			{
				board[d][0][col] = tolower(board[d][0][col]);
				board[d][1][col] = tolower(board[d][1][col]);
				board[d][2][col] = tolower(board[d][2][col]);
				return 0;
			}

		if (board[d][0][0] != ' ' && (board[d][0][0] == board[d][1][1]) && (board[d][1][1] == board[d][2][2]))
		{
			board[d][0][0] = tolower(board[d][0][0]);
			board[d][1][1] = tolower(board[d][1][1]);
			board[d][2][2] = tolower(board[d][2][2]);
			return 0;
		}

		if (board[d][2][0] != ' ' && (board[d][2][0] == board[d][1][1]) && (board[d][1][1] == board[d][0][2]))
		{
			board[d][2][0] = tolower(board[d][2][0]);
			board[d][1][1] = tolower(board[d][1][1]);
			board[d][0][2] = tolower(board[d][0][2]);
			return 0;
		}
	}
	//dimention "columns"
	for (int d = 0; d < 3; d++)
	{
		//converted rows
		for (int row = 0; row < 3; row++)
			if (board[row][0][d] != ' ' && (board[row][0][d] == board[row][1][d]) && (board[row][1][d] == board[row][2][d]))
			{
				board[row][0][d] = tolower(board[row][0][d]);
				board[row][1][d] = tolower(board[row][1][d]);
				board[row][2][d] = tolower(board[row][2][d]);
			}
			
		//converted cols
		for (int col = 0; col < 3; col++)
			if (board[0][col][d] != ' ' && (board[0][col][d] == board[1][col][d]) && (board[1][col][d] == board[2][col][d]))
			{
				board[0][col][d] = tolower(board[0][col][d]);
				board[1][col][d] = tolower(board[1][col][d]);
				board[2][col][d] = tolower(board[2][col][d]);
			}
				
		if (board[0][0][d] != ' ' && (board[0][0][d] == board[1][1][d]) && (board[1][1][d] == board[2][2][d]))
		{
			board[0][0][d] = tolower(board[0][0][d]);
			board[1][1][d] = tolower(board[1][1][d]);
			board[2][2][d] = tolower(board[2][2][d]);
		}
			
		if (board[2][0][d] != ' ' && (board[2][0][d] == board[1][1][d]) && (board[1][1][d] == board[0][2][d]))
		{
			board[2][0][d] = tolower(board[2][0][d]);
			board[1][1][d] = tolower(board[1][1][d]);
			board[0][2][d] = tolower(board[0][2][d]);
		}
	}
	for (int d = 0; d < 3; d++) //dimention "columns" v2
	{
		//converted rows
		for (int row = 0; row < 3; row++)
			if (board[0][d][row] != ' ' && (board[0][d][row] == board[1][d][row]) && (board[1][d][row] == board[2][d][row]))
			{
				board[0][d][row] = tolower(board[0][d][row]);
				board[1][d][row] = tolower(board[1][d][row]);
				board[2][d][row] = tolower(board[2][d][row]);
			}

		//converted cols
		for (int col = 0; col < 3; col++)
			if (board[col][d][0] != ' ' && (board[col][d][0] == board[col][d][1]) && (board[col][d][1] == board[col][d][2]))
			{
				board[col][d][0] = tolower(board[col][d][0]);
				board[col][d][1] = tolower(board[col][d][1]);
				board[col][d][2] = tolower(board[col][d][2]);
			}

		//digone
		if (board[0][d][0] != ' ' && (board[0][d][0] == board[1][d][1]) && (board[1][d][1] == board[2][d][2]))
		{
			board[0][d][0] = tolower(board[0][d][0]);
			board[1][d][1] = tolower(board[1][d][1]);
			board[2][d][2] = tolower(board[2][d][2]);
		}

		if (board[0][d][2] != ' ' && (board[0][d][2] == board[1][d][1]) && (board[1][d][1] == board[2][d][0]))
		{
			board[0][d][2] = tolower(board[0][d][2]);
			board[1][d][1] = tolower(board[1][d][1]);
			board[2][d][0] = tolower(board[2][d][0]);
		}
	}
	//dimentional "diagonals"
	if (board[0][0][0] != ' ' && (board[0][0][0] == board[1][1][1]) && (board[1][1][1] == board[2][2][2]))
	{
		board[0][0][0] = tolower(board[0][0][0]);
		board[1][1][1] = tolower(board[1][1][1]);
		board[2][2][2] = tolower(board[2][2][2]);
	}

	if (board[2][2][0] != ' ' && (board[2][2][0] == board[1][1][1]) && (board[1][1][1] == board[0][0][2]))
	{
		board[2][2][0] = tolower(board[2][2][0]);
		board[1][1][1] = tolower(board[1][1][1]);
		board[0][0][2] = tolower(board[0][0][2]);
	}

	if (board[2][0][0] != ' ' && (board[2][0][0] == board[1][1][1]) && (board[1][1][1] == board[0][2][2]))
	{
		board[2][0][0] = tolower(board[2][0][0]);
		board[1][1][1] = tolower(board[1][1][1]);
		board[0][2][2] = tolower(board[0][2][2]);
	}

	if (board[0][2][0] != ' ' && (board[0][2][0] == board[1][1][1]) && (board[1][1][1] == board[2][0][2]))
	{
		board[0][2][0] = tolower(board[0][2][0]);
		board[1][1][1] = tolower(board[1][1][1]);
		board[2][0][2] = tolower(board[2][0][2]);
	}
	return 0;
}

bool ticTacToe3D::boardEmpty()
{
	for(int dimention = 0; dimention < 3; dimention++)
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 3; col++)
				if (board[dimention][row][col] != ' ')
					return false;
	return true;
}

void ticTacToe3D::reStart()
{
	for (int dimention = 0; dimention < 3; dimention++)
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 3; col++)
				board[dimention][row][col] = ' ';

	noOfMoves = 0;
}

ticTacToe3D::ticTacToe3D()
{
	for (int dimention = 0; dimention < 3; dimention++)
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 3; col++)
				board[dimention][row][col] = ' ';

	noOfMoves = 0;
	againstAI = true;
	player1.name = "~";
	player2.name = "~";
	computer.name = "COMPUTER";
	player1.wins = 0;
	player2.wins = 0;
	computer.wins = 0;
}

void ticTacToe3D::displayStats()
{
	system("cls");
	cout << "---------STATS---------";
	cout << endl << player1.name << " (" << player1.playerSymbol << ")" << " won " << player1.wins;
	(player1.wins == 1) ? cout << " time." : cout << " times.";
	if (player2.name != "~") {
		cout << endl << player2.name << " (" << player2.playerSymbol << ")" << " won " << player2.wins;
		(player2.wins == 1) ? cout << " time." : cout << " times.";
	}
	cout << endl << computer.name << " (" << computer.playerSymbol << ")" << " won " << computer.wins;
	(computer.wins == 1) ? cout << " time." : cout << " times.";
}