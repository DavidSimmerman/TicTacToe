#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
class FTicTacToe
{
public:
	void ResetGame();

	void PrintMainMenu();
	void PrintBoard();
	void PrintTurn();

	char GetTurn();
	int GetValidAnswer(int NumOfAns);
	void SetDifficulty();

	void PlayMove();
	void CPUMove();
	bool CheckThree();
	bool CheckTwo();
	void MoveOne();

	bool IsGameWon();
	void PrintEnding();
	
private:
	char Board[9];
	char turn;
	char winner;
	int difficulty;
	int noOfCpuMoves;
	int turns;
	bool cat;
};

