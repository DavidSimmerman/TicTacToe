/*
TODO
	Tie condition




*/
#include <iostream>
#include "FTicTacToe.h"

FTicTacToe tttGame;

int MainMenu();
void SinglePlayer();
void MultiPlayer();
bool AskToPlayAgain();

int main()
{
	do
	{
		if (MainMenu() == 1)
		{
			SinglePlayer();
		}
		else
		{
			MultiPlayer();
		}
	} while (AskToPlayAgain());
    
}


/*
1 | 2 | 3
---------
4 | 5 | 6
---------
7 | 8 | 9
*/

int MainMenu()
{
	tttGame.PrintMainMenu();
	return tttGame.GetValidAnswer(2);
}

void SinglePlayer()
{
	tttGame.ResetGame();
	tttGame.SetDifficulty();

	do
	{
		if (tttGame.GetTurn() == 'X')
		{
			system("cls");
			tttGame.PrintBoard();
			tttGame.PrintTurn();
			tttGame.PlayMove();
		}
		else
		{
			tttGame.CPUMove();
		}
	} while (!tttGame.IsGameWon());

	tttGame.PrintEnding();
}

void MultiPlayer()
{
	tttGame.ResetGame();
	do
	{
		system("cls");
		tttGame.PrintBoard();
		tttGame.PrintTurn();
		tttGame.PlayMove();

	} while (!tttGame.IsGameWon());

	tttGame.PrintEnding();
}

bool AskToPlayAgain()
{
	int resp;
	std::cout << "\n Would you like to play again?\n";
	std::cout << " 1: Yes    2: No\n\n";
	std::cout << " > ";
	std::cin >> resp;
	if (resp == 1) { return true; }
	else { return false; }
	return false;
}
