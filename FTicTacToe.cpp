#include "FTicTacToe.h"



void FTicTacToe::ResetGame()
{
	cat = false;
	turn = 'X';
	winner = 'n';
	noOfCpuMoves = 0;
	turns = 0;
	for (int i = 0; i < 9; i++)
	{
		Board[i] = '1' + i;
	}
}

void FTicTacToe::PrintMainMenu()
{
	system("cls");
	std::cout << " ===============================================\n";
	std::cout << " ||           Welcome To Tic Tac Toe          ||\n";
	std::cout << " ||-------------------------------------------||\n";
	std::cout << " || Please enter the number of your selection ||\n";
	std::cout << " ||              1: Play vs CPU               ||\n";
	std::cout << " ||              2: Two Player                ||\n";
	std::cout << " ===============================================\n";
}

void FTicTacToe::PrintBoard()
{
	std::cout << "  " << Board[0] << " | " << Board[1] << " | " << Board[2] << " \n";
	std::cout << "  --------- \n";
	std::cout << "  " << Board[3] << " | " << Board[4] << " | " << Board[5] << " \n";
	std::cout << "  --------- \n";
	std::cout << "  " << Board[6] << " | " << Board[7] << " | " << Board[8] << " \n";
}

void FTicTacToe::PrintTurn()
{
	std::cout << "\n It is " << turn << "s turn.";
	std::cout << "\n Type the number of the space you want: ";
}

char FTicTacToe::GetTurn() { return turn; }

int FTicTacToe::GetValidAnswer(int NumOfAns)
{
	bool valid = false;
	int ans;
	do
	{
		std::cout << " > ";
		std::cin >> ans;
		if (ans > 0 && ans <= NumOfAns)
		{
			return ans;
			valid = true;
		}
		else
		{
			std::cout << " [Error] That is not a valid answer! Please try again.\n";
		}
	} while (!valid);
	
}

void FTicTacToe::SetDifficulty()
{
	system("cls");
	std::cout << " Select your difficulty:";
	std::cout << "\n   1: Easy";
	std::cout << "\n   2: Medium";
	std::cout << "\n   3: Hard\n";
	
	difficulty = GetValidAnswer(3);
}

void FTicTacToe::PlayMove()
{
	int moveSpot;
	bool ValidMove = false;
	do
	{
		std::cout << "\n > ";
		std::cin >> moveSpot;

		if (moveSpot > 9 || moveSpot < 1)
		{
			std::cout << "\n [Error] That is not a valid move! \n Please try again.";
		}
		else if (Board[moveSpot - 1] == 'O' || Board[moveSpot - 1] == 'X')
		{
			std::cout << "\n That spot is already taken.\n";
			std::cout << " Please enter a diffrent spot:";
		}
		else
		{
			Board[moveSpot - 1] = turn;
			turns++;
			ValidMove = true;
			if (turn == 'X') { turn = 'O'; }
			else { turn = 'X'; }
		}
	} while (!ValidMove);
}

void FTicTacToe::CPUMove()
{
	if (difficulty == 1) { MoveOne(); }
	else
	{
		bool AlreadyMoved = CheckThree();
		if (!AlreadyMoved) { AlreadyMoved = CheckTwo(); }
		if (!AlreadyMoved) { MoveOne(); }
	}
	turns++;
}

bool FTicTacToe::CheckThree()
{
	srand(time(0));
	int medRand;
	// Winning
	// Rows
	for (int r = 0; r < 7; r += 3)
	{
		if (Board[r] == 'O' && Board[r + 1] == 'O' && Board[r + 2] != 'X')
		{
			if (difficulty == 2)
			{
				medRand = (rand() % 4);
				if (medRand != 1)
				{
					Board[r + 2] = 'O';
					turn = 'X';
					return true;
				}
			}
			else
			{
				Board[r + 2] = 'O';
				turn = 'X';
				return true;
			}
		}
		if (Board[r + 2] == 'O' && Board[r + 1] == 'O' && Board[r] != 'X')
		{
			if (difficulty == 2)
			{
				medRand = (rand() % 4);
				if (medRand != 1)
				{
					Board[r] = 'O';
					turn = 'X';
					return true;
				}
			}
			else
			{
				Board[r] = 'O';
				turn = 'X';
				return true;
			}
		}
		if (Board[r] == 'O' && Board[r + 2] == 'O' && Board[r + 1] != 'X')
		{
			if (difficulty == 2)
			{
				medRand = (rand() % 4);
				if (medRand != 1)
				{
					Board[r + 1] = 'O';
					turn = 'X';
					return true;
				}
			}
			else
			{
				Board[r + 1] = 'O';
				turn = 'X';
				return true;
			}
		}
	}
	// collumns
	for (int r = 0; r < 3; r++)
	{
		if (Board[r] == 'O' && Board[r + 3] == 'O' && Board[r + 6] != 'X')
		{
			if (difficulty == 2)
			{
				medRand = (rand() % 4);
				if (medRand != 1)
				{
					Board[r + 6] = 'O';
					turn = 'X';
					return true;
				}
			}
			else
			{
				Board[r + 6] = 'O';
				turn = 'X';
				return true;
			}
		}
		if (Board[r + 6] == 'O' && Board[r + 3] == 'O' && Board[r] != 'X')
		{
			if (difficulty == 2)
			{
				medRand = (rand() % 4);
				if (medRand != 1)
				{
					Board[r] = 'O';
					turn = 'X';
					return true;
				}
			}
			else
			{
				Board[r] = 'O';
				turn = 'X';
				return true;
			}
		}
		if (Board[r] == 'O' && Board[r + 6] == 'O' && Board[r + 3] != 'X')
		{
			if (difficulty == 2)
			{
				medRand = (rand() % 4);
				if (medRand != 1)
				{
					Board[r + 3] = 'O';
					turn = 'X';
					return true;
				}
			}
			else
			{
				Board[r + 3] = 'O';
				turn = 'X';
				return true;
			}
		}
	}
	// Diagonal
	if (Board[4] != 'X' && ((Board[0] == 'O' && Board[8] == 'O') || (Board[2] == 'O' && Board[6] == 'O')))
	{
		if (difficulty == 2)
		{
			medRand = (rand() % 4);
			if (medRand != 1)
			{
				Board[4] = 'O';
				turn = 'X';
				return true;
			}
		}
		else
		{
			Board[4] = 'O';
			turn = 'X';
			return true;
		}
	}
	if (Board[4] == 'O' && Board[0] == 'O' && Board[8] != 'X')
	{
		if (difficulty == 2)
		{
			medRand = (rand() % 4);
			if (medRand != 1)
			{
				Board[8] = 'O';
				turn = 'X';
				return true;
			}
		}
		else
		{
			Board[8] = 'O';
			turn = 'X';
			return true;
		}
	}
	if (Board[4] == 'O' && Board[8] == 'O' && Board[0] != 'X')
	{
		if (difficulty == 2)
		{
			medRand = (rand() % 4);
			if (medRand != 1)
			{
				Board[0] = 'O';
				turn = 'X';
				return true;
			}
		}
		else
		{
			Board[0] = 'O';
			turn = 'X';
			return true;
		}
	}
	if (Board[4] == 'O' && Board[2] == 'O' && Board[6] != 'X')
	{
		if (difficulty == 2)
		{
			medRand = (rand() % 4);
			if (medRand != 1)
			{
				Board[6] = 'O';
				turn = 'X';
				return true;
			}
		}
		else
		{
			Board[6] = 'O';
			turn = 'X';
			return true;
		}
	}
	if (Board[4] == 'O' && Board[6] == 'O' && Board[2] != 'X')
	{
		if (difficulty == 2)
		{
			medRand = (rand() % 4);
			if (medRand != 1)
			{
				Board[2] = 'O';
				turn = 'X';
				return true;
			}
		}
		else
		{
			Board[2] = 'O';
			turn = 'X';
			return true;
		}
	}


	// Blocking
	// Rows
	for (int r = 0; r < 7; r += 3)
	{
		if (Board[r] == 'X' && Board[r + 1] == 'X' && Board[r + 2] != 'O')
		{
			if (difficulty == 2)
			{
				medRand = (rand() % 4);
				if (medRand != 1)
				{
					Board[r + 2] = 'O';
					turn = 'X';
					return true;
				}
			}
			else
			{
				Board[r + 2] = 'O';
				turn = 'X';
				return true;
			}
		}
		if (Board[r + 2] == 'X' && Board[r + 1] == 'X' && Board[r] != 'O')
		{
			if (difficulty == 2)
			{
				medRand = (rand() % 4);
				if (medRand != 1)
				{
					Board[r] = 'O';
					turn = 'X';
					return true;
				}
			}
			else
			{
				Board[r] = 'O';
				turn = 'X';
				return true;
			}
		}
		if (Board[r] == 'X' && Board[r + 2] == 'X' && Board[r + 1] != 'O')
		{
			if (difficulty == 2)
			{
				medRand = (rand() % 4);
				if (medRand != 1)
				{
					Board[r + 1] = 'O';
					turn = 'X';
					return true;
				}
			}
			else
			{
				Board[r + 1] = 'O';
				turn = 'X';
				return true;
			}
		}
	}
	// collumns
	for (int r = 0; r < 3; r++)
	{
		if (Board[r] == 'X' && Board[r + 3] == 'X' && Board[r + 6] != 'O')
		{
			if (difficulty == 2)
			{
				medRand = (rand() % 4);
				if (medRand != 1)
				{
					Board[r + 6] = 'O';
					turn = 'X';
					return true;
				}
			}
			else
			{
				Board[r + 6] = 'O';
				turn = 'X';
				return true;
			}
		}
		if (Board[r + 6] == 'X' && Board[r + 3] == 'X' && Board[r] != 'O')
		{
			if (difficulty == 2)
			{
				medRand = (rand() % 4);
				if (medRand != 1)
				{
					Board[r] = 'O';
					turn = 'X';
					return true;
				}
			}
			else
			{
				Board[r] = 'O';
				turn = 'X';
				return true;
			}
		}
		if (Board[r] == 'X' && Board[r + 6] == 'X' && Board[r + 3] != 'O')
		{
			if (difficulty == 2)
			{
				medRand = (rand() % 4);
				if (medRand != 1)
				{
					Board[r + 3] = 'O';
					turn = 'X';
					return true;
				}
			}
			else
			{
				Board[r + 3] = 'O';
				turn = 'X';
				return true;
			}
		}
	}
	// Diagonal
	if (Board[4] != 'O' && ((Board[0] == 'X' && Board[8] == 'X') || (Board[2] == 'X' && Board[6] == 'X')))
	{
		if (difficulty == 2)
		{
			medRand = (rand() % 4);
			if (medRand != 1)
			{
				Board[4] = 'O';
				turn = 'X';
				return true;
			}
		}
		else
		{
			Board[4] = 'O';
			turn = 'X';
			return true;
		}
	}
	if (Board[4] == 'X' && Board[0] == 'X' && Board[8] != 'O')
	{
		if (difficulty == 2)
		{
			medRand = (rand() % 4);
			if (medRand != 1)
			{
				Board[8] = 'O';
				turn = 'X';
				return true;
			}
		}
		else
		{
			Board[8] = 'O';
			turn = 'X';
			return true;
		}
	}
	if (Board[4] == 'X' && Board[8] == 'X' && Board[0] != 'O')
	{
		if (difficulty == 2)
		{
			medRand = (rand() % 4);
			if (medRand != 1)
			{
				Board[0] = 'O';
				turn = 'X';
				return true;
			}
		}
		else
		{
			Board[0] = 'O';
			turn = 'X';
			return true;
		}
	}
	if (Board[4] == 'X' && Board[2] == 'X' && Board[6] != 'O')
	{
		if (difficulty == 2)
		{
			medRand = (rand() % 4);
			if (medRand != 1)
			{
				Board[6] = 'O';
				turn = 'X';
				return true;
			}
		}
		else
		{
			Board[6] = 'O';
			turn = 'X';
			return true;
		}
	}
	if (Board[4] == 'X' && Board[6] == 'X' && Board[2] != 'O')
	{
		if (difficulty == 2)
		{
			medRand = (rand() % 4);
			if (medRand != 1)
			{
				Board[2] = 'O';
				turn = 'X';
				return true;
			}
		}
		else
		{
			Board[2] = 'O';
			turn = 'X';
			return true;
		}
	}

	return false;
}

bool FTicTacToe::CheckTwo()
{
	srand(time(0));
	int diffChance;
	int ospot;
	int mspot;
	int nspots;
	int noguesses;
	bool pspots[9];
	bool uspots[9];

	bool CTPass = false;
	do
	{
		noguesses = 0;
		for (int i = 0; i < 9; i++) { pspots[i] = false; uspots[i] = false; }
		bool spotpass = false;
		do
		{
			ospot = (rand() % 9);
			if (uspots[ospot])
			{	
				spotpass = false;
			}
			else
			{
				spotpass = true;
				uspots[ospot] = true;
				noguesses++;
			}
		} while (spotpass);
		if (Board[ospot] == 'O')
		{
			if (difficulty == 2)
			{
				switch (ospot)
				{
				case 0:
					if (Board[1] == '2') { pspots[1] = true; }
					if (Board[3] == '4') { pspots[3] = true; }
					if (Board[4] == '5') { pspots[4] = true; }
					break;
				case 1:
					if (Board[0] == '1') { pspots[0] = true; }
					if (Board[2] == '3') { pspots[2] = true; }
					if (Board[4] == '5') { pspots[4] = true; }
					break;
				case 2:
					if (Board[1] == '2') { pspots[1] = true; }
					if (Board[5] == '6') { pspots[5] = true; }
					if (Board[4] == '5') { pspots[4] = true; }
					break;
				case 3:
					if (Board[0] == '1') { pspots[0] = true; }
					if (Board[4] == '5') { pspots[4] = true; }
					if (Board[6] == '7') { pspots[6] = true; }
					break;
				case 4:
					if (Board[0] == '1') { pspots[0] = true; }
					if (Board[1] == '2') { pspots[1] = true; }
					if (Board[2] == '3') { pspots[2] = true; }
					if (Board[3] == '4') { pspots[3] = true; }
					if (Board[5] == '6') { pspots[5] = true; }
					if (Board[6] == '7') { pspots[6] = true; }
					if (Board[7] == '8') { pspots[7] = true; }
					if (Board[8] == '9') { pspots[8] = true; }
					break;
				case 5:
					if (Board[2] == '3') { pspots[2] = true; }
					if (Board[8] == '9') { pspots[8] = true; }
					if (Board[4] == '5') { pspots[4] = true; }
					break;
				case 6:
					if (Board[3] == '4') { pspots[3] = true; }
					if (Board[7] == '8') { pspots[7] = true; }
					if (Board[4] == '5') { pspots[4] = true; }
					break;
				case 7:
					if (Board[6] == '7') { pspots[6] = true; }
					if (Board[8] == '9') { pspots[8] = true; }
					if (Board[4] == '5') { pspots[4] = true; }
					break;
				case 8:
					if (Board[5] == '6') { pspots[5] = true; }
					if (Board[7] == '8') { pspots[7] = true; }
					if (Board[4] == '5') { pspots[4] = true; }
					break;
				default:
					break;
				}
			}
			else
			{
				switch (ospot)
				{
				case 0:
					if (Board[1] == '2' && Board[2] == '3') { pspots[1] = true; pspots[2] = true; }
					if (Board[3] == '4' && Board[6] == '7') { pspots[3] = true; pspots[6] = true; }
					if (Board[4] == '5' && Board[8] == '9') { pspots[4] = true; pspots[8] = true; }
					break;
				case 1:
					if (Board[0] == '1' && Board[2] == '3') { pspots[0] = true; pspots[2] = true; }
					if (Board[4] == '5' && Board[7] == '8') { pspots[4] = true; pspots[7] = true; }
					break;
				case 2:
					if (Board[1] == '2' && Board[0] == '1') { pspots[1] = true; pspots[0] = true; }
					if (Board[5] == '6' && Board[8] == '9') { pspots[5] = true; pspots[8] = true; }
					if (Board[4] == '5' && Board[6] == '7') { pspots[4] = true; pspots[6] = true; }
					break;
				case 3:
					if (Board[0] == '1' && Board[6] == '7') { pspots[0] = true; pspots[6] = true; }
					if (Board[4] == '5' && Board[5] == '6') { pspots[4] = true; pspots[5] = true; }
					break;
				case 4:
					if (Board[0] == '1' && Board[8] == '9') { pspots[0] = true; pspots[8] = true; }
					if (Board[2] == '3' && Board[6] == '7') { pspots[3] = true; pspots[7] = true; }
					if (Board[1] == '2' && Board[7] == '8') { pspots[1] = true; pspots[7] = true; }
					if (Board[3] == '4' && Board[5] == '6') { pspots[3] = true; pspots[5] = true; }
					break;
				case 5:
					if (Board[2] == '3' && Board[8] == '9') { pspots[8] = true; pspots[2] = true; }
					if (Board[4] == '5' && Board[3] == '4') { pspots[3] = true; pspots[7] = true; }
					break;
				case 6:
					if (Board[3] == '4' && Board[0] == '1') { pspots[3] = true; pspots[0] = true; }
					if (Board[7] == '8' && Board[8] == '9') { pspots[7] = true; pspots[8] = true; }
					if (Board[4] == '5' && Board[2] == '3') { pspots[4] = true; pspots[2] = true; }
					break;
				case 7:
					if (Board[6] == '7' && Board[8] == '9') { pspots[6] = true; pspots[8] = true; }
					if (Board[4] == '5' && Board[1] == '2') { pspots[4] = true; pspots[1] = true; }
					break;
				case 8:
					if (Board[7] == '8' && Board[6] == '7') { pspots[6] = true; pspots[7] = true; }
					if (Board[5] == '6' && Board[2] == '3') { pspots[5] = true; pspots[2] = true; }
					if (Board[4] == '5' && Board[0] == '1') { pspots[4] = true; pspots[0] = true; }
					break;
				default:
					break;
				}
			}
		}
		nspots = 0;
		for (int i = 0; i < 9; i++) { if (pspots[i]) { nspots++; } }
		if (nspots > 0)
		{
			bool nspPass = false;
			do
			{
				mspot = (rand() % 9);
				if (pspots[mspot])
				{
					Board[mspot] = 'O';
					turn = 'X';
					return true;
					nspPass = true;
				}
			} while (!nspots);
		}
		if (noguesses >= 9) { CTPass = true; }
	} while (!CTPass);

	return false;
}

void FTicTacToe::MoveOne()
{
	srand(time(0));
	int move;
	int validMove = false;
	do
	{
		move = (rand() % 9);
		if (Board[move] == 'X' || Board[move] == 'O') { validMove = false; }
		else { validMove = true; }
	} while (!validMove);
	Board[move] = 'O';
	turn = 'X';
}

bool FTicTacToe::IsGameWon()
{
	if (turns == 9)
	{
		cat = true;
		return true;
	}

	char TestChar = 'X';
	for (int t = 0; t < 3; t++)
	{
		if (Board[t] == TestChar && Board[t + 3] == TestChar && Board[t + 6] == TestChar)
		{
			winner = TestChar;
			return true;
		}
	}
	for (int t = 0; t < 7; t += 3)
	{
		if (Board[t] == TestChar && Board[t + 1] == TestChar && Board[t + 2] == TestChar) 
		{ 
			winner = TestChar;
			return true; 
		}
	}
	if ((Board[4] == TestChar) && ((Board[0] == TestChar && Board[8] == TestChar) || (Board[2] == TestChar && Board[6] == TestChar))) 
	{
		winner = TestChar;
		return true; 
	}
	
	TestChar = 'O';
	for (int t = 0; t < 3; t++)
	{
		if (Board[t] == TestChar && Board[t + 3] == TestChar && Board[t + 6] == TestChar)
		{
			winner = TestChar;
			return true;
		}
	}
	for (int t = 0; t < 7; t += 3)
	{
		if (Board[t] == TestChar && Board[t + 1] == TestChar && Board[t + 2] == TestChar)
		{
			winner = TestChar;
			return true;
		}
	}
	if ((Board[4] == TestChar) && ((Board[0] == TestChar && Board[8] == TestChar) || (Board[2] == TestChar && Board[6] == TestChar)))
	{
		winner = TestChar;
		return true;
	}
	return false;
}

void FTicTacToe::PrintEnding()
{	
	system("cls");
	PrintBoard();
	if (cat)
	{
		std::cout << "\n The game has ended in a cat! There is no winner.";
	}
	else
	{
		std::cout << "\n " << winner << " has won the game!";
	}
	
}

 