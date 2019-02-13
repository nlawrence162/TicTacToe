/*
name: nathan / dummy kevin
date: nobody im lonly
desc: tix tax toes
*/

#include <windows.h>
#include <conio.h>

#include <iostream>
#include <iomanip>

#include <random>
#include <ctime>

#include "ticTacToe.h"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#define SPACE 32
#define ENTER 13
#define BACK 8
#define ESC 27

void ticTacToe::play()
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
				SetConsoleTextAttribute(hConsole, 7);
				cout << "|-vs Computer-| ";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "|--- P v P ---|\n";
				SetConsoleTextAttribute(hConsole, 7);
				cout << "|-  _______  -| ";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "|-  \\        -|\n";
				SetConsoleTextAttribute(hConsole, 7);
				cout << "|- |   | | | -| ";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "|-  \\ \\      -|\n";
				SetConsoleTextAttribute(hConsole, 7);
				cout << "|- |_______| -| ";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "|-   \\ \\     -|\n";
				SetConsoleTextAttribute(hConsole, 7);
				cout << "|-    /|\\    -| ";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "|-   -\\-\\-   -|\n";
				SetConsoleTextAttribute(hConsole, 7);
				cout << "|-           -| ";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "|-      \\    -|\n";
				if (player1.name == "~") {
					SetConsoleTextAttribute(hConsole, 10);
					cout << "          <-       ->";
				}
				SetConsoleTextAttribute(hConsole, 7);
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 8);
				cout << "|-vs Computer-| ";
				SetConsoleTextAttribute(hConsole, 7);
				cout << "|--- P v P ---|\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "|-  _______  -| ";
				SetConsoleTextAttribute(hConsole, 7);
				cout << "|-  \\        -|\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "|- |   | | | -| ";
				SetConsoleTextAttribute(hConsole, 7);
				cout << "|-  \\ \\      -|\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "|- |_______| -| ";
				SetConsoleTextAttribute(hConsole, 7);
				cout << "|-   \\ \\     -|\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "|-    /|\\    -| ";
				SetConsoleTextAttribute(hConsole, 7);
				cout << "|-   -\\-\\-   -|\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "|-           -| ";
				SetConsoleTextAttribute(hConsole, 7);
				cout << "|-      \\    -|\n";
				if (player1.name == "~") {
					SetConsoleTextAttribute(hConsole, 10);
					cout << "          <-       ->";
				}
				SetConsoleTextAttribute(hConsole, 7);
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
						SetConsoleTextAttribute(hConsole, 7);
						cout << " \\  /  ";
						SetConsoleTextAttribute(hConsole, 8);
						cout << "  /--\\  \n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "  \\/   ";
						SetConsoleTextAttribute(hConsole, 8);
						cout << " /    \\ \n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "  /\\   ";
						SetConsoleTextAttribute(hConsole, 8);
						cout << " \\    / \n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << " /  \\  ";
						SetConsoleTextAttribute(hConsole, 8);
						cout << "  \\--/  \n";
						SetConsoleTextAttribute(hConsole, 7);

					}
					else
					{
						SetConsoleTextAttribute(hConsole, 8);
						cout << " \\  /  ";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "  /--\\  \n";
						SetConsoleTextAttribute(hConsole, 8);
						cout << "  \\/   ";
						SetConsoleTextAttribute(hConsole, 7);
						cout << " /    \\ \n";
						SetConsoleTextAttribute(hConsole, 8);
						cout << "  /\\   ";
						SetConsoleTextAttribute(hConsole, 7);
						cout << " \\    / \n";
						SetConsoleTextAttribute(hConsole, 8);
						cout << " /  \\  ";
						SetConsoleTextAttribute(hConsole, 7);
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
						SetConsoleTextAttribute(hConsole, 7);
						cout << " \\  /  ";
						SetConsoleTextAttribute(hConsole, 8);
						cout << "  /--\\  \n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "  \\/   ";
						SetConsoleTextAttribute(hConsole, 8);
						cout << " /    \\ \n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "  /\\   ";
						SetConsoleTextAttribute(hConsole, 8);
						cout << " \\    / \n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << " /  \\  ";
						SetConsoleTextAttribute(hConsole, 8);
						cout << "  \\--/  \n";
						SetConsoleTextAttribute(hConsole, 7);

					}
					else
					{
						SetConsoleTextAttribute(hConsole, 8);
						cout << " \\  /  ";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "  /--\\  \n";
						SetConsoleTextAttribute(hConsole, 8);
						cout << "  \\/   ";
						SetConsoleTextAttribute(hConsole, 7);
						cout << " /    \\ \n";
						SetConsoleTextAttribute(hConsole, 8);
						cout << "  /\\   ";
						SetConsoleTextAttribute(hConsole, 7);
						cout << " \\    / \n";
						SetConsoleTextAttribute(hConsole, 8);
						cout << " /  \\  ";
						SetConsoleTextAttribute(hConsole, 7);
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

void ticTacToe::displayBoard() const
{
	cout << "               \n";

	for (int row = 0; row < 3; row++)
	{
		cout << " ";

		for (int col = 0; col < 3; col++)
		{
			if(board[row][col] == 'x' || board[row][col] == 'o')
				SetConsoleTextAttribute(hConsole, 6);
			cout << setw(3) << (char)toupper(board[row][col]);
			SetConsoleTextAttribute(hConsole, 7);

			if (col != 2)
				cout << "  |";
		}

		cout << endl;

		if (row != 2)
			cout << "   ___|_____|___\n      |     |   \n";
	}

	cout << "\n";
}

void ticTacToe::displayBoard(int r, int c, char p)
{
	cout << "               \n";

	for (int row = 0; row < 3; row++)
	{
		cout << " ";

		for (int col = 0; col < 3; col++)
		{
			if (row == r && col == c){
				if (board[row][col] == ' ')
					SetConsoleTextAttribute(hConsole, 10);
				else
					SetConsoleTextAttribute(hConsole, 12);
				cout << setw(3) << p;
				SetConsoleTextAttribute(hConsole, 7);
			}
			else
				cout << setw(3) << board[row][col];

			if (col != 2)
				cout << "  |";
		}

		cout << endl;

		if (row != 2)
			cout << "   ___|_____|___\n      |     |   \n";
	}

	cout << "\n";
}

bool ticTacToe::isValidMove(int row, int col) const
{
	if (0 <= row && row <= 2 && 0 <= col && col <= 2 && board[row][col] == ' ')
		return true;
	else
		return false;
}

bool ticTacToe::getXOMove(char playerSymbol)
{
	int row = 0;
	int col = 0;
	int c = 1;
	int temp = 0;
	c = 1;

	while (c != -1)
	{
		if (c != 0 && c != 224){
			system("cls");
			displayBoard(row, col, playerSymbol);
		}
		if (c == -2)
		{
			system("cls");
			displayBoard(row, col, playerSymbol);
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\n\nYou can't do that. -.-";
			SetConsoleTextAttribute(hConsole, 7);
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
				row = 0;
			break;
		case KEY_UP:
			if (row > 0)
				row--;
			else
				row = 2;
			break;
		case SPACE:
		case ENTER:
			if (isValidMove(row, col))
				c = -1;
			else
				c = -2;
		default:
			break;
		}
	}

	noOfMoves++;
	board[row][col] = playerSymbol;

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

bool ticTacToe::getXOMoveAI(char playerSymbol)
{
	int row, col;
	srand(time(NULL));

	if (!boardEmpty())
	{
		row = 1;
		col = 1;
	}
	else
	{
		row = rand() % 3;
		col = rand() % 3;
	}

	for (int r = 0; r < 3; r++) //check to block opponet
	{
		for (int c = 0; c < 3; c++)
		{
			if (board[r][c] == ' ')
			{
				board[r][c] = player1.playerSymbol;
				if (gameStatus() == WIN)
				{
					row = r;
					col = c;
				}
				board[r][c] = ' ';
			}
		}
	}
	for (int r = 0; r < 3; r++) //check for win. overides blocking opponent
	{
		for (int c = 0; c < 3; c++)
		{
			if (board[r][c] == ' ')
			{
				board[r][c] = playerSymbol; //lol copy paste modify for the win
				if (gameStatus() == WIN)
				{
					row = r;
					col = c;
				}
				board[r][c] = ' ';
			}
		}
	}
	while (!isValidMove(row, col)) //otherwise
	{
		row = rand() % 3;
		col = rand() % 3;
	}

	noOfMoves++;

	board[row][col] = playerSymbol;

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

status ticTacToe::gameStatus()
{
	//rowes
	for (int row = 0; row < 3; row++)
		if (board[row][0] != ' ' && (board[row][0] == board[row][1]) && (board[row][1] == board[row][2]))
			return WIN;

	//col
	for(int col = 0; col < 3; col++)
		if (board[0][col] != ' ' && (board[0][col] == board[1][col]) && (board[1][col] == board[2][col]))
			return WIN;

	//digoneals
	if (board[0][0] != ' ' && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
		return WIN;

	if (board[2][0] != ' ' && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))
		return WIN;

	if (noOfMoves < 9)
		return CONTINUE;

	return DRAW;
}

int ticTacToe::winConvert()
{
	for (int row = 0; row < 3; row++)
		if (board[row][0] != ' ' && (board[row][0] == board[row][1]) && (board[row][1] == board[row][2]))
		{
			board[row][0] = tolower(board[row][0]);
			board[row][1] = tolower(board[row][1]);
			board[row][2] = tolower(board[row][2]);
			return 0;
		}

	for (int col = 0; col < 3; col++)
		if (board[0][col] != ' ' && (board[0][col] == board[1][col]) && (board[1][col] == board[2][col]))
		{
			board[0][col] = tolower(board[0][col]);
			board[1][col] = tolower(board[1][col]);
			board[2][col] = tolower(board[2][col]);
			return 0;
		}

	if (board[0][0] != ' ' && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
	{
		board[0][0] = tolower(board[0][0]);
		board[1][1] = tolower(board[1][1]);
		board[2][2] = tolower(board[2][2]);
		return 0;
	}	

	if (board[2][0] != ' ' && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))
	{
		board[2][0] = tolower(board[2][0]);
		board[1][1] = tolower(board[1][1]);
		board[0][2] = tolower(board[0][2]);
		return 0;
	}
	return 0;
}

bool ticTacToe::boardEmpty()
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (board[row][col] != ' ')
				return false;
	return true;
}

void ticTacToe::reStart()
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';

	noOfMoves = 0;
}

ticTacToe::ticTacToe()
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';

	noOfMoves = 0;
	againstAI = true;
	player1.name = "~";
	player2.name = "~";
	computer.name = "COMPUTER";
	player1.wins = 0;
	player2.wins = 0;
	computer.wins = 0;
}

void ticTacToe::displayStats()
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