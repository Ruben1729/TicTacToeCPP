#include "Game.h"
#include <iostream>

Game::Game(): p1(), p2('O'){

}

Game::~Game() {

}

void Game::start() {
	while (1) {
		getMoves();
		draw();
		
		char winner = checkWinner();
		if (winner != 'N') {
			std::string pWinner;
			if (winner == p1.getLetter()) {
				p1.addWin();
				p2.addLoss();
				pWinner = "Player 1";
			} else {
				p1.addLoss();
				p2.addWin();
				pWinner = "Player 2";
			}

			std::cout << "The winner is: " << pWinner << ". Congratulations!"; std::cout << std::endl;
			std::cout << "Score: Player 1:" << p1.getWins() << " | Player 2: " << p2.getWins(); std::cout << std::endl;
			std::cout << "Resetting the game..."; std::cout << std::endl;

			resetBoard();
		}
	}
}

void Game::resetBoard() {
	for (int i = 0; i < sizeof(board); i++) {
		board[i] = ' ';
	}
}

char Game::checkWinner() {
	for (int i = 0; i <= 6; i += 3) {
		if (board[i] == board[i + 1] && board[i + 1] == board[i + 2] && board[i] != ' ' && board[i + 1] != ' ' && board[i+2] != ' ') {
			return board[i];
		}
	}

	for (int i = 0; i < 3; i ++) {
		if (board[i] == board[i+3] && board[i+3] == board[i+6] && board[i] != ' ' && board[i + 3] != ' ' && board[i + 6] != ' ') {
			return board[i];
		}
	}

	if ((board[2] == board[4] && board[4] == board[6]) && board[4] != ' ') {
		return board[4];
	}

	if ((board[0] == board[4] && board[4] == board[8]) && board[4] != ' ') {
		return board[4];
	}

	return 'N';
}

void Game::getMoves() {
	int newMove;
	char player;
	char moveOnBoard = 'N';
	do {
		if (p1Turn) {
			newMove = p1.getMove();
			player = p1.getLetter();
		}
		else {
			newMove = p2.getMove();
			player = p2.getLetter();
		}

		moveOnBoard = board[newMove];

	} while (moveOnBoard != ' ');

	board[newMove] = player;
	p1Turn = !p1Turn;
}

void Game::draw() {
	for (int i = 0; i < 3; i++) {
		for (int j = i*3; j <= (i*3)+2; j++) {
			std::cout << board[j] << " ";
		}
		std::cout << std::endl;
	}
}

