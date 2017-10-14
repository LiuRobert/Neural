#include "Game.h"



Game::Game()
{
	for (int i = 0; i < 42; i++)
	{
		board[i] = 0;
	}
}

Game::~Game()
{
}

int Game::getTile(int x, int y) const
{
	return board[y * 7 + x];
}

int Game::getTile(int n) const
{
	return board[n];
}

const int* Game::getBoard() const
{
	return board;
}

bool Game::playMove(int color, int x)
{
	for (int y = 5; y >= 0; y--)
	{
		if (board[y * 7 + x] == 0)
		{
			board[y * 7 + x] = color;
			return checkWinner(x, y);
		}
	}
	throw "Invalid move!";
}

bool Game::checkWinner(int x, int y)
{
	return	winnerInDirection(x, y, 1, 0) ||
			winnerInDirection(x, y, 1, 1) ||
			winnerInDirection(x, y, -1, 1) ||
			winnerInDirection(x, y, 0, 1);
}


bool Game::winnerInDirection(int x, int y, int dX, int dY)
{
	int myColor = board[y * 7 + x];
	int n = 1;
	int cX = x;
	int cY = y;
	bool changedOnce = false;

	while (n < 4)
	{
		cX += dX;
		cY += dY;
		if (cX > 6 || cX < 0 || cY > 5 || cY < 0)
		{
			if (changedOnce)
				return false;

			changedOnce = true;
			cX = x;
			cY = y;
			dX = -dX;
			dY = -dY;
		}
		else if (board[cY * 7 + cX] == myColor)
		{
			n++;
		}
		else
		{
			if (changedOnce)
				return false;

			changedOnce = true;
			cX = x;
			cY = y;
			dX = -dX;
			dY = -dY;
		}
	}
	
	return true;
}
