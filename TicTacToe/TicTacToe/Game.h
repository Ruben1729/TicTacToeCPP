#pragma once
#include "Player.h"

class Game
{
private:
	Player p1, p2;
	bool p1Turn{ true };
	char board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };

public:
	void draw();
	void getMoves();
	void start();
	char checkWinner();
	void resetBoard();

	Game();
	~Game();
};

