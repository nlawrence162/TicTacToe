#include<windows.h>
#include<conio.h>
#include<iostream>

#include "TicTacToe.h"
#include "TicTacToe3D.h"

using namespace std;

#define SPACE 32
#define ENTER 13
#define BACK 8
#define ESC 27

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
	bool gameOn = true;
	bool D31 = false;
	bool D32 = false;
	ticTacToe game;
	ticTacToe3D game3D;
	int c = 0;
	
	ShowConsoleCursor(false);

	while(gameOn)
	{
		game.play();

		
		c = 0;
		while (c != -1)
		{
			system("cls");
			cout << "Press ENTER to play again, or press ESC to quit...";
			c = 0;

			switch ((c = _getch())) {
			case 0:
				break;
			case SPACE:
			case ENTER:
				game.reStart();
				c = -1;
				break;
			case BACK:
			case ESC:
				gameOn = false;
				c = -1;
				break;
			case 51:
				D31 = true;
				break;
			case 100:
				D32 = true;
				break;
			default:
				D31 = false;
				D32 = false;
				break;
			}
		}
	}
	game.displayStats();
	cin.clear();
	cin.ignore();
	if (D31 && D32)
	{
		gameOn = true;

		while (gameOn)
		{
			game3D.play();


			c = 0;
			while (c != -1)
			{
				system("cls");
				cout << "Press ENTER to play again, or press ESC to quit...";
				c = 0;

				switch ((c = _getch())) {
				case SPACE:
				case ENTER:
					game3D.reStart();
					c = -1;
					break;
				case BACK:
				case ESC:
					gameOn = false;
					c = -1;
					break;
				case 51:
					D31 = true;
				case 100:
					D32 = true;
				default:
					break;
				}
			}
		}
		game3D.displayStats();
		cin.clear();
		cin.ignore();
	}
}