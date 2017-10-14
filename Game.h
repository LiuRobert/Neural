#pragma once
class Game
{
public:
	Game();
	~Game();

	int getTile(int x, int y) const;
	int getTile(int n) const;
	const int* getBoard() const;
	bool playMove(int color, int move);

private:
	// 7 * 6 = 42
	int board[42];

	bool checkWinner(int x, int y);
	bool winnerInDirection(int x, int y, int dX, int dY);
};

