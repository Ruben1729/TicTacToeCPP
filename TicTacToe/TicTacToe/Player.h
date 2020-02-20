#pragma once
#include <string>
class Player
{

private:
	int wins, losses;
	char letter;

public:
	int getMove();
	int getWins();
	int getLosses();

	char getLetter();

	void addWin();
	void addLoss();

	Player();
	Player(char);
	~Player();
};

